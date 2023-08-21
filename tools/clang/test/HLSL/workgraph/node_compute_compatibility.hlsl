// RUN: %clang_cc1 -fsyntax-only -verify %s
// ==================================================================
// Errors are generated for shaders with both "node" and "compute"
// specified when:
// - the launch type is not Broadcasting
// - a broadcasting node has an input record and/or output records
// ==================================================================

struct RECORD {
  uint a;
};

[Shader("node")]
[Shader("compute")]
[NumThreads(1024,1,1)]
[NodeDispatchGrid(128,1,1)]
[NodeLaunch("Broadcasting")]
void node01()
{ /* compatible */  }

[Shader("node")]
[Shader("compute")]
[NumThreads(1024,1,1)]
[NodeDispatchGrid(128,1,1)]
// implicit [NodeLaunch("Broadcasting")]
void node02()
{ /* compatible */  }

[Shader("node")]
[Shader("compute")] // expected-note {{compute defined here}}
[NumThreads(128,1,1)]
[NodeLaunch("Coalescing")]      // expected-error {{Node shader 'node03' with coalescing launch type is not compatible with compute (must be broadcasting)}}
void node03()
{ }

[Shader("compute")] // expected-note {{compute defined here}}
[Shader("node")]
[NumThreads(1,1,1)]
[NodeLaunch("Thread")] // expected-error {{Node shader 'node04' with thread launch type is not compatible with compute}}
void node04()
{ }

[Shader("node")]
[NumThreads(1024,1,1)]
[Shader("compute")] // expected-note {{compute defined here}}
[NodeLaunch("Broadcasting")]
[NodeDispatchGrid(128,1,1)]
void node05(DispatchNodeInputRecord<RECORD> input) // expected-error {{Node shader 'node05' with node input/output is not compatible with compute}}
{ }

[Shader("compute")] // expected-note {{compute defined here}}
[NumThreads(1024,1,1)]
[Shader("node")]
[NodeLaunch("Broadcasting")]
[NodeDispatchGrid(128,1,1)]
void node06(RWDispatchNodeInputRecord<RECORD> input) // expected-error {{Node shader 'node06' with node input/output is not compatible with compute}}
{ }

[NodeLaunch("Broadcasting")]
[Shader("node")]
[NumThreads(1024,1,1)]
[NodeDispatchGrid(128,1,1)]
[Shader("compute")]                    // expected-note {{compute defined here}}
void node07(NodeOutput<RECORD> output) // expected-error {{Node shader 'node07' with node input/output is not compatible with compute}}
{ }

[NumThreads(1024,1,1)]
[NodeLaunch("Broadcasting")]
[NodeDispatchGrid(128,1,1)]
[Shader("node")]
[Shader("compute")] // expected-note {{compute defined here}}
void node08(EmptyNodeOutput output) // expected-error {{Node shader 'node08' with node input/output is not compatible with compute}}
{ }
