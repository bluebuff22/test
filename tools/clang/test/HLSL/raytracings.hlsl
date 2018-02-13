// RUN: %clang_cc1 -HV 2018 -Wno-unused-value -fsyntax-only -ffreestanding -verify %s

void run() {
  RAY_FLAG rayFlag =
    RAY_FLAG_NONE                            +
    RAY_FLAG_FORCE_OPAQUE                    +
    RAY_FLAG_FORCE_NON_OPAQUE                +
    RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH +
    RAY_FLAG_SKIP_CLOSEST_HIT_SHADER         +
    RAY_FLAG_CULL_BACK_FACING_TRIANGLES      +
    RAY_FLAG_CULL_FRONT_FACING_TRIANGLES     +
    RAY_FLAG_CULL_OPAQUE                     +
    RAY_FLAG_CULL_NON_OPAQUE;

  rayFlag += RAY_FLAG_INVALID;                             /* expected-note@? {{'RAY_FLAG_NONE' declared here}} */ /* expected-error {{use of undeclared identifier 'RAY_FLAG_INVALID'; did you mean 'RAY_FLAG_NONE'?}} */

  int intFlag = RAY_FLAG_CULL_OPAQUE;

  int hitKindFlag =
    HIT_KIND_TRIANGLE_FRONT_FACE + HIT_KIND_TRIANGLE_BACK_FACE;

  hitKindFlag += HIT_KIND_INVALID;                          /* expected-error {{use of undeclared identifier 'HIT_KIND_INVALID'}} */
}
