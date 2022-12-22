// Smoke test for dxopt command line
// RUN: %dxc /Odump  -Tps_6_0 %S/Inputs/smoke.hlsl > %t.opt.passes.txt

// RUN: %echo -print-module:test >> %t.opt.passes.txt

// RUN: %dxc -T ps_6_0 %S/Inputs/smoke.hlsl -fcgl -Fc %t.smoke.hl.ll
// RUN: FileCheck --input-file=%t.smoke.hl.ll %s --check-prefix=HL_LL

// Make sure hl.ll not empty.
// HL_LL:{{.+}}

// RUN: %opt -pf %t.opt.passes.txt -o=%t.smoke.opt.bc %t.smoke.hl.ll | FileCheck %s --check-prefix=OPT_PRN

// OPT_PRN:MODULE-PRINT

// RUN: %dxc -dumpbin %t.smoke.opt.bc | FileCheck %s --check-prefix=OPT_BC

// Make sure OPT_BC not empty.
// OPT_BC:{{.+}}
