$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/LzmaLib.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/LzmaLib.c
@@ -1,12 +1,14 @@
 /* LzmaLib.c -- LZMA library wrapper
-2015-06-13 : Igor Pavlov : Public domain */
+2023-04-02 : Igor Pavlov : Public domain */
+
+#include "Precomp.h"
 
 #include "Alloc.h"
 #include "LzmaDec.h"
 #include "LzmaEnc.h"
 #include "LzmaLib.h"
 
-MY_STDAPI LzmaCompress(unsigned char *dest, size_t *destLen, const unsigned char *src, size_t srcLen,
+Z7_STDAPI LzmaCompress(unsigned char *dest, size_t *destLen, const unsigned char *src, size_t srcLen,
   unsigned char *outProps, size_t *outPropsSize,
   int level, /* 0 <= level <= 9, default = 5 */
   unsigned dictSize, /* use (1 << N) or (3 << N). 4 KB < dictSize <= 128 MB */
@@ -32,7 +34,7 @@ MY_STDAPI LzmaCompress(unsigned char *de
 }
 
 
-MY_STDAPI LzmaUncompress(unsigned char *dest, size_t *destLen, const unsigned char *src, size_t *srcLen,
+Z7_STDAPI LzmaUncompress(unsigned char *dest, size_t *destLen, const unsigned char *src, size_t *srcLen,
   const unsigned char *props, size_t propsSize)
 {
   ELzmaStatus status;
