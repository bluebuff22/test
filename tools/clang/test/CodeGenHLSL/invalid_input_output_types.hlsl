// RUN: %dxc -E main -T ps_6_0 %s | FileCheck %s

// CHECK: cannot used as shader inputs or outputs
// CHECK: cannot used as shader inputs or outputs

double main(uint64_t i:I) : SV_Target {
    return 1;
}