$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zDec.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zDec.c
@@ -1,11 +1,11 @@
 /* 7zDec.c -- Decoding from 7z folder
-2021-02-09 : Igor Pavlov : Public domain */
+: Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
 #include <string.h>
 
-/* #define _7ZIP_PPMD_SUPPPORT */
+/* #define Z7_PPMD_SUPPORT */
 
 #include "7z.h"
 #include "7zCrc.h"
@@ -16,27 +16,50 @@
 #include "Delta.h"
 #include "LzmaDec.h"
 #include "Lzma2Dec.h"
-#ifdef _7ZIP_PPMD_SUPPPORT
+#ifdef Z7_PPMD_SUPPORT
 #include "Ppmd7.h"
 #endif
 
 #define k_Copy 0
-#ifndef _7Z_NO_METHOD_LZMA2
+#ifndef Z7_NO_METHOD_LZMA2
 #define k_LZMA2 0x21
 #endif
 #define k_LZMA  0x30101
 #define k_BCJ2  0x303011B
-#ifndef _7Z_NO_METHODS_FILTERS
+
+#if !defined(Z7_NO_METHODS_FILTERS)
+#define Z7_USE_BRANCH_FILTER
+#endif
+
+#if !defined(Z7_NO_METHODS_FILTERS) || \
+     defined(Z7_USE_NATIVE_BRANCH_FILTER) && defined(MY_CPU_ARM64)
+#define Z7_USE_FILTER_ARM64
+#ifndef Z7_USE_BRANCH_FILTER
+#define Z7_USE_BRANCH_FILTER
+#endif
+#define k_ARM64 0xa
+#endif
+
+#if !defined(Z7_NO_METHODS_FILTERS) || \
+     defined(Z7_USE_NATIVE_BRANCH_FILTER) && defined(MY_CPU_ARMT)
+#define Z7_USE_FILTER_ARMT
+#ifndef Z7_USE_BRANCH_FILTER
+#define Z7_USE_BRANCH_FILTER
+#endif
+#define k_ARMT  0x3030701
+#endif
+
+#ifndef Z7_NO_METHODS_FILTERS
 #define k_Delta 3
+#define k_RISCV 0xb
 #define k_BCJ   0x3030103
 #define k_PPC   0x3030205
 #define k_IA64  0x3030401
 #define k_ARM   0x3030501
-#define k_ARMT  0x3030701
 #define k_SPARC 0x3030805
 #endif
 
-#ifdef _7ZIP_PPMD_SUPPPORT
+#ifdef Z7_PPMD_SUPPORT
 
 #define k_PPMD 0x30401
 
@@ -49,12 +72,12 @@ typedef struct
   UInt64 processed;
   BoolInt extra;
   SRes res;
-  const ILookInStream *inStream;
+  ILookInStreamPtr inStream;
 } CByteInToLook;
 
-static Byte ReadByte(const IByteIn *pp)
+static Byte ReadByte(IByteInPtr pp)
 {
-  CByteInToLook *p = CONTAINER_FROM_VTBL(pp, CByteInToLook, vt);
+  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(CByteInToLook)
   if (p->cur != p->end)
     return *p->cur++;
   if (p->res == SZ_OK)
@@ -67,13 +90,13 @@ static Byte ReadByte(const IByteIn *pp)
     p->cur = p->begin;
     p->end = p->begin + size;
     if (size != 0)
-      return *p->cur++;;
+      return *p->cur++;
   }
   p->extra = True;
   return 0;
 }
 
