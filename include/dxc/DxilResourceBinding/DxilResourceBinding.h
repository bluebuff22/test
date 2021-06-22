///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// DxilResourceBinding.h                                                     //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "llvm/ADT/StringRef.h"
#include "dxc/DXIL/DxilConstants.h"

#include <string>
#include <map>

namespace llvm {
  class raw_ostream;
  class Module;
}

namespace hlsl {
  class DxilModule;
}

namespace hlsl {
struct ResourceBinding {
  typedef std::pair<std::string, hlsl::DXIL::ResourceClass> Key;
  struct Entry {
    unsigned index = UINT_MAX;
    unsigned space = UINT_MAX;
  };
  std::map<Key, Entry> entries;
};

bool ParseResourceBindingFile(llvm::StringRef fileName, llvm::StringRef content, llvm::raw_ostream &errors, ResourceBinding *outBinding);
void WriteResourceBindingToMetadata(llvm::Module &M, const ResourceBinding &bindings);
void ApplyResourceBindingOverridesFromMetadata(hlsl::DxilModule &DM);
void WriteResourceBindingFile(const hlsl::DxilModule &DM, llvm::raw_ostream &os);

}
