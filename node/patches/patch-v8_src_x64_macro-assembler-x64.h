$NetBSD: patch-v8_src_x64_macro-assembler-x64.h,v 1.1.1.1 2011/05/03 19:53:18 genolopolis Exp $

--- deps/v8/src/x64/macro-assembler-x64.h.orig	2011-04-13 08:24:39.000000000 +0000
+++ deps/v8/src/x64/macro-assembler-x64.h
@@ -256,8 +256,9 @@ class MacroAssembler: public Assembler {
                                            int power);
 
 
-  // Simple comparison of smis.
-  void SmiCompare(Register dst, Register src);
+  // Simple comparison of smis.  Both sides must be known smis to use these,
+  // otherwise use Cmp.
+  void SmiCompare(Register smi1, Register smi2);
   void SmiCompare(Register dst, Smi* src);
   void SmiCompare(Register dst, const Operand& src);
   void SmiCompare(const Operand& dst, Register src);
@@ -579,6 +580,8 @@ class MacroAssembler: public Assembler {
   void Move(const Operand& dst, Handle<Object> source);
   void Cmp(Register dst, Handle<Object> source);
   void Cmp(const Operand& dst, Handle<Object> source);
+  void Cmp(Register dst, Smi* src);
+  void Cmp(const Operand& dst, Smi* src);
   void Push(Handle<Object> source);
 
   // Emit code to discard a non-negative number of pointer-sized elements
@@ -646,6 +649,7 @@ class MacroAssembler: public Assembler {
 
   // Abort execution if argument is not a smi. Used in debug code.
   void AbortIfNotSmi(Register object);
+  void AbortIfNotSmi(const Operand& object);
 
   // Abort execution if argument is a string. Used in debug code.
   void AbortIfNotString(Register object);
