$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/LzmaDec.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/LzmaDec.c
@@ -1,5 +1,5 @@
 /* LzmaDec.c -- LZMA Decoder
-2021-04-01 : Igor Pavlov : Public domain */
+2023-04-07 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -8,15 +8,15 @@
 /* #include "CpuArch.h" */
 #include "LzmaDec.h"
 
-#define kNumTopBits 24
-#define kTopValue ((UInt32)1 << kNumTopBits)
+// #define kNumTopBits 24
+#define kTopValue ((UInt32)1 << 24)
 
 #define kNumBitModelTotalBits 11
 #define kBitModelTotal (1 << kNumBitModelTotalBits)
 
 #define RC_INIT_SIZE 5
 
-#ifndef _LZMA_DEC_OPT
+#ifndef Z7_LZMA_DEC_OPT
 
 #define kNumMoveBits 5
 #define NORMALIZE if (range < kTopValue) { range <<= 8; code = (code << 8) | (*buf++); }
@@ -25,14 +25,14 @@
 #define UPDATE_0(p) range = bound; *(p) = (CLzmaProb)(ttt + ((kBitModelTotal - ttt) >> kNumMoveBits));
 #define UPDATE_1(p) range -= bound; code -= bound; *(p) = (CLzmaProb)(ttt - (ttt >> kNumMoveBits));
 #define GET_BIT2(p, i, A0, A1) IF_BIT_0(p) \
-  { UPDATE_0(p); i = (i + i); A0; } else \
-  { UPDATE_1(p); i = (i + i) + 1; A1; }
+  { UPDATE_0(p)  i = (i + i); A0; } else \
+  { UPDATE_1(p)  i = (i + i) + 1; A1; }
 
 #define TREE_GET_BIT(probs, i) { GET_BIT2(probs + i, i, ;, ;); }
 
 #define REV_BIT(p, i, A0, A1) IF_BIT_0(p + i) \
-  { UPDATE_0(p + i); A0; } else \
-  { UPDATE_1(p + i); A1; }
+  { UPDATE_0(p + i)  A0; } else \
+  { UPDATE_1(p + i)  A1; }
 #define REV_BIT_VAR(  p, i, m) REV_BIT(p, i, i += m; m += m, m += m; i += m; )
 #define REV_BIT_CONST(p, i, m) REV_BIT(p, i, i += m;       , i += m * 2; )
 #define REV_BIT_LAST( p, i, m) REV_BIT(p, i, i -= m        , ; )
@@ -40,19 +40,19 @@
 #define TREE_DECODE(probs, limit, i) \
   { i = 1; do { TREE_GET_BIT(probs, i); } while (i < limit); i -= limit; }
 
-/* #define _LZMA_SIZE_OPT */
+/* #define Z7_LZMA_SIZE_OPT */
 
-#ifdef _LZMA_SIZE_OPT
+#ifdef Z7_LZMA_SIZE_OPT
 #define TREE_6_DECODE(probs, i) TREE_DECODE(probs, (1 << 6), i)
 #else
 #define TREE_6_DECODE(probs, i) \
   { i = 1; \
-  TREE_GET_BIT(probs, i); \
-  TREE_GET_BIT(probs, i); \
-  TREE_GET_BIT(probs, i); \
-  TREE_GET_BIT(probs, i); \
-  TREE_GET_BIT(probs, i); \
-  TREE_GET_BIT(probs, i); \
+  TREE_GET_BIT(probs, i) \
+  TREE_GET_BIT(probs, i) \
+  TREE_GET_BIT(probs, i) \
+  TREE_GET_BIT(probs, i) \
+  TREE_GET_BIT(probs, i) \
+  TREE_GET_BIT(probs, i) \
   i -= 0x40; }
 #endif
 
@@ -64,25 +64,25 @@
   probLit = prob + (offs + bit + symbol); \
   GET_BIT2(probLit, symbol, offs ^= bit; , ;)
 
