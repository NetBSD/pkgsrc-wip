$NetBSD$

--- lib/Driver/ToolChains/NetBSD.cpp.orig	2017-08-19 15:58:01.065451438 +0000
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -428,6 +428,8 @@ SanitizerMask NetBSD::getSupportedSaniti
     Res |= SanitizerKind::Vptr;
   }
   if (IsX86_64) {
+    Res |= SanitizerKind::Fuzzer;
+    Res |= SanitizerKind::FuzzerNoLink;
     Res |= SanitizerKind::Thread;
   }
   return Res;
