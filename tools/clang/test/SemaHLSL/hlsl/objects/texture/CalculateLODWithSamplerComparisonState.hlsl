// RUN: dxc -Tlib_6_7 %s -verify

SamplerComparisonState s;
Texture1D t;

// Make sure direct call to CalculateLevelOfDetail and CalculateLevelOfDetailUnclamped get error.
export
float foo(float a) {
  return t.CalculateLevelOfDetail(s, a) + // expected-error {{overload of intrinsic CalculateLevelOfDetail requires shader model 6.8 or greater}}
    t.CalculateLevelOfDetailUnclamped(s, a); // expected-error {{overload of intrinsic CalculateLevelOfDetailUnclamped requires shader model 6.8 or greater}}
}

// Make sure unused function call to CalculateLevelOfDetail and CalculateLevelOfDetailUnclamped don't get error.
float bar(float a) {
  return t.CalculateLevelOfDetail(s, a) +
    t.CalculateLevelOfDetailUnclamped(s, a);
}

// Make sure nested call to CalculateLevelOfDetail and CalculateLevelOfDetailUnclamped get error.
float foo2(float a) {
  return t.CalculateLevelOfDetail(s, a) + // expected-error {{overload of intrinsic CalculateLevelOfDetail requires shader model 6.8 or greater}}
    t.CalculateLevelOfDetailUnclamped(s, a); // expected-error {{overload of intrinsic CalculateLevelOfDetailUnclamped requires shader model 6.8 or greater}}
}

export
float bar2(float a) {
  return foo2(a);
}

// Make sure report error when derivatives not supported.

[shader("pixel")]
float ps(float a:A) : SV_Target {
  return t.CalculateLevelOfDetail(s, a) + // expected-error {{overload of intrinsic CalculateLevelOfDetail requires shader model 6.8 or greater}}
    t.CalculateLevelOfDetailUnclamped(s, a); // expected-error {{overload of intrinsic CalculateLevelOfDetailUnclamped requires shader model 6.8 or greater}}
}

[shader("vertex")]
float4 vs(float a:A) : SV_Position {
  // expected-error@+1 {{Derivatives intrinsic CalculateLevelOfDetail only works in ps and cs_6.6+/as_6.6+/ms_6.6+/node}}
  return t.CalculateLevelOfDetail(s, a) + // expected-error {{overload of intrinsic CalculateLevelOfDetail requires shader model 6.8 or greater}}
  // expected-error@+1 {{Derivatives intrinsic CalculateLevelOfDetailUnclamped only works in ps and cs_6.6+/as_6.6+/ms_6.6+/node}}
    t.CalculateLevelOfDetailUnclamped(s, a); // expected-error {{overload of intrinsic CalculateLevelOfDetailUnclamped requires shader model 6.8 or greater}}
}
