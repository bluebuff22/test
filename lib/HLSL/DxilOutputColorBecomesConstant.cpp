///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// DxilOutputColorBecomesConstant.cpp                                        //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
// Provides a pass to stomp a pixel shader's output color to a given         //
// constant value                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "dxc/HLSL/DxilGenerationPass.h"
#include "dxc/HLSL/DxilOperations.h"
#include "dxc/HLSL/DxilSignatureElement.h"
#include "dxc/HLSL/DxilModule.h"
#include "dxc/Support/Global.h"
#include "dxc/HLSL/DxilTypeSystem.h"
#include "dxc/HLSL/DxilInstructions.h"
#include "dxc/HLSL/DxilSpanAllocator.h"

#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/Pass.h"
#include "llvm/Transforms/Utils/Local.h"
#include <memory>
#include <unordered_set>

using namespace llvm;
using namespace hlsl;

class DxilOutputColorBecomesConstant : public ModulePass {

  float r = 2.2f;
  float g = 0.4f;
  float b = 0.6f;
  float a = 1.f;

public:
  static char ID; // Pass identification, replacement for typeid
  explicit DxilOutputColorBecomesConstant() : ModulePass(ID) {}

  const char *getPassName() const override { return "DXIL Constant Color Mod"; }

  virtual void applyOptions(PassOptions O) override {
    for (const auto & option : O)
    {
      if (0 == option.first.compare("constant-red"))
      {
        r = atof(option.second.data());
      }
      else if (0 == option.first.compare("constant-green"))
      {
        g = atof(option.second.data());
      }
      else if (0 == option.first.compare("constant-blue"))
      {
        b = atof(option.second.data());
      }
      else if (0 == option.first.compare("constant-alpha"))
      {
        a = atof(option.second.data());
      }
    }
  }

  bool runOnModule(Module &M) override {

    float color[4] = { r, g, b, a };

    DxilModule &DM = M.GetOrCreateDxilModule();

    LLVMContext & Ctx = M.getContext();

    OP *HlslOP = DM.GetOP();

    // The StoreOutput function can store either a float or an integer, in order to be compatible with the particular output
    // render-target resource view.
    Function *OutputFunction = HlslOP->GetOpFunc(DXIL::OpCode::StoreOutput, Type::getFloatTy(Ctx));

    if (OutputFunction->getNumUses() == 0)
    {
      OutputFunction = HlslOP->GetOpFunc(DXIL::OpCode::StoreOutput, Type::getInt32Ty(Ctx));
      if (OutputFunction->getNumUses() == 0)
      {
        // Returning false, indicating that the shader was not modified, since there were no calls to StoreOutput
        return false;
      }
    }

    const hlsl::DxilSignature & OutputSignature = DM.GetOutputSignature();

    auto OutputFunctionUses = OutputFunction->uses();

    for (Use &FunctionUse : OutputFunctionUses) {
      iterator_range<Value::user_iterator> FunctionUsers = FunctionUse->users();
      for (User * FunctionUser : FunctionUsers) {
        if (isa<Instruction>(FunctionUser)) {
          auto CallInstruction = cast<CallInst>(FunctionUser);

          // Check if the instruction writes to a render target (as opposed to a system-value, such as RenderTargetArrayIndex)
          Value *OutputID = CallInstruction->getArgOperand(DXIL::OperandIndex::kStoreOutputIDOpIdx);
          unsigned SignatureElementIndex = cast<ConstantInt>(OutputID)->getLimitedValue();
          const DxilSignatureElement &SignatureElement = OutputSignature.GetElement(SignatureElementIndex);

          if (SignatureElement.GetSemantic()->GetKind() == DXIL::SemanticKind::Target)
    {
            DxilInst_StoreOutput StoreOutputInstruction(CallInstruction);

            // The output column is the channel (red, green, blue or alpha) within the output pixel
            Value * OutputColumnOperand = CallInstruction->getOperand(hlsl::DXIL::OperandIndex::kStoreOutputColOpIdx);
            ConstantInt * OutputColumnConstant = cast<ConstantInt>(OutputColumnOperand);
            APInt OutputColumn = OutputColumnConstant->getValue();

            Value * OutputValueOperand = CallInstruction->getOperand(hlsl::DXIL::OperandIndex::kStoreOutputValOpIdx);

            // Replace the source operand with the appropriate constant literal value
            if (isa<ConstantFP>(OutputValueOperand))
          {
              Constant * FloatConstant = HlslOP->GetFloatConst(color[*OutputColumn.getRawData()]);
              CallInstruction->setOperand(hlsl::DXIL::OperandIndex::kStoreOutputValOpIdx, FloatConstant);
          }
            else if (isa<ConstantInt>(OutputValueOperand))
          {
              Constant * pIntegerConstant = HlslOP->GetI32Const(static_cast<int>(color[*OutputColumn.getRawData()]));
              CallInstruction->setOperand(hlsl::DXIL::OperandIndex::kStoreOutputValOpIdx, pIntegerConstant);
          }
        }
      }
    }
    }

    // Returning true, indicating that the shader was modified
    return true;
  }
};



char DxilOutputColorBecomesConstant::ID = 0;

ModulePass *llvm::createDxilOutputColorBecomesConstantPass() {
  return new DxilOutputColorBecomesConstant();
}

INITIALIZE_PASS(DxilOutputColorBecomesConstant, "hlsl-dxil-constantColor", "DXIL Constant Color Mod", false, false)
