$NetBSD$

--- lib/Driver/ToolChains/NetBSD.cpp.orig	2017-08-29 00:48:11.000000000 +0000
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -431,6 +431,7 @@ SanitizerMask NetBSD::getSupportedSaniti
     Res |= SanitizerKind::Fuzzer;
     Res |= SanitizerKind::FuzzerNoLink;
     Res |= SanitizerKind::Thread;
+    Res |= SanitizerKind::KernelAddress;
   }
   return Res;
 }
