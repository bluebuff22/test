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
#include "llvm/Analysis/DxilValueCache.h"
#include "dxc/DXIL/DxilModule.h"
#include "dxc/DXIL/DxilOperations.h"
#include "dxc/DXIL/DxilUtil.h"

#include "llvm/Analysis/InstructionSimplify.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
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

  LoopInfo LI;

public:
  static char ID; // Pass identification, replacement for typeid
  explicit DxilLegalizeSampleOffsetPass() : FunctionPass(ID) {}

  const char *getPassName() const override {
    return "DXIL legalize sample offset";
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<DxilValueCache>();
    AU.setPreservesAll();
  }

  bool runOnFunction(Function &F) override {
    DxilModule &DM = F.getParent()->GetOrCreateDxilModule();
    hlsl::OP *hlslOP = DM.GetOP();

    std::vector<std::pair<Value *, CallInst*>> illegalOffsets;

    CollectIllegalOffsets(illegalOffsets, F, hlslOP);

    if (illegalOffsets.empty())
      return false;

    // Loop unroll if has offset inside loop.
    TryUnrollLoop(illegalOffsets, F);

    // Collect offset again after mem2reg.
    std::vector<std::pair<Value *, CallInst*>> ssaIllegalOffsets;
    CollectIllegalOffsets(ssaIllegalOffsets, F, hlslOP);

    // Run simple optimization to legalize offsets.
    LegalizeOffsets(ssaIllegalOffsets);

    FinalCheck(F, hlslOP);

    return true;
  }

private:
  void TryUnrollLoop(std::vector<std::pair<Value *, CallInst*>> &illegalOffsets, Function &F);
  void CollectIllegalOffsets(std::vector<std::pair<Value *, CallInst*>> &illegalOffsets,
                             Function &F, hlsl::OP *hlslOP);
  void CollectIllegalOffsets(std::vector<std::pair<Value *, CallInst*>> &illegalOffsets,
                             Function &F, DXIL::OpCode opcode,
                             hlsl::OP *hlslOP);
  void LegalizeOffsets(const std::vector<std::pair<Value *, CallInst*>> &illegalOffsets);
  void FinalCheck(Function &F, hlsl::OP *hlslOP);
};

char DxilLegalizeSampleOffsetPass::ID = 0;

bool HasIllegalOffsetInLoop(std::vector<std::pair<Value *, CallInst*>> &illegalOffsets, LoopInfo &LI,
                            Function &F) {
  DominatorTreeAnalysis DTA;
  DominatorTree DT = DTA.run(F);
  LI.Analyze(DT);

  bool findOffset = false;

  for (auto it : illegalOffsets) {
    if (Instruction *I = dyn_cast<Instruction>(it.first)) {
      BasicBlock *BB = I->getParent();
      if (LI.getLoopFor(BB)) {
        findOffset = true;
        break;
      }
    }
  }
  return findOffset;
}

void GetOffsetRange(DXIL::OpCode opcode, unsigned &offsetStart, unsigned &offsetEnd)
{
  switch(opcode) {
  case DXIL::OpCode::TextureLoad:
    offsetStart = DXIL::OperandIndex::kTextureLoadOffset0OpIdx;
    offsetEnd = DXIL::OperandIndex::kTextureLoadOffset2OpIdx;
    break;
  case DXIL::OpCode::TextureGather:
  case DXIL::OpCode::TextureGatherCmp:
    offsetStart = DXIL::OperandIndex::kTextureGatherOffset0OpIdx;
    offsetEnd = DXIL::OperandIndex::kTextureGatherOffset1OpIdx;
    break;
  default:
    // everything else are sample variants
    offsetStart = DXIL::OperandIndex::kTextureSampleOffset0OpIdx;
    offsetEnd = DXIL::OperandIndex::kTextureSampleOffset2OpIdx;
    break;
  }
}

void CollectIllegalOffset(CallInst *CI, DXIL::OpCode opcode,
                          std::vector<std::pair<Value *, CallInst*>> &illegalOffsets) {

  unsigned offsetStart = 0, offsetEnd = 0;

  GetOffsetRange(opcode, offsetStart, offsetEnd);

  Value *offset0 =
      CI->getArgOperand(offsetStart);
  // No offsets
  if (isa<UndefValue>(offset0))
    return;

  for (unsigned i = offsetStart; i <= offsetEnd; i++) {
    Value *offset = CI->getArgOperand(i);
    if (Instruction *I = dyn_cast<Instruction>(offset))
      illegalOffsets.emplace_back(std::make_pair(I, CI));
  }
}
}

// Return true if the call instruction in pair a and b are the same
bool InstEq(const std::pair<Value*,CallInst*> &a, const std::pair<Value*,CallInst*> &b) {
  return a.second == b.second;
}

