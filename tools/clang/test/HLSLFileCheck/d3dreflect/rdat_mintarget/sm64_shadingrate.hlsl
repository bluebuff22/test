// RUN: %dxilver 1.8 | %dxc -T lib_6_8 %s | %D3DReflect %s | %FileCheck %s -check-prefixes=RDAT,RDAT18
// RUN: %dxilver 1.7 | %dxc -T lib_6_7 -validator-version 1.7 %s | %D3DReflect %s | FileCheck %s -check-prefixes=RDAT,RDAT17

// Ensure min shader target incorporates optional features used

// RDAT: FunctionTable[{{.*}}] = {

// SM 6.4+

///////////////////////////////////////////////////////////////////////////////
// ShaderFeatureInfo_ShadingRate (0x80000) = 524288
// Not sure if already caught.

// RDAT-LABEL: UnmangledName: "ps_shadingrate"
// RDAT:   FeatureInfo1: 524288
// RDAT:   FeatureInfo2: 0
// MinShaderTarget: (Pixel(0) << 16) + (SM 6.4 ((6 << 4) + 4)) = 0x64 = 100
// RDAT18: MinShaderTarget: 100
// Old 6.0
// RDAT17: MinShaderTarget: 96

[shader("pixel")]
void ps_shadingrate(uint rate : SV_ShadingRate, out float4 target : SV_Target) {
  target = rate;
}
