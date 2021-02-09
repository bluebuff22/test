// RUN: %dxc -E main -T vs_6_2 -DTY=uint %s | FileCheck %s -check-prefix=CHK_NO_ERR
// RUN: %dxc -E main -T vs_6_2 -DTY=uint2 %s | FileCheck %s -check-prefix=CHK_ERR
// RUN: %dxc -E main -T vs_6_2 -DTY=int2x2 %s | FileCheck %s -check-prefix=CHK_ERR
// RUN: %dxc -E main -T vs_6_2 -DTY=float %s | FileCheck %s -check-prefix=CHK_ERR
// RUN: %dxc -E main -T vs_6_2 -DTY=bool %s | FileCheck %s -check-prefix=CHK_ERR

// CHK_NO_ERR: define void @main
// CHK_ERR: error: invalid type used for 'SV_VertexID' semantic

void main(TY id : SV_VertexID) {}
