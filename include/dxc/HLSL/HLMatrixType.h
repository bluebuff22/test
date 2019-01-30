///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// HLMatrixType.h                                                            //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "llvm/IR/IRBuilder.h"

namespace llvm {
  class Type;
  class Value;
  template<typename T>
  class ArrayRef;
  class StructType;
  class VectorType;
}

namespace hlsl {

class DxilFieldAnnotation;
class DxilTypeSystem;

// A high-level matrix type in LLVM IR.
//
// Matrices are represented by an llvm struct type of the following form:
// { [RowCount x <ColCount x RegReprTy>] }
// Note that the element type is always in its register representation (ie bools are i1s).
// This allows preserving the original type and is okay since matrix types are only
// manipulated in an opaque way, through intrinsics.
//
// During matrix lowering, matrices are converted to vectors of the following form:
// <RowCount*ColCount x Ty>
// At this point, register vs memory representation starts to matter and we have to
// imitate the codegen for scalar and vector bools: i1s when in llvm registers,
// and i32s when in memory (allocas, pointers, or in structs/lists, which are always in memory).
//
// This class is designed to resemble a llvm::Type-derived class.
class HLMatrixType
{
public:
  static constexpr char* StructNamePrefix = "class.matrix";

  HLMatrixType() : RegReprElemTy(nullptr), RowCount(0), ColCount(0) {}
  HLMatrixType(llvm::Type *RegReprElemTy, unsigned RowCount, unsigned ColCount);

  // We allow default construction to an invalid state to support the dynCast pattern.
  // This tests whether we have a legit object.
  operator bool() const { return RegReprElemTy != nullptr; }

  llvm::Type *getElemType(bool MemRepr) const;
  unsigned getRowCount() const { return RowCount; }
  unsigned getColumnCount() const { return ColCount; }

  llvm::VectorType *getLoweredVectorType(bool MemRepr) const;

  llvm::Value *emitLoweredVectorMemToReg(llvm::Value *VecVal, llvm::IRBuilder<> &Builder) const;
  llvm::Value *emitLoweredVectorRegToMem(llvm::Value *VecVal, llvm::IRBuilder<> &Builder) const;
  llvm::Value *emitLoweredVectorLoad(llvm::Value *VecPtr, llvm::IRBuilder<> &Builder) const;
  void emitLoweredVectorStore(llvm::Value *VecVal, llvm::Value *VecPtr, llvm::IRBuilder<> &Builder) const;

  static bool isa(llvm::Type *Ty);
  static bool isMatrixPtr(llvm::Type *Ty);
  static bool isMatrixArrayPtr(llvm::Type *Ty);
  static bool isMatrixOrPtrOrArrayPtr(llvm::Type *Ty);

  static HLMatrixType cast(llvm::Type *Ty);
  static HLMatrixType dyn_cast(llvm::Type *Ty);

private:
  llvm::Type *RegReprElemTy;
  unsigned RowCount, ColCount;
};

} // namespace hlsl