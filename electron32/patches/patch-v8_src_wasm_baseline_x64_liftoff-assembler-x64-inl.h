$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/wasm/baseline/x64/liftoff-assembler-x64-inl.h.orig	2024-10-18 12:48:35.488421200 +0000
+++ v8/src/wasm/baseline/x64/liftoff-assembler-x64-inl.h
@@ -51,6 +51,8 @@ constexpr Operand kInstanceDataOperand =
 
 constexpr Operand kOSRTargetSlot = GetStackSlot(kOSRTargetOffset);
 
+// Note: The returned Operand might contain {kScratchRegister2}; make sure not
+// to clobber that until after the last use of the Operand.
 inline Operand GetMemOp(LiftoffAssembler* assm, Register addr,
                         Register offset_reg, uintptr_t offset_imm,
                         ScaleFactor scale_factor = times_1) {
@@ -61,7 +63,7 @@ inline Operand GetMemOp(LiftoffAssembler
                : Operand(addr, offset_reg, scale_factor, offset_imm32);
   }
   // Offset immediate does not fit in 31 bits.
-  Register scratch = kScratchRegister;
+  Register scratch = kScratchRegister2;
   assm->MacroAssembler::Move(scratch, offset_imm);
   if (offset_reg != no_reg) assm->addq(scratch, offset_reg);
   return Operand(addr, scratch, scale_factor, 0);
