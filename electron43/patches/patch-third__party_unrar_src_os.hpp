$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/unrar/src/os.hpp.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/unrar/src/os.hpp
@@ -162,10 +162,13 @@
 
 #if defined(__aarch64__) && (defined(__ARM_FEATURE_CRYPTO) || defined(__ARM_FEATURE_CRC32))
 #include <arm_neon.h>
-#ifndef _APPLE
+#if !defined(_APPLE) && !defined(__FreeBSD__)
 #include <sys/auxv.h>
 #include <asm/hwcap.h>
 #endif
+#ifdef __FreeBSD__
+#include <machine/armreg.h>
+#endif
 #ifdef __ARM_FEATURE_CRYPTO
 #define USE_NEON_AES
 #endif
