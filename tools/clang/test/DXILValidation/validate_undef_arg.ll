; RUN: %dxv %s | FileCheck %s

; The purpose of this test is to make sure that for various dxil ops that take in one
; of three handle types: Handle (resource handles), NodeHandle, and NodeRecordHandle
; when the argument given to these types is zeroinitializer or undef, an
; error gets emitted, which proves there is validation that handle arguments
; aren't ill-formed.


target datalayout = "e-m:e-p:32:32-i1:32-i8:32-i16:32-i32:32-i64:64-f16:32-f32:32-f64:64-n8:16:32:64"
target triple = "dxil-ms-dx"

%dx.types.Handle = type { i8* }
%dx.types.NodeHandle = type { i8* }
%dx.types.NodeInfo = type { i32, i32 }
%dx.types.NodeRecordHandle = type { i8* }
%dx.types.NodeRecordInfo = type { i32, i32 }
%struct.loadStressRecord.0 = type { [3 x i32], [3 x i32] }

define void @loadStress_16() {
  %1 = call i32 @dx.op.flattenedThreadIdInGroup.i32(i32 96)
  %2 = call %dx.types.NodeHandle @dx.op.createNodeOutputHandle(i32 247, i32 0)
  %3 = call %dx.types.NodeHandle @dx.op.annotateNodeHandle(i32 249, %dx.types.NodeHandle %2, %dx.types.NodeInfo { i32 6, i32 24 })
  %4 = call %dx.types.NodeRecordHandle @dx.op.allocateNodeOutputRecords(i32 238, %dx.types.NodeHandle %3, i32 1, i1 true)
  %5 = call %dx.types.NodeRecordHandle @dx.op.annotateNodeRecordHandle(i32 251, %dx.types.NodeRecordHandle %4, %dx.types.NodeRecordInfo { i32 38, i32 24 })  

  ; Test a Dxil op with a NodeRecordHandle handle type
  ; CHECK-DAG: error: Instructions should not read uninitialized value.
  ; CHECK-DAG: note: at '%6 = call %struct.loadStressRecord.0 addrspace(6)* @dx.op.getNodeRecordPtr.struct.loadStressRecord.0
  %6 = call %struct.loadStressRecord.0 addrspace(6)* @dx.op.getNodeRecordPtr.struct.loadStressRecord.0(i32 239, %dx.types.NodeRecordHandle zeroinitializer, i32 0)    
  
  ; Test that OutputComplete fails when it receives an undef.
  ; OutputComplete also serves as a test for NodeRecordHandle handle types.
  ; CHECK-DAG: error: Instructions should not read uninitialized value.
  ; CHECK-DAG: note: at 'call void @dx.op.outputComplete(i32 241, %dx.types.NodeRecordHandle undef)
  call void @dx.op.outputComplete(i32 241, %dx.types.NodeRecordHandle undef)


  ; Test that OutputComplete fails when it receives an undef.
  ; CHECK-DAG: error: Instructions should not read uninitialized value.
  ; CHECK-DAG: note: at 'call void @dx.op.outputComplete(i32 241, %dx.types.NodeRecordHandle zeroinitializer)
  call void @dx.op.outputComplete(i32 241, %dx.types.NodeRecordHandle zeroinitializer)

  ; Test a Dxil op with a Resource handle type (mixing in undef and zeroinitializer)
  ; (it should be noted that handles with zeroinitialize / undef values are invalid according to DxilResourceProperties)
  ; CHECK-DAG: error: Instructions should not read uninitialized value.
  ; CHECK-DAG: note: at 'call void @dx.op.writeSamplerFeedbackLevel(i32 176, %dx.types.Handle undef,
  ; CHECK-DAG: note: at 'call void @dx.op.writeSamplerFeedbackLevel(i32 176, %dx.types.Handle undef, %dx.types.Handle zeroinitializer,
  ; CHECK-DAG: note: at 'call void @dx.op.writeSamplerFeedbackLevel(i32 176, %dx.types.Handle undef, %dx.types.Handle zeroinitializer, %dx.types.Handle undef
  call void @dx.op.writeSamplerFeedbackLevel(i32 176, %dx.types.Handle undef, %dx.types.Handle zeroinitializer, %dx.types.Handle undef, float 2.100000e+01, float 2.200000e+01, float undef, float undef, float 6.000000e+00)  ; WriteSamplerFeedbackLevel(feedbackTex,sampledTex,sampler,c0,c1,c2,c3,lod)

  ; Test a dxil op with a NodeHandle handle type as undef
  ; CHECK-DAG: error: Instructions should not read uninitialized value.
  ; CHECK-DAG: note: at '%7 = call %dx.types.NodeHandle @dx.op.annotateNodeHandle(i32 249, %dx.types.NodeHandle undef,
  %7 = call %dx.types.NodeHandle @dx.op.annotateNodeHandle(i32 249, %dx.types.NodeHandle undef, %dx.types.NodeInfo { i32 6, i32 24 })

  ; Test a dxil op with a NodeHandle handle type as zeroinitializer
  ; CHECK-DAG: error: Instructions should not read uninitialized value.
  ; CHECK-DAG: note: at '%8 = call %dx.types.NodeHandle @dx.op.annotateNodeHandle(i32 249, %dx.types.NodeHandle zeroinitializer, %dx.types.NodeInfo { i32 6, i32 24 })
  %8 = call %dx.types.NodeHandle @dx.op.annotateNodeHandle(i32 249, %dx.types.NodeHandle zeroinitializer, %dx.types.NodeInfo { i32 6, i32 24 })

  br label %9
; <label>:9                                        ; preds = %0
  ret void  
}

