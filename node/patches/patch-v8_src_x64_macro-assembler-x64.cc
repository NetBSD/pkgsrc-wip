$NetBSD: patch-v8_src_x64_macro-assembler-x64.cc,v 1.1.1.1 2011/05/03 19:53:18 genolopolis Exp $

--- deps/v8/src/x64/macro-assembler-x64.cc.orig	2011-04-13 08:24:39.000000000 +0000
+++ deps/v8/src/x64/macro-assembler-x64.cc
@@ -109,7 +109,7 @@ void MacroAssembler::RecordWrite(Registe
   ASSERT(!object.is(rsi) && !value.is(rsi) && !index.is(rsi));
 
   // First, check if a write barrier is even needed. The tests below
-  // catch stores of Smis and stores into young gen.
+  // catch stores of smis and stores into young gen.
   Label done;
   JumpIfSmi(value, &done);
 
@@ -138,7 +138,7 @@ void MacroAssembler::RecordWrite(Registe
   ASSERT(!object.is(rsi) && !value.is(rsi) && !address.is(rsi));
 
   // First, check if a write barrier is even needed. The tests below
-  // catch stores of Smis and stores into young gen.
+  // catch stores of smis and stores into young gen.
   Label done;
   JumpIfSmi(value, &done);
 
@@ -820,12 +820,26 @@ void MacroAssembler::SmiTest(Register sr
 }
 
 
-void MacroAssembler::SmiCompare(Register dst, Register src) {
-  cmpq(dst, src);
+void MacroAssembler::SmiCompare(Register smi1, Register smi2) {
+  if (FLAG_debug_code) {
+    AbortIfNotSmi(smi1);
+    AbortIfNotSmi(smi2);
+  }
+  cmpq(smi1, smi2);
 }
 
 
 void MacroAssembler::SmiCompare(Register dst, Smi* src) {
+  if (FLAG_debug_code) {
+    AbortIfNotSmi(dst);
+  }
+  // Actually, knowing the register is a smi doesn't enable any optimizations
+  // with the current tagging scheme.
+  Cmp(dst, src);
+}
+
+
+void MacroAssembler::Cmp(Register dst, Smi* src) {
   ASSERT(!dst.is(kScratchRegister));
   if (src->value() == 0) {
     testq(dst, dst);
@@ -837,20 +851,41 @@ void MacroAssembler::SmiCompare(Register
 
 
 void MacroAssembler::SmiCompare(Register dst, const Operand& src) {
+  if (FLAG_debug_code) {
+    AbortIfNotSmi(dst);
+    AbortIfNotSmi(src);
+  }
   cmpq(dst, src);
 }
 
 
 void MacroAssembler::SmiCompare(const Operand& dst, Register src) {
+  if (FLAG_debug_code) {
+    AbortIfNotSmi(dst);
+    AbortIfNotSmi(src);
+  }
   cmpq(dst, src);
 }
 
 
 void MacroAssembler::SmiCompare(const Operand& dst, Smi* src) {
+  if (FLAG_debug_code) {
+    AbortIfNotSmi(dst);
+  }
   cmpl(Operand(dst, kSmiShift / kBitsPerByte), Immediate(src->value()));
 }
 
 
+void MacroAssembler::Cmp(const Operand& dst, Smi* src) {
+  // The Operand cannot use the smi register, since we may use the scratch
+  // register to get around the lack of 64 bit immediates in the instruction
+  // set.
+  Register smi_reg = GetSmiConstant(src);
+  ASSERT(!dst.AddressUsesRegister(smi_reg));
+  cmpq(dst, smi_reg);
+}
+
+
 void MacroAssembler::SmiCompareInteger32(const Operand& dst, Register src) {
   cmpl(Operand(dst, kSmiShift / kBitsPerByte), src);
 }
@@ -1335,7 +1370,7 @@ void MacroAssembler::Move(const Operand&
 
 void MacroAssembler::Cmp(Register dst, Handle<Object> source) {
   if (source->IsSmi()) {
-    SmiCompare(dst, Smi::cast(*source));
+    Cmp(dst, Smi::cast(*source));
   } else {
     Move(kScratchRegister, source);
     cmpq(dst, kScratchRegister);
@@ -1345,7 +1380,7 @@ void MacroAssembler::Cmp(Register dst, H
 
 void MacroAssembler::Cmp(const Operand& dst, Handle<Object> source) {
   if (source->IsSmi()) {
-    SmiCompare(dst, Smi::cast(*source));
+    Cmp(dst, Smi::cast(*source));
   } else {
     ASSERT(source->IsHeapObject());
     movq(kScratchRegister, source, RelocInfo::EMBEDDED_OBJECT);
@@ -1692,7 +1727,12 @@ void MacroAssembler::AbortIfSmi(Register
 
 
 void MacroAssembler::AbortIfNotSmi(Register object) {
-  NearLabel ok;
+  Condition is_smi = CheckSmi(object);
+  Assert(is_smi, "Operand is not a smi");
+}
+
+
+void MacroAssembler::AbortIfNotSmi(const Operand& object) {
   Condition is_smi = CheckSmi(object);
   Assert(is_smi, "Operand is not a smi");
 }