-#endif // _LZMA_DEC_OPT
+#endif // Z7_LZMA_DEC_OPT
 
 
 #define NORMALIZE_CHECK if (range < kTopValue) { if (buf >= bufLimit) return DUMMY_INPUT_EOF; range <<= 8; code = (code << 8) | (*buf++); }
 
-#define IF_BIT_0_CHECK(p) ttt = *(p); NORMALIZE_CHECK; bound = (range >> kNumBitModelTotalBits) * (UInt32)ttt; if (code < bound)
+#define IF_BIT_0_CHECK(p) ttt = *(p); NORMALIZE_CHECK bound = (range >> kNumBitModelTotalBits) * (UInt32)ttt; if (code < bound)
 #define UPDATE_0_CHECK range = bound;
 #define UPDATE_1_CHECK range -= bound; code -= bound;
 #define GET_BIT2_CHECK(p, i, A0, A1) IF_BIT_0_CHECK(p) \
-  { UPDATE_0_CHECK; i = (i + i); A0; } else \
-  { UPDATE_1_CHECK; i = (i + i) + 1; A1; }
+  { UPDATE_0_CHECK  i = (i + i); A0; } else \
+  { UPDATE_1_CHECK  i = (i + i) + 1; A1; }
 #define GET_BIT_CHECK(p, i) GET_BIT2_CHECK(p, i, ; , ;)
 #define TREE_DECODE_CHECK(probs, limit, i) \
   { i = 1; do { GET_BIT_CHECK(probs + i, i) } while (i < limit); i -= limit; }
 
 
 #define REV_BIT_CHECK(p, i, m) IF_BIT_0_CHECK(p + i) \
-  { UPDATE_0_CHECK; i += m; m += m; } else \
-  { UPDATE_1_CHECK; m += m; i += m; }
+  { UPDATE_0_CHECK  i += m; m += m; } else \
+  { UPDATE_1_CHECK  m += m; i += m; }
 
 
 #define kNumPosBitsMax 4
@@ -224,14 +224,14 @@ Out:
 */
 
 
-#ifdef _LZMA_DEC_OPT
+#ifdef Z7_LZMA_DEC_OPT
 
-int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaDec *p, SizeT limit, const Byte *bufLimit);
+int Z7_FASTCALL LZMA_DECODE_REAL(CLzmaDec *p, SizeT limit, const Byte *bufLimit);
 
 #else
 
 static
