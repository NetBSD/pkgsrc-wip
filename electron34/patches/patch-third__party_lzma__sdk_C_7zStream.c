$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zStream.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zStream.c
@@ -1,5 +1,5 @@
 /* 7zStream.c -- 7z Stream functions
-2021-02-09 : Igor Pavlov : Public domain */
+2023-04-02 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -7,12 +7,33 @@
 
 #include "7zTypes.h"
 
-SRes SeqInStream_Read2(const ISeqInStream *stream, void *buf, size_t size, SRes errorType)
+
+SRes SeqInStream_ReadMax(ISeqInStreamPtr stream, void *buf, size_t *processedSize)
+{
+  size_t size = *processedSize;
+  *processedSize = 0;
+  while (size != 0)
+  {
+    size_t cur = size;
+    const SRes res = ISeqInStream_Read(stream, buf, &cur);
+    *processedSize += cur;
+    buf = (void *)((Byte *)buf + cur);
+    size -= cur;
+    if (res != SZ_OK)
+      return res;
+    if (cur == 0)
+      return SZ_OK;
+  }
+  return SZ_OK;
+}
+
+/*
+SRes SeqInStream_Read2(ISeqInStreamPtr stream, void *buf, size_t size, SRes errorType)
 {
   while (size != 0)
   {
     size_t processed = size;
-    RINOK(ISeqInStream_Read(stream, buf, &processed));
+    RINOK(ISeqInStream_Read(stream, buf, &processed))
     if (processed == 0)
       return errorType;
     buf = (void *)((Byte *)buf + processed);
@@ -21,42 +42,44 @@ SRes SeqInStream_Read2(const ISeqInStrea
   return SZ_OK;
 }
 
-SRes SeqInStream_Read(const ISeqInStream *stream, void *buf, size_t size)
+SRes SeqInStream_Read(ISeqInStreamPtr stream, void *buf, size_t size)
 {
   return SeqInStream_Read2(stream, buf, size, SZ_ERROR_INPUT_EOF);
 }
+*/
+
 
-SRes SeqInStream_ReadByte(const ISeqInStream *stream, Byte *buf)
+SRes SeqInStream_ReadByte(ISeqInStreamPtr stream, Byte *buf)
 {
   size_t processed = 1;
-  RINOK(ISeqInStream_Read(stream, buf, &processed));
+  RINOK(ISeqInStream_Read(stream, buf, &processed))
   return (processed == 1) ? SZ_OK : SZ_ERROR_INPUT_EOF;
 }
 
 
 
-SRes LookInStream_SeekTo(const ILookInStream *stream, UInt64 offset)
+SRes LookInStream_SeekTo(ILookInStreamPtr stream, UInt64 offset)
 {
   Int64 t = (Int64)offset;
   return ILookInStream_Seek(stream, &t, SZ_SEEK_SET);
 }
 
-SRes LookInStream_LookRead(const ILookInStream *stream, void *buf, size_t *size)
+SRes LookInStream_LookRead(ILookInStreamPtr stream, void *buf, size_t *size)
 {
   const void *lookBuf;
   if (*size == 0)
     return SZ_OK;
-  RINOK(ILookInStream_Look(stream, &lookBuf, size));
+  RINOK(ILookInStream_Look(stream, &lookBuf, size))
   memcpy(buf, lookBuf, *size);
   return ILookInStream_Skip(stream, *size);
 }
 
-SRes LookInStream_Read2(const ILookInStream *stream, void *buf, size_t size, SRes errorType)
+SRes LookInStream_Read2(ILookInStreamPtr stream, void *buf, size_t size, SRes errorType)
 {
   while (size != 0)
   {
     size_t processed = size;
-    RINOK(ILookInStream_Read(stream, buf, &processed));
+    RINOK(ILookInStream_Read(stream, buf, &processed))
     if (processed == 0)
       return errorType;
     buf = (void *)((Byte *)buf + processed);
@@ -65,16 +88,16 @@ SRes LookInStream_Read2(const ILookInStr
   return SZ_OK;
 }
 
-SRes LookInStream_Read(const ILookInStream *stream, void *buf, size_t size)
+SRes LookInStream_Read(ILookInStreamPtr stream, void *buf, size_t size)
 {
   return LookInStream_Read2(stream, buf, size, SZ_ERROR_INPUT_EOF);
 }
 
 
 
-#define GET_LookToRead2 CLookToRead2 *p = CONTAINER_FROM_VTBL(pp, CLookToRead2, vt);
+#define GET_LookToRead2  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(CLookToRead2)
 
-static SRes LookToRead2_Look_Lookahead(const ILookInStream *pp, const void **buf, size_t *size)
+static SRes LookToRead2_Look_Lookahead(ILookInStreamPtr pp, const void **buf, size_t *size)
 {
   SRes res = SZ_OK;
   GET_LookToRead2
@@ -93,7 +116,7 @@ static SRes LookToRead2_Look_Lookahead(c
   return res;
 }
 
-static SRes LookToRead2_Look_Exact(const ILookInStream *pp, const void **buf, size_t *size)
+static SRes LookToRead2_Look_Exact(ILookInStreamPtr pp, const void **buf, size_t *size)
 {
   SRes res = SZ_OK;
   GET_LookToRead2
@@ -113,14 +136,14 @@ static SRes LookToRead2_Look_Exact(const
   return res;
 }
 
-static SRes LookToRead2_Skip(const ILookInStream *pp, size_t offset)
+static SRes LookToRead2_Skip(ILookInStreamPtr pp, size_t offset)
 {
   GET_LookToRead2
   p->pos += offset;
   return SZ_OK;
 }
 
-static SRes LookToRead2_Read(const ILookInStream *pp, void *buf, size_t *size)
+static SRes LookToRead2_Read(ILookInStreamPtr pp, void *buf, size_t *size)
 {
   GET_LookToRead2
   size_t rem = p->size - p->pos;
@@ -134,7 +157,7 @@ static SRes LookToRead2_Read(const ILook
   return SZ_OK;
 }
 
-static SRes LookToRead2_Seek(const ILookInStream *pp, Int64 *pos, ESzSeek origin)
+static SRes LookToRead2_Seek(ILookInStreamPtr pp, Int64 *pos, ESzSeek origin)
 {
   GET_LookToRead2
   p->pos = p->size = 0;
@@ -153,9 +176,9 @@ void LookToRead2_CreateVTable(CLookToRea
 
 
 
-static SRes SecToLook_Read(const ISeqInStream *pp, void *buf, size_t *size)
+static SRes SecToLook_Read(ISeqInStreamPtr pp, void *buf, size_t *size)
 {
-  CSecToLook *p = CONTAINER_FROM_VTBL(pp, CSecToLook, vt);
+  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(CSecToLook)
   return LookInStream_LookRead(p->realStream, buf, size);
 }
 
@@ -164,9 +187,9 @@ void SecToLook_CreateVTable(CSecToLook *
   p->vt.Read = SecToLook_Read;
 }
 
-static SRes SecToRead_Read(const ISeqInStream *pp, void *buf, size_t *size)
+static SRes SecToRead_Read(ISeqInStreamPtr pp, void *buf, size_t *size)
 {
-  CSecToRead *p = CONTAINER_FROM_VTBL(pp, CSecToRead, vt);
+  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(CSecToRead)
   return ILookInStream_Read(p->realStream, buf, size);
 }
 
