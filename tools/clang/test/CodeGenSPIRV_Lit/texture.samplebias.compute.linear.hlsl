// RUN: %dxc -T cs_6_6 -E main -fspv-extension=SPV_NV_compute_shader_derivatives -fcgl  %s -spirv  2>&1 | FileCheck %s

// This test checks tha hte execution mode is not added multiple times. Other
// tests will verify that the code generation is correct.

// CHECK: OpCapability ComputeDerivativeGroupLinearNV
// CHECK: OpExtension "SPV_NV_compute_shader_derivatives"
// CHECK: OpExecutionMode %main DerivativeGroupLinearNV

SamplerState ss : register(s2);
SamplerComparisonState scs;

RWStructuredBuffer<uint> o;
Texture1D        <float>  t1;

[numthreads(8,1,1)]
void main(uint3 id : SV_GroupThreadID)
{
    // CHECK:              [[t1:%[0-9]+]] = OpLoad %type_1d_image %t1
    // CHECK-NEXT:   [[ss:%[0-9]+]] = OpLoad %type_sampler %ss
    // CHECK-NEXT: [[sampledImg:%[0-9]+]] = OpSampledImage %type_sampled_image [[t1]] [[ss]]
    // CHECK-NEXT:            {{%[0-9]+}} = OpImageSampleImplicitLod %v4float [[sampledImg]] %float_1 Bias %float_0_5
    o[0] = t1.SampleBias(ss, 1, 0.5);
}