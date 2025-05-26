$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Xz.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Xz.h
@@ -1,21 +1,24 @@
 /* Xz.h - Xz interface
-2021-04-01 : Igor Pavlov : Public domain */
+2024-01-26 : Igor Pavlov : Public domain */
 
-#ifndef __XZ_H
-#define __XZ_H
+#ifndef ZIP7_INC_XZ_H
+#define ZIP7_INC_XZ_H
 
 #include "Sha256.h"
+#include "Delta.h"
 
 EXTERN_C_BEGIN
 
 #define XZ_ID_Subblock 1
 #define XZ_ID_Delta 3
-#define XZ_ID_X86 4
-#define XZ_ID_PPC 5
-#define XZ_ID_IA64 6
-#define XZ_ID_ARM 7
-#define XZ_ID_ARMT 8
+#define XZ_ID_X86   4
+#define XZ_ID_PPC   5
+#define XZ_ID_IA64  6
+#define XZ_ID_ARM   7
+#define XZ_ID_ARMT  8
 #define XZ_ID_SPARC 9
+#define XZ_ID_ARM64 0xa
+#define XZ_ID_RISCV 0xb
 #define XZ_ID_LZMA2 0x21
 
 unsigned Xz_ReadVarInt(const Byte *p, size_t maxSize, UInt64 *value);
@@ -53,7 +56,7 @@ typedef struct
 #define XzBlock_HasUnsupportedFlags(p) (((p)->flags & ~(XZ_BF_NUM_FILTERS_MASK | XZ_BF_PACK_SIZE | XZ_BF_UNPACK_SIZE)) != 0)
 
 SRes XzBlock_Parse(CXzBlock *p, const Byte *header);
-SRes XzBlock_ReadHeader(CXzBlock *p, ISeqInStream *inStream, BoolInt *isIndex, UInt32 *headerSizeRes);
+SRes XzBlock_ReadHeader(CXzBlock *p, ISeqInStreamPtr inStream, BoolInt *isIndex, UInt32 *headerSizeRes);
 
 /* ---------- xz stream ---------- */
 
@@ -101,7 +104,7 @@ typedef UInt16 CXzStreamFlags;
 unsigned XzFlags_GetCheckSize(CXzStreamFlags f);
 
 SRes Xz_ParseHeader(CXzStreamFlags *p, const Byte *buf);
-SRes Xz_ReadHeader(CXzStreamFlags *p, ISeqInStream *inStream);
+SRes Xz_ReadHeader(CXzStreamFlags *p, ISeqInStreamPtr inStream);
 
 typedef struct
 {
@@ -112,6 +115,7 @@ typedef struct
 typedef struct
 {
   CXzStreamFlags flags;
+  // Byte _pad[6];
   size_t numBlocks;
   CXzBlockSizes *blocks;
   UInt64 startOffset;
@@ -134,7 +138,7 @@ typedef struct
 
 void Xzs_Construct(CXzs *p);
 void Xzs_Free(CXzs *p, ISzAllocPtr alloc);
-SRes Xzs_ReadBackward(CXzs *p, ILookInStream *inStream, Int64 *startOffset, ICompressProgress *progress, ISzAllocPtr alloc);
+SRes Xzs_ReadBackward(CXzs *p, ILookInStreamPtr inStream, Int64 *startOffset, ICompressProgressPtr progress, ISzAllocPtr alloc);
 
 UInt64 Xzs_GetNumBlocks(const CXzs *p);
 UInt64 Xzs_GetUnpackSize(const CXzs *p);
@@ -160,9 +164,9 @@ typedef enum
 } ECoderFinishMode;
 
 
-typedef struct _IStateCoder
+typedef struct
 {
-  void *p;
+  void *p; // state object;
   void (*Free)(void *p, ISzAllocPtr alloc);
   SRes (*SetProps)(void *p, const Byte *props, size_t propSize, ISzAllocPtr alloc);
   void (*Init)(void *p);
@@ -174,6 +178,20 @@ typedef struct _IStateCoder
 } IStateCoder;
 
 
+typedef struct
+{
+  UInt32 methodId;
+  UInt32 delta;
+  UInt32 ip;
+  UInt32 X86_State;
+  Byte delta_State[DELTA_STATE_SIZE];
+} CXzBcFilterStateBase;
+
+typedef SizeT (*Xz_Func_BcFilterStateBase_Filter)(CXzBcFilterStateBase *p, Byte *data, SizeT size);
+
+SRes Xz_StateCoder_Bc_SetFromMethod_Func(IStateCoder *p, UInt64 id,
+    Xz_Func_BcFilterStateBase_Filter func, ISzAllocPtr alloc);
+
 
 #define MIXCODER_NUM_FILTERS_MAX 4
 
@@ -216,13 +234,13 @@ typedef enum
 typedef struct
 {
   EXzState state;
-  UInt32 pos;
+  unsigned pos;
   unsigned alignPos;
   unsigned indexPreSize;
 
   CXzStreamFlags streamFlags;
   
-  UInt32 blockHeaderSize;
+  unsigned blockHeaderSize;
   UInt64 packSize;
   UInt64 unpackSize;
 
@@ -422,7 +440,7 @@ typedef struct
   size_t outStep_ST;      // size of output buffer for Single-Thread decoding
   BoolInt ignoreErrors;   // if set to 1, the decoder can ignore some errors and it skips broken parts of data.
   
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   unsigned numThreads;    // the number of threads for Multi-Thread decoding. if (umThreads == 1) it will use Single-thread decoding
   size_t inBufSize_MT;    // size of small input data buffers for Multi-Thread decoding. Big number of such small buffers can be created
   size_t memUseMax;       // the limit of total memory usage for Multi-Thread decoding.
@@ -432,8 +450,9 @@ typedef struct
 
 void XzDecMtProps_Init(CXzDecMtProps *p);
 
-
-typedef void * CXzDecMtHandle;
+typedef struct CXzDecMt CXzDecMt;
+typedef CXzDecMt * CXzDecMtHandle;
+// Z7_DECLARE_HANDLE(CXzDecMtHandle)
 
 /*
   alloc    : XzDecMt uses CAlignOffsetAlloc internally for addresses allocated by (alloc).
@@ -503,14 +522,14 @@ SRes XzDecMt_Decode(CXzDecMtHandle p,
     const CXzDecMtProps *props,
     const UInt64 *outDataSize, // NULL means undefined
     int finishMode,            // 0 - partial unpacking is allowed, 1 - xz stream(s) must be finished
-    ISeqOutStream *outStream,
+    ISeqOutStreamPtr outStream,
     // Byte *outBuf, size_t *outBufSize,
-    ISeqInStream *inStream,
+    ISeqInStreamPtr inStream,
     // const Byte *inData, size_t inDataSize,
     CXzStatInfo *stat,         // out: decoding results and statistics
     int *isMT,                 // out: 0 means that ST (Single-Thread) version was used
                                //      1 means that MT (Multi-Thread) version was used
-    ICompressProgress *progress);
+    ICompressProgressPtr progress);
 
 EXTERN_C_END
 
