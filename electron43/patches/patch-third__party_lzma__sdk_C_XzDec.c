$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/XzDec.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/XzDec.c
@@ -1,5 +1,5 @@
 /* XzDec.c -- Xz Decode
-2021-09-04 : Igor Pavlov : Public domain */
+2024-03-01 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -67,7 +67,8 @@ unsigned Xz_ReadVarInt(const Byte *p, si
   return 0;
 }
 
-/* ---------- BraState ---------- */
+
+/* ---------- XzBcFilterState ---------- */
 
 #define BRA_BUF_SIZE (1 << 14)
 
@@ -76,55 +77,60 @@ typedef struct
   size_t bufPos;
   size_t bufConv;
   size_t bufTotal;
+  Byte *buf;  // must be aligned for 4 bytes
+  Xz_Func_BcFilterStateBase_Filter filter_func;
+  // int encodeMode;
+  CXzBcFilterStateBase base;
+  // Byte buf[BRA_BUF_SIZE];
+} CXzBcFilterState;
 
-  int encodeMode;
-
-  UInt32 methodId;
-  UInt32 delta;
-  UInt32 ip;
-  UInt32 x86State;
-  Byte deltaState[DELTA_STATE_SIZE];
-
-  Byte buf[BRA_BUF_SIZE];
-} CBraState;
 
-static void BraState_Free(void *pp, ISzAllocPtr alloc)
+static void XzBcFilterState_Free(void *pp, ISzAllocPtr alloc)
 {
-  ISzAlloc_Free(alloc, pp);
+  if (pp)
+  {
+    CXzBcFilterState *p = ((CXzBcFilterState *)pp);
+    ISzAlloc_Free(alloc, p->buf);
+    ISzAlloc_Free(alloc, pp);
+  }
 }
 
