// RUN: %dxc -E Range -T ps_6_0 %s | FileCheck %s -check-prefix=CHK_RANGE
// RUN: %dxc -E VarOffset -T ps_6_0 %s | FileCheck %s -check-prefix=CHK_VAROFF

// CHK_RANGE:  error: offset texture instructions must take offset which can resolve to integer literal in the range -8 to 7.
// CHK_RANGE:  error: offset texture instructions must take offset which can resolve to integer literal in the range -8 to 7.
// CHK_RANGE:  error: offset texture instructions must take offset which can resolve to integer literal in the range -8 to 7.
// CHK_RANGE:  error: offset texture instructions must take offset which can resolve to integer literal in the range -8 to 7.

// CHK_VAROFF: Offsets to texture access operations must be immediate values
// CHK_VAROFF: Offsets to texture access operations must be immediate values
// CHK_VAROFF: Offsets to texture access operations must be immediate values
// CHK_VAROFF: Offsets to texture access operations must be immediate values
// CHK_VAROFF: Offsets to texture access operations must be immediate values
// CHK_VAROFF: Offsets to texture access operations must be immediate values
// CHK_VAROFF: Offsets to texture access operations must be immediate values
// CHK_VAROFF: Offsets to texture access operations must be immediate values


Texture2D t;
SamplerState s;
SamplerComparisonState sc;

float4 Range(float2 uv : UV, uint2 offset : O) : SV_TARGET
{
    float4 a = t.GatherRed(s, uv, int2(-9,-8));
    float4 b = t.Sample(s, uv, int2(-18,19));
    float4 c = t.Load(0, int2(80, 90));
    float4 d = t.GatherCmp(sc, uv, 0.0, int2(999999, -999999));
    return a + b + c + d;
}

float4 VarOffset(float2 uv : UV, uint2 offset : O) : SV_TARGET
{
    float4 a = t.GatherRed(s, uv, offset);
    float4 b = t.Sample(s, uv, offset);
    float4 c = t.Load(0, offset);
    float4 d = t.GatherCmp(sc, uv, 0.0, offset);
    return a + b + c + d;
}
