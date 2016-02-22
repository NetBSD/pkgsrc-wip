$NetBSD$

--- lib/CoreDisTools/coredistools.cpp.orig	2016-02-22 20:43:07.000000000 +0000
+++ lib/CoreDisTools/coredistools.cpp
@@ -49,13 +49,13 @@ public:
   void printInstruction(const MCInst *MI, size_t Address, size_t InstSize,
                         ArrayRef<uint8_t> Bytes) const;
 
-  CorDisasm(TargetArch Target) { TargetArch = Target; }
+  CorDisasm(TargetArch Target) { TheTargetArch = Target; }
 
 private:
   bool setTarget();
   bool verifyPrefixDecoding();
 
-  TargetArch TargetArch;
+  TargetArch TheTargetArch;
   string TargetTriple;
   const Target *TheTarget;
 
@@ -113,20 +113,20 @@ bool CorDisasm::setTarget() {
   TargetTriple = Triple::normalize(TargetTriple);
   Triple TheTriple(TargetTriple);
 
-  switch (TargetArch) {
+  switch (TheTargetArch) {
   case Target_Host:
     switch (TheTriple.getArch()) {
     case Triple::x86:
-      TargetArch = Target_X86;
+      TheTargetArch = Target_X86;
       break;
     case Triple::x86_64:
-      TargetArch = Target_X64;
+      TheTargetArch = Target_X64;
       break;
     case Triple::thumb:
-      TargetArch = Target_Thumb;
+      TheTargetArch = Target_Thumb;
       break;
     case Triple::aarch64:
-      TargetArch = Target_Arm64;
+      TheTargetArch = Target_Arm64;
       break;
     default:
       errs() << "Unsupported Architecture"
@@ -146,7 +146,7 @@ bool CorDisasm::setTarget() {
     TheTriple.setArch(Triple::x86_64);
   }
 
-  assert(TargetArch != Target_Host && "Target Expected to be specific");
+  assert(TheTargetArch != Target_Host && "Target Expected to be specific");
 
   // Get the target specific parser.
   string Error;
@@ -235,7 +235,7 @@ bool CorDisasm::init() {
 // X86 prefix bytes are decoded by LLVM -- and learn about
 // any change in behavior.
 bool CorDisasm::verifyPrefixDecoding() {
-  if ((TargetArch != Target_X86) && (TargetArch != Target_X64)) {
+  if ((TheTargetArch != Target_X86) && (TheTargetArch != Target_X64)) {
     return true;
   }
 
@@ -296,7 +296,7 @@ size_t CorDisasm::disasmInstruction(size
     }
 
     ContinueDisasm = false;
-    if ((TargetArch == Target_X86) || (TargetArch == Target_X64)) {
+    if ((TheTargetArch == Target_X86) || (TheTargetArch == Target_X64)) {
 
       // Check if the decoded instruction is a prefix byte, and if so,
       // continue decoding.