-static SRes BraState_SetProps(void *pp, const Byte *props, size_t propSize, ISzAllocPtr alloc)
+
+static SRes XzBcFilterState_SetProps(void *pp, const Byte *props, size_t propSize, ISzAllocPtr alloc)
 {
-  CBraState *p = ((CBraState *)pp);
-  UNUSED_VAR(alloc);
+  CXzBcFilterStateBase *p = &((CXzBcFilterState *)pp)->base;
+  UNUSED_VAR(alloc)
   p->ip = 0;
   if (p->methodId == XZ_ID_Delta)
   {
     if (propSize != 1)
       return SZ_ERROR_UNSUPPORTED;
-    p->delta = (unsigned)props[0] + 1;
+    p->delta = (UInt32)props[0] + 1;
   }
   else
   {
     if (propSize == 4)
     {
-      UInt32 v = GetUi32(props);
+      const UInt32 v = GetUi32(props);
       switch (p->methodId)
       {
         case XZ_ID_PPC:
         case XZ_ID_ARM:
         case XZ_ID_SPARC:
-          if ((v & 3) != 0)
+        case XZ_ID_ARM64:
+          if (v & 3)
             return SZ_ERROR_UNSUPPORTED;
           break;
         case XZ_ID_ARMT:
-          if ((v & 1) != 0)
+        case XZ_ID_RISCV:
+          if (v & 1)
             return SZ_ERROR_UNSUPPORTED;
           break;
         case XZ_ID_IA64:
-          if ((v & 0xF) != 0)
+          if (v & 0xf)
             return SZ_ERROR_UNSUPPORTED;
           break;
+        default: break;
       }
       p->ip = v;
     }
@@ -134,73 +140,91 @@ static SRes BraState_SetProps(void *pp, 
   return SZ_OK;
 }
 
-static void BraState_Init(void *pp)
+
+static void XzBcFilterState_Init(void *pp)
 {
-  CBraState *p = ((CBraState *)pp);
+  CXzBcFilterState *p = ((CXzBcFilterState *)pp);
   p->bufPos = p->bufConv = p->bufTotal = 0;
-  x86_Convert_Init(p->x86State);
-  if (p->methodId == XZ_ID_Delta)
-    Delta_Init(p->deltaState);
+  p->base.X86_State = Z7_BRANCH_CONV_ST_X86_STATE_INIT_VAL;
+  if (p->base.methodId == XZ_ID_Delta)
+    Delta_Init(p->base.delta_State);
 }
 
 
-#define CASE_BRA_CONV(isa) case XZ_ID_ ## isa: size = isa ## _Convert(data, size, p->ip, p->encodeMode); break;
+static const z7_Func_BranchConv g_Funcs_BranchConv_RISC_Dec[] =
+{
+  Z7_BRANCH_CONV_DEC_2 (BranchConv_PPC),
+  Z7_BRANCH_CONV_DEC_2 (BranchConv_IA64),
+  Z7_BRANCH_CONV_DEC_2 (BranchConv_ARM),
+  Z7_BRANCH_CONV_DEC_2 (BranchConv_ARMT),
+  Z7_BRANCH_CONV_DEC_2 (BranchConv_SPARC),
+  Z7_BRANCH_CONV_DEC_2 (BranchConv_ARM64),
+  Z7_BRANCH_CONV_DEC_2 (BranchConv_RISCV)
+};
 
-static SizeT BraState_Filter(void *pp, Byte *data, SizeT size)
+static SizeT XzBcFilterStateBase_Filter_Dec(CXzBcFilterStateBase *p, Byte *data, SizeT size)
 {
-  CBraState *p = ((CBraState *)pp);
   switch (p->methodId)
   {
     case XZ_ID_Delta:
-      if (p->encodeMode)
-        Delta_Encode(p->deltaState, p->delta, data, size);
-      else
-        Delta_Decode(p->deltaState, p->delta, data, size);
+      Delta_Decode(p->delta_State, p->delta, data, size);
       break;
     case XZ_ID_X86:
-      size = x86_Convert(data, size, p->ip, &p->x86State, p->encodeMode);
+      size = (SizeT)(z7_BranchConvSt_X86_Dec(data, size, p->ip, &p->X86_State) - data);
+      break;
+    default:
+      if (p->methodId >= XZ_ID_PPC)
+      {
+        const UInt32 i = p->methodId - XZ_ID_PPC;
+        if (i < Z7_ARRAY_SIZE(g_Funcs_BranchConv_RISC_Dec))
+          size = (SizeT)(g_Funcs_BranchConv_RISC_Dec[i](data, size, p->ip) - data);
+      }
       break;
-    CASE_BRA_CONV(PPC)
-    CASE_BRA_CONV(IA64)
-    CASE_BRA_CONV(ARM)
-    CASE_BRA_CONV(ARMT)
-    CASE_BRA_CONV(SPARC)
   }
   p->ip += (UInt32)size;
   return size;
 }
 
 
-static SRes BraState_Code2(void *pp,
+static SizeT XzBcFilterState_Filter(void *pp, Byte *data, SizeT size)
+{
+  CXzBcFilterState *p = ((CXzBcFilterState *)pp);
+  return p->filter_func(&p->base, data, size);
+}
+
+
+static SRes XzBcFilterState_Code2(void *pp,
     Byte *dest, SizeT *destLen,
     const Byte *src, SizeT *srcLen, int srcWasFinished,
     ECoderFinishMode finishMode,
     // int *wasFinished
     ECoderStatus *status)
 {
-  CBraState *p = ((CBraState *)pp);
+  CXzBcFilterState *p = ((CXzBcFilterState *)pp);
   SizeT destRem = *destLen;
   SizeT srcRem = *srcLen;
-  UNUSED_VAR(finishMode);
+  UNUSED_VAR(finishMode)
 
   *destLen = 0;
   *srcLen = 0;
   // *wasFinished = False;
   *status = CODER_STATUS_NOT_FINISHED;
   
-  while (destRem > 0)
+  while (destRem != 0)
   {
-    if (p->bufPos != p->bufConv)
     {
       size_t size = p->bufConv - p->bufPos;
-      if (size > destRem)
-        size = destRem;
-      memcpy(dest, p->buf + p->bufPos, size);
-      p->bufPos += size;
-      *destLen += size;
-      dest += size;
-      destRem -= size;
-      continue;
+      if (size)
+      {
+        if (size > destRem)
+          size = destRem;
+        memcpy(dest, p->buf + p->bufPos, size);
+        p->bufPos += size;
+        *destLen += size;
+        dest += size;
+        destRem -= size;
+        continue;
+      }
     }
     
     p->bufTotal -= p->bufPos;
@@ -220,7 +244,7 @@ static SRes BraState_Code2(void *pp,
     if (p->bufTotal == 0)
       break;
     
-    p->bufConv = BraState_Filter(pp, p->buf, p->bufTotal);
+    p->bufConv = p->filter_func(&p->base, p->buf, p->bufTotal);
 
     if (p->bufConv == 0)
     {
@@ -240,27 +264,37 @@ static SRes BraState_Code2(void *pp,
 }
 
 
-SRes BraState_SetFromMethod(IStateCoder *p, UInt64 id, int encodeMode, ISzAllocPtr alloc);
-SRes BraState_SetFromMethod(IStateCoder *p, UInt64 id, int encodeMode, ISzAllocPtr alloc)
+#define XZ_IS_SUPPORTED_FILTER_ID(id) \
+    ((id) >= XZ_ID_Delta && (id) <= XZ_ID_RISCV)
+
+SRes Xz_StateCoder_Bc_SetFromMethod_Func(IStateCoder *p, UInt64 id,
+    Xz_Func_BcFilterStateBase_Filter func, ISzAllocPtr alloc)
 {
-  CBraState *decoder;
-  if (id < XZ_ID_Delta || id > XZ_ID_SPARC)
+  CXzBcFilterState *decoder;
+  if (!XZ_IS_SUPPORTED_FILTER_ID(id))
     return SZ_ERROR_UNSUPPORTED;
-  decoder = (CBraState *)p->p;
+  decoder = (CXzBcFilterState *)p->p;
   if (!decoder)
   {
-    decoder = (CBraState *)ISzAlloc_Alloc(alloc, sizeof(CBraState));
+    decoder = (CXzBcFilterState *)ISzAlloc_Alloc(alloc, sizeof(CXzBcFilterState));
     if (!decoder)
       return SZ_ERROR_MEM;
+    decoder->buf = ISzAlloc_Alloc(alloc, BRA_BUF_SIZE);
+    if (!decoder->buf)
+    {
+      ISzAlloc_Free(alloc, decoder);
+      return SZ_ERROR_MEM;
+    }
     p->p = decoder;
-    p->Free = BraState_Free;
-    p->SetProps = BraState_SetProps;
-    p->Init = BraState_Init;
-    p->Code2 = BraState_Code2;
-    p->Filter = BraState_Filter;
+    p->Free     = XzBcFilterState_Free;
+    p->SetProps = XzBcFilterState_SetProps;
+    p->Init     = XzBcFilterState_Init;
+    p->Code2    = XzBcFilterState_Code2;
+    p->Filter   = XzBcFilterState_Filter;
+    decoder->filter_func = func;
   }
-  decoder->methodId = (UInt32)id;
-  decoder->encodeMode = encodeMode;
+  decoder->base.methodId = (UInt32)id;
+  // decoder->encodeMode = encodeMode;
   return SZ_OK;
 }
 
@@ -279,9 +313,9 @@ static void SbState_Free(void *pp, ISzAl
 
 static SRes SbState_SetProps(void *pp, const Byte *props, size_t propSize, ISzAllocPtr alloc)
 {
-  UNUSED_VAR(pp);
-  UNUSED_VAR(props);
-  UNUSED_VAR(alloc);
+  UNUSED_VAR(pp)
+  UNUSED_VAR(props)
+  UNUSED_VAR(alloc)
   return (propSize == 0) ? SZ_OK : SZ_ERROR_UNSUPPORTED;
 }
 
@@ -297,7 +331,7 @@ static SRes SbState_Code2(void *pp, Byte
 {
   CSbDec *p = (CSbDec *)pp;
   SRes res;
-  UNUSED_VAR(srcWasFinished);
+  UNUSED_VAR(srcWasFinished)
   p->dest = dest;
   p->destLen = *destLen;
   p->src = src;
@@ -389,7 +423,7 @@ static SRes Lzma2State_Code2(void *pp, B
   ELzmaStatus status2;
   /* ELzmaFinishMode fm = (finishMode == LZMA_FINISH_ANY) ? LZMA_FINISH_ANY : LZMA_FINISH_END; */
   SRes res;
-  UNUSED_VAR(srcWasFinished);
+  UNUSED_VAR(srcWasFinished)
   if (spec->outBufMode)
   {
     SizeT dicPos = spec->decoder.decoder.dicPos;
@@ -420,7 +454,7 @@ static SRes Lzma2State_SetFromMethod(ISt
     p->Init = Lzma2State_Init;
     p->Code2 = Lzma2State_Code2;
     p->Filter = NULL;
-    Lzma2Dec_Construct(&spec->decoder);
+    Lzma2Dec_CONSTRUCT(&spec->decoder)
   }
   spec->outBufMode = False;
   if (outBuf)
@@ -510,26 +544,24 @@ static SRes MixCoder_SetFromMethod(CMixC
 {
   IStateCoder *sc = &p->coders[coderIndex];
   p->ids[coderIndex] = methodId;
-  switch (methodId)
-  {
-    case XZ_ID_LZMA2: return Lzma2State_SetFromMethod(sc, outBuf, outBufSize, p->alloc);
-    #ifdef USE_SUBBLOCK
-    case XZ_ID_Subblock: return SbState_SetFromMethod(sc, p->alloc);
-    #endif
-  }
+  if (methodId == XZ_ID_LZMA2)
+    return Lzma2State_SetFromMethod(sc, outBuf, outBufSize, p->alloc);
+#ifdef USE_SUBBLOCK
+  if (methodId == XZ_ID_Subblock)
+    return SbState_SetFromMethod(sc, p->alloc);
+#endif
   if (coderIndex == 0)
     return SZ_ERROR_UNSUPPORTED;
-  return BraState_SetFromMethod(sc, methodId, 0, p->alloc);
+  return Xz_StateCoder_Bc_SetFromMethod_Func(sc, methodId,
+      XzBcFilterStateBase_Filter_Dec, p->alloc);
 }
 
 
 static SRes MixCoder_ResetFromMethod(CMixCoder *p, unsigned coderIndex, UInt64 methodId, Byte *outBuf, size_t outBufSize)
 {
   IStateCoder *sc = &p->coders[coderIndex];
-  switch (methodId)
-  {
-    case XZ_ID_LZMA2: return Lzma2State_ResetOutBuf(sc, outBuf, outBufSize);
-  }
+  if (methodId == XZ_ID_LZMA2)
+    return Lzma2State_ResetOutBuf(sc, outBuf, outBufSize);
   return SZ_ERROR_UNSUPPORTED;
 }
 
@@ -568,7 +600,7 @@ static SRes MixCoder_Code(CMixCoder *p,
     SizeT destLen2, srcLen2;
     int wasFinished;
     
-    PRF_STR("------- MixCoder Single ----------");
+    PRF_STR("------- MixCoder Single ----------")
       
     srcLen2 = srcLenOrig;
     destLen2 = destLenOrig;
@@ -615,14 +647,14 @@ static SRes MixCoder_Code(CMixCoder *p,
         processed = coder->Filter(coder->p, p->outBuf, processed);
         if (wasFinished || (destFinish && p->outWritten == destLenOrig))
           processed = p->outWritten;
-        PRF_STR_INT("filter", i);
+        PRF_STR_INT("filter", i)
       }
       *destLen = processed;
     }
     return res;
   }
 
-  PRF_STR("standard mix");
+  PRF_STR("standard mix")
 
   if (p->numCoders != 1)
   {
@@ -772,14 +804,14 @@ static BoolInt Xz_CheckFooter(CXzStreamF
 }
 
 #define READ_VARINT_AND_CHECK(buf, pos, size, res) \
-  { unsigned s = Xz_ReadVarInt(buf + pos, size - pos, res); \
+  { const unsigned s = Xz_ReadVarInt(buf + pos, size - pos, res); \
   if (s == 0) return SZ_ERROR_ARCHIVE; \
   pos += s; }
 
 
 static BoolInt XzBlock_AreSupportedFilters(const CXzBlock *p)
 {
-  unsigned numFilters = XzBlock_GetNumFilters(p) - 1;
+  const unsigned numFilters = XzBlock_GetNumFilters(p) - 1;
   unsigned i;
   {
     const CXzFilter *f = &p->filters[numFilters];
@@ -795,8 +827,7 @@ static BoolInt XzBlock_AreSupportedFilte
       if (f->propsSize != 1)
         return False;
     }
-    else if (f->id < XZ_ID_Delta
-        || f->id > XZ_ID_SPARC
+    else if (!XZ_IS_SUPPORTED_FILTER_ID(f->id)
         || (f->propsSize != 0 && f->propsSize != 4))
       return False;
   }
@@ -821,22 +852,24 @@ SRes XzBlock_Parse(CXzBlock *p, const By
   p->packSize = (UInt64)(Int64)-1;
   if (XzBlock_HasPackSize(p))
   {
-    READ_VARINT_AND_CHECK(header, pos, headerSize, &p->packSize);
+    READ_VARINT_AND_CHECK(header, pos, headerSize, &p->packSize)
     if (p->packSize == 0 || p->packSize + headerSize >= (UInt64)1 << 63)
       return SZ_ERROR_ARCHIVE;
   }
 
   p->unpackSize = (UInt64)(Int64)-1;
   if (XzBlock_HasUnpackSize(p))
-    READ_VARINT_AND_CHECK(header, pos, headerSize, &p->unpackSize);
+  {
+    READ_VARINT_AND_CHECK(header, pos, headerSize, &p->unpackSize)
+  }
 
   numFilters = XzBlock_GetNumFilters(p);
   for (i = 0; i < numFilters; i++)
   {
     CXzFilter *filter = p->filters + i;
     UInt64 size;
-    READ_VARINT_AND_CHECK(header, pos, headerSize, &filter->id);
-    READ_VARINT_AND_CHECK(header, pos, headerSize, &size);
+    READ_VARINT_AND_CHECK(header, pos, headerSize, &filter->id)
+    READ_VARINT_AND_CHECK(header, pos, headerSize, &size)
     if (size > headerSize - pos || size > XZ_FILTER_PROPS_SIZE_MAX)
       return SZ_ERROR_ARCHIVE;
     filter->propsSize = (UInt32)size;
@@ -894,20 +927,20 @@ static SRes XzDecMix_Init(CMixCoder *p, 
     MixCoder_Free(p);
     for (i = 0; i < numFilters; i++)
     {
-      RINOK(MixCoder_SetFromMethod(p, i, block->filters[numFilters - 1 - i].id, outBuf, outBufSize));
+      RINOK(MixCoder_SetFromMethod(p, i, block->filters[numFilters - 1 - i].id, outBuf, outBufSize))
     }
     p->numCoders = numFilters;
   }
   else
   {
-    RINOK(MixCoder_ResetFromMethod(p, 0, block->filters[numFilters - 1].id, outBuf, outBufSize));
+    RINOK(MixCoder_ResetFromMethod(p, 0, block->filters[numFilters - 1].id, outBuf, outBufSize))
   }
 
   for (i = 0; i < numFilters; i++)
   {
     const CXzFilter *f = &block->filters[numFilters - 1 - i];
     IStateCoder *sc = &p->coders[i];
-    RINOK(sc->SetProps(sc->p, f->props, f->propsSize, p->alloc));
+    RINOK(sc->SetProps(sc->p, f->props, f->propsSize, p->alloc))
   }
   
   MixCoder_Init(p);
@@ -1001,7 +1034,7 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
       SRes res;
 
       ECoderFinishMode finishMode2 = finishMode;
-      BoolInt srcFinished2 = srcFinished;
+      BoolInt srcFinished2 = (BoolInt)srcFinished;
       BoolInt destFinish = False;
 
       if (p->block.packSize != (UInt64)(Int64)-1)
@@ -1054,14 +1087,14 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
       (*destLen) += destLen2;
       p->unpackSize += destLen2;
 
-      RINOK(res);
+      RINOK(res)
 
       if (*status != CODER_STATUS_FINISHED_WITH_MARK)
       {
         if (p->block.packSize == p->packSize
             && *status == CODER_STATUS_NEEDS_MORE_INPUT)
         {
-          PRF_STR("CODER_STATUS_NEEDS_MORE_INPUT");
+          PRF_STR("CODER_STATUS_NEEDS_MORE_INPUT")
           *status = CODER_STATUS_NOT_SPECIFIED;
           return SZ_ERROR_DATA;
         }
@@ -1078,7 +1111,7 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
         if ((p->block.packSize != (UInt64)(Int64)-1 && p->block.packSize != p->packSize)
            || (p->block.unpackSize != (UInt64)(Int64)-1 && p->block.unpackSize != p->unpackSize))
         {
-          PRF_STR("ERROR: block.size mismatch");
+          PRF_STR("ERROR: block.size mismatch")
           return SZ_ERROR_DATA;
         }
       }
@@ -1094,7 +1127,7 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
       return SZ_OK;
     }
 
-    switch (p->state)
+    switch ((int)p->state)
     {
       case XZ_STATE_STREAM_HEADER:
       {
@@ -1109,7 +1142,7 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
         }
         else
         {
-          RINOK(Xz_ParseHeader(&p->streamFlags, p->buf));
+          RINOK(Xz_ParseHeader(&p->streamFlags, p->buf))
           p->numStartedStreams++;
           p->indexSize = 0;
           p->numBlocks = 0;
@@ -1139,15 +1172,15 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
             p->state = XZ_STATE_STREAM_INDEX;
             break;
           }
-          p->blockHeaderSize = ((UInt32)p->buf[0] << 2) + 4;
+          p->blockHeaderSize = ((unsigned)p->buf[0] << 2) + 4;
           break;
         }
         
         if (p->pos != p->blockHeaderSize)
         {
-          UInt32 cur = p->blockHeaderSize - p->pos;
+          unsigned cur = p->blockHeaderSize - p->pos;
           if (cur > srcRem)
-            cur = (UInt32)srcRem;
+            cur = (unsigned)srcRem;
           memcpy(p->buf + p->pos, src, cur);
           p->pos += cur;
           (*srcLen) += cur;
@@ -1155,7 +1188,7 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
         }
         else
         {
-          RINOK(XzBlock_Parse(&p->block, p->buf));
+          RINOK(XzBlock_Parse(&p->block, p->buf))
           if (!XzBlock_AreSupportedFilters(&p->block))
             return SZ_ERROR_UNSUPPORTED;
           p->numTotalBlocks++;
@@ -1168,7 +1201,7 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
             p->headerParsedOk = True;
             return SZ_OK;
           }
-          RINOK(XzDecMix_Init(&p->decoder, &p->block, p->outBuf, p->outBufSize));
+          RINOK(XzDecMix_Init(&p->decoder, &p->block, p->outBuf, p->outBufSize))
         }
         break;
       }
@@ -1189,8 +1222,8 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
         }
         else
         {
-          UInt32 checkSize = XzFlags_GetCheckSize(p->streamFlags);
-          UInt32 cur = checkSize - p->pos;
+          const unsigned checkSize = XzFlags_GetCheckSize(p->streamFlags);
+          unsigned cur = checkSize - p->pos;
           if (cur != 0)
           {
             if (srcRem == 0)
@@ -1199,7 +1232,7 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
               return SZ_OK;
             }
             if (cur > srcRem)
-              cur = (UInt32)srcRem;
+              cur = (unsigned)srcRem;
             memcpy(p->buf + p->pos, src, cur);
             p->pos += cur;
             (*srcLen) += cur;
@@ -1288,9 +1321,9 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
 
       case XZ_STATE_STREAM_FOOTER:
       {
-        UInt32 cur = XZ_STREAM_FOOTER_SIZE - p->pos;
+        unsigned cur = XZ_STREAM_FOOTER_SIZE - p->pos;
         if (cur > srcRem)
-          cur = (UInt32)srcRem;
+          cur = (unsigned)srcRem;
         memcpy(p->buf + p->pos, src, cur);
         p->pos += cur;
         (*srcLen) += cur;
@@ -1325,6 +1358,8 @@ SRes XzUnpacker_Code(CXzUnpacker *p, Byt
       }
       
       case XZ_STATE_BLOCK: break; /* to disable GCC warning */
+
+      default: return SZ_ERROR_FAIL;
     }
   }
   /*
@@ -1389,7 +1424,7 @@ UInt64 XzUnpacker_GetExtraSize(const CXz
 
 
 
-#ifndef _7ZIP_ST
+#ifndef Z7_ST
 #include "MtDec.h"
 #endif
 
@@ -1400,7 +1435,7 @@ void XzDecMtProps_Init(CXzDecMtProps *p)
   p->outStep_ST = 1 << 20;
   p->ignoreErrors = False;
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   p->numThreads = 1;
   p->inBufSize_MT = 1 << 18;
   p->memUseMax = sizeof(size_t) << 28;
@@ -1409,7 +1444,7 @@ void XzDecMtProps_Init(CXzDecMtProps *p)
 
 
 
-#ifndef _7ZIP_ST
+#ifndef Z7_ST
 
 /* ---------- CXzDecMtThread ---------- */
 
@@ -1448,7 +1483,7 @@ typedef struct
 
 /* ---------- CXzDecMt ---------- */
 
-typedef struct
+struct CXzDecMt
 {
   CAlignOffsetAlloc alignOffsetAlloc;
   ISzAllocPtr allocMid;
@@ -1456,9 +1491,9 @@ typedef struct
   CXzDecMtProps props;
   size_t unpackBlockMaxSize;
   
-  ISeqInStream *inStream;
-  ISeqOutStream *outStream;
-  ICompressProgress *progress;
+  ISeqInStreamPtr inStream;
+  ISeqOutStreamPtr outStream;
+  ICompressProgressPtr progress;
 
   BoolInt finishMode;
   BoolInt outSize_Defined;
@@ -1481,7 +1516,7 @@ typedef struct
   ECoderStatus status;
   SRes codeRes;
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   BoolInt mainDecoderWasCalled;
   // int statErrorDefined;
   int finishedDecoderIndex;
@@ -1504,10 +1539,9 @@ typedef struct
 
   BoolInt mtc_WasConstructed;
   CMtDec mtc;
-  CXzDecMtThread coders[MTDEC__THREADS_MAX];
+  CXzDecMtThread coders[MTDEC_THREADS_MAX];
   #endif
-
-} CXzDecMt;
+};
 
 
 
@@ -1535,11 +1569,11 @@ CXzDecMtHandle XzDecMt_Create(ISzAllocPt
 
   XzDecMtProps_Init(&p->props);
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   p->mtc_WasConstructed = False;
   {
     unsigned i;
-    for (i = 0; i < MTDEC__THREADS_MAX; i++)
+    for (i = 0; i < MTDEC_THREADS_MAX; i++)
     {
       CXzDecMtThread *coder = &p->coders[i];
       coder->dec_created = False;
@@ -1549,16 +1583,16 @@ CXzDecMtHandle XzDecMt_Create(ISzAllocPt
   }
   #endif
 
-  return p;
+  return (CXzDecMtHandle)p;
 }
 
 
-#ifndef _7ZIP_ST
+#ifndef Z7_ST
 
 static void XzDecMt_FreeOutBufs(CXzDecMt *p)
 {
   unsigned i;
-  for (i = 0; i < MTDEC__THREADS_MAX; i++)
+  for (i = 0; i < MTDEC_THREADS_MAX; i++)
   {
     CXzDecMtThread *coder = &p->coders[i];
     if (coder->outBuf)
@@ -1595,13 +1629,15 @@ static void XzDecMt_FreeSt(CXzDecMt *p)
 }
 
 
-void XzDecMt_Destroy(CXzDecMtHandle pp)
+// #define GET_CXzDecMt_p  CXzDecMt *p = pp;
+
+void XzDecMt_Destroy(CXzDecMtHandle p)
 {
-  CXzDecMt *p = (CXzDecMt *)pp;
+  // GET_CXzDecMt_p
 
   XzDecMt_FreeSt(p);
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
 
   if (p->mtc_WasConstructed)
   {
@@ -1610,7 +1646,7 @@ void XzDecMt_Destroy(CXzDecMtHandle pp)
   }
   {
     unsigned i;
-    for (i = 0; i < MTDEC__THREADS_MAX; i++)
+    for (i = 0; i < MTDEC_THREADS_MAX; i++)
     {
       CXzDecMtThread *t = &p->coders[i];
       if (t->dec_created)
@@ -1625,12 +1661,12 @@ void XzDecMt_Destroy(CXzDecMtHandle pp)
 
   #endif
 
-  ISzAlloc_Free(p->alignOffsetAlloc.baseAlloc, pp);
+  ISzAlloc_Free(p->alignOffsetAlloc.baseAlloc, p);
 }
 
 
 
-#ifndef _7ZIP_ST
+#ifndef Z7_ST
 
 static void XzDecMt_Callback_Parse(void *obj, unsigned coderIndex, CMtDecCallbackInfo *cc)
 {
@@ -1696,7 +1732,7 @@ static void XzDecMt_Callback_Parse(void 
     coder->dec.parseMode = True;
     coder->dec.headerParsedOk = False;
     
-    PRF_STR_INT("Parse", srcSize2);
+    PRF_STR_INT("Parse", srcSize2)
     
     res = XzUnpacker_Code(&coder->dec,
         NULL, &destSize,
@@ -1739,10 +1775,10 @@ static void XzDecMt_Callback_Parse(void 
           }
         }
         {
-        UInt64 packSize = block->packSize;
-        UInt64 packSizeAligned = packSize + ((0 - (unsigned)packSize) & 3);
-        UInt32 checkSize = XzFlags_GetCheckSize(coder->dec.streamFlags);
-        UInt64 blockPackSum = coder->inPreSize + packSizeAligned + checkSize;
+        const UInt64 packSize = block->packSize;
+        const UInt64 packSizeAligned = packSize + ((0 - (unsigned)packSize) & 3);
+        const unsigned checkSize = XzFlags_GetCheckSize(coder->dec.streamFlags);
+        const UInt64 blockPackSum = coder->inPreSize + packSizeAligned + checkSize;
         // if (blockPackSum <= me->props.inBlockMax)
         // unpackBlockMaxSize
         {
@@ -2071,7 +2107,7 @@ static SRes XzDecMt_Callback_Write(void 
         }
         data += cur;
         size -= cur;
-        // PRF_STR_INT("Written size =", size);
+        // PRF_STR_INT("Written size =", size)
         if (size == 0)
           break;
         res = MtProgress_ProgressAdd(&me->mtc.mtProgress, 0, 0);
@@ -2087,7 +2123,7 @@ static SRes XzDecMt_Callback_Write(void 
         return res;
       }
 
-    RINOK(res);
+    RINOK(res)
 
     if (coder->inPreSize != coder->inCodeSize
         || coder->blockPackTotal != coder->inCodeSize)
@@ -2106,13 +2142,13 @@ static SRes XzDecMt_Callback_Write(void 
   // (coder->state == MTDEC_PARSE_END) means that there are no other working threads
   // so we can use mtc variables without lock
 
-  PRF_STR_INT("Write MTDEC_PARSE_END", me->mtc.inProcessed);
+  PRF_STR_INT("Write MTDEC_PARSE_END", me->mtc.inProcessed)
 
   me->mtc.mtProgress.totalInSize = me->mtc.inProcessed;
   {
     CXzUnpacker *dec = &me->dec;
     
-    PRF_STR_INT("PostSingle", srcSize);
+    PRF_STR_INT("PostSingle", srcSize)
     
     {
       size_t srcProcessed = srcSize;
@@ -2186,7 +2222,7 @@ static SRes XzDecMt_Callback_Write(void 
           me->mtc.crossEnd = srcSize;
         }
 
-        PRF_STR_INT("XZ_STATE_STREAM_HEADER crossEnd = ", (unsigned)me->mtc.crossEnd);
+        PRF_STR_INT("XZ_STATE_STREAM_HEADER crossEnd = ", (unsigned)me->mtc.crossEnd)
 
         return SZ_OK;
       }
@@ -2277,7 +2313,7 @@ static SRes XzDecMt_Callback_Write(void 
           UInt64 inDelta = me->mtc.inProcessed - inProgressPrev;
           if (inDelta >= (1 << 22))
           {
-            RINOK(MtProgress_Progress_ST(&me->mtc.mtProgress));
+            RINOK(MtProgress_Progress_ST(&me->mtc.mtProgress))
             inProgressPrev = me->mtc.inProcessed;
           }
         }
@@ -2331,7 +2367,7 @@ void XzStatInfo_Clear(CXzStatInfo *p)
 */
 
 static SRes XzDecMt_Decode_ST(CXzDecMt *p
-    #ifndef _7ZIP_ST
+    #ifndef Z7_ST
     , BoolInt tMode
     #endif
     , CXzStatInfo *stat)
@@ -2343,11 +2379,11 @@ static SRes XzDecMt_Decode_ST(CXzDecMt *
 
   CXzUnpacker *dec;
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   if (tMode)
   {
     XzDecMt_FreeOutBufs(p);
-    tMode = MtDec_PrepareRead(&p->mtc);
+    tMode = (BoolInt)MtDec_PrepareRead(&p->mtc);
   }
   #endif
 
@@ -2400,7 +2436,7 @@ static SRes XzDecMt_Decode_ST(CXzDecMt *
 
     if (inPos == inLim)
     {
-      #ifndef _7ZIP_ST
+      #ifndef Z7_ST
       if (tMode)
       {
         inData = MtDec_Read(&p->mtc, &inLim);
@@ -2577,19 +2613,19 @@ static void XzStatInfo_SetStat(const CXz
 
 
 
-SRes XzDecMt_Decode(CXzDecMtHandle pp,
+SRes XzDecMt_Decode(CXzDecMtHandle p,
     const CXzDecMtProps *props,
     const UInt64 *outDataSize, int finishMode,
-    ISeqOutStream *outStream,
+    ISeqOutStreamPtr outStream,
     // Byte *outBuf, size_t *outBufSize,
-    ISeqInStream *inStream,
+    ISeqInStreamPtr inStream,
     // const Byte *inData, size_t inDataSize,
     CXzStatInfo *stat,
     int *isMT,
-    ICompressProgress *progress)
+    ICompressProgressPtr progress)
 {
-  CXzDecMt *p = (CXzDecMt *)pp;
-  #ifndef _7ZIP_ST
+  // GET_CXzDecMt_p
+  #ifndef Z7_ST
   BoolInt tMode;
   #endif
 
@@ -2610,7 +2646,7 @@ SRes XzDecMt_Decode(CXzDecMtHandle pp,
     p->outSize = *outDataSize;
   }
 
-  p->finishMode = finishMode;
+  p->finishMode = (BoolInt)finishMode;
 
   // p->outSize = 457; p->outSize_Defined = True; p->finishMode = False; // for test
 
@@ -2640,7 +2676,7 @@ SRes XzDecMt_Decode(CXzDecMtHandle pp,
     */
 
   
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
 
   p->isBlockHeaderState_Parse = False;
   p->isBlockHeaderState_Write = False;
@@ -2782,7 +2818,7 @@ SRes XzDecMt_Decode(CXzDecMtHandle pp,
       return res;
     }
 
-    PRF_STR("----- decoding ST -----");
+    PRF_STR("----- decoding ST -----")
   }
 
   #endif
@@ -2792,13 +2828,13 @@ SRes XzDecMt_Decode(CXzDecMtHandle pp,
 
   {
     SRes res = XzDecMt_Decode_ST(p
-        #ifndef _7ZIP_ST
+        #ifndef Z7_ST
         , tMode
         #endif
         , stat
         );
 
-    #ifndef _7ZIP_ST
+    #ifndef Z7_ST
     // we must set error code from MT decoding at first
     if (p->mainErrorCode != SZ_OK)
       stat->DecodeRes = p->mainErrorCode;
@@ -2835,3 +2871,7 @@ SRes XzDecMt_Decode(CXzDecMtHandle pp,
     return res;
   }
 }
+
+#undef PRF
+#undef PRF_STR
+#undef PRF_STR_INT_2
