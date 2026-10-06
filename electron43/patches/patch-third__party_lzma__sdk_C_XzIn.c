$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/XzIn.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/XzIn.c
@@ -1,5 +1,5 @@
 /* XzIn.c - Xz input
-2021-09-04 : Igor Pavlov : Public domain */
+2023-09-07 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -15,27 +15,29 @@
 #define XZ_FOOTER_SIG_CHECK(p) ((p)[0] == XZ_FOOTER_SIG_0 && (p)[1] == XZ_FOOTER_SIG_1)
 
 
-SRes Xz_ReadHeader(CXzStreamFlags *p, ISeqInStream *inStream)
+SRes Xz_ReadHeader(CXzStreamFlags *p, ISeqInStreamPtr inStream)
 {
   Byte sig[XZ_STREAM_HEADER_SIZE];
-  RINOK(SeqInStream_Read2(inStream, sig, XZ_STREAM_HEADER_SIZE, SZ_ERROR_NO_ARCHIVE));
-  if (memcmp(sig, XZ_SIG, XZ_SIG_SIZE) != 0)
+  size_t processedSize = XZ_STREAM_HEADER_SIZE;
+  RINOK(SeqInStream_ReadMax(inStream, sig, &processedSize))
+  if (processedSize != XZ_STREAM_HEADER_SIZE
+      || memcmp(sig, XZ_SIG, XZ_SIG_SIZE) != 0)
     return SZ_ERROR_NO_ARCHIVE;
   return Xz_ParseHeader(p, sig);
 }
 
 #define READ_VARINT_AND_CHECK(buf, pos, size, res) \
