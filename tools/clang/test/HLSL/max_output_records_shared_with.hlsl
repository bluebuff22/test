// RUN: %clang_cc1 -fsyntax-only -ffreestanding -verify %s

// Test referencing params with MaxOutputRecordsSharedWith before and after
// copied from  tools/clang/test/HLSLFileCheck/shader_targets/nodes/max_output_records_shared_with.hlsl

// CHECK: define void {{.*}}BackwardRef
// CHECK: define void {{.*}}ForwardRef

struct rec0
{
    int i0;
    float f0;
};

struct rec1
{
    float f1;
    int i1;
};

[Shader("node")]
[NodeLaunch("Thread")]
void BackwardRef(
  RWThreadNodeInputRecord<rec0> InputyMcInputFace,
  [MaxRecords(5)] NodeOutput<rec1> Output1,
  [MaxRecordsSharedWith(Output1)] NodeOutput<rec1> Output2)
{
}

[Shader("node")]
[NodeLaunch("Thread")]
void ForwardRef(
  RWThreadNodeInputRecord<rec0> InputyMcInputFace,
  [MaxRecordsSharedWith(Output2)] NodeOutput<rec1> Output1,
  [MaxRecords(5)] NodeOutput<rec1> Output2)
{
}
