$NetBSD$

--- third_party/zlib/cpu_features.c.orig	2020-07-15 18:56:49.000000000 +0000
+++ third_party/zlib/cpu_features.c
@@ -25,7 +25,7 @@ int ZLIB_INTERNAL x86_cpu_enable_simd = 
 
 #ifndef CPU_NO_SIMD
 
-#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA)
+#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <pthread.h>
 #endif
 
