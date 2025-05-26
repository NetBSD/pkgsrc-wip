$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/LzmaLib.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/LzmaLib.h
@@ -1,14 +1,14 @@
 /* LzmaLib.h -- LZMA library interface
-2021-04-03 : Igor Pavlov : Public domain */
+2023-04-02 : Igor Pavlov : Public domain */
 
-#ifndef __LZMA_LIB_H
-#define __LZMA_LIB_H
+#ifndef ZIP7_INC_LZMA_LIB_H
+#define ZIP7_INC_LZMA_LIB_H
 
 #include "7zTypes.h"
 
 EXTERN_C_BEGIN
 
-#define MY_STDAPI int MY_STD_CALL
+#define Z7_STDAPI int Z7_STDCALL
 
 #define LZMA_PROPS_SIZE 5
 
@@ -100,7 +100,7 @@ Returns:
   SZ_ERROR_THREAD     - errors in multithreading functions (only for Mt version)
 */
 
-MY_STDAPI LzmaCompress(unsigned char *dest, size_t *destLen, const unsigned char *src, size_t srcLen,
+Z7_STDAPI LzmaCompress(unsigned char *dest, size_t *destLen, const unsigned char *src, size_t srcLen,
   unsigned char *outProps, size_t *outPropsSize, /* *outPropsSize must be = 5 */
   int level,      /* 0 <= level <= 9, default = 5 */
   unsigned dictSize,  /* default = (1 << 24) */
@@ -130,7 +130,7 @@ Returns:
   SZ_ERROR_INPUT_EOF   - it needs more bytes in input buffer (src)
 */
 
-MY_STDAPI LzmaUncompress(unsigned char *dest, size_t *destLen, const unsigned char *src, SizeT *srcLen,
+Z7_STDAPI LzmaUncompress(unsigned char *dest, size_t *destLen, const unsigned char *src, SizeT *srcLen,
   const unsigned char *props, size_t propsSize);
 
 EXTERN_C_END
