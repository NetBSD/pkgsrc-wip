$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/histogram/src/hdr_histogram.c.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/histogram/src/hdr_histogram.c
@@ -36,8 +36,10 @@
 
 /* Runtime-dispatched AVX2 path: keep the rest of this TU at the project's
    baseline ISA so the shipped binary does not silently require AVX2. */
-#if (defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)) \
-    && (defined(__GNUC__) || defined(__clang__)) && !defined(__INTEL_COMPILER) && !defined(_MSC_VER)
+/* NetBSD + clang: hdr_histogram.c:(.text+0x43): undefined reference to `__cpu_model' */
+#if (defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86)) \
+     && (defined(__GNUC__) || defined(__clang__)) && !defined(__INTEL_COMPILER) && !defined(_MSC_VER) \
+     && !defined(__NetBSD__)
 #  define HDR_HAS_AVX2_DISPATCH 1
 #  include <immintrin.h>
 #endif
