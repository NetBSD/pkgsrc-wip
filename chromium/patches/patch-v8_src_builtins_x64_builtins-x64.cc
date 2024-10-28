$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/builtins/x64/builtins-x64.cc.orig	2024-10-26 07:03:27.482252800 +0000
+++ v8/src/builtins/x64/builtins-x64.cc
@@ -2838,7 +2838,11 @@ void Generate_OSREntry(MacroAssembler* m
   // Drop the return address on the stack and jump to the OSR entry
   // point of the function.
   __ Drop(1);
+#ifdef V8_ENABLE_CET_IBT
+  __ jmp(entry_address, /*notrack=*/true);
+#else
   __ jmp(entry_address);
+#endif
 }
 
 enum class OsrSourceTier {