// Return true if the call instruction in pair a is before that in pair b
bool InstLT(const std::pair<Value*,CallInst*> &a, const std::pair<Value*,CallInst*> &b) {
  DebugLoc aLoc = a.second->getDebugLoc();
  DebugLoc bLoc = b.second->getDebugLoc();
  if (aLoc && bLoc)
    return aLoc.getLine() < bLoc.getLine();
  // No line numbers, just compare pointers so that matching instructions will be adjacent
  return a.second < b.second;
}

void DxilLegalizeSampleOffsetPass::FinalCheck(Function &F, hlsl::OP *hlslOP) {
  // Collect offset to make sure no illegal offsets.
  std::vector<std::pair<Value *, CallInst*>> finalIllegalOffsets;
  CollectIllegalOffsets(finalIllegalOffsets, F, hlslOP);

  if (!finalIllegalOffsets.empty()) {
    std::string errorMsg = "Offsets to texture access operations must be immediate values. ";

    auto offsetBegin = finalIllegalOffsets.begin();
    auto offsetEnd = finalIllegalOffsets.end();

    std::sort(offsetBegin, offsetEnd, InstLT);
    offsetEnd = std::unique(offsetBegin, offsetEnd, InstEq);

    for (auto it = offsetBegin; it != offsetEnd; it++) {
      CallInst *CI = it->second;
      if (Instruction *offset = dyn_cast<Instruction>(it->first)) {
        if (LI.getLoopFor(offset->getParent()))
          dxilutil::EmitErrorOnInstruction(CI, errorMsg + "Unrolling the loop containing the offset value"
                                           " manually and using -O3 may help in some cases.\n");
        else
          dxilutil::EmitErrorOnInstruction(CI, errorMsg);
      }
    }
  }
}

void DxilLegalizeSampleOffsetPass::TryUnrollLoop(
    std::vector<std::pair<Value *, CallInst*>> &illegalOffsets, Function &F) {
  legacy::FunctionPassManager PM(F.getParent());
  // Scalarize aggregates as mem2reg only applies on scalars.
  PM.add(createSROAPass());
  // Always need mem2reg for simplify illegal offsets.
  PM.add(createPromoteMemoryToRegisterPass());

  bool UnrollLoop = HasIllegalOffsetInLoop(illegalOffsets, LI, F);
  if (UnrollLoop) {
    PM.add(createCFGSimplificationPass());
    PM.add(createLCSSAPass());
    PM.add(createLoopSimplifyPass());
    PM.add(createLoopRotatePass());
    PM.add(createLoopUnrollPass(-2, -1, 0, 0));
  }
  PM.run(F);

  if (UnrollLoop) {
    DxilValueCache *DVC = &getAnalysis<DxilValueCache>();
    DVC->ResetUnknowns();
  }
}

void DxilLegalizeSampleOffsetPass::CollectIllegalOffsets(
    std::vector<std::pair<Value *, CallInst*>> &illegalOffsets, Function &CurF,
    hlsl::OP *hlslOP) {
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::Sample, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleBias, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleCmp, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleCmpLevelZero,
                        hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleGrad, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::SampleLevel,
                        hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::TextureGather, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::TextureGatherCmp, hlslOP);
  CollectIllegalOffsets(illegalOffsets, CurF, DXIL::OpCode::TextureLoad, hlslOP);
}

void DxilLegalizeSampleOffsetPass::CollectIllegalOffsets(
    std::vector<std::pair<Value *, CallInst*>> &illegalOffsets, Function &CurF,
    DXIL::OpCode opcode, hlsl::OP *hlslOP) {
  auto &intrFuncList = hlslOP->GetOpFuncList(opcode);
  for (auto it : intrFuncList) {
    Function *intrFunc = it.second;
    if (!intrFunc)
      continue;
    for (User *U : intrFunc->users()) {
      CallInst *CI = cast<CallInst>(U);
      // Skip inst not in current function.
      if (CI->getParent()->getParent() != &CurF)
        continue;

      CollectIllegalOffset(CI, opcode, illegalOffsets);
    }
  }
}

void DxilLegalizeSampleOffsetPass::LegalizeOffsets(
    const std::vector<std::pair<Value *, CallInst*>> &illegalOffsets) {
  if (!illegalOffsets.empty()) {
    DxilValueCache *DVC = &getAnalysis<DxilValueCache>();
    for (auto it : illegalOffsets) {
      if (Instruction *I = dyn_cast<Instruction>(it.first))
        if (Value *V = DVC->GetValue(I))
          I->replaceAllUsesWith(V);
    }
  }
}

FunctionPass *llvm::createDxilLegalizeSampleOffsetPass() {
  return new DxilLegalizeSampleOffsetPass();
}

INITIALIZE_PASS_BEGIN(DxilLegalizeSampleOffsetPass, "dxil-legalize-sample-offset",
                "DXIL legalize sample offset", false, false)
INITIALIZE_PASS_DEPENDENCY(DxilValueCache)
INITIALIZE_PASS_END(DxilLegalizeSampleOffsetPass, "dxil-legalize-sample-offset",
                "DXIL legalize sample offset", false, false)
