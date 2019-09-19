// RUN: %dxc -E main -T ps_6_0 -not_use_legacy_cbuf_load %s  | FileCheck %s

struct Foo {
  float4 f;
};

typedef Foo FooA[2];

// CHECK: error: 'const FooA' (aka 'Foo const[2]') cannot be used as a type parameter where a struct is required
ConstantBuffer<FooA> CB1;

// CHECK: error: 'const FooA' (aka 'Foo const[2]') cannot be used as a type parameter where a struct is required
ConstantBuffer<FooA> CB[4][3];
// CHECK: error: 'const FooA' (aka 'Foo const[2]') cannot be used as a type parameter where a struct is required
TextureBuffer<FooA> TB[4][3];

float4 main(int a : A) : SV_Target
{
  return CB[3][2][1].f * TB[3][2][1].f;
}
