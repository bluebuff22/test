// RUN: %dxc -Od -Zi -E main -T ps_6_0 %s | FileCheck %s

// Make sure the bit pieces have the offset in bits
// CHECK-DAG: !DIExpression(DW_OP_bit_piece, 0, 32)
// CHECK-DAG: !DIExpression(DW_OP_bit_piece, 32, 32)

struct S {
  float foo;
  float bar;
};

float main(float a : A) : SV_Target {
  S s;
  s.foo = a * a;
  s.bar = a + a;
  return s.foo + s.bar;
}

