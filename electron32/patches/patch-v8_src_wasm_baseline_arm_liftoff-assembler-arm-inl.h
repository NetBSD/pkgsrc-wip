$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/wasm/baseline/arm/liftoff-assembler-arm-inl.h.orig	2024-10-18 12:48:35.480421300 +0000
+++ v8/src/wasm/baseline/arm/liftoff-assembler-arm-inl.h
@@ -496,21 +496,23 @@ void LiftoffAssembler::CallFrameSetupStu
 
 void LiftoffAssembler::PrepareTailCall(int num_callee_stack_params,
                                        int stack_param_delta) {
-  UseScratchRegisterScope temps(this);
-  Register scratch = temps.Acquire();
+  {
+    UseScratchRegisterScope temps(this);
+    Register scratch = temps.Acquire();
 
-  // Push the return address and frame pointer to complete the stack frame.
-  sub(sp, sp, Operand(8));
-  ldr(scratch, MemOperand(fp, 4));
-  str(scratch, MemOperand(sp, 4));
-  ldr(scratch, MemOperand(fp, 0));
-  str(scratch, MemOperand(sp, 0));
-
-  // Shift the whole frame upwards.
-  int slot_count = num_callee_stack_params + 2;
-  for (int i = slot_count - 1; i >= 0; --i) {
-    ldr(scratch, MemOperand(sp, i * 4));
-    str(scratch, MemOperand(fp, (i - stack_param_delta) * 4));
+    // Push the return address and frame pointer to complete the stack frame.
+    sub(sp, sp, Operand(8));
+    ldr(scratch, MemOperand(fp, 4));
+    str(scratch, MemOperand(sp, 4));
+    ldr(scratch, MemOperand(fp, 0));
+    str(scratch, MemOperand(sp, 0));
+
+    // Shift the whole frame upwards.
+    int slot_count = num_callee_stack_params + 2;
+    for (int i = slot_count - 1; i >= 0; --i) {
+      ldr(scratch, MemOperand(sp, i * 4));
+      str(scratch, MemOperand(fp, (i - stack_param_delta) * 4));
+    }
   }
 
   // Set the new stack and frame pointer.
