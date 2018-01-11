// RUN: %dxc -T lib_6_1 %s | FileCheck %s

// CHECK: error: only one parameter (ray payload) allowed for miss shader

struct MyPayload {
  float4 color;
  uint2 pos;
};

[shader("miss")]
void miss_2payload( inout MyPayload payload : SV_RayPayload,
                    inout MyPayload payload2 : SV_RayPayload2) {}
