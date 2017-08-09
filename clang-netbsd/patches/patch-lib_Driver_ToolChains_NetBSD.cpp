$NetBSD$

--- lib/Driver/ToolChains/NetBSD.cpp.orig	2017-08-03 20:23:21.000000000 +0000
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -417,10 +417,18 @@ void NetBSD::addLibStdCxxIncludePaths(co
 }
 
 SanitizerMask NetBSD::getSupportedSanitizers() const {
+  const bool IsX86 = getTriple().getArch() == llvm::Triple::x86;
   const bool IsX86_64 = getTriple().getArch() == llvm::Triple::x86_64;
   SanitizerMask Res = ToolChain::getSupportedSanitizers();
-  if (IsX86_64) {
+  if (IsX86 || IsX86_64) {
     Res |= SanitizerKind::Address;
+    Res |= SanitizerKind::Function;
+    Res |= SanitizerKind::Leak;
+    Res |= SanitizerKind::SafeStack;
+    Res |= SanitizerKind::Vptr;
+  }
+  if (IsX86_64) {
+    Res |= SanitizerKind::Thread;
   }
   return Res;
 }
