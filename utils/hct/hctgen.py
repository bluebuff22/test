#!/usr/bin/env python3
import argparse
from hctdb_instrhelp import *
from hctdb import *
import sys
import os
import CodeTags

parser = argparse.ArgumentParser()
parser.add_argument('mode', choices=['HLSLIntrinsicOp',
                                     'DxilConstants',
                                     'DxilInstructions',
                                     'DxilSigPoint',
                                     'DxilIntrinsicTables',
                                     'DxilOperations',
                                     'DxilDocs',
                                     'DxilShaderModelInc',
                                     'DxilShaderModel',
                                     'DxilValidationInc',
                                     'DxilValidation',
                                     'HLSLOptions',
                                     'DxcOptimizer',
                                     'DxilPIXPasses',
                                     'DxcDisassembler',
                                     'DxilCounters',
                                     'DxilMetadata'
                                     ])
parser.add_argument('--output', required=True)
parser.add_argument('--input', default=None)
parser.add_argument('--force-lf', action='store_true',)

def eprint(*args, **kwargs):
  print(*args, file=sys.stderr, **kwargs)

def writeCodeTag(args):
  out = openOutput(args)
  if not args.input:
    eprint('Writing %s requires --input' % args.mode)
    return 1

  args = [args.input, args.output]
  result = CodeTags.main(args)
  return 0
  
def openOutput(args):
  newline=None
  if args.force_lf:
    newline='\n'
  return open(args.output, 'w', newline=newline)

def printHeader(out, filename):
  out.write('// %s - Generated by hctgen.py\n' % filename)
  out.write('// DO NOT MODIFY!!!\n')
  out.write('// Changes to this code are made in gen_intrin_main.txt\n\n')

def writeHLSLIntrinsicOp(args):
  out = openOutput(args)
  printHeader(out, 'HlslIntrinsicOp.h')
  out.write('\n'.join(['#pragma once',
                       'namespace hlsl {',
                       'enum class IntrinsicOp {']))
  out.write(enum_hlsl_intrinsics())
  out.write('};\n')
  out.write('\n'.join(['inline bool HasUnsignedIntrinsicOpcode(IntrinsicOp opcode) {',
  '  switch (opcode) {']))
  out.write(has_unsigned_hlsl_intrinsics())

  out.write('\n'.join([
        '    return true;',
        '  default:',
        '    return false;',
        '  }',
        '}',
        'inline unsigned GetUnsignedIntrinsicOpcode(IntrinsicOp opcode) {',
        '  switch (opcode) {']))
  out.write(get_unsigned_hlsl_intrinsics())
  out.write('\n'.join([
        '  default:',
        '    return static_cast<unsigned>(opcode);',
        '  }',
        '}',
        '} // namespace hlsl\n']))
  return 0

def writeDxilIntrinsicTables(args):
  out = openOutput(args)
  printHeader(out, "gen_intrin_main_tables_15.h")
  out.write(get_hlsl_intrinsics())
  out.write(get_hlsl_intrinsic_stats())
  return 0

def writeDxcDisassembler(args):
  out = openOutput(args)
  printHeader(out, "DxcDisassembler.inc")
  out.write(get_opsigs())
  out.write('\n')
  return 0

def writeDxcOptimizer(args):
  out = openOutput(args)
  printHeader(out, "DxcOptimizer.inc")
  out.write('\n'.join([
    'HRESULT SetupRegistryPassForHLSL() {',
    '  try {',
    '    PassRegistry &Registry = *PassRegistry::getPassRegistry();\n']))
  out.write(get_init_passes(set(["llvm", "dxil_gen"])))
  out.write('\n'.join([
    '    // Not schematized - exclusively for compiler authors.',
    '    initializeCFGPrinterPasses(Registry);',
    '  }',
    '  CATCH_CPP_RETURN_HRESULT();',
    '  return S_OK;',
    '}\n}',
    'static ArrayRef<LPCSTR> GetPassArgNames(LPCSTR passName) {',
  ]))
  out.write(get_pass_arg_names())
  out.write('\nreturn ArrayRef<LPCSTR>();\n}\n\n')
  out.write('static ArrayRef<LPCSTR> GetPassArgDescriptions(LPCSTR passName) {\n')
  out.write(get_pass_arg_descs())
  out.write('\nreturn ArrayRef<LPCSTR>();\n}\n\n')
  out.write('static bool IsPassOptionName(StringRef S) {\n')
  out.write(get_is_pass_option_name())
  out.write('}\n')
  return 0

def writeDxilValidationInc(args):
  out = openOutput(args)
  printHeader(out, "DxilValidation.inc")
  out.write(get_valrule_enum())
  out.write('\n')
  return 0

def writeDxilValidation(args):
  out = openOutput(args)
  printHeader(out, "DxilValidationImpl.inc")
  out.write('const char *hlsl::GetValidationRuleText(ValidationRule value) {\n')
  out.write(get_valrule_text())
  out.write('\n'.join([
  '  llvm_unreachable("invalid value");',
  '  return "<unknown>";',
  '}\nnamespace hlsl {\n',
  'static bool ValidateOpcodeInProfile(DXIL::OpCode opcode,',
  '                                    DXIL::ShaderKind SK,',
  '                                    unsigned major,',
  '                                    unsigned minor) {',
  '  unsigned op = (unsigned)opcode;'
  ]))
  out.write(get_valopcode_sm_text())
  out.write('\n'.join([
    '}\n',
    'static bool IsLLVMInstructionAllowed(llvm::Instruction &I) {',
    '  unsigned op = I.getOpcode();',
    ]))
  out.write(get_instrs_pred("op", lambda i: not i.is_dxil_op and i.is_allowed, "llvm_id"))
  out.write('}\n}\n')
  return 0

def writeDxilPIXPasses(args):
  out = openOutput(args)
  printHeader(out, "DxilPIXPasses.inc")
  return 0

args = parser.parse_args()
writeFnName = 'write%s' % args.mode
if writeFnName in locals():
  exit(locals()[writeFnName](args))
else:
  exit(writeCodeTag(args))
