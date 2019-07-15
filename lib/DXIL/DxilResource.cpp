///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// DxilResource.cpp                                                          //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "dxc/DXIL/DxilResource.h"
#include "dxc/Support/Global.h"
#include "dxc/DXIL/DxilResourceBase.h"
#include "llvm/IR/Constant.h"
#include "llvm/IR/DerivedTypes.h"

using namespace llvm;

namespace hlsl {

//------------------------------------------------------------------------------
//
// Resource methods.
//
DxilResource::DxilResource()
: DxilResourceBase(DxilResourceBase::Class::Invalid)
, m_SampleCount(0)
, m_ElementStride(0)
, m_bGloballyCoherent(false)
, m_bHasCounter(false)
, m_bROV(false) {
}

CompType DxilResource::GetCompType() const {
  return m_CompType;
}

void DxilResource::SetCompType(const CompType CT) {
  m_CompType = CT;
}

Type *DxilResource::GetRetType() const {
  Type *Ty = GetGlobalSymbol()->getType()->getPointerElementType();
  // For resource array, use element type.
  while (Ty->isArrayTy())
    Ty = Ty->getArrayElementType();
  // Get the struct buffer type like this %class.StructuredBuffer = type {
  // %struct.mat }.
  StructType *ST = cast<StructType>(Ty);
  // Get the struct type inside struct buffer.
  return ST->getElementType(0);
}

unsigned DxilResource::GetSampleCount() const {
  return m_SampleCount;
}

void DxilResource::SetSampleCount(unsigned SampleCount) {
  m_SampleCount = SampleCount;
}

unsigned DxilResource::GetElementStride() const {
  return m_ElementStride;
}

void DxilResource::SetElementStride(unsigned ElemStride) {
  m_ElementStride = ElemStride;
}

bool DxilResource::IsGloballyCoherent() const {
  return m_bGloballyCoherent;
}

void DxilResource::SetGloballyCoherent(bool b) {
  m_bGloballyCoherent = b;
}

bool DxilResource::HasCounter() const {
  return m_bHasCounter;
}

void DxilResource::SetHasCounter(bool b) {
  m_bHasCounter = b;
}

bool DxilResource::IsRO() const {
  return GetClass() == DxilResourceBase::Class::SRV;
}

bool DxilResource::IsRW() const {
  return GetClass() == DxilResourceBase::Class::UAV;
}

void DxilResource::SetRW(bool bRW) {
  SetClass(bRW ? DxilResourceBase::Class::UAV : DxilResourceBase::Class::SRV);
}

bool DxilResource::IsROV() const {
  return m_bROV;
}

void DxilResource::SetROV(bool bROV) {
  m_bROV = bROV;
}

bool DxilResource::IsAnyTexture() const {
  return IsAnyTexture(GetKind());
}

bool DxilResource::IsAnyTexture(Kind ResourceKind) {
  return Kind::Texture1D <= ResourceKind &&
         ResourceKind <= Kind::TextureCubeArray;
}

bool DxilResource::IsStructuredBuffer() const {
  return GetKind() == Kind::StructuredBuffer;
}

bool DxilResource::IsTypedBuffer() const {
  return GetKind() == Kind::TypedBuffer;
}

bool DxilResource::IsRawBuffer() const {
  return GetKind() == Kind::RawBuffer;
}

bool DxilResource::IsTBuffer() const {
  return GetKind() == Kind::TBuffer;
}

unsigned DxilResource::GetNumCoords(Kind ResourceKind) {
  const unsigned CoordSizeTab[] = {
      0, // Invalid = 0,
      1, // Texture1D,
      2, // Texture2D,
      2, // Texture2DMS,
      3, // Texture3D,
      3, // TextureCube,
      2, // Texture1DArray,
      3, // Texture2DArray,
      3, // Texture2DMSArray,
      4, // TextureCubeArray,
      1, // TypedBuffer,
      1, // RawBuffer,
      2, // StructuredBuffer,
      0, // CBuffer,
      0, // Sampler,
      1, // TBuffer,
      0, // RaytracingAccelerationStructure,
      2, // FeedbackTexture2D,
      3, // FeedbackTexture2DArray,
  };
  static_assert(_countof(CoordSizeTab) == (unsigned)Kind::NumEntries, "check helper array size");
  DXASSERT(ResourceKind > Kind::Invalid && ResourceKind < Kind::NumEntries, "otherwise the caller passed wrong resource type");
  return CoordSizeTab[(unsigned)ResourceKind];
}

unsigned DxilResource::GetNumDimensions(Kind ResourceKind) {
  const unsigned NumDimTab[] = {
      0, // Invalid = 0,
      1, // Texture1D,
      2, // Texture2D,
      2, // Texture2DMS,
      3, // Texture3D,
      2, // TextureCube,
      1, // Texture1DArray,
      2, // Texture2DArray,
      2, // Texture2DMSArray,
      3, // TextureCubeArray,
      1, // TypedBuffer,
      1, // RawBuffer,
      2, // StructuredBuffer,
      0, // CBuffer,
      0, // Sampler,
      1, // TBuffer,
      0, // RaytracingAccelerationStructure,
      2, // FeedbackTexture2D,
      2, // FeedbackTexture2DArray,
  };
  static_assert(_countof(NumDimTab) == (unsigned)Kind::NumEntries, "check helper array size");
  DXASSERT(ResourceKind > Kind::Invalid && ResourceKind < Kind::NumEntries, "otherwise the caller passed wrong resource type");
  return NumDimTab[(unsigned)ResourceKind];
}

unsigned DxilResource::GetNumDimensionsForCalcLOD(Kind ResourceKind) {
  const unsigned NumDimTab[] = {
      0, // Invalid = 0,
      1, // Texture1D,
      2, // Texture2D,
      2, // Texture2DMS,
      3, // Texture3D,
      3, // TextureCube,
      1, // Texture1DArray,
      2, // Texture2DArray,
      2, // Texture2DMSArray,
      3, // TextureCubeArray,
      1, // TypedBuffer,
      1, // RawBuffer,
      2, // StructuredBuffer,
      0, // CBuffer,
      0, // Sampler,
      1, // TBuffer,
      0, // RaytracingAccelerationStructure,
      2, // FeedbackTexture2D,
      2, // FeedbackTexture2DArray,
  };
  static_assert(_countof(NumDimTab) == (unsigned)Kind::NumEntries, "check helper array size");
  DXASSERT(ResourceKind > Kind::Invalid && ResourceKind < Kind::NumEntries, "otherwise the caller passed wrong resource type");
  return NumDimTab[(unsigned)ResourceKind];
}

unsigned DxilResource::GetNumOffsets(Kind ResourceKind) {
  const unsigned OffsetSizeTab[] = {
      0, // Invalid = 0,
      1, // Texture1D,
      2, // Texture2D,
      2, // Texture2DMS,
      3, // Texture3D,
      0, // TextureCube,
      1, // Texture1DArray,
      2, // Texture2DArray,
      2, // Texture2DMSArray,
      0, // TextureCubeArray,
      0, // TypedBuffer,
      0, // RawBuffer,
      0, // StructuredBuffer,
      0, // CBuffer,
      0, // Sampler,
      1, // TBuffer,
      0, // RaytracingAccelerationStructure,
      2, // FeedbackTexture2D,
      2, // FeedbackTexture2DArray,
  };
  static_assert(_countof(OffsetSizeTab) == (unsigned)Kind::NumEntries, "check helper array size");
  DXASSERT(ResourceKind > Kind::Invalid && ResourceKind < Kind::NumEntries, "otherwise the caller passed wrong resource type");
  return OffsetSizeTab[(unsigned)ResourceKind];
}

} // namespace hlsl
