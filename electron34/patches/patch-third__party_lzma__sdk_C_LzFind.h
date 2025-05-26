$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/LzFind.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/LzFind.h
@@ -1,8 +1,8 @@
 /* LzFind.h -- Match finder for LZ algorithms
-2021-07-13 : Igor Pavlov : Public domain */
+2024-01-22 : Igor Pavlov : Public domain */
 
-#ifndef __LZ_FIND_H
-#define __LZ_FIND_H
+#ifndef ZIP7_INC_LZ_FIND_H
+#define ZIP7_INC_LZ_FIND_H
 
 #include "7zTypes.h"
 
@@ -10,9 +10,9 @@ EXTERN_C_BEGIN
 
 typedef UInt32 CLzRef;
 
-typedef struct _CMatchFinder
+typedef struct
 {
-  Byte *buffer;
+  const Byte *buffer;
   UInt32 pos;
   UInt32 posLimit;
   UInt32 streamPos;  /* wrap over Zero is allowed (streamPos < pos). Use (UInt32)(streamPos - pos) */
@@ -32,8 +32,8 @@ typedef struct _CMatchFinder
   UInt32 hashMask;
   UInt32 cutValue;
 
-  Byte *bufferBase;
-  ISeqInStream *stream;
+  Byte *bufBase;
+  ISeqInStreamPtr stream;
   
   UInt32 blockSize;
   UInt32 keepSizeBefore;
@@ -43,7 +43,9 @@ typedef struct _CMatchFinder
   size_t directInputRem;
   UInt32 historySize;
   UInt32 fixedHashSize;
-  UInt32 hashSizeSum;
+  Byte numHashBytes_Min;
+  Byte numHashOutBits;
+  Byte _pad2_[2];
   SRes result;
   UInt32 crc[256];
   size_t numRefs;
@@ -69,24 +71,45 @@ void MatchFinder_ReadIfRequired(CMatchFi
 
 void MatchFinder_Construct(CMatchFinder *p);
 
-/* Conditions:
-     historySize <= 3 GB
-     keepAddBufferBefore + matchMaxLen + keepAddBufferAfter < 511MB
+/* (directInput = 0) is default value.
+   It's required to provide correct (directInput) value
+   before calling MatchFinder_Create().
+   You can set (directInput) by any of the following calls:
+     - MatchFinder_SET_DIRECT_INPUT_BUF()
+     - MatchFinder_SET_STREAM()
+     - MatchFinder_SET_STREAM_MODE()
 */
+
+#define MatchFinder_SET_DIRECT_INPUT_BUF(p, _src_, _srcLen_) { \
+  (p)->stream = NULL; \
+  (p)->directInput = 1; \
+  (p)->buffer = (_src_); \
+  (p)->directInputRem = (_srcLen_); }
+
+/*
+#define MatchFinder_SET_STREAM_MODE(p) { \
+  (p)->directInput = 0; }
+*/
+
+#define MatchFinder_SET_STREAM(p, _stream_) { \
+  (p)->stream = _stream_; \
+  (p)->directInput = 0; }
+
+
 int MatchFinder_Create(CMatchFinder *p, UInt32 historySize,
     UInt32 keepAddBufferBefore, UInt32 matchMaxLen, UInt32 keepAddBufferAfter,
     ISzAllocPtr alloc);
 void MatchFinder_Free(CMatchFinder *p, ISzAllocPtr alloc);
 void MatchFinder_Normalize3(UInt32 subValue, CLzRef *items, size_t numItems);
-// void MatchFinder_ReduceOffsets(CMatchFinder *p, UInt32 subValue);
 
 /*
-#define Inline_MatchFinder_InitPos(p, val) \
+#define MatchFinder_INIT_POS(p, val) \
     (p)->pos = (val); \
     (p)->streamPos = (val);
 */
 
-#define Inline_MatchFinder_ReduceOffsets(p, subValue) \
+// void MatchFinder_ReduceOffsets(CMatchFinder *p, UInt32 subValue);
+#define MatchFinder_REDUCE_OFFSETS(p, subValue) \
     (p)->pos -= (subValue); \
     (p)->streamPos -= (subValue);
 
@@ -107,7 +130,7 @@ typedef const Byte * (*Mf_GetPointerToCu
 typedef UInt32 * (*Mf_GetMatches_Func)(void *object, UInt32 *distances);
 typedef void (*Mf_Skip_Func)(void *object, UInt32);
 
-typedef struct _IMatchFinder
+typedef struct
 {
   Mf_Init_Func Init;
   Mf_GetNumAvailableBytes_Func GetNumAvailableBytes;
@@ -121,7 +144,8 @@ void MatchFinder_CreateVTable(CMatchFind
 void MatchFinder_Init_LowHash(CMatchFinder *p);
 void MatchFinder_Init_HighHash(CMatchFinder *p);
 void MatchFinder_Init_4(CMatchFinder *p);
-void MatchFinder_Init(CMatchFinder *p);
+// void MatchFinder_Init(CMatchFinder *p);
+void MatchFinder_Init(void *p);
 
 UInt32* Bt3Zip_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances);
 UInt32* Hc3Zip_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances);
