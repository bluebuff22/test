///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// DxilInstructions.h                                                        //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
// This file provides a library of instruction helper classes.               //
// MUCH WORK YET TO BE DONE - EXPECT THIS WILL CHANGE - GENERATED FILE       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "llvm/IR/Constants.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"

// TODO: add correct include directives
// TODO: add accessors with values
// TODO: add validation support code, including calling into right fn
// TODO: add type hierarchy
namespace hlsl {
/* <py>
import hctdb_instrhelp
</py> */
/* <py::lines('INSTR-HELPER')>hctdb_instrhelp.get_instrhelper()</py>*/
// INSTR-HELPER:BEGIN
/// This instruction returns a value (possibly void), from a function.
struct LlvmInst_Ret {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Ret(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Ret;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction branches (conditional or unconditional)
struct LlvmInst_Br {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Br(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Br;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction performs a multiway switch
struct LlvmInst_Switch {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Switch(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Switch;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction branches indirectly
struct LlvmInst_IndirectBr {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_IndirectBr(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::IndirectBr;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction invokes function with normal and exceptional returns
struct LlvmInst_Invoke {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Invoke(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Invoke;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction resumes the propagation of an exception
struct LlvmInst_Resume {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Resume(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Resume;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction is unreachable
struct LlvmInst_Unreachable {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Unreachable(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Unreachable;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction returns the sum of its two operands
struct LlvmInst_Add {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Add(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Add;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the sum of its two operands
struct LlvmInst_FAdd {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FAdd(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FAdd;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the difference of its two operands
struct LlvmInst_Sub {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Sub(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Sub;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the difference of its two operands
struct LlvmInst_FSub {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FSub(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FSub;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the product of its two operands
struct LlvmInst_Mul {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Mul(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Mul;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the product of its two operands
struct LlvmInst_FMul {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FMul(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FMul;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the quotient of its two unsigned operands
struct LlvmInst_UDiv {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_UDiv(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::UDiv;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the quotient of its two signed operands
struct LlvmInst_SDiv {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_SDiv(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::SDiv;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the quotient of its two operands
struct LlvmInst_FDiv {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FDiv(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FDiv;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the remainder from the unsigned division of its two operands
struct LlvmInst_URem {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_URem(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::URem;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the remainder from the signed division of its two operands
struct LlvmInst_SRem {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_SRem(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::SRem;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns the remainder from the division of its two operands
struct LlvmInst_FRem {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FRem(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FRem;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction shifts left (logical)
struct LlvmInst_Shl {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Shl(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Shl;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction shifts right (logical), with zero bit fill
struct LlvmInst_LShr {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_LShr(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::LShr;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction shifts right (arithmetic), with 'a' operand sign bit fill
struct LlvmInst_AShr {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_AShr(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::AShr;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns a  bitwise logical and of its two operands
struct LlvmInst_And {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_And(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::And;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns a bitwise logical or of its two operands
struct LlvmInst_Or {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Or(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Or;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction returns a bitwise logical xor of its two operands
struct LlvmInst_Xor {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Xor(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Xor;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction allocates memory on the stack frame of the currently executing function
struct LlvmInst_Alloca {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Alloca(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Alloca;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction reads from memory
struct LlvmInst_Load {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Load(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Load;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction writes to memory
struct LlvmInst_Store {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Store(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Store;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction gets the address of a subelement of an aggregate value
struct LlvmInst_GetElementPtr {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_GetElementPtr(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::GetElementPtr;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction introduces happens-before edges between operations
struct LlvmInst_Fence {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Fence(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Fence;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction atomically modifies memory
struct LlvmInst_AtomicCmpXchg {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_AtomicCmpXchg(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::AtomicCmpXchg;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction atomically modifies memory
struct LlvmInst_AtomicRMW {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_AtomicRMW(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::AtomicRMW;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction truncates an integer
struct LlvmInst_Trunc {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Trunc(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Trunc;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction zero extends an integer
struct LlvmInst_ZExt {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_ZExt(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::ZExt;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction sign extends an integer
struct LlvmInst_SExt {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_SExt(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::SExt;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction converts a floating point to UInt
struct LlvmInst_FPToUI {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FPToUI(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FPToUI;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction converts a floating point to SInt
struct LlvmInst_FPToSI {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FPToSI(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FPToSI;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction converts a UInt to floating point
struct LlvmInst_UIToFP {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_UIToFP(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::UIToFP;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction converts a SInt to floating point
struct LlvmInst_SIToFP {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_SIToFP(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::SIToFP;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction truncates a floating point
struct LlvmInst_FPTrunc {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FPTrunc(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FPTrunc;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction extends a floating point
struct LlvmInst_FPExt {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FPExt(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FPExt;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction converts a pointer to integer
struct LlvmInst_PtrToInt {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_PtrToInt(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::PtrToInt;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction converts an integer to Pointer
struct LlvmInst_IntToPtr {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_IntToPtr(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::IntToPtr;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction performs a bit-preserving type cast
struct LlvmInst_BitCast {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_BitCast(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::BitCast;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction casts a value addrspace
struct LlvmInst_AddrSpaceCast {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_AddrSpaceCast(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::AddrSpaceCast;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction compares integers
struct LlvmInst_ICmp {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_ICmp(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::ICmp;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction compares floating points
struct LlvmInst_FCmp {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_FCmp(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::FCmp;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction is a PHI node instruction
struct LlvmInst_PHI {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_PHI(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::PHI;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction calls a function
struct LlvmInst_Call {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Call(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Call;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction selects an instruction
struct LlvmInst_Select {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_Select(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::Select;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction may be used internally in a pass
struct LlvmInst_UserOp1 {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_UserOp1(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::UserOp1;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction internal to passes only
struct LlvmInst_UserOp2 {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_UserOp2(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::UserOp2;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction vaarg instruction
struct LlvmInst_VAArg {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_VAArg(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::VAArg;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction extracts from aggregate
struct LlvmInst_ExtractValue {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_ExtractValue(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::ExtractValue;
  }
  // Validation support
  bool isAllowed() const { return true; }
};

/// This instruction represents a landing pad
struct LlvmInst_LandingPad {
  llvm::Instruction *Instr;
  // Construction and identification
  LlvmInst_LandingPad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return Instr->getOpcode() == llvm::Instruction::LandingPad;
  }
  // Validation support
  bool isAllowed() const { return false; }
};

/// This instruction Helper load operation
struct DxilInst_TempRegLoad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_TempRegLoad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::TempRegLoad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_index = 1,
  };
  // Accessors
  llvm::Value *get_index() const { return Instr->getOperand(1); }
  void set_index(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Helper store operation
struct DxilInst_TempRegStore {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_TempRegStore(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::TempRegStore);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_index = 1,
    arg_value = 2,
  };
  // Accessors
  llvm::Value *get_index() const { return Instr->getOperand(1); }
  void set_index(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_value() const { return Instr->getOperand(2); }
  void set_value(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction Helper load operation for minprecision
struct DxilInst_MinPrecXRegLoad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_MinPrecXRegLoad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::MinPrecXRegLoad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_regIndex = 1,
    arg_index = 2,
    arg_component = 3,
  };
  // Accessors
  llvm::Value *get_regIndex() const { return Instr->getOperand(1); }
  void set_regIndex(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_index() const { return Instr->getOperand(2); }
  void set_index(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_component() const { return Instr->getOperand(3); }
  void set_component(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction Helper store operation for minprecision
struct DxilInst_MinPrecXRegStore {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_MinPrecXRegStore(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::MinPrecXRegStore);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_regIndex = 1,
    arg_index = 2,
    arg_component = 3,
    arg_value = 4,
  };
  // Accessors
  llvm::Value *get_regIndex() const { return Instr->getOperand(1); }
  void set_regIndex(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_index() const { return Instr->getOperand(2); }
  void set_index(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_component() const { return Instr->getOperand(3); }
  void set_component(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_value() const { return Instr->getOperand(4); }
  void set_value(llvm::Value *val) { Instr->setOperand(4, val); }
};

/// This instruction Loads the value from shader input
struct DxilInst_LoadInput {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_LoadInput(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::LoadInput);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_inputSigId = 1,
    arg_rowIndex = 2,
    arg_colIndex = 3,
    arg_gsVertexAxis = 4,
  };
  // Accessors
  llvm::Value *get_inputSigId() const { return Instr->getOperand(1); }
  void set_inputSigId(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_rowIndex() const { return Instr->getOperand(2); }
  void set_rowIndex(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_colIndex() const { return Instr->getOperand(3); }
  void set_colIndex(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_gsVertexAxis() const { return Instr->getOperand(4); }
  void set_gsVertexAxis(llvm::Value *val) { Instr->setOperand(4, val); }
};

/// This instruction Stores the value to shader output
struct DxilInst_StoreOutput {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_StoreOutput(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::StoreOutput);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_outputSigId = 1,
    arg_rowIndex = 2,
    arg_colIndex = 3,
    arg_value = 4,
  };
  // Accessors
  llvm::Value *get_outputSigId() const { return Instr->getOperand(1); }
  void set_outputSigId(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_rowIndex() const { return Instr->getOperand(2); }
  void set_rowIndex(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_colIndex() const { return Instr->getOperand(3); }
  void set_colIndex(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_value() const { return Instr->getOperand(4); }
  void set_value(llvm::Value *val) { Instr->setOperand(4, val); }
};

/// This instruction returns the absolute value of the input value.
struct DxilInst_FAbs {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_FAbs(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::FAbs);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction clamps the result of a single or double precision floating point value to [0.0f...1.0f]
struct DxilInst_Saturate {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Saturate(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Saturate);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Returns true if x is NAN or QNAN, false otherwise.
struct DxilInst_IsNaN {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_IsNaN(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::IsNaN);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Returns true if x is +INF or -INF, false otherwise.
struct DxilInst_IsInf {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_IsInf(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::IsInf);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Returns true if x is finite, false otherwise.
struct DxilInst_IsFinite {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_IsFinite(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::IsFinite);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns IsNormal
struct DxilInst_IsNormal {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_IsNormal(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::IsNormal);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns cosine(theta) for theta in radians.
struct DxilInst_Cos {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Cos(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Cos);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns sine(theta) for theta in radians.
struct DxilInst_Sin {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Sin(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Sin);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns tan(theta) for theta in radians.
struct DxilInst_Tan {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Tan(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Tan);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Returns the arccosine of the specified value. Input should be a floating-point value within the range of -1 to 1.
struct DxilInst_Acos {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Acos(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Acos);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Returns the arccosine of the specified value. Input should be a floating-point value within the range of -1 to 1
struct DxilInst_Asin {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Asin(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Asin);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Returns the arctangent of the specified value. The return value is within the range of -PI/2 to PI/2.
struct DxilInst_Atan {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Atan(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Atan);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns the hyperbolic cosine of the specified value.
struct DxilInst_Hcos {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Hcos(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Hcos);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns the hyperbolic sine of the specified value.
struct DxilInst_Hsin {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Hsin(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Hsin);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns the hyperbolic tangent of the specified value.
struct DxilInst_Htan {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Htan(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Htan);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns 2^exponent
struct DxilInst_Exp {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Exp(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Exp);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction extract fracitonal component.
struct DxilInst_Frc {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Frc(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Frc);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns log base 2.
struct DxilInst_Log {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Log(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Log);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns square root
struct DxilInst_Sqrt {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Sqrt(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Sqrt);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns reciprocal square root (1 / sqrt(src)
struct DxilInst_Rsqrt {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Rsqrt(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Rsqrt);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction floating-point round to integral float.
struct DxilInst_Round_ne {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Round_ne(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Round_ne);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction floating-point round to integral float.
struct DxilInst_Round_ni {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Round_ni(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Round_ni);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction floating-point round to integral float.
struct DxilInst_Round_pi {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Round_pi(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Round_pi);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction floating-point round to integral float.
struct DxilInst_Round_z {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Round_z(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Round_z);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Reverses the order of the bits.
struct DxilInst_Bfrev {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Bfrev(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Bfrev);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Counts the number of bits in the input integer.
struct DxilInst_Countbits {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Countbits(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Countbits);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Returns the location of the first set bit starting from the lowest order bit and working upward.
struct DxilInst_FirstbitLo {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_FirstbitLo(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::FirstbitLo);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Returns the location of the first set bit starting from the highest order bit and working downward.
struct DxilInst_FirstbitHi {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_FirstbitHi(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::FirstbitHi);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction Returns the location of the first set bit from the highest order bit based on the sign.
struct DxilInst_FirstbitSHi {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_FirstbitSHi(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::FirstbitSHi);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns a if a >= b, else b
struct DxilInst_FMax {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_FMax(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::FMax);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction returns a if a < b, else b
struct DxilInst_FMin {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_FMin(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::FMin);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction IMax(a,b) returns a if a > b, else b
struct DxilInst_IMax {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_IMax(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::IMax);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction IMin(a,b) returns a if a < b, else b
struct DxilInst_IMin {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_IMin(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::IMin);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction unsigned integer maximum. UMax(a,b) = a > b ? a : b
struct DxilInst_UMax {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_UMax(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::UMax);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction unsigned integer minimum. UMin(a,b) = a < b ? a : b
struct DxilInst_UMin {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_UMin(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::UMin);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction multiply of 32-bit operands to produce the correct full 64-bit result.
struct DxilInst_IMul {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_IMul(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::IMul);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction multiply of 32-bit operands to produce the correct full 64-bit result.
struct DxilInst_UMul {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_UMul(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::UMul);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction unsigned divide of the 32-bit operand src0 by the 32-bit operand src1.
struct DxilInst_UDiv {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_UDiv(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::UDiv);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction unsigned add of 32-bit operand with the carry
struct DxilInst_UAddc {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_UAddc(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::UAddc);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction unsigned subtract of 32-bit operands with the borrow
struct DxilInst_USubb {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_USubb(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::USubb);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction floating point multiply & add
struct DxilInst_FMad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_FMad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::FMad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
    arg_c = 3,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_c() const { return Instr->getOperand(3); }
  void set_c(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction fused multiply-add
struct DxilInst_Fma {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Fma(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Fma);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
    arg_c = 3,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_c() const { return Instr->getOperand(3); }
  void set_c(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction Signed integer multiply & add
struct DxilInst_IMad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_IMad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::IMad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
    arg_c = 3,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_c() const { return Instr->getOperand(3); }
  void set_c(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction Unsigned integer multiply & add
struct DxilInst_UMad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_UMad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::UMad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
    arg_c = 3,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_c() const { return Instr->getOperand(3); }
  void set_c(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction masked Sum of Absolute Differences.
struct DxilInst_Msad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Msad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Msad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
    arg_c = 3,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_c() const { return Instr->getOperand(3); }
  void set_c(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction Integer bitfield extract
struct DxilInst_Ibfe {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Ibfe(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Ibfe);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
    arg_c = 3,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_c() const { return Instr->getOperand(3); }
  void set_c(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction Unsigned integer bitfield extract
struct DxilInst_Ubfe {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Ubfe(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Ubfe);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_a = 1,
    arg_b = 2,
    arg_c = 3,
  };
  // Accessors
  llvm::Value *get_a() const { return Instr->getOperand(1); }
  void set_a(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_b() const { return Instr->getOperand(2); }
  void set_b(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_c() const { return Instr->getOperand(3); }
  void set_c(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction Given a bit range from the LSB of a number, places that number of bits in another number at any offset
struct DxilInst_Bfi {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Bfi(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Bfi);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_width = 1,
    arg_offset = 2,
    arg_value = 3,
    arg_replacedValue = 4,
  };
  // Accessors
  llvm::Value *get_width() const { return Instr->getOperand(1); }
  void set_width(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_offset() const { return Instr->getOperand(2); }
  void set_offset(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_value() const { return Instr->getOperand(3); }
  void set_value(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_replacedValue() const { return Instr->getOperand(4); }
  void set_replacedValue(llvm::Value *val) { Instr->setOperand(4, val); }
};

/// This instruction Two-dimensional vector dot-product
struct DxilInst_Dot2 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Dot2(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Dot2);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_ax = 1,
    arg_ay = 2,
    arg_bx = 3,
    arg_by = 4,
  };
  // Accessors
  llvm::Value *get_ax() const { return Instr->getOperand(1); }
  void set_ax(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_ay() const { return Instr->getOperand(2); }
  void set_ay(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_bx() const { return Instr->getOperand(3); }
  void set_bx(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_by() const { return Instr->getOperand(4); }
  void set_by(llvm::Value *val) { Instr->setOperand(4, val); }
};

/// This instruction Three-dimensional vector dot-product
struct DxilInst_Dot3 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Dot3(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Dot3);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (7 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_ax = 1,
    arg_ay = 2,
    arg_az = 3,
    arg_bx = 4,
    arg_by = 5,
    arg_bz = 6,
  };
  // Accessors
  llvm::Value *get_ax() const { return Instr->getOperand(1); }
  void set_ax(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_ay() const { return Instr->getOperand(2); }
  void set_ay(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_az() const { return Instr->getOperand(3); }
  void set_az(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_bx() const { return Instr->getOperand(4); }
  void set_bx(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_by() const { return Instr->getOperand(5); }
  void set_by(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_bz() const { return Instr->getOperand(6); }
  void set_bz(llvm::Value *val) { Instr->setOperand(6, val); }
};

/// This instruction Four-dimensional vector dot-product
struct DxilInst_Dot4 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Dot4(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Dot4);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (9 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_ax = 1,
    arg_ay = 2,
    arg_az = 3,
    arg_aw = 4,
    arg_bx = 5,
    arg_by = 6,
    arg_bz = 7,
    arg_bw = 8,
  };
  // Accessors
  llvm::Value *get_ax() const { return Instr->getOperand(1); }
  void set_ax(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_ay() const { return Instr->getOperand(2); }
  void set_ay(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_az() const { return Instr->getOperand(3); }
  void set_az(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_aw() const { return Instr->getOperand(4); }
  void set_aw(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_bx() const { return Instr->getOperand(5); }
  void set_bx(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_by() const { return Instr->getOperand(6); }
  void set_by(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_bz() const { return Instr->getOperand(7); }
  void set_bz(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_bw() const { return Instr->getOperand(8); }
  void set_bw(llvm::Value *val) { Instr->setOperand(8, val); }
};

/// This instruction creates the handle to a resource
struct DxilInst_CreateHandle {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_CreateHandle(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::CreateHandle);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_resourceClass = 1,
    arg_rangeId = 2,
    arg_index = 3,
    arg_nonUniformIndex = 4,
  };
  // Accessors
  llvm::Value *get_resourceClass() const { return Instr->getOperand(1); }
  void set_resourceClass(llvm::Value *val) { Instr->setOperand(1, val); }
  int8_t get_resourceClass_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(1))->getZExtValue()); }
  void set_resourceClass_val(int8_t val) { Instr->setOperand(1, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
  llvm::Value *get_rangeId() const { return Instr->getOperand(2); }
  void set_rangeId(llvm::Value *val) { Instr->setOperand(2, val); }
  int32_t get_rangeId_val() const { return (int32_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(2))->getZExtValue()); }
  void set_rangeId_val(int32_t val) { Instr->setOperand(2, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 32), llvm::APInt(32, (uint64_t)val))); }
  llvm::Value *get_index() const { return Instr->getOperand(3); }
  void set_index(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_nonUniformIndex() const { return Instr->getOperand(4); }
  void set_nonUniformIndex(llvm::Value *val) { Instr->setOperand(4, val); }
  bool get_nonUniformIndex_val() const { return (bool)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(4))->getZExtValue()); }
  void set_nonUniformIndex_val(bool val) { Instr->setOperand(4, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 1), llvm::APInt(1, (uint64_t)val))); }
};

/// This instruction loads a value from a constant buffer resource
struct DxilInst_CBufferLoad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_CBufferLoad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::CBufferLoad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_handle = 1,
    arg_byteOffset = 2,
    arg_alignment = 3,
  };
  // Accessors
  llvm::Value *get_handle() const { return Instr->getOperand(1); }
  void set_handle(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_byteOffset() const { return Instr->getOperand(2); }
  void set_byteOffset(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_alignment() const { return Instr->getOperand(3); }
  void set_alignment(llvm::Value *val) { Instr->setOperand(3, val); }
  uint32_t get_alignment_val() const { return (uint32_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(3))->getZExtValue()); }
  void set_alignment_val(uint32_t val) { Instr->setOperand(3, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 32), llvm::APInt(32, (uint64_t)val))); }
};

/// This instruction loads a value from a constant buffer resource
struct DxilInst_CBufferLoadLegacy {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_CBufferLoadLegacy(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::CBufferLoadLegacy);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_handle = 1,
    arg_regIndex = 2,
  };
  // Accessors
  llvm::Value *get_handle() const { return Instr->getOperand(1); }
  void set_handle(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_regIndex() const { return Instr->getOperand(2); }
  void set_regIndex(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction samples a texture
struct DxilInst_Sample {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Sample(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Sample);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (11 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_sampler = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_coord3 = 6,
    arg_offset0 = 7,
    arg_offset1 = 8,
    arg_offset2 = 9,
    arg_clamp = 10,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_sampler() const { return Instr->getOperand(2); }
  void set_sampler(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_coord3() const { return Instr->getOperand(6); }
  void set_coord3(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(7); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(8); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(8, val); }
  llvm::Value *get_offset2() const { return Instr->getOperand(9); }
  void set_offset2(llvm::Value *val) { Instr->setOperand(9, val); }
  llvm::Value *get_clamp() const { return Instr->getOperand(10); }
  void set_clamp(llvm::Value *val) { Instr->setOperand(10, val); }
};

/// This instruction samples a texture after applying the input bias to the mipmap level
struct DxilInst_SampleBias {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_SampleBias(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::SampleBias);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (12 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_sampler = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_coord3 = 6,
    arg_offset0 = 7,
    arg_offset1 = 8,
    arg_offset2 = 9,
    arg_bias = 10,
    arg_clamp = 11,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_sampler() const { return Instr->getOperand(2); }
  void set_sampler(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_coord3() const { return Instr->getOperand(6); }
  void set_coord3(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(7); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(8); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(8, val); }
  llvm::Value *get_offset2() const { return Instr->getOperand(9); }
  void set_offset2(llvm::Value *val) { Instr->setOperand(9, val); }
  llvm::Value *get_bias() const { return Instr->getOperand(10); }
  void set_bias(llvm::Value *val) { Instr->setOperand(10, val); }
  llvm::Value *get_clamp() const { return Instr->getOperand(11); }
  void set_clamp(llvm::Value *val) { Instr->setOperand(11, val); }
};

/// This instruction samples a texture using a mipmap-level offset
struct DxilInst_SampleLevel {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_SampleLevel(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::SampleLevel);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (11 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_sampler = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_coord3 = 6,
    arg_offset0 = 7,
    arg_offset1 = 8,
    arg_offset2 = 9,
    arg_LOD = 10,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_sampler() const { return Instr->getOperand(2); }
  void set_sampler(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_coord3() const { return Instr->getOperand(6); }
  void set_coord3(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(7); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(8); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(8, val); }
  llvm::Value *get_offset2() const { return Instr->getOperand(9); }
  void set_offset2(llvm::Value *val) { Instr->setOperand(9, val); }
  llvm::Value *get_LOD() const { return Instr->getOperand(10); }
  void set_LOD(llvm::Value *val) { Instr->setOperand(10, val); }
};

/// This instruction samples a texture using a gradient to influence the way the sample location is calculated
struct DxilInst_SampleGrad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_SampleGrad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::SampleGrad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (17 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_sampler = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_coord3 = 6,
    arg_offset0 = 7,
    arg_offset1 = 8,
    arg_offset2 = 9,
    arg_ddx0 = 10,
    arg_ddx1 = 11,
    arg_ddx2 = 12,
    arg_ddy0 = 13,
    arg_ddy1 = 14,
    arg_ddy2 = 15,
    arg_clamp = 16,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_sampler() const { return Instr->getOperand(2); }
  void set_sampler(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_coord3() const { return Instr->getOperand(6); }
  void set_coord3(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(7); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(8); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(8, val); }
  llvm::Value *get_offset2() const { return Instr->getOperand(9); }
  void set_offset2(llvm::Value *val) { Instr->setOperand(9, val); }
  llvm::Value *get_ddx0() const { return Instr->getOperand(10); }
  void set_ddx0(llvm::Value *val) { Instr->setOperand(10, val); }
  llvm::Value *get_ddx1() const { return Instr->getOperand(11); }
  void set_ddx1(llvm::Value *val) { Instr->setOperand(11, val); }
  llvm::Value *get_ddx2() const { return Instr->getOperand(12); }
  void set_ddx2(llvm::Value *val) { Instr->setOperand(12, val); }
  llvm::Value *get_ddy0() const { return Instr->getOperand(13); }
  void set_ddy0(llvm::Value *val) { Instr->setOperand(13, val); }
  llvm::Value *get_ddy1() const { return Instr->getOperand(14); }
  void set_ddy1(llvm::Value *val) { Instr->setOperand(14, val); }
  llvm::Value *get_ddy2() const { return Instr->getOperand(15); }
  void set_ddy2(llvm::Value *val) { Instr->setOperand(15, val); }
  llvm::Value *get_clamp() const { return Instr->getOperand(16); }
  void set_clamp(llvm::Value *val) { Instr->setOperand(16, val); }
};

/// This instruction samples a texture and compares a single component against the specified comparison value
struct DxilInst_SampleCmp {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_SampleCmp(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::SampleCmp);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (12 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_sampler = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_coord3 = 6,
    arg_offset0 = 7,
    arg_offset1 = 8,
    arg_offset2 = 9,
    arg_compareValue = 10,
    arg_clamp = 11,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_sampler() const { return Instr->getOperand(2); }
  void set_sampler(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_coord3() const { return Instr->getOperand(6); }
  void set_coord3(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(7); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(8); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(8, val); }
  llvm::Value *get_offset2() const { return Instr->getOperand(9); }
  void set_offset2(llvm::Value *val) { Instr->setOperand(9, val); }
  llvm::Value *get_compareValue() const { return Instr->getOperand(10); }
  void set_compareValue(llvm::Value *val) { Instr->setOperand(10, val); }
  llvm::Value *get_clamp() const { return Instr->getOperand(11); }
  void set_clamp(llvm::Value *val) { Instr->setOperand(11, val); }
};

/// This instruction samples a texture and compares a single component against the specified comparison value
struct DxilInst_SampleCmpLevelZero {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_SampleCmpLevelZero(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::SampleCmpLevelZero);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (11 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_sampler = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_coord3 = 6,
    arg_offset0 = 7,
    arg_offset1 = 8,
    arg_offset2 = 9,
    arg_compareValue = 10,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_sampler() const { return Instr->getOperand(2); }
  void set_sampler(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_coord3() const { return Instr->getOperand(6); }
  void set_coord3(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(7); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(8); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(8, val); }
  llvm::Value *get_offset2() const { return Instr->getOperand(9); }
  void set_offset2(llvm::Value *val) { Instr->setOperand(9, val); }
  llvm::Value *get_compareValue() const { return Instr->getOperand(10); }
  void set_compareValue(llvm::Value *val) { Instr->setOperand(10, val); }
};

/// This instruction reads texel data without any filtering or sampling
struct DxilInst_TextureLoad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_TextureLoad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::TextureLoad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (9 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_mipLevelOrSampleCount = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_offset0 = 6,
    arg_offset1 = 7,
    arg_offset2 = 8,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_mipLevelOrSampleCount() const { return Instr->getOperand(2); }
  void set_mipLevelOrSampleCount(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(6); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(7); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_offset2() const { return Instr->getOperand(8); }
  void set_offset2(llvm::Value *val) { Instr->setOperand(8, val); }
};

/// This instruction reads texel data without any filtering or sampling
struct DxilInst_TextureStore {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_TextureStore(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::TextureStore);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (10 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_coord0 = 2,
    arg_coord1 = 3,
    arg_coord2 = 4,
    arg_value0 = 5,
    arg_value1 = 6,
    arg_value2 = 7,
    arg_value3 = 8,
    arg_mask = 9,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(2); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(3); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(4); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_value0() const { return Instr->getOperand(5); }
  void set_value0(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_value1() const { return Instr->getOperand(6); }
  void set_value1(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_value2() const { return Instr->getOperand(7); }
  void set_value2(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_value3() const { return Instr->getOperand(8); }
  void set_value3(llvm::Value *val) { Instr->setOperand(8, val); }
  llvm::Value *get_mask() const { return Instr->getOperand(9); }
  void set_mask(llvm::Value *val) { Instr->setOperand(9, val); }
};

/// This instruction reads from a TypedBuffer
struct DxilInst_BufferLoad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_BufferLoad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::BufferLoad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_index = 2,
    arg_wot = 3,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_index() const { return Instr->getOperand(2); }
  void set_index(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_wot() const { return Instr->getOperand(3); }
  void set_wot(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction writes to a RWTypedBuffer
struct DxilInst_BufferStore {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_BufferStore(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::BufferStore);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (9 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_uav = 1,
    arg_coord0 = 2,
    arg_coord1 = 3,
    arg_value0 = 4,
    arg_value1 = 5,
    arg_value2 = 6,
    arg_value3 = 7,
    arg_mask = 8,
  };
  // Accessors
  llvm::Value *get_uav() const { return Instr->getOperand(1); }
  void set_uav(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(2); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(3); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_value0() const { return Instr->getOperand(4); }
  void set_value0(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_value1() const { return Instr->getOperand(5); }
  void set_value1(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_value2() const { return Instr->getOperand(6); }
  void set_value2(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_value3() const { return Instr->getOperand(7); }
  void set_value3(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_mask() const { return Instr->getOperand(8); }
  void set_mask(llvm::Value *val) { Instr->setOperand(8, val); }
};

/// This instruction atomically increments/decrements the hidden 32-bit counter stored with a Count or Append UAV
struct DxilInst_BufferUpdateCounter {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_BufferUpdateCounter(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::BufferUpdateCounter);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_uav = 1,
    arg_inc = 2,
  };
  // Accessors
  llvm::Value *get_uav() const { return Instr->getOperand(1); }
  void set_uav(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_inc() const { return Instr->getOperand(2); }
  void set_inc(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction determines whether all values from a Sample, Gather, or Load operation accessed mapped tiles in a tiled resource
struct DxilInst_CheckAccessFullyMapped {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_CheckAccessFullyMapped(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::CheckAccessFullyMapped);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_status = 1,
  };
  // Accessors
  llvm::Value *get_status() const { return Instr->getOperand(1); }
  void set_status(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction gets texture size information
struct DxilInst_GetDimensions {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_GetDimensions(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::GetDimensions);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_handle = 1,
    arg_mipLevel = 2,
  };
  // Accessors
  llvm::Value *get_handle() const { return Instr->getOperand(1); }
  void set_handle(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_mipLevel() const { return Instr->getOperand(2); }
  void set_mipLevel(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction gathers the four texels that would be used in a bi-linear filtering operation
struct DxilInst_TextureGather {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_TextureGather(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::TextureGather);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (10 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_sampler = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_coord3 = 6,
    arg_offset0 = 7,
    arg_offset1 = 8,
    arg_channel = 9,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_sampler() const { return Instr->getOperand(2); }
  void set_sampler(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_coord3() const { return Instr->getOperand(6); }
  void set_coord3(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(7); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(8); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(8, val); }
  llvm::Value *get_channel() const { return Instr->getOperand(9); }
  void set_channel(llvm::Value *val) { Instr->setOperand(9, val); }
};

/// This instruction same as TextureGather, except this instrution performs comparison on texels, similar to SampleCmp
struct DxilInst_TextureGatherCmp {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_TextureGatherCmp(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::TextureGatherCmp);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (11 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_sampler = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_coord3 = 6,
    arg_offset0 = 7,
    arg_offset1 = 8,
    arg_channel = 9,
    arg_compareVale = 10,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_sampler() const { return Instr->getOperand(2); }
  void set_sampler(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_coord3() const { return Instr->getOperand(6); }
  void set_coord3(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(7); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(8); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(8, val); }
  llvm::Value *get_channel() const { return Instr->getOperand(9); }
  void set_channel(llvm::Value *val) { Instr->setOperand(9, val); }
  llvm::Value *get_compareVale() const { return Instr->getOperand(10); }
  void set_compareVale(llvm::Value *val) { Instr->setOperand(10, val); }
};

/// This instruction gets the position of the specified sample
struct DxilInst_Texture2DMSGetSamplePosition {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Texture2DMSGetSamplePosition(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Texture2DMSGetSamplePosition);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_index = 2,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_index() const { return Instr->getOperand(2); }
  void set_index(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction gets the position of the specified sample
struct DxilInst_RenderTargetGetSamplePosition {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_RenderTargetGetSamplePosition(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::RenderTargetGetSamplePosition);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_index = 1,
  };
  // Accessors
  llvm::Value *get_index() const { return Instr->getOperand(1); }
  void set_index(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction gets the number of samples for a render target
struct DxilInst_RenderTargetGetSampleCount {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_RenderTargetGetSampleCount(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::RenderTargetGetSampleCount);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction performs an atomic operation on two operands
struct DxilInst_AtomicBinOp {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_AtomicBinOp(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::AtomicBinOp);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (7 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_handle = 1,
    arg_atomicOp = 2,
    arg_offset0 = 3,
    arg_offset1 = 4,
    arg_offset2 = 5,
    arg_newValue = 6,
  };
  // Accessors
  llvm::Value *get_handle() const { return Instr->getOperand(1); }
  void set_handle(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_atomicOp() const { return Instr->getOperand(2); }
  void set_atomicOp(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(3); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(4); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_offset2() const { return Instr->getOperand(5); }
  void set_offset2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_newValue() const { return Instr->getOperand(6); }
  void set_newValue(llvm::Value *val) { Instr->setOperand(6, val); }
};

/// This instruction atomic compare and exchange to memory
struct DxilInst_AtomicCompareExchange {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_AtomicCompareExchange(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::AtomicCompareExchange);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (7 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_handle = 1,
    arg_offset0 = 2,
    arg_offset1 = 3,
    arg_offset2 = 4,
    arg_compareValue = 5,
    arg_newValue = 6,
  };
  // Accessors
  llvm::Value *get_handle() const { return Instr->getOperand(1); }
  void set_handle(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_offset0() const { return Instr->getOperand(2); }
  void set_offset0(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_offset1() const { return Instr->getOperand(3); }
  void set_offset1(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_offset2() const { return Instr->getOperand(4); }
  void set_offset2(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_compareValue() const { return Instr->getOperand(5); }
  void set_compareValue(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_newValue() const { return Instr->getOperand(6); }
  void set_newValue(llvm::Value *val) { Instr->setOperand(6, val); }
};

/// This instruction inserts a memory barrier in the shader
struct DxilInst_Barrier {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Barrier(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Barrier);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_barrierMode = 1,
  };
  // Accessors
  llvm::Value *get_barrierMode() const { return Instr->getOperand(1); }
  void set_barrierMode(llvm::Value *val) { Instr->setOperand(1, val); }
  int32_t get_barrierMode_val() const { return (int32_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(1))->getZExtValue()); }
  void set_barrierMode_val(int32_t val) { Instr->setOperand(1, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 32), llvm::APInt(32, (uint64_t)val))); }
};

/// This instruction calculates the level of detail
struct DxilInst_CalculateLOD {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_CalculateLOD(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::CalculateLOD);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (7 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_handle = 1,
    arg_sampler = 2,
    arg_coord0 = 3,
    arg_coord1 = 4,
    arg_coord2 = 5,
    arg_clamped = 6,
  };
  // Accessors
  llvm::Value *get_handle() const { return Instr->getOperand(1); }
  void set_handle(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_sampler() const { return Instr->getOperand(2); }
  void set_sampler(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_coord0() const { return Instr->getOperand(3); }
  void set_coord0(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_coord1() const { return Instr->getOperand(4); }
  void set_coord1(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_coord2() const { return Instr->getOperand(5); }
  void set_coord2(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_clamped() const { return Instr->getOperand(6); }
  void set_clamped(llvm::Value *val) { Instr->setOperand(6, val); }
};

/// This instruction discard the current pixel
struct DxilInst_Discard {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Discard(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Discard);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_condition = 1,
  };
  // Accessors
  llvm::Value *get_condition() const { return Instr->getOperand(1); }
  void set_condition(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction computes the rate of change per stamp in x direction.
struct DxilInst_DerivCoarseX {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_DerivCoarseX(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::DerivCoarseX);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction computes the rate of change per stamp in y direction.
struct DxilInst_DerivCoarseY {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_DerivCoarseY(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::DerivCoarseY);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction computes the rate of change per pixel in x direction.
struct DxilInst_DerivFineX {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_DerivFineX(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::DerivFineX);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction computes the rate of change per pixel in y direction.
struct DxilInst_DerivFineY {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_DerivFineY(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::DerivFineY);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction evaluates an input attribute at pixel center with an offset
struct DxilInst_EvalSnapped {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_EvalSnapped(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::EvalSnapped);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (6 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_inputSigId = 1,
    arg_inputRowIndex = 2,
    arg_inputColIndex = 3,
    arg_offsetX = 4,
    arg_offsetY = 5,
  };
  // Accessors
  llvm::Value *get_inputSigId() const { return Instr->getOperand(1); }
  void set_inputSigId(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_inputRowIndex() const { return Instr->getOperand(2); }
  void set_inputRowIndex(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_inputColIndex() const { return Instr->getOperand(3); }
  void set_inputColIndex(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_offsetX() const { return Instr->getOperand(4); }
  void set_offsetX(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_offsetY() const { return Instr->getOperand(5); }
  void set_offsetY(llvm::Value *val) { Instr->setOperand(5, val); }
};

/// This instruction evaluates an input attribute at a sample location
struct DxilInst_EvalSampleIndex {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_EvalSampleIndex(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::EvalSampleIndex);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_inputSigId = 1,
    arg_inputRowIndex = 2,
    arg_inputColIndex = 3,
    arg_sampleIndex = 4,
  };
  // Accessors
  llvm::Value *get_inputSigId() const { return Instr->getOperand(1); }
  void set_inputSigId(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_inputRowIndex() const { return Instr->getOperand(2); }
  void set_inputRowIndex(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_inputColIndex() const { return Instr->getOperand(3); }
  void set_inputColIndex(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_sampleIndex() const { return Instr->getOperand(4); }
  void set_sampleIndex(llvm::Value *val) { Instr->setOperand(4, val); }
};

/// This instruction evaluates an input attribute at pixel center
struct DxilInst_EvalCentroid {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_EvalCentroid(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::EvalCentroid);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_inputSigId = 1,
    arg_inputRowIndex = 2,
    arg_inputColIndex = 3,
  };
  // Accessors
  llvm::Value *get_inputSigId() const { return Instr->getOperand(1); }
  void set_inputSigId(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_inputRowIndex() const { return Instr->getOperand(2); }
  void set_inputRowIndex(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_inputColIndex() const { return Instr->getOperand(3); }
  void set_inputColIndex(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction returns the sample index in a sample-frequency pixel shader
struct DxilInst_SampleIndex {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_SampleIndex(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::SampleIndex);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction returns the coverage mask input in a pixel shader
struct DxilInst_Coverage {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_Coverage(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::Coverage);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction returns underestimated coverage input from conservative rasterization in a pixel shader
struct DxilInst_InnerCoverage {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_InnerCoverage(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::InnerCoverage);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction reads the thread ID
struct DxilInst_ThreadId {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_ThreadId(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::ThreadId);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_component = 1,
  };
  // Accessors
  llvm::Value *get_component() const { return Instr->getOperand(1); }
  void set_component(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction reads the group ID (SV_GroupID)
struct DxilInst_GroupId {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_GroupId(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::GroupId);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_component = 1,
  };
  // Accessors
  llvm::Value *get_component() const { return Instr->getOperand(1); }
  void set_component(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction reads the thread ID within the group (SV_GroupThreadID)
struct DxilInst_ThreadIdInGroup {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_ThreadIdInGroup(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::ThreadIdInGroup);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_component = 1,
  };
  // Accessors
  llvm::Value *get_component() const { return Instr->getOperand(1); }
  void set_component(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction provides a flattened index for a given thread within a given group (SV_GroupIndex)
struct DxilInst_FlattenedThreadIdInGroup {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_FlattenedThreadIdInGroup(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::FlattenedThreadIdInGroup);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction emits a vertex to a given stream
struct DxilInst_EmitStream {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_EmitStream(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::EmitStream);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_streamId = 1,
  };
  // Accessors
  llvm::Value *get_streamId() const { return Instr->getOperand(1); }
  void set_streamId(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction completes the current primitive topology at the specified stream
struct DxilInst_CutStream {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_CutStream(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::CutStream);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_streamId = 1,
  };
  // Accessors
  llvm::Value *get_streamId() const { return Instr->getOperand(1); }
  void set_streamId(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction equivalent to an EmitStream followed by a CutStream
struct DxilInst_EmitThenCutStream {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_EmitThenCutStream(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::EmitThenCutStream);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_streamId = 1,
  };
  // Accessors
  llvm::Value *get_streamId() const { return Instr->getOperand(1); }
  void set_streamId(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction GSInstanceID
struct DxilInst_GSInstanceID {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_GSInstanceID(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::GSInstanceID);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction creates a double value
struct DxilInst_MakeDouble {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_MakeDouble(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::MakeDouble);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_lo = 1,
    arg_hi = 2,
  };
  // Accessors
  llvm::Value *get_lo() const { return Instr->getOperand(1); }
  void set_lo(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_hi() const { return Instr->getOperand(2); }
  void set_hi(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction splits a double into low and high parts
struct DxilInst_SplitDouble {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_SplitDouble(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::SplitDouble);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction LoadOutputControlPoint
struct DxilInst_LoadOutputControlPoint {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_LoadOutputControlPoint(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::LoadOutputControlPoint);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_inputSigId = 1,
    arg_row = 2,
    arg_col = 3,
    arg_index = 4,
  };
  // Accessors
  llvm::Value *get_inputSigId() const { return Instr->getOperand(1); }
  void set_inputSigId(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_row() const { return Instr->getOperand(2); }
  void set_row(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_col() const { return Instr->getOperand(3); }
  void set_col(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_index() const { return Instr->getOperand(4); }
  void set_index(llvm::Value *val) { Instr->setOperand(4, val); }
};

/// This instruction LoadPatchConstant
struct DxilInst_LoadPatchConstant {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_LoadPatchConstant(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::LoadPatchConstant);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_inputSigId = 1,
    arg_row = 2,
    arg_col = 3,
  };
  // Accessors
  llvm::Value *get_inputSigId() const { return Instr->getOperand(1); }
  void set_inputSigId(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_row() const { return Instr->getOperand(2); }
  void set_row(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_col() const { return Instr->getOperand(3); }
  void set_col(llvm::Value *val) { Instr->setOperand(3, val); }
};

/// This instruction DomainLocation
struct DxilInst_DomainLocation {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_DomainLocation(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::DomainLocation);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_component = 1,
  };
  // Accessors
  llvm::Value *get_component() const { return Instr->getOperand(1); }
  void set_component(llvm::Value *val) { Instr->setOperand(1, val); }
  int8_t get_component_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(1))->getZExtValue()); }
  void set_component_val(int8_t val) { Instr->setOperand(1, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
};

/// This instruction StorePatchConstant
struct DxilInst_StorePatchConstant {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_StorePatchConstant(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::StorePatchConstant);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_outputSigID = 1,
    arg_row = 2,
    arg_col = 3,
    arg_value = 4,
  };
  // Accessors
  llvm::Value *get_outputSigID() const { return Instr->getOperand(1); }
  void set_outputSigID(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_row() const { return Instr->getOperand(2); }
  void set_row(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_col() const { return Instr->getOperand(3); }
  void set_col(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_value() const { return Instr->getOperand(4); }
  void set_value(llvm::Value *val) { Instr->setOperand(4, val); }
};

/// This instruction OutputControlPointID
struct DxilInst_OutputControlPointID {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_OutputControlPointID(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::OutputControlPointID);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction PrimitiveID
struct DxilInst_PrimitiveID {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_PrimitiveID(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::PrimitiveID);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction CycleCounterLegacy
struct DxilInst_CycleCounterLegacy {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_CycleCounterLegacy(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::CycleCounterLegacy);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction returns 1 for the first lane in the wave
struct DxilInst_WaveIsFirstLane {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveIsFirstLane(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveIsFirstLane);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction returns the index of the current lane in the wave
struct DxilInst_WaveGetLaneIndex {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveGetLaneIndex(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveGetLaneIndex);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction returns the number of lanes in the wave
struct DxilInst_WaveGetLaneCount {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveGetLaneCount(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveGetLaneCount);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction returns 1 if any of the lane evaluates the value to true
struct DxilInst_WaveAnyTrue {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveAnyTrue(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveAnyTrue);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_cond = 1,
  };
  // Accessors
  llvm::Value *get_cond() const { return Instr->getOperand(1); }
  void set_cond(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns 1 if all the lanes evaluate the value to true
struct DxilInst_WaveAllTrue {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveAllTrue(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveAllTrue);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_cond = 1,
  };
  // Accessors
  llvm::Value *get_cond() const { return Instr->getOperand(1); }
  void set_cond(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns 1 if all the lanes have the same value
struct DxilInst_WaveActiveAllEqual {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveActiveAllEqual(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveActiveAllEqual);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns a struct with a bit set for each lane where the condition is true
struct DxilInst_WaveActiveBallot {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveActiveBallot(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveActiveBallot);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_cond = 1,
  };
  // Accessors
  llvm::Value *get_cond() const { return Instr->getOperand(1); }
  void set_cond(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns the value from the specified lane
struct DxilInst_WaveReadLaneAt {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveReadLaneAt(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveReadLaneAt);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
    arg_lane = 2,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_lane() const { return Instr->getOperand(2); }
  void set_lane(llvm::Value *val) { Instr->setOperand(2, val); }
};

/// This instruction returns the value from the first lane
struct DxilInst_WaveReadLaneFirst {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveReadLaneFirst(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveReadLaneFirst);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns the result the operation across waves
struct DxilInst_WaveActiveOp {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveActiveOp(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveActiveOp);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
    arg_op = 2,
    arg_sop = 3,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_op() const { return Instr->getOperand(2); }
  void set_op(llvm::Value *val) { Instr->setOperand(2, val); }
  int8_t get_op_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(2))->getZExtValue()); }
  void set_op_val(int8_t val) { Instr->setOperand(2, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
  llvm::Value *get_sop() const { return Instr->getOperand(3); }
  void set_sop(llvm::Value *val) { Instr->setOperand(3, val); }
  int8_t get_sop_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(3))->getZExtValue()); }
  void set_sop_val(int8_t val) { Instr->setOperand(3, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
};

/// This instruction returns the result of the operation across all lanes
struct DxilInst_WaveActiveBit {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveActiveBit(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveActiveBit);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
    arg_op = 2,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_op() const { return Instr->getOperand(2); }
  void set_op(llvm::Value *val) { Instr->setOperand(2, val); }
  int8_t get_op_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(2))->getZExtValue()); }
  void set_op_val(int8_t val) { Instr->setOperand(2, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
};

/// This instruction returns the result of the operation on prior lanes
struct DxilInst_WavePrefixOp {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WavePrefixOp(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WavePrefixOp);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (4 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
    arg_op = 2,
    arg_sop = 3,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_op() const { return Instr->getOperand(2); }
  void set_op(llvm::Value *val) { Instr->setOperand(2, val); }
  int8_t get_op_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(2))->getZExtValue()); }
  void set_op_val(int8_t val) { Instr->setOperand(2, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
  llvm::Value *get_sop() const { return Instr->getOperand(3); }
  void set_sop(llvm::Value *val) { Instr->setOperand(3, val); }
  int8_t get_sop_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(3))->getZExtValue()); }
  void set_sop_val(int8_t val) { Instr->setOperand(3, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
};

/// This instruction reads from a lane in the quad
struct DxilInst_QuadReadLaneAt {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_QuadReadLaneAt(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::QuadReadLaneAt);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
    arg_quadLane = 2,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_quadLane() const { return Instr->getOperand(2); }
  void set_quadLane(llvm::Value *val) { Instr->setOperand(2, val); }
  uint32_t get_quadLane_val() const { return (uint32_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(2))->getZExtValue()); }
  void set_quadLane_val(uint32_t val) { Instr->setOperand(2, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 32), llvm::APInt(32, (uint64_t)val))); }
};

/// This instruction returns the result of a quad-level operation
struct DxilInst_QuadOp {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_QuadOp(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::QuadOp);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (3 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
    arg_op = 2,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_op() const { return Instr->getOperand(2); }
  void set_op(llvm::Value *val) { Instr->setOperand(2, val); }
  int8_t get_op_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(2))->getZExtValue()); }
  void set_op_val(int8_t val) { Instr->setOperand(2, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
};

/// This instruction bitcast between different sizes
struct DxilInst_BitcastI16toF16 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_BitcastI16toF16(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::BitcastI16toF16);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction bitcast between different sizes
struct DxilInst_BitcastF16toI16 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_BitcastF16toI16(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::BitcastF16toI16);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction bitcast between different sizes
struct DxilInst_BitcastI32toF32 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_BitcastI32toF32(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::BitcastI32toF32);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction bitcast between different sizes
struct DxilInst_BitcastF32toI32 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_BitcastF32toI32(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::BitcastF32toI32);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction bitcast between different sizes
struct DxilInst_BitcastI64toF64 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_BitcastI64toF64(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::BitcastI64toF64);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction bitcast between different sizes
struct DxilInst_BitcastF64toI64 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_BitcastF64toI64(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::BitcastF64toI64);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction legacy fuction to convert float (f32) to half (f16) (this is not related to min-precision)
struct DxilInst_LegacyF32ToF16 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_LegacyF32ToF16(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::LegacyF32ToF16);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction legacy fuction to convert half (f16) to float (f32) (this is not related to min-precision)
struct DxilInst_LegacyF16ToF32 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_LegacyF16ToF32(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::LegacyF16ToF32);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction legacy fuction to convert double to float
struct DxilInst_LegacyDoubleToFloat {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_LegacyDoubleToFloat(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::LegacyDoubleToFloat);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction legacy fuction to convert double to int32
struct DxilInst_LegacyDoubleToSInt32 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_LegacyDoubleToSInt32(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::LegacyDoubleToSInt32);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction legacy fuction to convert double to uint32
struct DxilInst_LegacyDoubleToUInt32 {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_LegacyDoubleToUInt32(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::LegacyDoubleToUInt32);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns the count of bits set to 1 across the wave
struct DxilInst_WaveAllBitCount {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WaveAllBitCount(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WaveAllBitCount);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns the count of bits set to 1 on prior lanes
struct DxilInst_WavePrefixBitCount {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_WavePrefixBitCount(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::WavePrefixBitCount);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (2 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_value = 1,
  };
  // Accessors
  llvm::Value *get_value() const { return Instr->getOperand(1); }
  void set_value(llvm::Value *val) { Instr->setOperand(1, val); }
};

/// This instruction returns the values of the attributes at the vertex.
struct DxilInst_AttributeAtVertex {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_AttributeAtVertex(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::AttributeAtVertex);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (5 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_inputSigId = 1,
    arg_inputRowIndex = 2,
    arg_inputColIndex = 3,
    arg_VertexID = 4,
  };
  // Accessors
  llvm::Value *get_inputSigId() const { return Instr->getOperand(1); }
  void set_inputSigId(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_inputRowIndex() const { return Instr->getOperand(2); }
  void set_inputRowIndex(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_inputColIndex() const { return Instr->getOperand(3); }
  void set_inputColIndex(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_VertexID() const { return Instr->getOperand(4); }
  void set_VertexID(llvm::Value *val) { Instr->setOperand(4, val); }
};

/// This instruction returns the view index
struct DxilInst_ViewID {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_ViewID(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::ViewID);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (1 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
};

/// This instruction reads from a raw buffer and structured buffer
struct DxilInst_RawBufferLoad {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_RawBufferLoad(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::RawBufferLoad);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (6 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_srv = 1,
    arg_index = 2,
    arg_elementOffset = 3,
    arg_mask = 4,
    arg_alignment = 5,
  };
  // Accessors
  llvm::Value *get_srv() const { return Instr->getOperand(1); }
  void set_srv(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_index() const { return Instr->getOperand(2); }
  void set_index(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_elementOffset() const { return Instr->getOperand(3); }
  void set_elementOffset(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_mask() const { return Instr->getOperand(4); }
  void set_mask(llvm::Value *val) { Instr->setOperand(4, val); }
  int8_t get_mask_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(4))->getZExtValue()); }
  void set_mask_val(int8_t val) { Instr->setOperand(4, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
  llvm::Value *get_alignment() const { return Instr->getOperand(5); }
  void set_alignment(llvm::Value *val) { Instr->setOperand(5, val); }
  int32_t get_alignment_val() const { return (int32_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(5))->getZExtValue()); }
  void set_alignment_val(int32_t val) { Instr->setOperand(5, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 32), llvm::APInt(32, (uint64_t)val))); }
};

/// This instruction writes to a RWByteAddressBuffer or RWStructuredBuffer
struct DxilInst_RawBufferStore {
  llvm::Instruction *Instr;
  // Construction and identification
  DxilInst_RawBufferStore(llvm::Instruction *pInstr) : Instr(pInstr) {}
  operator bool() const {
    return hlsl::OP::IsDxilOpFuncCallInst(Instr, hlsl::OP::OpCode::RawBufferStore);
  }
  // Validation support
  bool isAllowed() const { return true; }
  bool isArgumentListValid() const {
    if (10 != llvm::dyn_cast<llvm::CallInst>(Instr)->getNumArgOperands()) return false;
    return true;
  }
  // Metadata
  bool isAlwaysUniform() const { return false; }
  // Operand indexes
  enum OperandIdx {
    arg_uav = 1,
    arg_index = 2,
    arg_elementOffset = 3,
    arg_value0 = 4,
    arg_value1 = 5,
    arg_value2 = 6,
    arg_value3 = 7,
    arg_mask = 8,
    arg_alignment = 9,
  };
  // Accessors
  llvm::Value *get_uav() const { return Instr->getOperand(1); }
  void set_uav(llvm::Value *val) { Instr->setOperand(1, val); }
  llvm::Value *get_index() const { return Instr->getOperand(2); }
  void set_index(llvm::Value *val) { Instr->setOperand(2, val); }
  llvm::Value *get_elementOffset() const { return Instr->getOperand(3); }
  void set_elementOffset(llvm::Value *val) { Instr->setOperand(3, val); }
  llvm::Value *get_value0() const { return Instr->getOperand(4); }
  void set_value0(llvm::Value *val) { Instr->setOperand(4, val); }
  llvm::Value *get_value1() const { return Instr->getOperand(5); }
  void set_value1(llvm::Value *val) { Instr->setOperand(5, val); }
  llvm::Value *get_value2() const { return Instr->getOperand(6); }
  void set_value2(llvm::Value *val) { Instr->setOperand(6, val); }
  llvm::Value *get_value3() const { return Instr->getOperand(7); }
  void set_value3(llvm::Value *val) { Instr->setOperand(7, val); }
  llvm::Value *get_mask() const { return Instr->getOperand(8); }
  void set_mask(llvm::Value *val) { Instr->setOperand(8, val); }
  int8_t get_mask_val() const { return (int8_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(8))->getZExtValue()); }
  void set_mask_val(int8_t val) { Instr->setOperand(8, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 8), llvm::APInt(8, (uint64_t)val))); }
  llvm::Value *get_alignment() const { return Instr->getOperand(9); }
  void set_alignment(llvm::Value *val) { Instr->setOperand(9, val); }
  int32_t get_alignment_val() const { return (int32_t)(llvm::dyn_cast<llvm::ConstantInt>(Instr->getOperand(9))->getZExtValue()); }
  void set_alignment_val(int32_t val) { Instr->setOperand(9, llvm::Constant::getIntegerValue(llvm::IntegerType::get(Instr->getContext(), 32), llvm::APInt(32, (uint64_t)val))); }
};
// INSTR-HELPER:END
} // namespace hlsl
