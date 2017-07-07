///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// DxilReduceMSAAToSingleSample.cpp                                          //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
// Provides a pass to reduce all MSAA writes to single-sample writes         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "dxc/HLSL/DxilGenerationPass.h"
#include "dxc/HLSL/DxilOperations.h"
#include "dxc/HLSL/DxilModule.h"

#include "llvm/IR/Instructions.h"
#include "llvm/IR/PassManager.h"

using namespace llvm;
using namespace hlsl;

class DxilReduceMSAAToSingleSample : public ModulePass {

public:
  static char ID; // Pass identification, replacement for typeid
  explicit DxilReduceMSAAToSingleSample() : ModulePass(ID) {}
  const char *getPassName() const override { return "HLSL DXIL Reduce all MSAA writes to single-sample writes"; }
  bool runOnModule(Module &M) override;
};

bool DxilReduceMSAAToSingleSample::runOnModule(Module &M)
{
  // This pass removes all instances of the discard instruction within the shader.
  DxilModule &DM = M.GetOrCreateDxilModule();

  LLVMContext & Ctx = M.getContext();
  OP *HlslOP = DM.GetOP();

  auto TextureLoadOverloads = std::vector<Type*>{ /*todo: what's fp16 type? */ Type::getFloatTy(Ctx), Type::getInt16Ty(Ctx), Type::getInt32Ty(Ctx) };

  bool Modified = false;

  for (const auto & Overload : TextureLoadOverloads) {

    Function * TexLoadFunction = HlslOP->GetOpFunc(DXIL::OpCode::TextureLoad, Overload);
    auto TexLoadFunctionUses = TexLoadFunction->uses();

    for (auto FI = TexLoadFunctionUses.begin(); FI != TexLoadFunctionUses.end(); ) {
      auto & FunctionUse = *FI++;
      auto FunctionUser = FunctionUse.getUser();
      auto instruction = cast<Instruction>(FunctionUser);
      //todo: how to detect MS vs single-sample? MIP level and sample index are in the same field!

      //todo: no apparent constant definition for the mip-level/sample-index operand index (the "3"):
      // https://github.com/Microsoft/DirectXShaderCompiler/blob/master/docs/DXIL.rst#textureload
      instruction->setOperand(3, HlslOP->GetI32Const(0));
      Modified = true;
    }
  }

  return Modified;
}

char DxilReduceMSAAToSingleSample::ID = 0;

ModulePass *llvm::createDxilReduceMSAAToSingleSamplePass() {
  return new DxilReduceMSAAToSingleSample();
}

INITIALIZE_PASS(DxilReduceMSAAToSingleSample, "hlsl-dxil-reduce-msaa-to-single", "HLSL DXIL Reduce all MSAA writes to single-sample writes", false, false)
