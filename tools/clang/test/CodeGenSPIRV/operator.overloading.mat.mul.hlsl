// RUN: %dxc -T ps_6_0 -E main -enable-operator-overloading

struct GLFloat3x2 {
    float3x2 m;
};

struct GLFloat3x4 {
    float3x4 m;
};

struct GLFloat3x3 {
    float3x3 m;

    float3x3 operator*(GLFloat3x3 x) {
        return mul(m, x.m);
    }

    float3x2 operator*(GLFloat3x2 x) {
        return mul(m, x.m);
    }

    float3x4 operator*(GLFloat3x4 x) {
        return mul(m, x.m);
    }

    float3 operator[](int x) {
        return m[x];
    }
};

float3 main(float4 pos: SV_Position) : SV_Target {
    GLFloat3x3 a = {pos.xyz, pos.xyz, pos.xyz,};
    GLFloat3x3 b = {pos.xxx, pos.yyy, pos.zzz,};
    GLFloat3x2 c = {pos.xy, pos.yz, pos.zx,};
    GLFloat3x4 d = {pos, pos, pos,};

// CHECK: [[d:%\w+]] = OpLoad %GLFloat3x4 %d
// CHECK:              OpStore %param_var_x [[d]]
// CHECK:              OpFunctionCall %mat3v4float %GLFloat3x3_operator_Star %a %param_var_x
    a * d;

// CHECK: [[c:%\w+]] = OpLoad %GLFloat3x2 %c
// CHECK:              OpStore %param_var_x_0 [[c]]
// CHECK:              OpFunctionCall %mat3v2float %GLFloat3x3_operator_Star_0 %b %param_var_x_0
    b * c;

// CHECK: [[b:%\w+]] = OpLoad %GLFloat3x3 %b
// CHECK:              OpStore %param_var_x_1 [[b]]
// CHECK:              OpFunctionCall %mat3v3float %GLFloat3x3_operator_Star_1 %a %param_var_x_1
    a * b;

// CHECK: OpStore %param_var_x_2 %int_1
// CHECK: OpFunctionCall %v3float %GLFloat3x3_operator_Subscript %a %param_var_x_2
    return a[1];
}

// CHECK:                 OpFunction %mat3v4float None
// CHECK: [[this:%\w+]] = OpLoad %mat3v3float
// CHECK:    [[x:%\w+]] = OpLoad %mat3v4float
// CHECK:                 OpMatrixTimesMatrix %mat3v4float [[x]] [[this]]

// CHECK:                 OpFunction %mat3v2float None
// CHECK: [[this:%\w+]] = OpLoad %mat3v3float
// CHECK:    [[x:%\w+]] = OpLoad %mat3v2float
// CHECK:                 OpMatrixTimesMatrix %mat3v2float [[x]] [[this]]

// CHECK:                 OpFunction %mat3v3float None
// CHECK: [[this:%\w+]] = OpLoad %mat3v3float
// CHECK:    [[x:%\w+]] = OpLoad %mat3v3float
// CHECK:                 OpMatrixTimesMatrix %mat3v3float [[x]] [[this]]

// CHECK: %GLFloat3x3_operator_Subscript = OpFunction %v3float None
// CHECK:                     [[x:%\w+]] = OpLoad %int
// CHECK:                    [[ux:%\w+]] = OpBitcast %uint [[x]]
// CHECK:                  [[this:%\w+]] = OpAccessChain %_ptr_Function_v3float {{%\w+}} %int_0 [[ux]]
// CHECK:                                  OpLoad %v3float [[this]]
