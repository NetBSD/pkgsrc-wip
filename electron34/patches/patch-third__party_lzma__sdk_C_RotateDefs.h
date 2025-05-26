$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/RotateDefs.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/RotateDefs.h
@@ -1,14 +1,14 @@
 /* RotateDefs.h -- Rotate functions
-2015-03-25 : Igor Pavlov : Public domain */
+2023-06-18 : Igor Pavlov : Public domain */
 
-#ifndef __ROTATE_DEFS_H
-#define __ROTATE_DEFS_H
+#ifndef ZIP7_INC_ROTATE_DEFS_H
+#define ZIP7_INC_ROTATE_DEFS_H
 
 #ifdef _MSC_VER
 
 #include <stdlib.h>
 
-/* don't use _rotl with MINGW. It can insert slow call to function. */
+/* don't use _rotl with old MINGW. It can insert slow call to function. */
  
 /* #if (_MSC_VER >= 1200) */
 #pragma intrinsic(_rotl)
@@ -18,12 +18,32 @@
 #define rotlFixed(x, n) _rotl((x), (n))
 #define rotrFixed(x, n) _rotr((x), (n))
 
+#if (_MSC_VER >= 1300)
+#define Z7_ROTL64(x, n) _rotl64((x), (n))
+#define Z7_ROTR64(x, n) _rotr64((x), (n))
+#else
+#define Z7_ROTL64(x, n) (((x) << (n)) | ((x) >> (64 - (n))))
+#define Z7_ROTR64(x, n) (((x) >> (n)) | ((x) << (64 - (n))))
+#endif
+
 #else
 
 /* new compilers can translate these macros to fast commands. */
 
+#if defined(__clang__) && (__clang_major__ >= 4) \
+  || defined(__GNUC__) && (__GNUC__ >= 5)
+/* GCC 4.9.0 and clang 3.5 can recognize more correct version: */
+#define rotlFixed(x, n) (((x) << (n)) | ((x) >> (-(n) & 31)))
+#define rotrFixed(x, n) (((x) >> (n)) | ((x) << (-(n) & 31)))
+#define Z7_ROTL64(x, n) (((x) << (n)) | ((x) >> (-(n) & 63)))
+#define Z7_ROTR64(x, n) (((x) >> (n)) | ((x) << (-(n) & 63)))
+#else
+/* for old GCC / clang: */
 #define rotlFixed(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
 #define rotrFixed(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
+#define Z7_ROTL64(x, n) (((x) << (n)) | ((x) >> (64 - (n))))
+#define Z7_ROTR64(x, n) (((x) >> (n)) | ((x) << (64 - (n))))
+#endif
 
 #endif
 
