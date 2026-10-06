$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/LzmaDec.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/LzmaDec.h
@@ -1,19 +1,19 @@
 /* LzmaDec.h -- LZMA Decoder
-2020-03-19 : Igor Pavlov : Public domain */
+2023-04-02 : Igor Pavlov : Public domain */
 
-#ifndef __LZMA_DEC_H
-#define __LZMA_DEC_H
+#ifndef ZIP7_INC_LZMA_DEC_H
+#define ZIP7_INC_LZMA_DEC_H
 
 #include "7zTypes.h"
 
 EXTERN_C_BEGIN
 
-/* #define _LZMA_PROB32 */
-/* _LZMA_PROB32 can increase the speed on some CPUs,
+/* #define Z7_LZMA_PROB32 */
+/* Z7_LZMA_PROB32 can increase the speed on some CPUs,
    but memory usage for CLzmaDec::probs will be doubled in that case */
 
 typedef
-#ifdef _LZMA_PROB32
+#ifdef Z7_LZMA_PROB32
   UInt32
 #else
   UInt16
@@ -25,7 +25,7 @@ typedef
 
 #define LZMA_PROPS_SIZE 5
 
-typedef struct _CLzmaProps
+typedef struct
 {
   Byte lc;
   Byte lp;
@@ -73,7 +73,8 @@ typedef struct
   Byte tempBuf[LZMA_REQUIRED_INPUT_MAX];
 } CLzmaDec;
 
-#define LzmaDec_Construct(p) { (p)->dic = NULL; (p)->probs = NULL; }
+#define LzmaDec_CONSTRUCT(p) { (p)->dic = NULL; (p)->probs = NULL; }
+#define LzmaDec_Construct(p) LzmaDec_CONSTRUCT(p)
 
 void LzmaDec_Init(CLzmaDec *p);
 
