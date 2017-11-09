$NetBSD$

--- lib/Driver/ToolChains/NetBSD.cpp.orig	2017-10-17 16:48:56.000000000 +0000
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -430,7 +430,9 @@ SanitizerMask NetBSD::getSupportedSaniti
   if (IsX86_64) {
     Res |= SanitizerKind::Fuzzer;
     Res |= SanitizerKind::FuzzerNoLink;
+    Res |= SanitizerKind::Memory;
     Res |= SanitizerKind::Thread;
+    Res |= SanitizerKind::KernelAddress;
   }
   return Res;
 }
