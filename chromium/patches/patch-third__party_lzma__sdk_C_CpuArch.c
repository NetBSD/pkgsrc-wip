$NetBSD: patch-third__party_lzma__sdk_C_CpuArch.c,v 1.1 2025/02/06 09:58:26 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/lzma_sdk/C/CpuArch.c.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/lzma_sdk/C/CpuArch.c
@@ -412,12 +412,40 @@ BoolInt CPU_IsSupported_SHA1(void) { ret
 BoolInt CPU_IsSupported_SHA2(void) { return APPLE_CRYPTO_SUPPORT_VAL; }
 BoolInt CPU_IsSupported_AES (void) { return APPLE_CRYPTO_SUPPORT_VAL; }
 
+#elif defined(__OpenBSD__)
+
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <machine/cpu.h>
+#include <machine/armreg.h>
+
+BoolInt CPU_IsSupported_NEON() { return 1; }
+
+#define MY_HWCAP_CHECK_FUNC_2(name1, name2) \
+  BoolInt CPU_IsSupported_ ## name1() { \
+    int isar0_mib[] = { CTL_MACHDEP, CPU_ID_AA64ISAR0 }; \
+    size_t len = sizeof(uint64_t); \
+    uint64_t cpu_id = 0; \
+    if (sysctl(isar0_mib, 2, &cpu_id, &len, NULL, 0) < 0) \
+      return 0; \
+    if (ID_AA64ISAR0_ ## name2(cpu_id) >= ID_AA64ISAR0_## name2 ##_BASE) \
+      return 1; \
+    return 0; \
+  }
+
+#define MY_HWCAP_CHECK_FUNC(name) \
+  MY_HWCAP_CHECK_FUNC_2(name, name)
+
+MY_HWCAP_CHECK_FUNC (CRC32)
+MY_HWCAP_CHECK_FUNC (SHA1)
+MY_HWCAP_CHECK_FUNC (SHA2)
+MY_HWCAP_CHECK_FUNC (AES)
 
 #else // __APPLE__
 
 #include <sys/auxv.h>
 
-#if !defined(ARMV8_OS_FUCHSIA)
+#if !defined(ARMV8_OS_FUCHSIA) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #define USE_HWCAP
 #endif // !defined(ARMV8_OS_FUCHSIA)
 
