// RUN: %dxc -T cs_6_6 -E mymain -ast-dump %s | FileCheck %s

// CHECK: mymain 'void ()'
// CHECK: -HLSLShaderAttr

[numthreads(1,1,1)]
void mymain(){
	return;
}