; Function Attrs: nounwind readnone
declare i32 @dx.op.flattenedThreadIdInGroup.i32(i32) #0

; Function Attrs: nounwind readnone
declare %struct.loadStressRecord.0 addrspace(6)* @dx.op.getNodeRecordPtr.struct.loadStressRecord.0(i32, %dx.types.NodeRecordHandle, i32) #0

; Function Attrs: nounwind
declare void @dx.op.writeSamplerFeedbackLevel(i32, %dx.types.Handle, %dx.types.Handle, %dx.types.Handle, float, float, float, float, float) #0

; Function Attrs: nounwind
declare %dx.types.NodeRecordHandle @dx.op.allocateNodeOutputRecords(i32, %dx.types.NodeHandle, i32, i1) #1

; Function Attrs: nounwind
declare void @dx.op.outputComplete(i32, %dx.types.NodeRecordHandle) #1

; Function Attrs: nounwind
;declare void @dx.op.BufferLoad(i32, i32)

; Function Attrs: nounwind
;declare void @dx.op.EmitStream(i32, i32)

; Function Attrs: nounwind readnone
declare %dx.types.NodeRecordHandle @dx.op.annotateNodeRecordHandle(i32, %dx.types.NodeRecordHandle, %dx.types.NodeRecordInfo) #0

; Function Attrs: nounwind readnone
declare %dx.types.NodeHandle @dx.op.createNodeOutputHandle(i32, i32) #0

; Function Attrs: nounwind readnone
declare %dx.types.NodeHandle @dx.op.annotateNodeHandle(i32, %dx.types.NodeHandle, %dx.types.NodeInfo) #0

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind }

!llvm.ident = !{!0}
!dx.version = !{!1}
!dx.valver = !{!1}
!dx.shaderModel = !{!2}
!dx.typeAnnotations = !{!3}
!dx.entryPoints = !{!7, !8}

!0 = !{!"dxc(private) 1.7.0.4790 (work-graphs, 35d890870)"}
!1 = !{i32 1, i32 8}
!2 = !{!"lib", i32 6, i32 8}
!3 = !{i32 1, void ()* @loadStress_16, !4}
!4 = !{!5}
!5 = !{i32 0, !6, !6}
!6 = !{}
!7 = !{null, !"", null, null, null}
!8 = !{void ()* @loadStress_16, !"loadStress_16", null, null, !9}
!9 = !{i32 8, i32 15, i32 13, i32 1, i32 15, !10, i32 16, i32 -1, i32 22, !11, i32 20, !12, i32 21, !14, i32 4, !19, i32 5, !20}
!10 = !{!"loadStress_16", i32 0}
!11 = !{i32 3, i32 1, i32 1}
!12 = !{!13}
!13 = !{i32 1, i32 9}
!14 = !{!15}
!15 = !{i32 1, i32 6, i32 2, !16, i32 3, i32 0, i32 0, !18}
!16 = !{i32 0, i32 24, i32 1, !17}
!17 = !{i32 0, i32 5, i32 3}
!18 = !{!"loadStressChild", i32 0}
!19 = !{i32 1, i32 1, i32 1}
!20 = !{i32 0}
!21 = !{!22, !22, i64 0}
!22 = !{!"int", !23, i64 0}
!23 = !{!"omnipotent char", !24, i64 0}
!24 = !{!"Simple C/C++ TBAA"}
