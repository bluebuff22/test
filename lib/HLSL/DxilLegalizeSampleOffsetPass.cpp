///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// DxilSignature.cpp                                                         //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
// DxilLegalizeSampleOffsetPass implementation.                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "dxc/HLSL/DxilGenerationPass.h"
#include "dxc/HLSL/DxilModule.h"
#include "dxc/HLSL/DxilOperations.h"

#include "llvm/Analysis/InstructionSimplify.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"
#include "llvm/Transforms/Scalar.h"

#include <unordered_set>

using std::vector;
using std::unique_ptr;
using namespace llvm;
using namespace hlsl;

///////////////////////////////////////////////////////////////////////////////
// Legalize Sample offset.

namespace {
// When optimizations are disabled, try to legalize sample offset.
class DxilLegalizeSampleOffsetPass : public FunctionPass {

public:
  static char ID; // Pass identification, replacement for typeid
  explicit DxilLegalizeSampleOffsetPass() : FunctionPass(ID) {}

  const char *getPassName() const override {
    return "DXIL legalize sample offset";
  }

  bool runOnFunction(Function &F) override {
    DxilModule &DM = F.getParent()->GetOrCreateDxilModule();
    hlsl::OP *hlslOP = DM.GetOP();

    std::vector<Instruction *> illegalOffsets;

    CollectIllegalOffsets(illegalOffsets, F, hlslOP);

    if (illegalOffsets.empty())
      return false;

    // Loop unroll if has offset inside loop.
    TryUnrollLoop(illegalOffsets, F);

    // Collect offset again after mem2reg.
    std::vector<Instruction *> ssaIllegalOffsets;
    CollectIllegalOffsets(ssaIllegalOffsets, F, hlslOP);

    // Run simple optimization to legalize offsets.
    LegalizeOffsets(ssaIllegalOffsets);

    // Remove PHINodes to keep code shape.
    legacy::FunctionPassManager PM(F.getParent());
    PM.add(createDemoteRegisterToMemoryHlslPass());
    PM.run(F);

    return true;
  }

private:
  void TryUnrollLoop(std::vector<Instruction *> &illegalOffsets, Function &F);
  void CollectIllegalOffsets(std::vector<Instruction *> &illegalOffsets,
                             Function &F, hlsl::OP *hlslOP);
  void CollectIllegalOffsets(std::vector<Instruction *> &illegalOffsets,
                             Function &F, DXIL::OpCode opcode,
                             hlsl::OP *hlslOP);
  void LegalizeOffsets(const std::vector<Instruction *> &illegalOffsets);
};

char DxilLegalizeSampleOffsetPass::ID = 0;
}

void DxilLegalizeSampleOffsetPass::TryUnrollLoop(
    std::vector<Instruction *> &illegalOffsets, Function &F) {
  DominatorTreeAnalysis DTA;
  DominatorTree DT = DTA.run(F);
  LoopInfo LI;
  LI.Analyze(DT);

  bool findOffset = false;

  for (auto loopIt = LI.begin(); loopIt != LI.end(); loopIt++) {
    Loop *loop = *loopIt;
    for (Instruction *I : illegalOffsets) {
      BasicBlock *BB = I->getParent();
      if (loop->contains(BB)) {
        findOffset = true;
        break;
      }
    }
    if (findOffset)
      break;
  }

  legacy::FunctionPassManager PM(F.getParent());
  // Always need mem2reg for simplify illegal offsets.
  PM.add(createPromoteMemoryToRegisterPass());

  if (findOffset) {
    PM.add(createCFGSimplificationPass());
    PM.add(createLCSSAPass());
    PM.add(createLoopSimplifyPass());
    PM.add(createLoopRotatePass());
    PM.add(createLoopUnrollPass(-2, -1, 0, 0));
  }
  PM.run(F);
}

void DxilLegalizeSampleOffsetPass::CollectIllegalOffsets(
    std::vector<Instruction *> &illegalOffsets, Function &CurF,
    hlsl::OP *hlslOP) {
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::Sample, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleBias, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleCmp, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleCmpLevelZero,
                        hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleGrad, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleLevel,
                        hlslOP);
}

void DxilLegalizeSampleOffsetPass::CollectIllegalOffsets(
    std::vector<Instruction *> &illegalOffsets, Function &CurF,
    DXIL::OpCode opcode, hlsl::OP *hlslOP) {
  ArrayRef<Function*> intrFuncList = hlslOP->GetOpFuncList(opcode);
  for (Function *intrFunc : intrFuncList) {
    if (!intrFunc)
      continue;
    for (User *U : intrFunc->users()) {
      CallInst *CI = cast<CallInst>(U);
      // Skip inst not in current function.
      if (CI->getParent()->getParent() != &CurF)
        continue;

      Value *offset0 =
          CI->getArgOperand(DXIL::OperandIndex::kTextureSampleOffset0OpIdx);
      // No offset.
      if (isa<UndefValue>(offset0))
        continue;

      for (unsigned i = DXIL::OperandIndex::kTextureSampleOffset0OpIdx;
           i <= DXIL::OperandIndex::kTextureSampleOffset2OpIdx; i++) {
        Value *offset = CI->getArgOperand(i);
        if (Instruction *I = dyn_cast<Instruction>(offset))
          illegalOffsets.emplace_back(I);
      }
    }
  }
}

void DxilLegalizeSampleOffsetPass::LegalizeOffsets(
    const std::vector<Instruction *> &illegalOffsets) {
  for (Instruction *I : illegalOffsets)
    llvm::recursivelySimplifyInstruction(I);
}

FunctionPass *llvm::createDxilLegalizeSampleOffsetPass() {
  return new DxilLegalizeSampleOffsetPass();
}

INITIALIZE_PASS(DxilLegalizeSampleOffsetPass, "dxil-legalize-sample-offset",
                "DXIL legalize sample offset", false, false)
