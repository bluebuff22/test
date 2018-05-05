///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// DxilLibraryReflection.cpp                                                 //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
// Defines shader reflection for runtime usage.                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "dxc/hlsl/DxilRuntimeReflection.h"

namespace hlsl {
namespace DXIL {
namespace RDAT {

DxilRuntimeData::DxilRuntimeData() : DxilRuntimeData(nullptr) {}

DxilRuntimeData::DxilRuntimeData(const char *ptr)
    : m_TableCount(0), m_StringReader(), m_ResourceTableReader(),
      m_FunctionTableReader(), m_IndexTableReader(), m_Context() {
  m_Context = {&m_StringReader, &m_IndexTableReader, &m_ResourceTableReader,
               &m_FunctionTableReader};
  m_ResourceTableReader.SetContext(&m_Context);
  m_FunctionTableReader.SetContext(&m_Context);
  InitFromRDAT(ptr);
}

// initializing reader from RDAT. return true if no error has occured.
bool DxilRuntimeData::InitFromRDAT(const void *pRDAT) {
  if (pRDAT) {
    const char *ptr = static_cast<const char *>(pRDAT);
    uint32_t TableCount = (uint32_t)*ptr;
    RuntimeDataTableHeader *records = (RuntimeDataTableHeader *)(ptr + 4);
    for (uint32_t i = 0; i < TableCount; ++i) {
      RuntimeDataTableHeader *curRecord = &records[i];
      switch (curRecord->tableType) {
      case RuntimeDataPartType::Resource: {
        m_ResourceTableReader.SetResourceInfo(
            (RuntimeDataResourceInfo *)(ptr + curRecord->offset),
            curRecord->size / sizeof(RuntimeDataResourceInfo));
        break;
      }
      case RuntimeDataPartType::String: {
        m_StringReader =
            StringTableReader(ptr + curRecord->offset, curRecord->size);
        break;
      }
      case RuntimeDataPartType::Function: {
        m_FunctionTableReader.SetFunctionInfo(
            (RuntimeDataFunctionInfo *)(ptr + curRecord->offset));
        m_FunctionTableReader.SetCount(curRecord->size /
                                       sizeof(RuntimeDataFunctionInfo));
        break;
      }
      case RuntimeDataPartType::Index: {
        m_IndexTableReader = IndexTableReader(
            (uint32_t *)(ptr + curRecord->offset), curRecord->size / 4);
        break;
      }
      default:
        return false;
      }
    }
    return true;
  }
  return false;
}

FunctionTableReader *DxilRuntimeData::GetFunctionTableReader() {
  return &m_FunctionTableReader;
}

ResourceTableReader *DxilRuntimeData::GetResourceTableReader() {
  return &m_ResourceTableReader;
}

void DxilRuntimeReflection::AddString(const char *ptr) {
  if (m_StringMap.find(ptr) == m_StringMap.end()) {
    int size = ::MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, ptr, -1,
                                     nullptr, 0);
    if (size != 0) {
      auto pNew = std::make_unique<wchar_t[]>(size);
      ::MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, ptr, -1,
                            pNew.get(), size);
      m_StringMap[ptr] = std::move(pNew);
    }
  }
}

const wchar_t *DxilRuntimeReflection::GetWideString(const char *ptr) {
  if (m_StringMap.find(ptr) == m_StringMap.end()) {
    AddString(ptr);
  }
  return m_StringMap.at(ptr).get();
}

bool DxilRuntimeReflection::InitFromRDAT(const void *pRDAT) {
  m_initialized = m_RuntimeData.InitFromRDAT(pRDAT);
  if (m_initialized)
    InitializeReflection();
  return m_initialized;
}

const DXIL_LIBRARY_DESC DxilRuntimeReflection::GetLibraryReflection() {
  DXIL_LIBRARY_DESC reflection;
  if (m_initialized) {
    reflection.NumResources =
        m_RuntimeData.GetResourceTableReader()->GetNumResources();
    reflection.pResource = m_Resources.data();
    reflection.NumFunctions =
        m_RuntimeData.GetFunctionTableReader()->GetNumFunctions();
    reflection.pFunction = m_Functions.data();
  }
  return reflection;
}

void DxilRuntimeReflection::InitializeReflection() {
  // First need to reserve spaces for resources because functions will need to
  // reference them via pointers.
  const ResourceTableReader *resourceTableReader = m_RuntimeData.GetResourceTableReader();
  m_Resources.reserve(resourceTableReader->GetNumResources());
  for (uint32_t i = 0; i < resourceTableReader->GetNumResources(); ++i) {
    ResourceReader resourceReader = resourceTableReader->GetItem(i);
    AddString(resourceReader.GetName());
    DXIL_RESOURCE *pResource = AddResource(resourceReader);
    if (pResource) {
      ResourceKey key(pResource->Class, pResource->ID);
      m_ResourceMap[key] = pResource;
    }
  }
  const FunctionTableReader *functionTableReader = m_RuntimeData.GetFunctionTableReader();
  m_Functions.reserve(functionTableReader->GetNumFunctions());
  for (uint32_t i = 0; i < functionTableReader->GetNumFunctions(); ++i) {
    FunctionReader functionReader = functionTableReader->GetItem(i);
    AddString(functionReader.GetName());
    AddFunction(functionReader);
  }
}

DXIL_RESOURCE *
DxilRuntimeReflection::AddResource(const ResourceReader &resourceReader) {
  assert(m_Resources.size() < m_Resources.capacity() && "Otherwise, number of resources was incorrect");
  if (!(m_Resources.size() < m_Resources.capacity()))
    return nullptr;
  m_Resources.emplace_back(DXIL_RESOURCE({0}));
  DXIL_RESOURCE &resource = m_Resources.back();
  resource.Class = (uint32_t)resourceReader.GetResourceClass();
  resource.Kind = (uint32_t)resourceReader.GetResourceKind();
  resource.Space = resourceReader.GetSpace();
  resource.LowerBound = resourceReader.GetLowerBound();
  resource.UpperBound = resourceReader.GetUpperBound();
  resource.ID = resourceReader.GetID();
  resource.Flags = resourceReader.GetFlags();
  resource.Name = GetWideString(resourceReader.GetName());
  return &resource;
}

const DXIL_RESOURCE * const*DxilRuntimeReflection::GetResourcesForFunction(
    DXIL_FUNCTION &function, const FunctionReader &functionReader) {
  if (m_FuncToResMap.find(&function) == m_FuncToResMap.end())
    m_FuncToResMap.insert(std::pair<DXIL_FUNCTION *, ResourceRefList>(
        &function, ResourceRefList()));
  ResourceRefList &resourceList = m_FuncToResMap.at(&function);
  if (resourceList.empty()) {
    resourceList.reserve(functionReader.GetNumResources());
    for (uint32_t i = 0; i < functionReader.GetNumResources(); ++i) {
      const ResourceReader resourceReader = functionReader.GetResource(i);
      ResourceKey key((uint32_t)resourceReader.GetResourceClass(),
                      resourceReader.GetID());
      auto it = m_ResourceMap.find(key);
      assert(it != m_ResourceMap.end() && it->second && "Otherwise, resource was not in map, or was null");
      resourceList.emplace_back(it->second);
    }
  }
  return resourceList.empty() ? nullptr : resourceList.data();
}

const wchar_t **DxilRuntimeReflection::GetDependenciesForFunction(
    DXIL_FUNCTION &function, const FunctionReader &functionReader) {
  if (m_FuncToStringMap.find(&function) == m_FuncToStringMap.end())
    m_FuncToStringMap.insert(
        std::pair<DXIL_FUNCTION *, WStringList>(&function, WStringList()));
  WStringList &wStringList = m_FuncToStringMap.at(&function);
  for (uint32_t i = 0; i < functionReader.GetNumDependencies(); ++i) {
    wStringList.emplace_back(GetWideString(functionReader.GetDependency(i)));
  }
  return wStringList.empty() ? nullptr : wStringList.data();
}

DXIL_FUNCTION *
DxilRuntimeReflection::AddFunction(const FunctionReader &functionReader) {
  assert(m_Functions.size() < m_Functions.capacity() && "Otherwise, number of functions was incorrect");
  if (!(m_Functions.size() < m_Functions.capacity()))
    return nullptr;
  m_Functions.emplace_back(DXIL_FUNCTION({0}));
  DXIL_FUNCTION &function = m_Functions.back();
  function.Name = GetWideString(functionReader.GetName());
  function.UnmangledName = GetWideString(functionReader.GetUnmangledName());
  function.NumResources = functionReader.GetNumResources();
  function.Resources = GetResourcesForFunction(function, functionReader);
  function.NumFunctionDependencies = functionReader.GetNumDependencies();
  function.FunctionDependencies =
      GetDependenciesForFunction(function, functionReader);
  function.ShaderKind = (uint32_t)functionReader.GetShaderKind();
  function.PayloadSizeInBytes = functionReader.GetPayloadSizeInBytes();
  function.AttributeSizeInBytes = functionReader.GetAttributeSizeInBytes();
  function.FeatureInfo1 = functionReader.GetFeatureInfo1();
  function.FeatureInfo2 = functionReader.GetFeatureInfo2();
  function.ShaderStageFlag = functionReader.GetShaderStageFlag();
  function.MinShaderTarget = functionReader.GetMinShaderTarget();
  return &function;
}
}}}