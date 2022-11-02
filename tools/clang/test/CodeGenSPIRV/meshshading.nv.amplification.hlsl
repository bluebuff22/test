// RUN: %dxc -T as_6_5 -E main
// CHECK:  OpCapability MeshShadingNV
// CHECK:  OpExtension "SPV_NV_mesh_shader"
// CHECK:  OpEntryPoint TaskNV %main "main" [[drawid:%\d+]] %gl_LocalInvocationID %gl_WorkGroupID %gl_GlobalInvocationID %gl_LocalInvocationIndex %out_var_dummy %out_var_pos [[taskcount:%\d+]]
// CHECK:  OpExecutionMode %main LocalSize 128 1 1

// CHECK:  OpDecorate [[drawid]] BuiltIn DrawIndex
// CHECK:  OpDecorate %gl_LocalInvocationID BuiltIn LocalInvocationId
// CHECK:  OpDecorate %gl_WorkGroupID BuiltIn WorkgroupId
// CHECK:  OpDecorate %gl_GlobalInvocationID BuiltIn GlobalInvocationId
// CHECK:  OpDecorate %gl_LocalInvocationIndex BuiltIn LocalInvocationIndex

struct MeshPayload {
// CHECK:  OpDecorate %out_var_dummy PerTaskNV
// CHECK:  OpDecorate %out_var_dummy Offset 0
// CHECK:  OpDecorate %out_var_pos PerTaskNV
// CHECK:  OpDecorate %out_var_pos Offset 48
    float dummy[10];
    float4 pos;
};

// CHECK:  OpDecorate [[taskcount]] BuiltIn TaskCountNV

// CHECK:  %pld = OpVariable %_ptr_Workgroup_MeshPayload Workgroup
groupshared MeshPayload pld;

// CHECK:  %gl_GlobalInvocationID = OpVariable %_ptr_Input_v3uint Input
// CHECK:  %gl_LocalInvocationIndex = OpVariable %_ptr_Input_uint Input
// CHECK:  %out_var_dummy = OpVariable %_ptr_Output__arr_float_uint_10 Output
// CHECK:  %out_var_pos = OpVariable %_ptr_Output_v4float Output
// CHECK:  [[taskcount]] = OpVariable %_ptr_Output_uint Output

#define NUM_THREADS 128

[numthreads(NUM_THREADS, 1, 1)]
void main(
// CHECK:  %param_var_drawId = OpVariable %_ptr_Function_int Function
// CHECK:  %param_var_gtid = OpVariable %_ptr_Function_v3uint Function
// CHECK:  %param_var_gid = OpVariable %_ptr_Function_v2uint Function
// CHECK:  %param_var_tid = OpVariable %_ptr_Function_uint Function
// CHECK:  %param_var_tig = OpVariable %_ptr_Function_uint Function
        [[vk::builtin("DrawIndex")]] in int drawId : DRAW,  // -> BuiltIn DrawIndex
        in uint3 gtid : SV_GroupThreadID,
        in uint2 gid : SV_GroupID,
        in uint tid : SV_DispatchThreadID,
        in uint tig : SV_GroupIndex)
{

// CHECK:  [[a:%\d+]] = OpAccessChain %_ptr_Workgroup_v4float %pld %int_1
// CHECK:  OpStore [[a]] {{%\d+}}
    pld.pos = float4(gtid.x, gid.y, tid, tig);

// CHECK:  OpControlBarrier %uint_2 %uint_2 %uint_264
// CHECK:  [[c:%\d+]] = OpLoad %MeshPayload %pld
// CHECK:  [[d:%\d+]] = OpCompositeExtract %_arr_float_uint_10 [[c]] 0
// CHECK:  OpStore %out_var_dummy [[d]]
// CHECK:  [[e:%\d+]] = OpCompositeExtract %v4float [[c]] 1
// CHECK:  OpStore %out_var_pos [[e]]
// CHECK:  [[f:%\d+]] = OpBitcast %uint {{%\d+}}
// CHECK:  [[g:%\d+]] = OpIMul %uint [[f]] [[f]]
// CHECK:  [[h:%\d+]] = OpIMul %uint %uint_128 [[g]]
// CHECK:  OpStore [[taskcount]] [[g]]
   DispatchMesh(NUM_THREADS, drawId, drawId, pld);
}
