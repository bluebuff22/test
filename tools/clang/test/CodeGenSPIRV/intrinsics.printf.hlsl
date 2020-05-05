// Run: %dxc -T cs_6_0 -E main

// CHECK:                OpExtension "SPV_KHR_non_semantic_info"
// CHECK: [[set:%\d+]] = OpExtInstImport "NonSemantic.DebugPrintf"

// CHECK: [[format1:%\d+]] = OpString "first string"
// CHECK: [[format2:%\d+]] = OpString "second string"
// CHECK: [[format3:%\d+]] = OpString "please print this message."
// CHECK: [[format4:%\d+]] = OpString "Variables are: %d %d %.2f"
// CHECK: [[format5:%\d+]] = OpString "Integers are: %d %d %d"
// CHECK: [[format6:%\d+]] = OpString "More: %d %d %d %d %d %d %d %d %d %d"

const string first = "first string";
string second;

[numthreads(1,1,1)]
void main() {
  second = "second string";

// CHECK: {{%\d+}} = OpExtInst %void [[set]] 1 [[format1]]
  printf(first);
// CHECK: {{%\d+}} = OpExtInst %void [[set]] 1 [[format2]]
  printf(second);
// CHECK: {{%\d+}} = OpExtInst %void [[set]] 1 [[format3]]
  printf("please print this message.");
// CHECK: {{%\d+}} = OpExtInst %void [[set]] 1 [[format4]] %uint_1 %uint_2 %float_1_5
  printf("Variables are: %d %d %.2f", 1u, 2u, 1.5f);
// CHECK: {{%\d+}} = OpExtInst %void [[set]] 1 [[format5]] %int_1 %int_2 %int_3
  printf("Integers are: %d %d %d", 1, 2, 3);
// CHECK: {{%\d+}} = OpExtInst %void [[set]] 1 [[format6]] %int_1 %int_2 %int_3 %int_4 %int_5 %int_6 %int_7 %int_8 %int_9 %int_10
  printf("More: %d %d %d %d %d %d %d %d %d %d", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}

