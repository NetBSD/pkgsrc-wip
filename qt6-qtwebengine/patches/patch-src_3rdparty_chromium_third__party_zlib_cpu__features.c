$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/zlib/cpu_features.c.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/zlib/cpu_features.c
@@ -35,7 +35,7 @@ int ZLIB_INTERNAL x86_cpu_enable_avx512 
 
 #ifndef CPU_NO_SIMD
 
-#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_IOS)
+#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_IOS) || defined(ARMV8_OS_OPENBSD) || defined(ARMV8_OS_FREEBSD)
 #include <pthread.h>
 #endif
 
@@ -52,6 +52,10 @@ int ZLIB_INTERNAL x86_cpu_enable_avx512 
 #include <windows.h>
 #elif defined(ARMV8_OS_IOS)
 #include <sys/sysctl.h>
+#elif defined(ARMV8_OS_OPENBSD)
+#include <sys/sysctl.h>
+#include <machine/cpu.h>
+#include <machine/armreg.h>
 #elif !defined(_MSC_VER)
 #include <pthread.h>
 #else
@@ -62,7 +66,7 @@ int ZLIB_INTERNAL x86_cpu_enable_avx512 
 static void _cpu_check_features(void);
 #endif
 
-#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_MACOS) || defined(ARMV8_OS_FUCHSIA) || defined(X86_NOT_WINDOWS) || defined(ARMV8_OS_IOS) || defined(__ARM_NEON__) || defined(__ARM_NEON)
+#if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || defined(ARMV8_OS_MACOS) || defined(ARMV8_OS_FUCHSIA) || defined(X86_NOT_WINDOWS) || defined(ARMV8_OS_IOS) || defined(__ARM_NEON__) || defined(__ARM_NEON) || defined(ARMV8_OS_OPENBSD) || defined(ARMV8_OS_FREEBSD)
 #if !defined(ARMV8_OS_MACOS)
 // _cpu_check_features() doesn't need to do anything on mac/arm since all
 // features are known at build time, so don't call it.
@@ -115,6 +119,17 @@ static void _cpu_check_features(void)
     unsigned long features = getauxval(AT_HWCAP2);
     arm_cpu_enable_crc32 = !!(features & HWCAP2_CRC32);
     arm_cpu_enable_pmull = !!(features & HWCAP2_PMULL);
+#elif defined(ARMV8_OS_OPENBSD)
+    int isar0_mib[] = { CTL_MACHDEP, CPU_ID_AA64ISAR0 };
+    uint64_t cpu_id = 0;
+    size_t len = sizeof(cpu_id);
+    if (sysctl(isar0_mib, 2, &cpu_id, &len, NULL, 0) < 0)
+        return;
+    if (ID_AA64ISAR0_AES(cpu_id) >= ID_AA64ISAR0_AES_PMULL)
+        arm_cpu_enable_pmull = 1;
+
+    if (ID_AA64ISAR0_CRC32(cpu_id) >= ID_AA64ISAR0_CRC32_BASE)
+        arm_cpu_enable_crc32 = 1;
 #elif defined(ARMV8_OS_FUCHSIA)
     uint32_t features;
     zx_status_t rc = zx_system_get_features(ZX_FEATURE_KIND_CPU, &features);
