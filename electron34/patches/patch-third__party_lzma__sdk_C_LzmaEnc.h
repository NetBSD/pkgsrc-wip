$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/LzmaEnc.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/LzmaEnc.h
@@ -1,8 +1,8 @@
 /*  LzmaEnc.h -- LZMA Encoder
-2019-10-30 : Igor Pavlov : Public domain */
+2023-04-13 : Igor Pavlov : Public domain */
 
-#ifndef __LZMA_ENC_H
-#define __LZMA_ENC_H
+#ifndef ZIP7_INC_LZMA_ENC_H
+#define ZIP7_INC_LZMA_ENC_H
 
 #include "7zTypes.h"
 
@@ -10,7 +10,7 @@ EXTERN_C_BEGIN
 
 #define LZMA_PROPS_SIZE 5
 
-typedef struct _CLzmaEncProps
+typedef struct
 {
   int level;       /* 0 <= level <= 9 */
   UInt32 dictSize; /* (1 << 12) <= dictSize <= (1 << 27) for 32-bit version
@@ -23,10 +23,13 @@ typedef struct _CLzmaEncProps
   int fb;          /* 5 <= fb <= 273, default = 32 */
   int btMode;      /* 0 - hashChain Mode, 1 - binTree mode - normal, default = 1 */
   int numHashBytes; /* 2, 3 or 4, default = 4 */
+  unsigned numHashOutBits;  /* default = ? */
   UInt32 mc;       /* 1 <= mc <= (1 << 30), default = 32 */
   unsigned writeEndMark;  /* 0 - do not write EOPM, 1 - write EOPM, default = 0 */
   int numThreads;  /* 1 or 2, default = 2 */
 
+  // int _pad;
+
   UInt64 reduceSize; /* estimated size of data that will be compressed. default = (UInt64)(Int64)-1.
                         Encoder uses this value to reduce dictionary size */
 
@@ -51,7 +54,9 @@ SRes:
   SZ_ERROR_THREAD - error in multithreading functions (only for Mt version)
 */
 
-typedef void * CLzmaEncHandle;
+typedef struct CLzmaEnc CLzmaEnc;
+typedef CLzmaEnc * CLzmaEncHandle;
+// Z7_DECLARE_HANDLE(CLzmaEncHandle)
 
 CLzmaEncHandle LzmaEnc_Create(ISzAllocPtr alloc);
 void LzmaEnc_Destroy(CLzmaEncHandle p, ISzAllocPtr alloc, ISzAllocPtr allocBig);
@@ -61,17 +66,17 @@ void LzmaEnc_SetDataSize(CLzmaEncHandle 
 SRes LzmaEnc_WriteProperties(CLzmaEncHandle p, Byte *properties, SizeT *size);
 unsigned LzmaEnc_IsWriteEndMark(CLzmaEncHandle p);
 
-SRes LzmaEnc_Encode(CLzmaEncHandle p, ISeqOutStream *outStream, ISeqInStream *inStream,
-    ICompressProgress *progress, ISzAllocPtr alloc, ISzAllocPtr allocBig);
+SRes LzmaEnc_Encode(CLzmaEncHandle p, ISeqOutStreamPtr outStream, ISeqInStreamPtr inStream,
+    ICompressProgressPtr progress, ISzAllocPtr alloc, ISzAllocPtr allocBig);
 SRes LzmaEnc_MemEncode(CLzmaEncHandle p, Byte *dest, SizeT *destLen, const Byte *src, SizeT srcLen,
-    int writeEndMark, ICompressProgress *progress, ISzAllocPtr alloc, ISzAllocPtr allocBig);
+    int writeEndMark, ICompressProgressPtr progress, ISzAllocPtr alloc, ISzAllocPtr allocBig);
 
 
 /* ---------- One Call Interface ---------- */
 
 SRes LzmaEncode(Byte *dest, SizeT *destLen, const Byte *src, SizeT srcLen,
     const CLzmaEncProps *props, Byte *propsEncoded, SizeT *propsSize, int writeEndMark,
-    ICompressProgress *progress, ISzAllocPtr alloc, ISzAllocPtr allocBig);
+    ICompressProgressPtr progress, ISzAllocPtr alloc, ISzAllocPtr allocBig);
 
 EXTERN_C_END
 
