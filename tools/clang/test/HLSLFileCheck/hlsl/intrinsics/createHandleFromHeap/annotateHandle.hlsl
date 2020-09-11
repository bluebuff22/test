// RUN: %dxc -T ps_6_6 %s | %FileCheck %s

// Make sure sampler and texture get correct annotateHandle.

// CHECK-DAG:call %dx.types.Handle @dx.op.annotateHandle(i32 217, %dx.types.Handle %{{.*}}, %dx.types.ResourceProperties { i32 1033, i32 2 })  ; AnnotateHandle(res,props)  resource: Texture2D<F32>
// CHECK-DAG:call %dx.types.Handle @dx.op.annotateHandle(i32 217, %dx.types.Handle %{{.*}}, %dx.types.ResourceProperties { i32 0, i32 14 })  ; AnnotateHandle(res,props)  resource: SamplerState

SamplerState samplers : register(s0);
SamplerState foo() { return samplers; }
Texture2D t0 : register(t0);
[RootSignature("DescriptorTable(SRV(t0)),DescriptorTable(Sampler(s0))")]
float4 main( float2 uv : TEXCOORD ) : SV_TARGET {
  float4 val = t0.Sample(foo(), uv);
  return val;
}