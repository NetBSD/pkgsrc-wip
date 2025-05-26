$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Lzma2Dec.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Lzma2Dec.h
@@ -1,8 +1,8 @@
 /* Lzma2Dec.h -- LZMA2 Decoder
-2018-02-19 : Igor Pavlov : Public domain */
+2023-03-03 : Igor Pavlov : Public domain */
 
-#ifndef __LZMA2_DEC_H
-#define __LZMA2_DEC_H
+#ifndef ZIP7_INC_LZMA2_DEC_H
+#define ZIP7_INC_LZMA2_DEC_H
 
 #include "LzmaDec.h"
 
@@ -22,9 +22,10 @@ typedef struct
   CLzmaDec decoder;
 } CLzma2Dec;
 
-#define Lzma2Dec_Construct(p) LzmaDec_Construct(&(p)->decoder)
-#define Lzma2Dec_FreeProbs(p, alloc) LzmaDec_FreeProbs(&(p)->decoder, alloc)
-#define Lzma2Dec_Free(p, alloc) LzmaDec_Free(&(p)->decoder, alloc)
+#define Lzma2Dec_CONSTRUCT(p)  LzmaDec_CONSTRUCT(&(p)->decoder)
+#define Lzma2Dec_Construct(p)  Lzma2Dec_CONSTRUCT(p)
+#define Lzma2Dec_FreeProbs(p, alloc)  LzmaDec_FreeProbs(&(p)->decoder, alloc)
+#define Lzma2Dec_Free(p, alloc)  LzmaDec_Free(&(p)->decoder, alloc)
 
 SRes Lzma2Dec_AllocateProbs(CLzma2Dec *p, Byte prop, ISzAllocPtr alloc);
 SRes Lzma2Dec_Allocate(CLzma2Dec *p, Byte prop, ISzAllocPtr alloc);
@@ -90,7 +91,7 @@ Lzma2Dec_GetUnpackExtra() returns the va
     at current input positon.
 */
 
-#define Lzma2Dec_GetUnpackExtra(p) ((p)->isExtraMode ? (p)->unpackSize : 0);
+#define Lzma2Dec_GetUnpackExtra(p)  ((p)->isExtraMode ? (p)->unpackSize : 0)
 
 
 /* ---------- One Call Interface ---------- */
