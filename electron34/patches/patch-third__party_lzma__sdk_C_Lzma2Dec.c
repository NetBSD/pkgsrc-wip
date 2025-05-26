$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Lzma2Dec.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Lzma2Dec.c
@@ -1,5 +1,5 @@
 /* Lzma2Dec.c -- LZMA2 Decoder
-2021-02-09 : Igor Pavlov : Public domain */
+2024-03-01 : Igor Pavlov : Public domain */
 
 /* #define SHOW_DEBUG_INFO */
 
@@ -71,14 +71,14 @@ static SRes Lzma2Dec_GetOldProps(Byte pr
 SRes Lzma2Dec_AllocateProbs(CLzma2Dec *p, Byte prop, ISzAllocPtr alloc)
 {
   Byte props[LZMA_PROPS_SIZE];
-  RINOK(Lzma2Dec_GetOldProps(prop, props));
+  RINOK(Lzma2Dec_GetOldProps(prop, props))
   return LzmaDec_AllocateProbs(&p->decoder, props, LZMA_PROPS_SIZE, alloc);
 }
 
 SRes Lzma2Dec_Allocate(CLzma2Dec *p, Byte prop, ISzAllocPtr alloc)
 {
   Byte props[LZMA_PROPS_SIZE];
-  RINOK(Lzma2Dec_GetOldProps(prop, props));
+  RINOK(Lzma2Dec_GetOldProps(prop, props))
   return LzmaDec_Allocate(&p->decoder, props, LZMA_PROPS_SIZE, alloc);
 }
 
@@ -157,8 +157,10 @@ static unsigned Lzma2Dec_UpdateState(CLz
       p->decoder.prop.lp = (Byte)lp;
       return LZMA2_STATE_DATA;
     }
+
+    default:
+      return LZMA2_STATE_ERROR;
   }
-  return LZMA2_STATE_ERROR;
 }
 
 static void LzmaDec_UpdateWithUncompressed(CLzmaDec *p, const Byte *src, SizeT size)
@@ -474,8 +476,8 @@ SRes Lzma2Decode(Byte *dest, SizeT *dest
   SizeT outSize = *destLen, inSize = *srcLen;
   *destLen = *srcLen = 0;
   *status = LZMA_STATUS_NOT_SPECIFIED;
-  Lzma2Dec_Construct(&p);
-  RINOK(Lzma2Dec_AllocateProbs(&p, prop, alloc));
+  Lzma2Dec_CONSTRUCT(&p)
+  RINOK(Lzma2Dec_AllocateProbs(&p, prop, alloc))
   p.decoder.dic = dest;
   p.decoder.dicBufSize = outSize;
   Lzma2Dec_Init(&p);
@@ -487,3 +489,5 @@ SRes Lzma2Decode(Byte *dest, SizeT *dest
   Lzma2Dec_FreeProbs(&p, alloc);
   return res;
 }
+
+#undef PRF
