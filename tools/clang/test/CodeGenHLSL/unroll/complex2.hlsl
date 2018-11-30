// RUN: %dxc -E main -T ps_6_0 %s
// CHECK: @main

uint g_cond[4];
uint g_bound;

float main() : SV_Target {

  float foo = 10;

  [unroll]
  for (uint i = 0; i < 10; i++) {
    
    if (i == g_cond[0]) {
      foo += 100;
      break;
    }
    else if (i == g_cond[1]) {
      foo += 200;
      break;
    }
    else if (i == g_cond[2]) { 
      return 10;
    }
    else if (i == g_cond[3]) { 
      foo += 500;
      continue;
    }
    foo++;
  }

  if (foo > 300) {
    foo /= 2;
  }

  return foo;
}
