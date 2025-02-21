$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/builtins/x64/builtins-x64.cc.orig	2025-02-17 21:09:38.000000000 +0000
+++ v8/src/builtins/x64/builtins-x64.cc
@@ -1836,7 +1836,7 @@ static void Generate_InterpreterEnterByt
                   times_system_pointer_size, 0));
 
   // Jump to the interpreter entry, and call kJavaScriptCallCodeStartRegister.
-  __ jmp(rbx);
+  __ jmp(rbx, /*notrack=*/true);
 }
 
 void Builtins::Generate_InterpreterEnterAtNextBytecode(MacroAssembler* masm) {
