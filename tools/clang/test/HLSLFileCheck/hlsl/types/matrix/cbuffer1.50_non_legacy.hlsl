// RUN: %dxc -E main -T ps_6_0 -not_use_legacy_cbuf_load %s | FileCheck %s

// CHECK: ; cbuffer Foo2
// CHECK: ; {
// CHECK: ;
// CHECK: ;   struct Foo2
// CHECK: ;   {
// CHECK: ;
// CHECK: ;       float4 g2;                                    ; Offset:    0
// CHECK: ;
// CHECK: ;   } Foo2;                                           ; Offset:    0 Size:    16
// CHECK: ;
// CHECK: ; }

// CHECK: @main

cbuffer Foo1 : register(b5)
{
  float4 g1;
}
cbuffer Foo2 : register(b5)
{
  float4 g2;
}

float4 main() : SV_TARGET
{
  return g2;
}
