// RUN: %dxc -E plain -T vs_6_0 %s

// without also putting them in a static assertion

// __decltype is the GCC way of saying 'decltype', but doesn't require C++11
#ifdef VERIFY_FXC
#endif

// :FXC_VERIFY_ARGUMENTS: /E plain /T vs_6_0

// To test with the classic compiler, run
// %sdxroot%\tools\x86\fxc.exe /T vs_6_0 scalar-operators.hlsl
// with vs_2_0 (the default) min16float usage produces a complaint that it's not supported

float4 plain(float4 param4 : FOO) : FOO {
    bool        bools       = 0;
    int         ints        = 0;
    uint        uints       = 0;
    dword       dwords      = 0;
    half        halfs       = 0;
    float       floats      = 0;
    double      doubles     = 0;
    min16float  min16floats = 0;
    min10float  min10floats = 0;
    min16int    min16ints   = 0;
    min12int    min12ints   = 0;
    min16uint   min16uints  = 0;


  
    // float result = ints + floats;

    // Promotion cases with addition.
    // Two unsigned types will widen to widest type.
    
    // Two signed types will widen to widest type, but remain minprecision if either is.
    
    // Mixed signed-unsigned will widen to largest unsigned.
    
    // Mixed integral/floating point will turn to floating-point.
    
    // For two floating-point types, they will widen to the largest one.
    
  // Generated by running and modifying %sdxroot%\windows\directx\dxg\HLSL\test\lib\HLSL\operators.js

  return param4;
}