-  { unsigned s = Xz_ReadVarInt(buf + pos, size - pos, res); \
+  { const unsigned s = Xz_ReadVarInt(buf + pos, size - pos, res); \
   if (s == 0) return SZ_ERROR_ARCHIVE; \
   pos += s; }
 
-SRes XzBlock_ReadHeader(CXzBlock *p, ISeqInStream *inStream, BoolInt *isIndex, UInt32 *headerSizeRes)
+SRes XzBlock_ReadHeader(CXzBlock *p, ISeqInStreamPtr inStream, BoolInt *isIndex, UInt32 *headerSizeRes)
 {
   Byte header[XZ_BLOCK_HEADER_SIZE_MAX];
   unsigned headerSize;
   *headerSizeRes = 0;
-  RINOK(SeqInStream_ReadByte(inStream, &header[0]));
-  headerSize = (unsigned)header[0];
+  RINOK(SeqInStream_ReadByte(inStream, &header[0]))
+  headerSize = header[0];
   if (headerSize == 0)
   {
     *headerSizeRes = 1;
@@ -45,20 +47,27 @@ SRes XzBlock_ReadHeader(CXzBlock *p, ISe
 
   *isIndex = False;
   headerSize = (headerSize << 2) + 4;
-  *headerSizeRes = headerSize;
-  RINOK(SeqInStream_Read(inStream, header + 1, headerSize - 1));
+  *headerSizeRes = (UInt32)headerSize;
+  {
+    size_t processedSize = headerSize - 1;
+    RINOK(SeqInStream_ReadMax(inStream, header + 1, &processedSize))
+    if (processedSize != headerSize - 1)
+      return SZ_ERROR_INPUT_EOF;
+  }
   return XzBlock_Parse(p, header);
 }
 
 #define ADD_SIZE_CHECK(size, val) \
-  { UInt64 newSize = size + (val); if (newSize < size) return XZ_SIZE_OVERFLOW; size = newSize; }
+  { const UInt64 newSize = size + (val); if (newSize < size) return XZ_SIZE_OVERFLOW; size = newSize; }
 
 UInt64 Xz_GetUnpackSize(const CXzStream *p)
 {
   UInt64 size = 0;
   size_t i;
   for (i = 0; i < p->numBlocks; i++)
-    ADD_SIZE_CHECK(size, p->blocks[i].unpackSize);
+  {
+    ADD_SIZE_CHECK(size, p->blocks[i].unpackSize)
+  }
   return size;
 }
 
@@ -67,12 +76,14 @@ UInt64 Xz_GetPackSize(const CXzStream *p
   UInt64 size = 0;
   size_t i;
   for (i = 0; i < p->numBlocks; i++)
-    ADD_SIZE_CHECK(size, (p->blocks[i].totalSize + 3) & ~(UInt64)3);
+  {
+    ADD_SIZE_CHECK(size, (p->blocks[i].totalSize + 3) & ~(UInt64)3)
+  }
   return size;
 }
 
 /*
-SRes XzBlock_ReadFooter(CXzBlock *p, CXzStreamFlags f, ISeqInStream *inStream)
+SRes XzBlock_ReadFooter(CXzBlock *p, CXzStreamFlags f, ISeqInStreamPtr inStream)
 {
   return SeqInStream_Read(inStream, p->check, XzFlags_GetCheckSize(f));
 }
@@ -93,7 +104,7 @@ static SRes Xz_ReadIndex2(CXzStream *p, 
 
   {
     UInt64 numBlocks64;
-    READ_VARINT_AND_CHECK(buf, pos, size, &numBlocks64);
+    READ_VARINT_AND_CHECK(buf, pos, size, &numBlocks64)
     numBlocks = (size_t)numBlocks64;
     if (numBlocks != numBlocks64 || numBlocks * 2 > size)
       return SZ_ERROR_ARCHIVE;
@@ -110,8 +121,8 @@ static SRes Xz_ReadIndex2(CXzStream *p, 
     for (i = 0; i < numBlocks; i++)
     {
       CXzBlockSizes *block = &p->blocks[i];
-      READ_VARINT_AND_CHECK(buf, pos, size, &block->totalSize);
-      READ_VARINT_AND_CHECK(buf, pos, size, &block->unpackSize);
+      READ_VARINT_AND_CHECK(buf, pos, size, &block->totalSize)
+      READ_VARINT_AND_CHECK(buf, pos, size, &block->unpackSize)
       if (block->totalSize == 0)
         return SZ_ERROR_ARCHIVE;
     }
@@ -122,7 +133,7 @@ static SRes Xz_ReadIndex2(CXzStream *p, 
   return (pos == size) ? SZ_OK : SZ_ERROR_ARCHIVE;
 }
 
-static SRes Xz_ReadIndex(CXzStream *p, ILookInStream *stream, UInt64 indexSize, ISzAllocPtr alloc)
+static SRes Xz_ReadIndex(CXzStream *p, ILookInStreamPtr stream, UInt64 indexSize, ISzAllocPtr alloc)
 {
   SRes res;
   size_t size;
@@ -142,14 +153,14 @@ static SRes Xz_ReadIndex(CXzStream *p, I
   return res;
 }
 
-static SRes LookInStream_SeekRead_ForArc(ILookInStream *stream, UInt64 offset, void *buf, size_t size)
+static SRes LookInStream_SeekRead_ForArc(ILookInStreamPtr stream, UInt64 offset, void *buf, size_t size)
 {
-  RINOK(LookInStream_SeekTo(stream, offset));
+  RINOK(LookInStream_SeekTo(stream, offset))
   return LookInStream_Read(stream, buf, size);
   /* return LookInStream_Read2(stream, buf, size, SZ_ERROR_NO_ARCHIVE); */
 }
 
-static SRes Xz_ReadBackward(CXzStream *p, ILookInStream *stream, Int64 *startOffset, ISzAllocPtr alloc)
+static SRes Xz_ReadBackward(CXzStream *p, ILookInStreamPtr stream, Int64 *startOffset, ISzAllocPtr alloc)
 {
   UInt64 indexSize;
   Byte buf[XZ_STREAM_FOOTER_SIZE];
@@ -159,7 +170,7 @@ static SRes Xz_ReadBackward(CXzStream *p
     return SZ_ERROR_NO_ARCHIVE;
 
   pos -= XZ_STREAM_FOOTER_SIZE;
-  RINOK(LookInStream_SeekRead_ForArc(stream, pos, buf, XZ_STREAM_FOOTER_SIZE));
+  RINOK(LookInStream_SeekRead_ForArc(stream, pos, buf, XZ_STREAM_FOOTER_SIZE))
   
   if (!XZ_FOOTER_SIG_CHECK(buf + 10))
   {
@@ -174,7 +185,7 @@ static SRes Xz_ReadBackward(CXzStream *p
       
       i = (pos > TEMP_BUF_SIZE) ? TEMP_BUF_SIZE : (size_t)pos;
       pos -= i;
-      RINOK(LookInStream_SeekRead_ForArc(stream, pos, temp, i));
+      RINOK(LookInStream_SeekRead_ForArc(stream, pos, temp, i))
       total += (UInt32)i;
       for (; i != 0; i--)
         if (temp[i - 1] != 0)
@@ -193,7 +204,7 @@ static SRes Xz_ReadBackward(CXzStream *p
     if (pos < XZ_STREAM_FOOTER_SIZE)
       return SZ_ERROR_NO_ARCHIVE;
     pos -= XZ_STREAM_FOOTER_SIZE;
-    RINOK(LookInStream_SeekRead_ForArc(stream, pos, buf, XZ_STREAM_FOOTER_SIZE));
+    RINOK(LookInStream_SeekRead_ForArc(stream, pos, buf, XZ_STREAM_FOOTER_SIZE))
     if (!XZ_FOOTER_SIG_CHECK(buf + 10))
       return SZ_ERROR_NO_ARCHIVE;
   }
@@ -217,8 +228,8 @@ static SRes Xz_ReadBackward(CXzStream *p
     return SZ_ERROR_ARCHIVE;
 
   pos -= indexSize;
-  RINOK(LookInStream_SeekTo(stream, pos));
-  RINOK(Xz_ReadIndex(p, stream, indexSize, alloc));
+  RINOK(LookInStream_SeekTo(stream, pos))
+  RINOK(Xz_ReadIndex(p, stream, indexSize, alloc))
 
   {
     UInt64 totalSize = Xz_GetPackSize(p);
@@ -227,7 +238,7 @@ static SRes Xz_ReadBackward(CXzStream *p
         || pos < totalSize + XZ_STREAM_HEADER_SIZE)
       return SZ_ERROR_ARCHIVE;
     pos -= (totalSize + XZ_STREAM_HEADER_SIZE);
-    RINOK(LookInStream_SeekTo(stream, pos));
+    RINOK(LookInStream_SeekTo(stream, pos))
     *startOffset = (Int64)pos;
   }
   {
@@ -236,7 +247,7 @@ static SRes Xz_ReadBackward(CXzStream *p
     SecToRead_CreateVTable(&secToRead);
     secToRead.realStream = stream;
 
-    RINOK(Xz_ReadHeader(&headerFlags, &secToRead.vt));
+    RINOK(Xz_ReadHeader(&headerFlags, &secToRead.vt))
     return (p->flags == headerFlags) ? SZ_OK : SZ_ERROR_ARCHIVE;
   }
 }
@@ -274,7 +285,9 @@ UInt64 Xzs_GetUnpackSize(const CXzs *p)
   UInt64 size = 0;
   size_t i;
   for (i = 0; i < p->num; i++)
-    ADD_SIZE_CHECK(size, Xz_GetUnpackSize(&p->streams[i]));
+  {
+    ADD_SIZE_CHECK(size, Xz_GetUnpackSize(&p->streams[i]))
+  }
   return size;
 }
 
@@ -284,15 +297,17 @@ UInt64 Xzs_GetPackSize(const CXzs *p)
   UInt64 size = 0;
   size_t i;
   for (i = 0; i < p->num; i++)
-    ADD_SIZE_CHECK(size, Xz_GetTotalSize(&p->streams[i]));
+  {
+    ADD_SIZE_CHECK(size, Xz_GetTotalSize(&p->streams[i]))
+  }
   return size;
 }
 */
 
-SRes Xzs_ReadBackward(CXzs *p, ILookInStream *stream, Int64 *startOffset, ICompressProgress *progress, ISzAllocPtr alloc)
+SRes Xzs_ReadBackward(CXzs *p, ILookInStreamPtr stream, Int64 *startOffset, ICompressProgressPtr progress, ISzAllocPtr alloc)
 {
   Int64 endOffset = 0;
-  RINOK(ILookInStream_Seek(stream, &endOffset, SZ_SEEK_END));
+  RINOK(ILookInStream_Seek(stream, &endOffset, SZ_SEEK_END))
   *startOffset = endOffset;
   for (;;)
   {
@@ -301,7 +316,7 @@ SRes Xzs_ReadBackward(CXzs *p, ILookInSt
     Xz_Construct(&st);
     res = Xz_ReadBackward(&st, stream, startOffset, alloc);
     st.startOffset = (UInt64)*startOffset;
-    RINOK(res);
+    RINOK(res)
     if (p->num == p->numAllocated)
     {
       const size_t newNum = p->num + p->num / 4 + 1;
@@ -317,7 +332,7 @@ SRes Xzs_ReadBackward(CXzs *p, ILookInSt
     p->streams[p->num++] = st;
     if (*startOffset == 0)
       break;
-    RINOK(LookInStream_SeekTo(stream, (UInt64)*startOffset));
+    RINOK(LookInStream_SeekTo(stream, (UInt64)*startOffset))
     if (progress && ICompressProgress_Progress(progress, (UInt64)(endOffset - *startOffset), (UInt64)(Int64)-1) != SZ_OK)
       return SZ_ERROR_PROGRESS;
   }