-static SRes SzDecodePpmd(const Byte *props, unsigned propsSize, UInt64 inSize, const ILookInStream *inStream,
+static SRes SzDecodePpmd(const Byte *props, unsigned propsSize, UInt64 inSize, ILookInStreamPtr inStream,
     Byte *outBuffer, SizeT outSize, ISzAllocPtr allocMain)
 {
   CPpmd7 ppmd;
@@ -138,14 +161,14 @@ static SRes SzDecodePpmd(const Byte *pro
 #endif
 
 
-static SRes SzDecodeLzma(const Byte *props, unsigned propsSize, UInt64 inSize, ILookInStream *inStream,
+static SRes SzDecodeLzma(const Byte *props, unsigned propsSize, UInt64 inSize, ILookInStreamPtr inStream,
     Byte *outBuffer, SizeT outSize, ISzAllocPtr allocMain)
 {
   CLzmaDec state;
   SRes res = SZ_OK;
 
-  LzmaDec_Construct(&state);
-  RINOK(LzmaDec_AllocateProbs(&state, props, propsSize, allocMain));
+  LzmaDec_CONSTRUCT(&state)
+  RINOK(LzmaDec_AllocateProbs(&state, props, propsSize, allocMain))
   state.dic = outBuffer;
   state.dicBufSize = outSize;
   LzmaDec_Init(&state);
@@ -196,18 +219,18 @@ static SRes SzDecodeLzma(const Byte *pro
 }
 
 
-#ifndef _7Z_NO_METHOD_LZMA2
+#ifndef Z7_NO_METHOD_LZMA2
 
-static SRes SzDecodeLzma2(const Byte *props, unsigned propsSize, UInt64 inSize, ILookInStream *inStream,
+static SRes SzDecodeLzma2(const Byte *props, unsigned propsSize, UInt64 inSize, ILookInStreamPtr inStream,
     Byte *outBuffer, SizeT outSize, ISzAllocPtr allocMain)
 {
   CLzma2Dec state;
   SRes res = SZ_OK;
 
-  Lzma2Dec_Construct(&state);
+  Lzma2Dec_CONSTRUCT(&state)
   if (propsSize != 1)
     return SZ_ERROR_DATA;
-  RINOK(Lzma2Dec_AllocateProbs(&state, props[0], allocMain));
+  RINOK(Lzma2Dec_AllocateProbs(&state, props[0], allocMain))
   state.decoder.dic = outBuffer;
   state.decoder.dicBufSize = outSize;
   Lzma2Dec_Init(&state);
@@ -257,7 +280,7 @@ static SRes SzDecodeLzma2(const Byte *pr
 #endif
 
 
-static SRes SzDecodeCopy(UInt64 inSize, ILookInStream *inStream, Byte *outBuffer)
+static SRes SzDecodeCopy(UInt64 inSize, ILookInStreamPtr inStream, Byte *outBuffer)
 {
   while (inSize > 0)
   {
@@ -265,13 +288,13 @@ static SRes SzDecodeCopy(UInt64 inSize, 
     size_t curSize = (1 << 18);
     if (curSize > inSize)
       curSize = (size_t)inSize;
-    RINOK(ILookInStream_Look(inStream, &inBuf, &curSize));
+    RINOK(ILookInStream_Look(inStream, &inBuf, &curSize))
     if (curSize == 0)
       return SZ_ERROR_INPUT_EOF;
     memcpy(outBuffer, inBuf, curSize);
     outBuffer += curSize;
     inSize -= curSize;
-    RINOK(ILookInStream_Skip(inStream, curSize));
+    RINOK(ILookInStream_Skip(inStream, curSize))
   }
   return SZ_OK;
 }
@@ -282,15 +305,16 @@ static BoolInt IS_MAIN_METHOD(UInt32 m)
   {
     case k_Copy:
     case k_LZMA:
-    #ifndef _7Z_NO_METHOD_LZMA2
+  #ifndef Z7_NO_METHOD_LZMA2
     case k_LZMA2:
-    #endif
-    #ifdef _7ZIP_PPMD_SUPPPORT
+  #endif
+  #ifdef Z7_PPMD_SUPPORT
     case k_PPMD:
-    #endif
+  #endif
       return True;
+    default:
+      return False;
   }
-  return False;
 }
 
 static BoolInt IS_SUPPORTED_CODER(const CSzCoderInfo *c)
@@ -317,7 +341,7 @@ static SRes CheckSupportedFolder(const C
   }
   
   
-  #ifndef _7Z_NO_METHODS_FILTERS
+  #if defined(Z7_USE_BRANCH_FILTER)
 
   if (f->NumCoders == 2)
   {
@@ -333,13 +357,21 @@ static SRes CheckSupportedFolder(const C
       return SZ_ERROR_UNSUPPORTED;
     switch ((UInt32)c->MethodID)
     {
+    #if !defined(Z7_NO_METHODS_FILTERS)
       case k_Delta:
       case k_BCJ:
       case k_PPC:
       case k_IA64:
       case k_SPARC:
       case k_ARM:
+      case k_RISCV:
+    #endif
+    #ifdef Z7_USE_FILTER_ARM64
+      case k_ARM64:
+    #endif
+    #ifdef Z7_USE_FILTER_ARMT
       case k_ARMT:
+    #endif
         break;
       default:
         return SZ_ERROR_UNSUPPORTED;
@@ -372,15 +404,16 @@ static SRes CheckSupportedFolder(const C
   return SZ_ERROR_UNSUPPORTED;
 }
 
-#ifndef _7Z_NO_METHODS_FILTERS
-#define CASE_BRA_CONV(isa) case k_ ## isa: isa ## _Convert(outBuffer, outSize, 0, 0); break;
-#endif
+
+
+
+
 
 static SRes SzFolder_Decode2(const CSzFolder *folder,
     const Byte *propsData,
     const UInt64 *unpackSizes,
     const UInt64 *packPositions,
-    ILookInStream *inStream, UInt64 startPos,
+    ILookInStreamPtr inStream, UInt64 startPos,
     Byte *outBuffer, SizeT outSize, ISzAllocPtr allocMain,
     Byte *tempBuf[])
 {
@@ -389,7 +422,7 @@ static SRes SzFolder_Decode2(const CSzFo
   SizeT tempSize3 = 0;
   Byte *tempBuf3 = 0;
 
-  RINOK(CheckSupportedFolder(folder));
+  RINOK(CheckSupportedFolder(folder))
 
   for (ci = 0; ci < folder->NumCoders; ci++)
   {
@@ -404,8 +437,8 @@ static SRes SzFolder_Decode2(const CSzFo
       SizeT outSizeCur = outSize;
       if (folder->NumCoders == 4)
       {
-        UInt32 indices[] = { 3, 2, 0 };
-        UInt64 unpackSize = unpackSizes[ci];
+        const UInt32 indices[] = { 3, 2, 0 };
+        const UInt64 unpackSize = unpackSizes[ci];
         si = indices[ci];
         if (ci < 2)
         {
@@ -431,37 +464,37 @@ static SRes SzFolder_Decode2(const CSzFo
       }
       offset = packPositions[si];
       inSize = packPositions[(size_t)si + 1] - offset;
-      RINOK(LookInStream_SeekTo(inStream, startPos + offset));
+      RINOK(LookInStream_SeekTo(inStream, startPos + offset))
 
       if (coder->MethodID == k_Copy)
       {
         if (inSize != outSizeCur) /* check it */
           return SZ_ERROR_DATA;
-        RINOK(SzDecodeCopy(inSize, inStream, outBufCur));
+        RINOK(SzDecodeCopy(inSize, inStream, outBufCur))
       }
       else if (coder->MethodID == k_LZMA)
       {
-        RINOK(SzDecodeLzma(propsData + coder->PropsOffset, coder->PropsSize, inSize, inStream, outBufCur, outSizeCur, allocMain));
+        RINOK(SzDecodeLzma(propsData + coder->PropsOffset, coder->PropsSize, inSize, inStream, outBufCur, outSizeCur, allocMain))
       }
-      #ifndef _7Z_NO_METHOD_LZMA2
+    #ifndef Z7_NO_METHOD_LZMA2
       else if (coder->MethodID == k_LZMA2)
       {
-        RINOK(SzDecodeLzma2(propsData + coder->PropsOffset, coder->PropsSize, inSize, inStream, outBufCur, outSizeCur, allocMain));
+        RINOK(SzDecodeLzma2(propsData + coder->PropsOffset, coder->PropsSize, inSize, inStream, outBufCur, outSizeCur, allocMain))
       }
-      #endif
-      #ifdef _7ZIP_PPMD_SUPPPORT
+    #endif
+    #ifdef Z7_PPMD_SUPPORT
       else if (coder->MethodID == k_PPMD)
       {
-        RINOK(SzDecodePpmd(propsData + coder->PropsOffset, coder->PropsSize, inSize, inStream, outBufCur, outSizeCur, allocMain));
+        RINOK(SzDecodePpmd(propsData + coder->PropsOffset, coder->PropsSize, inSize, inStream, outBufCur, outSizeCur, allocMain))
       }
-      #endif
+    #endif
       else
         return SZ_ERROR_UNSUPPORTED;
     }
     else if (coder->MethodID == k_BCJ2)
     {
-      UInt64 offset = packPositions[1];
-      UInt64 s3Size = packPositions[2] - offset;
+      const UInt64 offset = packPositions[1];
+      const UInt64 s3Size = packPositions[2] - offset;
       
       if (ci != 3)
         return SZ_ERROR_UNSUPPORTED;
@@ -473,8 +506,8 @@ static SRes SzFolder_Decode2(const CSzFo
       if (!tempBuf[2] && tempSizes[2] != 0)
         return SZ_ERROR_MEM;
       
-      RINOK(LookInStream_SeekTo(inStream, startPos + offset));
-      RINOK(SzDecodeCopy(s3Size, inStream, tempBuf[2]));
+      RINOK(LookInStream_SeekTo(inStream, startPos + offset))
+      RINOK(SzDecodeCopy(s3Size, inStream, tempBuf[2]))
 
       if ((tempSizes[0] & 3) != 0 ||
           (tempSizes[1] & 3) != 0 ||
@@ -493,26 +526,22 @@ static SRes SzFolder_Decode2(const CSzFo
         p.destLim = outBuffer + outSize;
         
         Bcj2Dec_Init(&p);
-        RINOK(Bcj2Dec_Decode(&p));
+        RINOK(Bcj2Dec_Decode(&p))
 
         {
           unsigned i;
           for (i = 0; i < 4; i++)
             if (p.bufs[i] != p.lims[i])
               return SZ_ERROR_DATA;
-          
-          if (!Bcj2Dec_IsFinished(&p))
-            return SZ_ERROR_DATA;
-
-          if (p.dest != p.destLim
-             || p.state != BCJ2_STREAM_MAIN)
+          if (p.dest != p.destLim || !Bcj2Dec_IsMaybeFinished(&p))
             return SZ_ERROR_DATA;
         }
       }
     }
-    #ifndef _7Z_NO_METHODS_FILTERS
+#if defined(Z7_USE_BRANCH_FILTER)
     else if (ci == 1)
     {
+#if !defined(Z7_NO_METHODS_FILTERS)
       if (coder->MethodID == k_Delta)
       {
         if (coder->PropsSize != 1)
@@ -522,31 +551,75 @@ static SRes SzFolder_Decode2(const CSzFo
           Delta_Init(state);
           Delta_Decode(state, (unsigned)(propsData[coder->PropsOffset]) + 1, outBuffer, outSize);
         }
+        continue;
       }
-      else
+#endif
+
+#ifdef Z7_USE_FILTER_ARM64
+      if (coder->MethodID == k_ARM64)
+      {
+        UInt32 pc = 0;
+        if (coder->PropsSize == 4)
+        {
+          pc = GetUi32(propsData + coder->PropsOffset);
+          if (pc & 3)
+            return SZ_ERROR_UNSUPPORTED;
+        }
+        else if (coder->PropsSize != 0)
+          return SZ_ERROR_UNSUPPORTED;
+        z7_BranchConv_ARM64_Dec(outBuffer, outSize, pc);
+        continue;
+      }
+#endif
+
+#if !defined(Z7_NO_METHODS_FILTERS)
+      if (coder->MethodID == k_RISCV)
+      {
+        UInt32 pc = 0;
+        if (coder->PropsSize == 4)
+        {
+          pc = GetUi32(propsData + coder->PropsOffset);
+          if (pc & 1)
+            return SZ_ERROR_UNSUPPORTED;
+        }
+        else if (coder->PropsSize != 0)
+          return SZ_ERROR_UNSUPPORTED;
+        z7_BranchConv_RISCV_Dec(outBuffer, outSize, pc);
+        continue;
+      }
+#endif
+
+#if !defined(Z7_NO_METHODS_FILTERS) || defined(Z7_USE_FILTER_ARMT)
       {
         if (coder->PropsSize != 0)
           return SZ_ERROR_UNSUPPORTED;
+       #define CASE_BRA_CONV(isa) case k_ ## isa: Z7_BRANCH_CONV_DEC(isa)(outBuffer, outSize, 0); break; // pc = 0;
         switch (coder->MethodID)
         {
+         #if !defined(Z7_NO_METHODS_FILTERS)
           case k_BCJ:
           {
-            UInt32 state;
-            x86_Convert_Init(state);
-            x86_Convert(outBuffer, outSize, 0, &state, 0);
+            UInt32 state = Z7_BRANCH_CONV_ST_X86_STATE_INIT_VAL;
+            z7_BranchConvSt_X86_Dec(outBuffer, outSize, 0, &state); // pc = 0
             break;
           }
-          CASE_BRA_CONV(PPC)
+          case k_PPC: Z7_BRANCH_CONV_DEC_2(BranchConv_PPC)(outBuffer, outSize, 0); break; // pc = 0;
+          // CASE_BRA_CONV(PPC)
           CASE_BRA_CONV(IA64)
           CASE_BRA_CONV(SPARC)
           CASE_BRA_CONV(ARM)
+         #endif
+         #if !defined(Z7_NO_METHODS_FILTERS) || defined(Z7_USE_FILTER_ARMT)
           CASE_BRA_CONV(ARMT)
+         #endif
           default:
             return SZ_ERROR_UNSUPPORTED;
         }
+        continue;
       }
-    }
-    #endif
+#endif
+    } // (c == 1)
+#endif // Z7_USE_BRANCH_FILTER
     else
       return SZ_ERROR_UNSUPPORTED;
   }
@@ -556,7 +629,7 @@ static SRes SzFolder_Decode2(const CSzFo
 
 
 SRes SzAr_DecodeFolder(const CSzAr *p, UInt32 folderIndex,
-    ILookInStream *inStream, UInt64 startPos,
+    ILookInStreamPtr inStream, UInt64 startPos,
     Byte *outBuffer, size_t outSize,
     ISzAllocPtr allocMain)
 {
