// RUN: %dxc -T vs_6_0 -E main

struct S { float4 f; };
StructuredBuffer<S> PerFrame;

void main(float4 input: INPUT) {
// CHECK-LABEL: %bb_entry = OpLabel
    float4 v4f;
    float2 v2f;
    float1 v1f1, v1f2;
    float sf;

    // Assign to whole vector
// CHECK:      [[v0:%\d+]] = OpLoad %float %v1f1
// CHECK-NEXT: OpStore %v1f2 [[v0]]
    v1f2 = v1f1.x; // rhs: all in original order

    // Assign from whole vector, to one element
// CHECK-NEXT: [[v1:%\d+]] = OpLoad %float %v1f1
// CHECK-NEXT: OpStore %v1f2 [[v1]]
    v1f2.x = v1f1;

    // Select one element multiple times & select more than size
// CHECK-NEXT: [[v2:%\d+]] = OpLoad %float %v1f1
// CHECK-NEXT: [[cc0:%\d+]] = OpCompositeConstruct %v2float [[v2]] [[v2]]
// CHECK-NEXT: OpStore %v2f [[cc0]]
    v2f = v1f1.xx;

    // Select from rvalue & chained assignment
// CHECK-NEXT: [[v3:%\d+]] = OpLoad %float %v1f1
// CHECK-NEXT: [[v4:%\d+]] = OpLoad %float %v1f2
// CHECK-NEXT: [[mul0:%\d+]] = OpFMul %float [[v3]] [[v4]]
// CHECK-NEXT: [[ac0:%\d+]] = OpAccessChain %_ptr_Function_float %v2f %int_1
// CHECK-NEXT: OpStore [[ac0]] [[mul0]]
// CHECK-NEXT: OpStore %v1f2 [[mul0]]
// CHECK-NEXT: OpStore %sf [[mul0]]
    sf = v1f2 = v2f.y = (v1f1 * v1f2).r;

    // Continuous selection
// CHECK-NEXT: [[v5:%\d+]] = OpLoad %float %v1f1
// CHECK-NEXT: OpStore %v1f2 [[v5]]
    v1f2.x.r.x = v1f1.r.x.r;

    // Selecting from resources
// CHECK:      [[fptr:%\d+]] = OpAccessChain %_ptr_Uniform_v4float %PerFrame %int_0 %uint_5 %int_0
// CHECK-NEXT: [[elem:%\d+]] = OpAccessChain %_ptr_Uniform_float [[fptr]] %int_3
// CHECK-NEXT:      {{%\d+}} = OpLoad %float [[elem]]
    v4f = input * PerFrame[5].f.www.r;
// CHECK:      [[fptr:%\d+]] = OpAccessChain %_ptr_Uniform_v4float %PerFrame %int_0 %uint_6 %int_0
// CHECK-NEXT: [[elem:%\d+]] = OpAccessChain %_ptr_Uniform_float [[fptr]] %int_2
// CHECK-NEXT:      {{%\d+}} = OpLoad %float [[elem]]
    sf = PerFrame[6].f.zzz.r * input.y;
}
