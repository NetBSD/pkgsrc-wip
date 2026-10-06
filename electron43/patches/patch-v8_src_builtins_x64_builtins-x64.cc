$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/builtins/x64/builtins-x64.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/src/builtins/x64/builtins-x64.cc
@@ -1830,7 +1830,7 @@ static void Generate_InterpreterEnterByt
                   times_system_pointer_size, 0));
 
   // Jump to the interpreter entry, and call kJavaScriptCallCodeStartRegister.
-  __ jmp(rbx);
+  __ jmp(rbx, /*notrack=*/true);
 }
 
 void Builtins::Generate_InterpreterEnterAtNextBytecode(MacroAssembler* masm) {
