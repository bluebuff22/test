// RUN: %dxc -T lib_6_5 %s | FileCheck %s

// CHECK: error: recursive functions are not allowed: entry (or export) function calls recursive function 'recurse2'
void recurse2(inout float4 f, float a) {
  if (a > 0) {
    recurse2(f, a);
  }
  f -= abs(f+a);
}

// CHECK: error: recursive functions are not allowed: entry (or export) function calls recursive function 'recurse'
void recurse(inout float4 f, float a)
{
    if (a > 1) {
      recurse(f, a-1);
      recurse2(f, a-1);
    }
    f += abs(f+a);
}

float4 main(float a : A, float b:B) : SV_TARGET
{
  float4 f = b;
  recurse(f, a);
  return f;
}

