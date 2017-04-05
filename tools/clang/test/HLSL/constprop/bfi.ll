; RUN: %opt %s -sccp -S | FileCheck %s

target datalayout = "e-m:e-p:32:32-i64:64-f80:32-n8:16:32-a:0:32-S32"
target triple = "dxil-ms-dx"

%dx.types.Handle = type { i8* }
%struct.RWByteAddressBuffer = type { i32 }

define void @main() {
entry:
  %buf_UAV_rawbuf = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 1, i32 0, i32 0, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  
  ; CHECK: @dx.op.bufferStore{{.*}}, i32 510,
  %0 = call i32 @dx.op.quaternary.i32(i32 53, i32 8, i32 1, i32 255, i32 0)
  call void @dx.op.bufferStore.i32(i32 69, %dx.types.Handle %buf_UAV_rawbuf, i32 0, i32 undef, i32 %0, i32 undef, i32 undef, i32 undef, i8 1)  ; BufferStore(uav,coord0,coord1,value0,value1,value2,value3,mask)
  
  ; CHECK: @dx.op.bufferStore{{.*}}, i32 255,
  %1 = call i32 @dx.op.quaternary.i32(i32 53, i32 8, i32 32, i32 255, i32 0)
  call void @dx.op.bufferStore.i32(i32 69, %dx.types.Handle %buf_UAV_rawbuf, i32 4, i32 undef, i32 %1, i32 undef, i32 undef, i32 undef, i8 1)  ; BufferStore(uav,coord0,coord1,value0,value1,value2,value3,mask)
  
  ; CHECK: @dx.op.bufferStore{{.*}}, i32 -1091584273,
  %2 = call i32 @dx.op.quaternary.i32(i32 53, i32 16, i32 16, i32 48879, i32 3735928559)
  call void @dx.op.bufferStore.i32(i32 69, %dx.types.Handle %buf_UAV_rawbuf, i32 8, i32 undef, i32 %2, i32 undef, i32 undef, i32 undef, i8 1)  ; BufferStore(uav,coord0,coord1,value0,value1,value2,value3,mask)
  
  ; CHECK: @dx.op.bufferStore{{.*}}, i32 322420463,
  %3 = call i32 @dx.op.quaternary.i32(i32 53, i32 8, i32 16, i32 55, i32 318815983)
  call void @dx.op.bufferStore.i32(i32 69, %dx.types.Handle %buf_UAV_rawbuf, i32 12, i32 undef, i32 %3, i32 undef, i32 undef, i32 undef, i8 1)  ; BufferStore(uav,coord0,coord1,value0,value1,value2,value3,mask)
  
  ; CHECK: @dx.op.bufferStore{{.*}}, i32 15,
  %4 = call i32 @dx.op.quaternary.i32(i32 53, i32 0, i32 8, i32 0, i32 15)
  call void @dx.op.bufferStore.i32(i32 69, %dx.types.Handle %buf_UAV_rawbuf, i32 16, i32 undef, i32 %4, i32 undef, i32 undef, i32 undef, i8 1)  ; BufferStore(uav,coord0,coord1,value0,value1,value2,value3,mask)
  
  ; No i64 overloads for bfi in dxil yet.
  ; xHECK: @dx.op.bufferStore{{.*}}, i32 2560,
  ;%5 = call i64 @dx.op.quaternary.i64(i32 53, i64 4, i64 8, i64 4010, i64 0)
  ;%6 = trunc i64 %5 to i32
  ;call void @dx.op.bufferStore.i32(i32 69, %dx.types.Handle %buf_UAV_rawbuf, i32 20, i32 undef, i32 %6, i32 undef, i32 undef, i32 undef, i8 1)  ; BufferStore(uav,coord0,coord1,value0,value1,value2,value3,mask)
  
  ; No i64 overloads for bfi in dxil yet.
  ; xHECK: @dx.op.bufferStore{{.*}}, i32 10,
  ;%7 = call i64 @dx.op.quaternary.i64(i32 53, i64 4, i64 32, i64 4010, i64 0)
  ;%8 = lshr i64 %7, 32
  ;%9 = trunc i64 %8 to i32
  ;call void @dx.op.bufferStore.i32(i32 69, %dx.types.Handle %buf_UAV_rawbuf, i32 24, i32 undef, i32 %9, i32 undef, i32 undef, i32 undef, i8 1)  ; BufferStore(uav,coord0,coord1,value0,value1,value2,value3,mask)
  
  call void @dx.op.storeOutput.i32(i32 5, i32 0, i32 0, i8 0, i32 0)  ; StoreOutput(outputtSigId,rowIndex,colIndex,value)
  ret void
}

; Function Attrs: nounwind readnone
declare i32 @dx.op.loadInput.i32(i32, i32, i32, i8, i32) #0

; Function Attrs: nounwind
declare void @dx.op.storeOutput.i32(i32, i32, i32, i8, i32) #1

; Function Attrs: nounwind
declare void @dx.op.bufferStore.i32(i32, %dx.types.Handle, i32, i32, i32, i32, i32, i32, i8) #1

; Function Attrs: nounwind readonly
declare %dx.types.Handle @dx.op.createHandle(i32, i8, i32, i32, i1) #2

declare i32 @dx.op.quaternary.i32(i32, i32, i32, i32, i32) #1
declare i64 @dx.op.quaternary.i64(i32, i64, i64, i64, i64) #1

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind }
attributes #2 = { nounwind readonly }

!llvm.ident = !{!0}
!dx.valver = !{!1}
!dx.version = !{!1}
!dx.shaderModel = !{!2}
!dx.resources = !{!3}
!dx.typeAnnotations = !{!6, !9}
!dx.entryPoints = !{!13}

!0 = !{!"clang version 3.7 (tags/RELEASE_370/final)"}
!1 = !{i32 1, i32 0}
!2 = !{!"ps", i32 6, i32 0}
!3 = !{null, !4, null, null}
!4 = !{!5}
!5 = !{i32 0, %struct.RWByteAddressBuffer* undef, !"buf", i32 0, i32 0, i32 1, i32 11, i1 false, i1 false, i1 false, null}
!6 = !{i32 0, %struct.RWByteAddressBuffer undef, !7}
!7 = !{i32 4, !8}
!8 = !{i32 6, !"h", i32 3, i32 0, i32 7, i32 4}
!9 = !{i32 1, void ()* @main, !10}
!10 = !{!11}
!11 = !{i32 0, !12, !12}
!12 = !{}
!13 = !{void ()* @main, !"main", !14, !3, !20}
!14 = !{!15, !18, null}
!15 = !{!16}
!16 = !{i32 0, !"A", i8 4, i8 0, !17, i8 1, i32 1, i8 1, i32 0, i8 0, null}
!17 = !{i32 0}
!18 = !{!19}
!19 = !{i32 0, !"SV_Target", i8 4, i8 16, !17, i8 0, i32 1, i8 1, i32 0, i8 0, null}
!20 = !{i32 0, i64 16}