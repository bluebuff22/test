// RUN: %dxc -T ps_6_0 -E main -fspv-extension=SPV_EXT_demote_to_helper_invocation

// According to the HLS spec, discard can only be called from a pixel shader.

// CHECK: OpCapability DemoteToHelperInvocationEXT
// CHECK: OpExtension "SPV_EXT_demote_to_helper_invocation"

void main() {
  int a, b;
  bool cond = true;

  while(cond) {
// CHECK: %while_body = OpLabel
    if(a==b) {
// CHECK: %if_true = OpLabel
// CHECK: OpDemoteToHelperInvocationEXT
      discard;
      break;
    } else {
// CHECK: %if_false = OpLabel
      ++a;
// CHECK: OpDemoteToHelperInvocationEXT
      discard;
      continue;
      --b;
    }
// CHECK: %if_merge = OpLabel
  }
// CHECK: %while_merge = OpLabel

}
