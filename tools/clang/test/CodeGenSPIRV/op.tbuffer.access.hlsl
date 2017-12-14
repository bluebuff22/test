// Run: %dxc -T vs_6_0 -E main

struct S {
    float  f;
};

tbuffer MyTbuffer : register(t0) {
    float    a;
    float2   b;
    float3x4 c;
    S        s;
    float    t[4];
};

float main() : A {
// CHECK:      [[a:%\d+]] = OpAccessChain %_ptr_Uniform_float %var_MyTbuffer %int_0
// CHECK-NEXT: {{%\d+}} = OpLoad %float [[a]]

// CHECK:      [[b:%\d+]] = OpAccessChain %_ptr_Uniform_v2float %var_MyTbuffer %int_1
// CHECK-NEXT: [[b0:%\d+]] = OpAccessChain %_ptr_Uniform_float [[b]] %int_0
// CHECK-NEXT: {{%\d+}} = OpLoad %float [[b0]]

// CHECK:      [[c:%\d+]] = OpAccessChain %_ptr_Uniform_mat3v4float %var_MyTbuffer %int_2
// CHECK-NEXT: [[c12:%\d+]] = OpAccessChain %_ptr_Uniform_float [[c]] %uint_1 %uint_2
// CHECK-NEXT: {{%\d+}} = OpLoad %float [[c12]]

// CHECK:      [[s:%\d+]] = OpAccessChain %_ptr_Uniform_S %var_MyTbuffer %int_3
// CHECK-NEXT: [[s0:%\d+]] = OpAccessChain %_ptr_Uniform_float [[s]] %int_0
// CHECK-NEXT: {{%\d+}} = OpLoad %float [[s0]]

// CHECK:      [[t:%\d+]] = OpAccessChain %_ptr_Uniform__arr_float_uint_4 %var_MyTbuffer %int_4
// CHECK-NEXT: [[t3:%\d+]] = OpAccessChain %_ptr_Uniform_float [[t]] %int_3
// CHECK-NEXT: {{%\d+}} = OpLoad %float [[t3]]
    return a + b.x + c[1][2] + s.f + t[3];
}