-int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaDec *p, SizeT limit, const Byte *bufLimit)
+int Z7_FASTCALL LZMA_DECODE_REAL(CLzmaDec *p, SizeT limit, const Byte *bufLimit)
 {
   CLzmaProb *probs = GET_PROBS;
   unsigned state = (unsigned)p->state;
@@ -263,7 +263,7 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
     IF_BIT_0(prob)
     {
       unsigned symbol;
-      UPDATE_0(prob);
+      UPDATE_0(prob)
       prob = probs + Literal;
       if (processedPos != 0 || checkDicSize != 0)
         prob += (UInt32)3 * ((((processedPos << 8) + dic[(dicPos == 0 ? dicBufSize : dicPos) - 1]) & lpMask) << lc);
@@ -273,7 +273,7 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
       {
         state -= (state < 4) ? state : 3;
         symbol = 1;
-        #ifdef _LZMA_SIZE_OPT
+        #ifdef Z7_LZMA_SIZE_OPT
         do { NORMAL_LITER_DEC } while (symbol < 0x100);
         #else
         NORMAL_LITER_DEC
@@ -292,7 +292,7 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
         unsigned offs = 0x100;
         state -= (state < 10) ? 3 : 6;
         symbol = 1;
-        #ifdef _LZMA_SIZE_OPT
+        #ifdef Z7_LZMA_SIZE_OPT
         do
         {
           unsigned bit;
@@ -321,25 +321,25 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
     }
     
     {
-      UPDATE_1(prob);
+      UPDATE_1(prob)
       prob = probs + IsRep + state;
       IF_BIT_0(prob)
       {
-        UPDATE_0(prob);
+        UPDATE_0(prob)
         state += kNumStates;
         prob = probs + LenCoder;
       }
       else
       {
-        UPDATE_1(prob);
+        UPDATE_1(prob)
         prob = probs + IsRepG0 + state;
         IF_BIT_0(prob)
         {
-          UPDATE_0(prob);
+          UPDATE_0(prob)
           prob = probs + IsRep0Long + COMBINED_PS_STATE;
           IF_BIT_0(prob)
           {
-            UPDATE_0(prob);
+            UPDATE_0(prob)
   
             // that case was checked before with kBadRepCode
             // if (checkDicSize == 0 && processedPos == 0) { len = kMatchSpecLen_Error_Data + 1; break; }
@@ -353,30 +353,30 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
             state = state < kNumLitStates ? 9 : 11;
             continue;
           }
-          UPDATE_1(prob);
+          UPDATE_1(prob)
         }
         else
         {
           UInt32 distance;
-          UPDATE_1(prob);
+          UPDATE_1(prob)
           prob = probs + IsRepG1 + state;
           IF_BIT_0(prob)
           {
-            UPDATE_0(prob);
+            UPDATE_0(prob)
             distance = rep1;
           }
           else
           {
-            UPDATE_1(prob);
+            UPDATE_1(prob)
             prob = probs + IsRepG2 + state;
             IF_BIT_0(prob)
             {
-              UPDATE_0(prob);
+              UPDATE_0(prob)
               distance = rep2;
             }
             else
             {
-              UPDATE_1(prob);
+              UPDATE_1(prob)
               distance = rep3;
               rep3 = rep2;
             }
@@ -389,37 +389,37 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
         prob = probs + RepLenCoder;
       }
       
-      #ifdef _LZMA_SIZE_OPT
+      #ifdef Z7_LZMA_SIZE_OPT
       {
         unsigned lim, offset;
         CLzmaProb *probLen = prob + LenChoice;
         IF_BIT_0(probLen)
         {
-          UPDATE_0(probLen);
+          UPDATE_0(probLen)
           probLen = prob + LenLow + GET_LEN_STATE;
           offset = 0;
           lim = (1 << kLenNumLowBits);
         }
         else
         {
-          UPDATE_1(probLen);
+          UPDATE_1(probLen)
           probLen = prob + LenChoice2;
           IF_BIT_0(probLen)
           {
-            UPDATE_0(probLen);
+            UPDATE_0(probLen)
             probLen = prob + LenLow + GET_LEN_STATE + (1 << kLenNumLowBits);
             offset = kLenNumLowSymbols;
             lim = (1 << kLenNumLowBits);
           }
           else
           {
-            UPDATE_1(probLen);
+            UPDATE_1(probLen)
             probLen = prob + LenHigh;
             offset = kLenNumLowSymbols * 2;
             lim = (1 << kLenNumHighBits);
           }
         }
-        TREE_DECODE(probLen, lim, len);
+        TREE_DECODE(probLen, lim, len)
         len += offset;
       }
       #else
@@ -427,32 +427,32 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
         CLzmaProb *probLen = prob + LenChoice;
         IF_BIT_0(probLen)
         {
-          UPDATE_0(probLen);
+          UPDATE_0(probLen)
           probLen = prob + LenLow + GET_LEN_STATE;
           len = 1;
-          TREE_GET_BIT(probLen, len);
-          TREE_GET_BIT(probLen, len);
-          TREE_GET_BIT(probLen, len);
+          TREE_GET_BIT(probLen, len)
+          TREE_GET_BIT(probLen, len)
+          TREE_GET_BIT(probLen, len)
           len -= 8;
         }
         else
         {
-          UPDATE_1(probLen);
+          UPDATE_1(probLen)
           probLen = prob + LenChoice2;
           IF_BIT_0(probLen)
           {
-            UPDATE_0(probLen);
+            UPDATE_0(probLen)
             probLen = prob + LenLow + GET_LEN_STATE + (1 << kLenNumLowBits);
             len = 1;
-            TREE_GET_BIT(probLen, len);
-            TREE_GET_BIT(probLen, len);
-            TREE_GET_BIT(probLen, len);
+            TREE_GET_BIT(probLen, len)
+            TREE_GET_BIT(probLen, len)
+            TREE_GET_BIT(probLen, len)
           }
           else
           {
-            UPDATE_1(probLen);
+            UPDATE_1(probLen)
             probLen = prob + LenHigh;
-            TREE_DECODE(probLen, (1 << kLenNumHighBits), len);
+            TREE_DECODE(probLen, (1 << kLenNumHighBits), len)
             len += kLenNumLowSymbols * 2;
           }
         }
@@ -464,7 +464,7 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
         UInt32 distance;
         prob = probs + PosSlot +
             ((len < kNumLenToPosStates ? len : kNumLenToPosStates - 1) << kNumPosSlotBits);
-        TREE_6_DECODE(prob, distance);
+        TREE_6_DECODE(prob, distance)
         if (distance >= kStartPosModelIndex)
         {
           unsigned posSlot = (unsigned)distance;
@@ -479,7 +479,7 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
               distance++;
               do
               {
-                REV_BIT_VAR(prob, distance, m);
+                REV_BIT_VAR(prob, distance, m)
               }
               while (--numDirectBits);
               distance -= m;
@@ -514,10 +514,10 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
             distance <<= kNumAlignBits;
             {
               unsigned i = 1;
-              REV_BIT_CONST(prob, i, 1);
-              REV_BIT_CONST(prob, i, 2);
-              REV_BIT_CONST(prob, i, 4);
-              REV_BIT_LAST (prob, i, 8);
+              REV_BIT_CONST(prob, i, 1)
+              REV_BIT_CONST(prob, i, 2)
+              REV_BIT_CONST(prob, i, 4)
+              REV_BIT_LAST (prob, i, 8)
               distance |= i;
             }
             if (distance == (UInt32)0xFFFFFFFF)
@@ -592,7 +592,7 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
   }
   while (dicPos < limit && buf < bufLimit);
 
-  NORMALIZE;
+  NORMALIZE
   
   p->buf = buf;
   p->range = range;
@@ -613,7 +613,7 @@ int MY_FAST_CALL LZMA_DECODE_REAL(CLzmaD
 
 
 
-static void MY_FAST_CALL LzmaDec_WriteRem(CLzmaDec *p, SizeT limit)
+static void Z7_FASTCALL LzmaDec_WriteRem(CLzmaDec *p, SizeT limit)
 {
   unsigned len = (unsigned)p->remainLen;
   if (len == 0 /* || len >= kMatchSpecLenStart */)
@@ -683,7 +683,7 @@ and we support the following state of (p
     (p->checkDicSize == p->prop.dicSize)
 */
 
-static int MY_FAST_CALL LzmaDec_DecodeReal2(CLzmaDec *p, SizeT limit, const Byte *bufLimit)
+static int Z7_FASTCALL LzmaDec_DecodeReal2(CLzmaDec *p, SizeT limit, const Byte *bufLimit)
 {
   if (p->checkDicSize == 0)
   {
@@ -767,54 +767,54 @@ static ELzmaDummy LzmaDec_TryDummy(const
     else
     {
       unsigned len;
-      UPDATE_1_CHECK;
+      UPDATE_1_CHECK
 
       prob = probs + IsRep + state;
       IF_BIT_0_CHECK(prob)
       {
-        UPDATE_0_CHECK;
+        UPDATE_0_CHECK
         state = 0;
         prob = probs + LenCoder;
         res = DUMMY_MATCH;
       }
       else
       {
-        UPDATE_1_CHECK;
+        UPDATE_1_CHECK
         res = DUMMY_REP;
         prob = probs + IsRepG0 + state;
         IF_BIT_0_CHECK(prob)
         {
-          UPDATE_0_CHECK;
+          UPDATE_0_CHECK
           prob = probs + IsRep0Long + COMBINED_PS_STATE;
           IF_BIT_0_CHECK(prob)
           {
-            UPDATE_0_CHECK;
+            UPDATE_0_CHECK
             break;
           }
           else
           {
-            UPDATE_1_CHECK;
+            UPDATE_1_CHECK
           }
         }
         else
         {
-          UPDATE_1_CHECK;
+          UPDATE_1_CHECK
           prob = probs + IsRepG1 + state;
           IF_BIT_0_CHECK(prob)
           {
-            UPDATE_0_CHECK;
+            UPDATE_0_CHECK
           }
           else
           {
-            UPDATE_1_CHECK;
+            UPDATE_1_CHECK
             prob = probs + IsRepG2 + state;
             IF_BIT_0_CHECK(prob)
             {
-              UPDATE_0_CHECK;
+              UPDATE_0_CHECK
             }
             else
             {
-              UPDATE_1_CHECK;
+              UPDATE_1_CHECK
             }
           }
         }
@@ -826,31 +826,31 @@ static ELzmaDummy LzmaDec_TryDummy(const
         const CLzmaProb *probLen = prob + LenChoice;
         IF_BIT_0_CHECK(probLen)
         {
-          UPDATE_0_CHECK;
+          UPDATE_0_CHECK
           probLen = prob + LenLow + GET_LEN_STATE;
           offset = 0;
           limit = 1 << kLenNumLowBits;
         }
         else
         {
-          UPDATE_1_CHECK;
+          UPDATE_1_CHECK
           probLen = prob + LenChoice2;
           IF_BIT_0_CHECK(probLen)
           {
-            UPDATE_0_CHECK;
+            UPDATE_0_CHECK
             probLen = prob + LenLow + GET_LEN_STATE + (1 << kLenNumLowBits);
             offset = kLenNumLowSymbols;
             limit = 1 << kLenNumLowBits;
           }
           else
           {
-            UPDATE_1_CHECK;
+            UPDATE_1_CHECK
             probLen = prob + LenHigh;
             offset = kLenNumLowSymbols * 2;
             limit = 1 << kLenNumHighBits;
           }
         }
-        TREE_DECODE_CHECK(probLen, limit, len);
+        TREE_DECODE_CHECK(probLen, limit, len)
         len += offset;
       }
 
@@ -860,7 +860,7 @@ static ELzmaDummy LzmaDec_TryDummy(const
         prob = probs + PosSlot +
             ((len < kNumLenToPosStates - 1 ? len : kNumLenToPosStates - 1) <<
             kNumPosSlotBits);
-        TREE_DECODE_CHECK(prob, 1 << kNumPosSlotBits, posSlot);
+        TREE_DECODE_CHECK(prob, 1 << kNumPosSlotBits, posSlot)
         if (posSlot >= kStartPosModelIndex)
         {
           unsigned numDirectBits = ((posSlot >> 1) - 1);
@@ -888,7 +888,7 @@ static ELzmaDummy LzmaDec_TryDummy(const
             unsigned m = 1;
             do
             {
-              REV_BIT_CHECK(prob, i, m);
+              REV_BIT_CHECK(prob, i, m)
             }
             while (--numDirectBits);
           }
@@ -897,7 +897,7 @@ static ELzmaDummy LzmaDec_TryDummy(const
     }
     break;
   }
-  NORMALIZE_CHECK;
+  NORMALIZE_CHECK
 
   *bufOut = buf;
   return res;
@@ -943,7 +943,7 @@ When the decoder lookahead, and the look
 */
 
 
-#define RETURN__NOT_FINISHED__FOR_FINISH \
+#define RETURN_NOT_FINISHED_FOR_FINISH \
   *status = LZMA_STATUS_NOT_FINISHED; \
   return SZ_ERROR_DATA; // for strict mode
   // return SZ_OK; // for relaxed mode
@@ -1029,7 +1029,7 @@ SRes LzmaDec_DecodeToDic(CLzmaDec *p, Si
         }
         if (p->remainLen != 0)
         {
-          RETURN__NOT_FINISHED__FOR_FINISH;
+          RETURN_NOT_FINISHED_FOR_FINISH
         }
         checkEndMarkNow = 1;
       }
@@ -1072,7 +1072,7 @@ SRes LzmaDec_DecodeToDic(CLzmaDec *p, Si
             for (i = 0; i < (unsigned)dummyProcessed; i++)
               p->tempBuf[i] = src[i];
             // p->remainLen = kMatchSpecLen_Error_Data;
-            RETURN__NOT_FINISHED__FOR_FINISH;
+            RETURN_NOT_FINISHED_FOR_FINISH
           }
           
           bufLimit = src;
@@ -1150,7 +1150,7 @@ SRes LzmaDec_DecodeToDic(CLzmaDec *p, Si
             (*srcLen) += (unsigned)dummyProcessed - p->tempBufSize;
             p->tempBufSize = (unsigned)dummyProcessed;
             // p->remainLen = kMatchSpecLen_Error_Data;
-            RETURN__NOT_FINISHED__FOR_FINISH;
+            RETURN_NOT_FINISHED_FOR_FINISH
           }
         }
 
@@ -1299,8 +1299,8 @@ static SRes LzmaDec_AllocateProbs2(CLzma
 SRes LzmaDec_AllocateProbs(CLzmaDec *p, const Byte *props, unsigned propsSize, ISzAllocPtr alloc)
 {
   CLzmaProps propNew;
-  RINOK(LzmaProps_Decode(&propNew, props, propsSize));
-  RINOK(LzmaDec_AllocateProbs2(p, &propNew, alloc));
+  RINOK(LzmaProps_Decode(&propNew, props, propsSize))
+  RINOK(LzmaDec_AllocateProbs2(p, &propNew, alloc))
   p->prop = propNew;
   return SZ_OK;
 }
@@ -1309,14 +1309,14 @@ SRes LzmaDec_Allocate(CLzmaDec *p, const
 {
   CLzmaProps propNew;
   SizeT dicBufSize;
-  RINOK(LzmaProps_Decode(&propNew, props, propsSize));
-  RINOK(LzmaDec_AllocateProbs2(p, &propNew, alloc));
+  RINOK(LzmaProps_Decode(&propNew, props, propsSize))
+  RINOK(LzmaDec_AllocateProbs2(p, &propNew, alloc))
 
   {
     UInt32 dictSize = propNew.dicSize;
     SizeT mask = ((UInt32)1 << 12) - 1;
          if (dictSize >= ((UInt32)1 << 30)) mask = ((UInt32)1 << 22) - 1;
-    else if (dictSize >= ((UInt32)1 << 22)) mask = ((UInt32)1 << 20) - 1;;
+    else if (dictSize >= ((UInt32)1 << 22)) mask = ((UInt32)1 << 20) - 1;
     dicBufSize = ((SizeT)dictSize + mask) & ~mask;
     if (dicBufSize < dictSize)
       dicBufSize = dictSize;
@@ -1348,8 +1348,8 @@ SRes LzmaDecode(Byte *dest, SizeT *destL
   *status = LZMA_STATUS_NOT_SPECIFIED;
   if (inSize < RC_INIT_SIZE)
     return SZ_ERROR_INPUT_EOF;
-  LzmaDec_Construct(&p);
-  RINOK(LzmaDec_AllocateProbs(&p, propData, propSize, alloc));
+  LzmaDec_CONSTRUCT(&p)
+  RINOK(LzmaDec_AllocateProbs(&p, propData, propSize, alloc))
   p.dic = dest;
   p.dicBufSize = outSize;
   LzmaDec_Init(&p);
