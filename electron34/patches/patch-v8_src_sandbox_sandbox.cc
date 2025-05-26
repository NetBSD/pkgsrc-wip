$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/sandbox/sandbox.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/src/sandbox/sandbox.cc
@@ -50,7 +50,7 @@ static Address DetermineAddressSpaceLimi
   }
 #endif  // V8_TARGET_ARCH_X64
 
-#if defined(V8_TARGET_ARCH_ARM64) && defined(V8_TARGET_OS_ANDROID)
+#if defined(V8_TARGET_ARCH_ARM64) && (defined(V8_TARGET_OS_ANDROID) || defined(V8_TARGET_OS_OPENBSD))
   // On Arm64 Android assume a 40-bit virtual address space (39 bits for
   // userspace and kernel each) as that appears to be the most common
   // configuration and there seems to be no easy way to retrieve the actual
