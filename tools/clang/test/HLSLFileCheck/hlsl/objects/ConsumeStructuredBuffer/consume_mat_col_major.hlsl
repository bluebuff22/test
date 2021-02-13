// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=bool1x1 %s | FileCheck %s -check-prefix=CHK_MAT1x1
// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=float1x2 %s | FileCheck %s -check-prefix=CHK_MAT1x2
// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=int2x1 %s | FileCheck %s -check-prefix=CHK_MAT2x1
// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=uint2x2 %s | FileCheck %s -check-prefix=CHK_MAT2x2
// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=uint16_t2x3 %s | FileCheck %s -check-prefix=CHK_MAT2x3
// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=int16_t3x2 %s | FileCheck %s -check-prefix=CHK_MAT3x2
// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=float16_t3x3 %s | FileCheck %s -check-prefix=CHK_MAT3x3
// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=float3x4 %s | FileCheck %s -check-prefix=CHK_MAT3x4
// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=bool4x3 %s | FileCheck %s -check-prefix=CHK_MAT4x3
// RUN: %dxc -E main -T vs_6_2 -enable-16bit-types -Zpc -DTY=float4x4 %s | FileCheck %s -check-prefix=CHK_MAT4x4

ConsumeStructuredBuffer<TY> buf;

TY main() : OUT
{

// CHK_MAT1x1: dx.op.rawBufferLoad.i32(i32 139, 
// CHK_MAT1x1: i32 %{{.*}}, i32 0, i8 1, i32 4)

// CHK_MAT1x2: dx.op.rawBufferLoad.f32(i32 139, 
// CHK_MAT1x2: i32 %{{.*}}, i32 0, i8 3, i32 4)

// CHK_MAT2x1: dx.op.rawBufferLoad.i32(i32 139, 
// CHK_MAT2x1: i32 %{{.*}}, i32 0, i8 3, i32 4)

// CHK_MAT2x2: dx.op.rawBufferLoad.i32(i32 139, 
// CHK_MAT2x2: i32 %{{.*}}, i32 0, i8 15, i32 4)

// CHK_MAT2x3: dx.op.rawBufferLoad.i16(i32 139, 
// CHK_MAT2x3: i32 %{{.*}}, i32 0, i8 3, i32 2)
// CHK_MAT2x3: dx.op.rawBufferLoad.i16(i32 139, 
// CHK_MAT2x3: i32 %{{.*}}, i32 4, i8 15, i32 2)

// CHK_MAT3x2: dx.op.rawBufferLoad.i16(i32 139, 
// CHK_MAT3x2: i32 %{{.*}}, i32 0, i8 3, i32 2)
// CHK_MAT3x2: dx.op.rawBufferLoad.i16(i32 139, 
// CHK_MAT3x2: i32 %{{.*}}, i32 4, i8 15, i32 2)

// CHK_MAT3x3: dx.op.rawBufferLoad.f16(i32 139, 
// CHK_MAT3x3: i32 %{{.*}}, i32 0, i8 1, i32 2)
// CHK_MAT3x3: dx.op.rawBufferLoad.f16(i32 139, 
// CHK_MAT3x3: i32 %{{.*}}, i32 2, i8 15, i32 2)
// CHK_MAT3x3: dx.op.rawBufferLoad.f16(i32 139, 
// CHK_MAT3x3: i32 %{{.*}}, i32 10, i8 15, i32 2)

// CHK_MAT3x4: dx.op.rawBufferLoad.f32(i32 139, 
// CHK_MAT3x4: i32 %{{.*}}, i32 0, i8 15, i32 4)
// CHK_MAT3x4: dx.op.rawBufferLoad.f32(i32 139, 
// CHK_MAT3x4: i32 %{{.*}}, i32 16, i8 15, i32 4)
// CHK_MAT3x4: dx.op.rawBufferLoad.f32(i32 139, 
// CHK_MAT3x4: i32 %{{.*}}, i32 32, i8 15, i32 4)

// CHK_MAT4x3: dx.op.rawBufferLoad.i32(i32 139, 
// CHK_MAT4x3: i32 %{{.*}}, i32 0, i8 15, i32 4)
// CHK_MAT4x3: dx.op.rawBufferLoad.i32(i32 139, 
// CHK_MAT4x3: i32 %{{.*}}, i32 16, i8 15, i32 4)
// CHK_MAT4x3: dx.op.rawBufferLoad.i32(i32 139, 
// CHK_MAT4x3: i32 %{{.*}}, i32 32, i8 15, i32 4)

// CHK_MAT4x4: dx.op.rawBufferLoad.f32(i32 139, 
// CHK_MAT4x4: i32 %{{.*}}, i32 0, i8 15, i32 4)
// CHK_MAT4x4: dx.op.rawBufferLoad.f32(i32 139, 
// CHK_MAT4x4: i32 %{{.*}}, i32 16, i8 15, i32 4)
// CHK_MAT4x4: dx.op.rawBufferLoad.f32(i32 139, 
// CHK_MAT4x4: i32 %{{.*}}, i32 32, i8 15, i32 4)
// CHK_MAT4x4: dx.op.rawBufferLoad.f32(i32 139, 
// CHK_MAT4x4: i32 %{{.*}}, i32 48, i8 15, i32 4)
  
    return buf.Consume();
}