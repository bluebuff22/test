///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// DxilGenerationPass.h                                                      //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
// This file provides a DXIL Generation pass.                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#pragma once

namespace llvm {
class Module;
class ModulePass;
class Function;
class FunctionPass;
class Instruction;
class PassRegistry;
}

namespace hlsl {
class DxilResourceBase;
class WaveSensitivityAnalysis {
public:
  static WaveSensitivityAnalysis* create();
  virtual ~WaveSensitivityAnalysis() { }
  virtual void Analyze(llvm::Function *F) = 0;
  virtual bool IsWaveSensitive(llvm::Instruction *op) = 0;
};

class HLSLExtensionsCodegenHelper;
}

namespace llvm {

/// \brief Create and return a pass that tranform the module into a DXIL module
/// Note that this pass is designed for use with the legacy pass manager.
ModulePass *createDxilCondenseResourcesPass();
ModulePass *createDxilGenerationPass(bool NotOptimized, hlsl::HLSLExtensionsCodegenHelper *extensionsHelper);
ModulePass *createHLEmitMetadataPass();
ModulePass *createHLEnsureMetadataPass();
ModulePass *createDxilEmitMetadataPass();
ModulePass *createDxilPrecisePropagatePass();
ModulePass *createDxilLegalizeSampleOffsetPass();
FunctionPass *createSimplifyInstPass();

void initializeDxilCondenseResourcesPass(llvm::PassRegistry&);
void initializeDxilGenerationPassPass(llvm::PassRegistry&);
void initializeHLEnsureMetadataPass(llvm::PassRegistry&);
void initializeHLEmitMetadataPass(llvm::PassRegistry&);
void initializeDxilEmitMetadataPass(llvm::PassRegistry&);
void initializeDxilPrecisePropagatePassPass(llvm::PassRegistry&);
void initializeDxilLegalizeSampleOffsetPassPass(llvm::PassRegistry&);
void initializeSimplifyInstPass(llvm::PassRegistry&);

bool AreDxilResourcesDense(llvm::Module *M, hlsl::DxilResourceBase **ppNonDense);

}
