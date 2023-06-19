// RUN: %clang_cc1 -fsyntax-only -verify %s

// NodeDispatchGrid and NodeMaxDispatchGrid may only be used with Broadcasting launch nodes

[Shader("node")]
[NodeLaunch("Coalescing")]           // expected-note +{{Launch type defined here}}
[NodeDispatchGrid(4, 4, 2)]          // expected-error {{'nodedispatchgrid' may only be used with Broadcasting nodes}}
[NumThreads(32, 1, 1)]
void node01()
{ }

[Shader("node")]
[NodeLaunch("Thread")]               // expected-note +{{Launch type defined here}}
[NodeDispatchGrid(8, 4, 2)]          // expected-error {{'nodedispatchgrid' may only be used with Broadcasting nodes}}
void node02()
{ }

[Shader("node")]
[NodeLaunch("Coalescing")]           // expected-note +{{Launch type defined here}}
[NodeMaxDispatchGrid(8, 8, 8)]       // expected-error {{'nodemaxdispatchgrid' may only be used with Broadcasting nodes}}
[NumThreads(32, 1, 1)]
void node03()
{ }

[Shader("node")]
[NodeLaunch("Thread")]               // expected-note +{{Launch type defined here}}
[NodeMaxDispatchGrid(256, 8, 8)]     // expected-error {{'nodemaxdispatchgrid' may only be used with Broadcasting nodes}}
void node04()
{ }

// NodeDispatchGrid and NodeMaxDispatchGrid may not both be used

[Shader("node")]
[NodeLaunch("Broadcasting")]
[NodeMaxDispatchGrid(256, 64, 32)]   // expected-error {{Node shader 'node05' may not use both 'nodemaxdispatchgrid' and 'nodedispatchgrid'}}
[NodeDispatchGrid(32, 1, 1)]         // expected-note  {{nodedispatchgrid defined here}}
[NumThreads(32, 1, 1)]
void node05()
{ }

// One of NodeDispatchGrid or NodeMaxDispatchGrid must be specified for a Broadcasting node

[Shader("node")]
[NodeLaunch("Broadcasting")]
[NumThreads(32, 1, 1)]
void node06()                        // expected-error {{Broadcasting node shader 'node06' must have either the NodeDispatchGrid or NodeMaxDispatchGrid attribute}}
{ }

// NodeTrackRWInputRecordSharing must appear on the actual input record used if FinishedCrossGroupSharing may be called,
// and the attribute may not be inherited

struct [NodeTrackRWInputSharing] TrackedRecord {
  float4 f;
};

struct SharedRecord {
  float4 f;
};

struct InheritedRecord : TrackedRecord {
  float4 f;
};

[Shader("node")]
[NodeLaunch("Broadcasting")]
[NodeDispatchGrid(32, 1, 1)]
[NumThreads(32, 1, 1)]
void node10(RWDispatchNodeInputRecord<TrackedRecord> input)
{
  input.FinishedCrossGroupSharing(); // no error as NodeTrackRWInputSharing is present
}

[Shader("node")]
[NodeLaunch("Broadcasting")]
[NodeDispatchGrid(32, 1, 1)]
[NumThreads(32, 1, 1)]
void node11(RWDispatchNodeInputRecord<SharedRecord> input)
{
  input.FinishedCrossGroupSharing(); // expected-error {{Use of FinishedCrossGroupSharing() requires NodeTrackRWInputSharing attribute to be specified on the record struct type}}
}

[Shader("node")]
[NodeLaunch("Broadcasting")]
[NodeDispatchGrid(32, 1, 1)]
[NumThreads(32, 1, 1)]
// The [NodeTrackRWInputSharing] attribute is not inherited
void node12(RWDispatchNodeInputRecord<InheritedRecord> input)
{
  input.FinishedCrossGroupSharing(); // expected-error {{Use of FinishedCrossGroupSharing() requires NodeTrackRWInputSharing attribute to be specified on the record struct type}}
}
