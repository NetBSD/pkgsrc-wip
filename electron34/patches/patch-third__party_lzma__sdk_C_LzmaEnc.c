$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/LzmaEnc.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/LzmaEnc.c
@@ -1,5 +1,5 @@
 /* LzmaEnc.c -- LZMA Encoder
-2022-07-15: Igor Pavlov : Public domain */
+Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -16,22 +16,22 @@
 #include "LzmaEnc.h"
 
 #include "LzFind.h"
-#ifndef _7ZIP_ST
+#ifndef Z7_ST
 #include "LzFindMt.h"
 #endif
 
 /* the following LzmaEnc_* declarations is internal LZMA interface for LZMA2 encoder */
 
-SRes LzmaEnc_PrepareForLzma2(CLzmaEncHandle pp, ISeqInStream *inStream, UInt32 keepWindowSize,
+SRes LzmaEnc_PrepareForLzma2(CLzmaEncHandle p, ISeqInStreamPtr inStream, UInt32 keepWindowSize,
     ISzAllocPtr alloc, ISzAllocPtr allocBig);
-SRes LzmaEnc_MemPrepare(CLzmaEncHandle pp, const Byte *src, SizeT srcLen,
+SRes LzmaEnc_MemPrepare(CLzmaEncHandle p, const Byte *src, SizeT srcLen,
     UInt32 keepWindowSize, ISzAllocPtr alloc, ISzAllocPtr allocBig);
-SRes LzmaEnc_CodeOneMemBlock(CLzmaEncHandle pp, BoolInt reInit,
+SRes LzmaEnc_CodeOneMemBlock(CLzmaEncHandle p, BoolInt reInit,
     Byte *dest, size_t *destLen, UInt32 desiredPackSize, UInt32 *unpackSize);
-const Byte *LzmaEnc_GetCurBuf(CLzmaEncHandle pp);
-void LzmaEnc_Finish(CLzmaEncHandle pp);
-void LzmaEnc_SaveState(CLzmaEncHandle pp);
-void LzmaEnc_RestoreState(CLzmaEncHandle pp);
+const Byte *LzmaEnc_GetCurBuf(CLzmaEncHandle p);
+void LzmaEnc_Finish(CLzmaEncHandle p);
+void LzmaEnc_SaveState(CLzmaEncHandle p);
+void LzmaEnc_RestoreState(CLzmaEncHandle p);
 
 #ifdef SHOW_STAT
 static unsigned g_STAT_OFFSET = 0;
@@ -40,8 +40,8 @@ static unsigned g_STAT_OFFSET = 0;
 /* for good normalization speed we still reserve 256 MB before 4 GB range */
 #define kLzmaMaxHistorySize ((UInt32)15 << 28)
 
-#define kNumTopBits 24
-#define kTopValue ((UInt32)1 << kNumTopBits)
+// #define kNumTopBits 24
+#define kTopValue ((UInt32)1 << 24)
 
 #define kNumBitModelTotalBits 11
 #define kBitModelTotal (1 << kNumBitModelTotalBits)
@@ -60,6 +60,7 @@ void LzmaEncProps_Init(CLzmaEncProps *p)
   p->dictSize = p->mc = 0;
   p->reduceSize = (UInt64)(Int64)-1;
   p->lc = p->lp = p->pb = p->algo = p->fb = p->btMode = p->numHashBytes = p->numThreads = -1;
+  p->numHashOutBits = 0;
   p->writeEndMark = 0;
   p->affinity = 0;
 }
@@ -71,11 +72,11 @@ void LzmaEncProps_Normalize(CLzmaEncProp
   p->level = level;
   
   if (p->dictSize == 0)
-    p->dictSize =
-      ( level <= 3 ? ((UInt32)1 << (level * 2 + 16)) :
-      ( level <= 6 ? ((UInt32)1 << (level + 19)) :
-      ( level <= 7 ? ((UInt32)1 << 25) : ((UInt32)1 << 26)
-      )));
+    p->dictSize = (unsigned)level <= 4 ?
+        (UInt32)1 << (level * 2 + 16) :
+        (unsigned)level <= sizeof(size_t) / 2 + 4 ?
+          (UInt32)1 << (level + 20) :
+          (UInt32)1 << (sizeof(size_t) / 2 + 24);
 
   if (p->dictSize > p->reduceSize)
   {
@@ -91,15 +92,15 @@ void LzmaEncProps_Normalize(CLzmaEncProp
   if (p->lp < 0) p->lp = 0;
   if (p->pb < 0) p->pb = 2;
 
-  if (p->algo < 0) p->algo = (level < 5 ? 0 : 1);
-  if (p->fb < 0) p->fb = (level < 7 ? 32 : 64);
+  if (p->algo < 0) p->algo = (unsigned)level < 5 ? 0 : 1;
+  if (p->fb < 0) p->fb = (unsigned)level < 7 ? 32 : 64;
   if (p->btMode < 0) p->btMode = (p->algo == 0 ? 0 : 1);
   if (p->numHashBytes < 0) p->numHashBytes = (p->btMode ? 4 : 5);
   if (p->mc == 0) p->mc = (16 + ((unsigned)p->fb >> 1)) >> (p->btMode ? 0 : 1);
   
   if (p->numThreads < 0)
     p->numThreads =
-      #ifndef _7ZIP_ST
+      #ifndef Z7_ST
       ((p->btMode && p->algo) ? 2 : 1);
       #else
       1;
@@ -194,11 +195,11 @@ unsigned GetPosSlot1(UInt32 pos);
 unsigned GetPosSlot1(UInt32 pos)
 {
   unsigned res;
-  BSR2_RET(pos, res);
+  BSR2_RET(pos, res)
   return res;
 }
-#define GetPosSlot2(pos, res) { BSR2_RET(pos, res); }
-#define GetPosSlot(pos, res) { if (pos < 2) res = pos; else BSR2_RET(pos, res); }
+#define GetPosSlot2(pos, res) { BSR2_RET(pos, res) }
+#define GetPosSlot(pos, res) { if (pos < 2) res = pos; else BSR2_RET(pos, res) }
 
 
 #else // ! LZMA_LOG_BSR
@@ -293,7 +294,7 @@ typedef struct
 #define kNumFullDistances (1 << (kEndPosModelIndex >> 1))
 
 typedef
-#ifdef _LZMA_PROB32
+#ifdef Z7_LZMA_PROB32
   UInt32
 #else
   UInt16
@@ -350,7 +351,7 @@ typedef struct
   Byte *buf;
   Byte *bufLim;
   Byte *bufBase;
-  ISeqOutStream *outStream;
+  ISeqOutStreamPtr outStream;
   UInt64 processed;
   SRes res;
 } CRangeEnc;
@@ -383,7 +384,7 @@ typedef struct
 typedef UInt32 CProbPrice;
 
 
-typedef struct
+struct CLzmaEnc
 {
   void *matchFinderObj;
   IMatchFinder2 matchFinder;
@@ -426,7 +427,7 @@ typedef struct
   UInt32 dictSize;
   SRes result;
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   BoolInt mtMode;
   // begin of CMatchFinderMt is used in LZ thread
   CMatchFinderMt matchFinderMt;
@@ -439,7 +440,7 @@ typedef struct
   
   // we suppose that we have 8-bytes alignment after CMatchFinder
  
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   Byte pad[128];
   #endif
   
@@ -479,77 +480,59 @@ typedef struct
   CSaveState saveState;
 
   // BoolInt mf_Failure;
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   Byte pad2[128];
   #endif
-} CLzmaEnc;
+};
 
 
 #define MFB (p->matchFinderBase)
 /*
-#ifndef _7ZIP_ST
+#ifndef Z7_ST
 #define MFB (p->matchFinderMt.MatchFinder)
 #endif
 */
 
-#define COPY_ARR(dest, src, arr) memcpy(dest->arr, src->arr, sizeof(src->arr));
+// #define GET_CLzmaEnc_p  CLzmaEnc *p = (CLzmaEnc*)(void *)p;
+// #define GET_const_CLzmaEnc_p  const CLzmaEnc *p = (const CLzmaEnc*)(const void *)p;
 
-void LzmaEnc_SaveState(CLzmaEncHandle pp)
-{
-  CLzmaEnc *p = (CLzmaEnc *)pp;
-  CSaveState *dest = &p->saveState;
-  
-  dest->state = p->state;
-  
-  dest->lenProbs = p->lenProbs;
-  dest->repLenProbs = p->repLenProbs;
-
-  COPY_ARR(dest, p, reps);
+#define COPY_ARR(dest, src, arr)  memcpy((dest)->arr, (src)->arr, sizeof((src)->arr));
 
-  COPY_ARR(dest, p, posAlignEncoder);
-  COPY_ARR(dest, p, isRep);
-  COPY_ARR(dest, p, isRepG0);
-  COPY_ARR(dest, p, isRepG1);
-  COPY_ARR(dest, p, isRepG2);
-  COPY_ARR(dest, p, isMatch);
-  COPY_ARR(dest, p, isRep0Long);
-  COPY_ARR(dest, p, posSlotEncoder);
-  COPY_ARR(dest, p, posEncoders);
+#define COPY_LZMA_ENC_STATE(d, s, p)  \
+  (d)->state = (s)->state;  \
+  COPY_ARR(d, s, reps)  \
+  COPY_ARR(d, s, posAlignEncoder)  \
+  COPY_ARR(d, s, isRep)  \
+  COPY_ARR(d, s, isRepG0)  \
+  COPY_ARR(d, s, isRepG1)  \
+  COPY_ARR(d, s, isRepG2)  \
+  COPY_ARR(d, s, isMatch)  \
+  COPY_ARR(d, s, isRep0Long)  \
+  COPY_ARR(d, s, posSlotEncoder)  \
+  COPY_ARR(d, s, posEncoders)  \
+  (d)->lenProbs = (s)->lenProbs;  \
+  (d)->repLenProbs = (s)->repLenProbs;  \
+  memcpy((d)->litProbs, (s)->litProbs, ((size_t)0x300 * sizeof(CLzmaProb)) << (p)->lclp);
 
-  memcpy(dest->litProbs, p->litProbs, ((UInt32)0x300 << p->lclp) * sizeof(CLzmaProb));
+void LzmaEnc_SaveState(CLzmaEncHandle p)
+{
+  // GET_CLzmaEnc_p
+  CSaveState *v = &p->saveState;
+  COPY_LZMA_ENC_STATE(v, p, p)
 }
 
-
-void LzmaEnc_RestoreState(CLzmaEncHandle pp)
+void LzmaEnc_RestoreState(CLzmaEncHandle p)
 {
-  CLzmaEnc *dest = (CLzmaEnc *)pp;
-  const CSaveState *p = &dest->saveState;
-
-  dest->state = p->state;
-
-  dest->lenProbs = p->lenProbs;
-  dest->repLenProbs = p->repLenProbs;
-  
-  COPY_ARR(dest, p, reps);
-  
-  COPY_ARR(dest, p, posAlignEncoder);
-  COPY_ARR(dest, p, isRep);
-  COPY_ARR(dest, p, isRepG0);
-  COPY_ARR(dest, p, isRepG1);
-  COPY_ARR(dest, p, isRepG2);
-  COPY_ARR(dest, p, isMatch);
-  COPY_ARR(dest, p, isRep0Long);
-  COPY_ARR(dest, p, posSlotEncoder);
-  COPY_ARR(dest, p, posEncoders);
-
-  memcpy(dest->litProbs, p->litProbs, ((UInt32)0x300 << dest->lclp) * sizeof(CLzmaProb));
+  // GET_CLzmaEnc_p
+  const CSaveState *v = &p->saveState;
+  COPY_LZMA_ENC_STATE(p, v, p)
 }
 
 
-
-SRes LzmaEnc_SetProps(CLzmaEncHandle pp, const CLzmaEncProps *props2)
+Z7_NO_INLINE
+SRes LzmaEnc_SetProps(CLzmaEncHandle p, const CLzmaEncProps *props2)
 {
-  CLzmaEnc *p = (CLzmaEnc *)pp;
+  // GET_CLzmaEnc_p
   CLzmaEncProps props = *props2;
   LzmaEncProps_Normalize(&props);
 
@@ -585,6 +568,7 @@ SRes LzmaEnc_SetProps(CLzmaEncHandle pp,
   p->fastMode = (props.algo == 0);
   // p->_maxMode = True;
   MFB.btMode = (Byte)(props.btMode ? 1 : 0);
+  // MFB.btMode = (Byte)(props.btMode);
   {
     unsigned numHashBytes = 4;
     if (props.btMode)
@@ -595,13 +579,15 @@ SRes LzmaEnc_SetProps(CLzmaEncHandle pp,
     if (props.numHashBytes >= 5) numHashBytes = 5;
 
     MFB.numHashBytes = numHashBytes;
+    // MFB.numHashBytes_Min = 2;
+    MFB.numHashOutBits = (Byte)props.numHashOutBits;
   }
 
   MFB.cutValue = props.mc;
 
   p->writeEndMark = (BoolInt)props.writeEndMark;
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   /*
   if (newMultiThread != _multiThread)
   {
@@ -618,9 +604,9 @@ SRes LzmaEnc_SetProps(CLzmaEncHandle pp,
 }
 
 
-void LzmaEnc_SetDataSize(CLzmaEncHandle pp, UInt64 expectedDataSiize)
+void LzmaEnc_SetDataSize(CLzmaEncHandle p, UInt64 expectedDataSiize)
 {
-  CLzmaEnc *p = (CLzmaEnc *)pp;
+  // GET_CLzmaEnc_p
   MFB.expectedDataSize = expectedDataSiize;
 }
 
@@ -684,7 +670,7 @@ static void RangeEnc_Init(CRangeEnc *p)
   p->res = SZ_OK;
 }
 
-MY_NO_INLINE static void RangeEnc_FlushStream(CRangeEnc *p)
+Z7_NO_INLINE static void RangeEnc_FlushStream(CRangeEnc *p)
 {
   const size_t num = (size_t)(p->buf - p->bufBase);
   if (p->res == SZ_OK)
@@ -696,7 +682,7 @@ MY_NO_INLINE static void RangeEnc_FlushS
   p->buf = p->bufBase;
 }
 
-MY_NO_INLINE static void MY_FAST_CALL RangeEnc_ShiftLow(CRangeEnc *p)
+Z7_NO_INLINE static void Z7_FASTCALL RangeEnc_ShiftLow(CRangeEnc *p)
 {
   UInt32 low = (UInt32)p->low;
   unsigned high = (unsigned)(p->low >> 32);
@@ -741,9 +727,9 @@ static void RangeEnc_FlushData(CRangeEnc
   ttt = *(prob); \
   newBound = (range >> kNumBitModelTotalBits) * ttt;
 
-// #define _LZMA_ENC_USE_BRANCH
+// #define Z7_LZMA_ENC_USE_BRANCH
 
-#ifdef _LZMA_ENC_USE_BRANCH
+#ifdef Z7_LZMA_ENC_USE_BRANCH
 
 #define RC_BIT(p, prob, bit) { \
   RC_BIT_PRE(p, prob) \
@@ -811,7 +797,7 @@ static void LitEnc_Encode(CRangeEnc *p, 
     CLzmaProb *prob = probs + (sym >> 8);
     UInt32 bit = (sym >> 7) & 1;
     sym <<= 1;
-    RC_BIT(p, prob, bit);
+    RC_BIT(p, prob, bit)
   }
   while (sym < 0x10000);
   p->range = range;
@@ -833,7 +819,7 @@ static void LitEnc_EncodeMatched(CRangeE
     bit = (sym >> 7) & 1;
     sym <<= 1;
     offs &= ~(matchByte ^ sym);
-    RC_BIT(p, prob, bit);
+    RC_BIT(p, prob, bit)
   }
   while (sym < 0x10000);
   p->range = range;
@@ -867,10 +853,10 @@ static void LzmaEnc_InitPriceTables(CPro
 
 
 #define GET_PRICE(prob, bit) \
-  p->ProbPrices[((prob) ^ (unsigned)(((-(int)(bit))) & (kBitModelTotal - 1))) >> kNumMoveReducingBits];
+  p->ProbPrices[((prob) ^ (unsigned)(((-(int)(bit))) & (kBitModelTotal - 1))) >> kNumMoveReducingBits]
 
 #define GET_PRICEa(prob, bit) \
-     ProbPrices[((prob) ^ (unsigned)((-((int)(bit))) & (kBitModelTotal - 1))) >> kNumMoveReducingBits];
+     ProbPrices[((prob) ^ (unsigned)((-((int)(bit))) & (kBitModelTotal - 1))) >> kNumMoveReducingBits]
 
 #define GET_PRICE_0(prob) p->ProbPrices[(prob) >> kNumMoveReducingBits]
 #define GET_PRICE_1(prob) p->ProbPrices[((prob) ^ (kBitModelTotal - 1)) >> kNumMoveReducingBits]
@@ -921,7 +907,7 @@ static void RcTree_ReverseEncode(CRangeE
     unsigned bit = sym & 1;
     // RangeEnc_EncodeBit(rc, probs + m, bit);
     sym >>= 1;
-    RC_BIT(rc, probs + m, bit);
+    RC_BIT(rc, probs + m, bit)
     m = (m << 1) | bit;
   }
   while (--numBits);
@@ -944,15 +930,15 @@ static void LenEnc_Encode(CLenEnc *p, CR
   UInt32 range, ttt, newBound;
   CLzmaProb *probs = p->low;
   range = rc->range;
-  RC_BIT_PRE(rc, probs);
+  RC_BIT_PRE(rc, probs)
   if (sym >= kLenNumLowSymbols)
   {
-    RC_BIT_1(rc, probs);
+    RC_BIT_1(rc, probs)
     probs += kLenNumLowSymbols;
-    RC_BIT_PRE(rc, probs);
+    RC_BIT_PRE(rc, probs)
     if (sym >= kLenNumLowSymbols * 2)
     {
-      RC_BIT_1(rc, probs);
+      RC_BIT_1(rc, probs)
       rc->range = range;
       // RcTree_Encode(rc, p->high, kLenNumHighBits, sym - kLenNumLowSymbols * 2);
       LitEnc_Encode(rc, p->high, sym - kLenNumLowSymbols * 2);
@@ -965,11 +951,11 @@ static void LenEnc_Encode(CLenEnc *p, CR
   {
     unsigned m;
     unsigned bit;
-    RC_BIT_0(rc, probs);
+    RC_BIT_0(rc, probs)
     probs += (posState << (1 + kLenNumLowBits));
-    bit = (sym >> 2)    ; RC_BIT(rc, probs + 1, bit); m = (1 << 1) + bit;
-    bit = (sym >> 1) & 1; RC_BIT(rc, probs + m, bit); m = (m << 1) + bit;
-    bit =  sym       & 1; RC_BIT(rc, probs + m, bit);
+    bit = (sym >> 2)    ; RC_BIT(rc, probs + 1, bit)  m = (1 << 1) + bit;
+    bit = (sym >> 1) & 1; RC_BIT(rc, probs + m, bit)  m = (m << 1) + bit;
+    bit =  sym       & 1; RC_BIT(rc, probs + m, bit)
     rc->range = range;
   }
 }
@@ -990,7 +976,7 @@ static void SetPrices_3(const CLzmaProb 
 }
 
 
-MY_NO_INLINE static void MY_FAST_CALL LenPriceEnc_UpdateTables(
+Z7_NO_INLINE static void Z7_FASTCALL LenPriceEnc_UpdateTables(
     CLenPriceEnc *p,
     unsigned numPosStates,
     const CLenEnc *enc,
@@ -1054,14 +1040,14 @@ MY_NO_INLINE static void MY_FAST_CALL Le
         UInt32 price = b;
         do
         {
-          unsigned bit = sym & 1;
+          const unsigned bit = sym & 1;
           sym >>= 1;
           price += GET_PRICEa(probs[sym], bit);
         }
         while (sym >= 2);
 
         {
-          unsigned prob = probs[(size_t)i + (1 << (kLenNumHighBits - 1))];
+          const unsigned prob = probs[(size_t)i + (1 << (kLenNumHighBits - 1))];
           prices[(size_t)i * 2    ] = price + GET_PRICEa_0(prob);
           prices[(size_t)i * 2 + 1] = price + GET_PRICEa_1(prob);
         }
@@ -1070,7 +1056,7 @@ MY_NO_INLINE static void MY_FAST_CALL Le
 
       {
         unsigned posState;
-        size_t num = (p->tableSize - kLenNumLowSymbols * 2) * sizeof(p->prices[0][0]);
+        const size_t num = (p->tableSize - kLenNumLowSymbols * 2) * sizeof(p->prices[0][0]);
         for (posState = 1; posState < numPosStates; posState++)
           memcpy(p->prices[posState] + kLenNumLowSymbols * 2, p->prices[0] + kLenNumLowSymbols * 2, num);
       }
@@ -1152,7 +1138,7 @@ static unsigned ReadMatchDistances(CLzma
   + GET_PRICE_1(p->isRep[state]) \
   + GET_PRICE_0(p->isRepG0[state])
   
-MY_FORCE_INLINE
+Z7_FORCE_INLINE
 static UInt32 GetPrice_PureRep(const CLzmaEnc *p, unsigned repIndex, size_t state, size_t posState)
 {
   UInt32 price;
@@ -1331,7 +1317,7 @@ static unsigned GetOptimum(CLzmaEnc *p, 
           LitEnc_GetPrice(probs, curByte, p->ProbPrices));
     }
 
-    MakeAs_Lit(&p->opt[1]);
+    MakeAs_Lit(&p->opt[1])
     
     matchPrice = GET_PRICE_1(p->isMatch[p->state][posState]);
     repMatchPrice = matchPrice + GET_PRICE_1(p->isRep[p->state]);
@@ -1343,7 +1329,7 @@ static unsigned GetOptimum(CLzmaEnc *p, 
       if (shortRepPrice < p->opt[1].price)
       {
         p->opt[1].price = shortRepPrice;
-        MakeAs_ShortRep(&p->opt[1]);
+        MakeAs_ShortRep(&p->opt[1])
       }
       if (last < 2)
       {
@@ -1410,7 +1396,7 @@ static unsigned GetOptimum(CLzmaEnc *p, 
           else
           {
             unsigned slot;
-            GetPosSlot2(dist, slot);
+            GetPosSlot2(dist, slot)
             price += p->alignPrices[dist & kAlignMask];
             price += p->posSlotPrices[lenToPosState][slot];
           }
@@ -1486,7 +1472,7 @@ static unsigned GetOptimum(CLzmaEnc *p, 
         unsigned delta = best - cur;
         if (delta != 0)
         {
-          MOVE_POS(p, delta);
+          MOVE_POS(p, delta)
         }
       }
       cur = best;
@@ -1633,7 +1619,7 @@ static unsigned GetOptimum(CLzmaEnc *p, 
       {
         nextOpt->price = litPrice;
         nextOpt->len = 1;
-        MakeAs_Lit(nextOpt);
+        MakeAs_Lit(nextOpt)
         nextIsLit = True;
       }
     }
@@ -1667,7 +1653,7 @@ static unsigned GetOptimum(CLzmaEnc *p, 
       {
         nextOpt->price = shortRepPrice;
         nextOpt->len = 1;
-        MakeAs_ShortRep(nextOpt);
+        MakeAs_ShortRep(nextOpt)
         nextIsLit = False;
       }
     }
@@ -1871,7 +1857,7 @@ static unsigned GetOptimum(CLzmaEnc *p, 
       dist = MATCHES[(size_t)offs + 1];
       
       // if (dist >= kNumFullDistances)
-      GetPosSlot2(dist, posSlot);
+      GetPosSlot2(dist, posSlot)
       
       for (len = /*2*/ startLen; ; len++)
       {
@@ -1962,7 +1948,7 @@ static unsigned GetOptimum(CLzmaEnc *p, 
             break;
           dist = MATCHES[(size_t)offs + 1];
           // if (dist >= kNumFullDistances)
-            GetPosSlot2(dist, posSlot);
+            GetPosSlot2(dist, posSlot)
         }
       }
     }
@@ -2138,7 +2124,7 @@ static void WriteEndMarker(CLzmaEnc *p, 
     {
       UInt32 ttt, newBound;
       RC_BIT_PRE(p, probs + m)
-      RC_BIT_1(&p->rc, probs + m);
+      RC_BIT_1(&p->rc, probs + m)
       m = (m << 1) + 1;
     }
     while (m < (1 << kNumPosSlotBits));
@@ -2163,7 +2149,7 @@ static void WriteEndMarker(CLzmaEnc *p, 
     {
       UInt32 ttt, newBound;
       RC_BIT_PRE(p, probs + m)
-      RC_BIT_1(&p->rc, probs + m);
+      RC_BIT_1(&p->rc, probs + m)
       m = (m << 1) + 1;
     }
     while (m < kAlignTableSize);
@@ -2179,7 +2165,7 @@ static SRes CheckErrors(CLzmaEnc *p)
   if (p->rc.res != SZ_OK)
     p->result = SZ_ERROR_WRITE;
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   if (
       // p->mf_Failure ||
         (p->mtMode &&
@@ -2187,7 +2173,7 @@ static SRes CheckErrors(CLzmaEnc *p)
             p->matchFinderMt.failure_LZ_BT))
      )
   {
-    p->result = MY_HRES_ERROR__INTERNAL_ERROR;
+    p->result = MY_HRES_ERROR_INTERNAL_ERROR;
     // printf("\nCheckErrors p->matchFinderMt.failureLZ\n");
   }
   #endif
@@ -2201,7 +2187,7 @@ static SRes CheckErrors(CLzmaEnc *p)
 }
 
 
-MY_NO_INLINE static SRes Flush(CLzmaEnc *p, UInt32 nowPos)
+Z7_NO_INLINE static SRes Flush(CLzmaEnc *p, UInt32 nowPos)
 {
   /* ReleaseMFStream(); */
   p->finished = True;
@@ -2213,7 +2199,7 @@ MY_NO_INLINE static SRes Flush(CLzmaEnc 
 }
 
 
-MY_NO_INLINE static void FillAlignPrices(CLzmaEnc *p)
+Z7_NO_INLINE static void FillAlignPrices(CLzmaEnc *p)
 {
   unsigned i;
   const CProbPrice *ProbPrices = p->ProbPrices;
@@ -2237,7 +2223,7 @@ MY_NO_INLINE static void FillAlignPrices
 }
 
 
-MY_NO_INLINE static void FillDistancesPrices(CLzmaEnc *p)
+Z7_NO_INLINE static void FillDistancesPrices(CLzmaEnc *p)
 {
   // int y; for (y = 0; y < 100; y++) {
 
@@ -2337,7 +2323,7 @@ static void LzmaEnc_Construct(CLzmaEnc *
   RangeEnc_Construct(&p->rc);
   MatchFinder_Construct(&MFB);
   
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   p->matchFinderMt.MatchFinder = &MFB;
   MatchFinderMt_Construct(&p->matchFinderMt);
   #endif
@@ -2345,7 +2331,7 @@ static void LzmaEnc_Construct(CLzmaEnc *
   {
     CLzmaEncProps props;
     LzmaEncProps_Init(&props);
-    LzmaEnc_SetProps(p, &props);
+    LzmaEnc_SetProps((CLzmaEncHandle)(void *)p, &props);
   }
 
   #ifndef LZMA_LOG_BSR
@@ -2376,7 +2362,7 @@ static void LzmaEnc_FreeLits(CLzmaEnc *p
 
 static void LzmaEnc_Destruct(CLzmaEnc *p, ISzAllocPtr alloc, ISzAllocPtr allocBig)
 {
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   MatchFinderMt_Destruct(&p->matchFinderMt, allocBig);
   #endif
   
@@ -2387,21 +2373,22 @@ static void LzmaEnc_Destruct(CLzmaEnc *p
 
 void LzmaEnc_Destroy(CLzmaEncHandle p, ISzAllocPtr alloc, ISzAllocPtr allocBig)
 {
-  LzmaEnc_Destruct((CLzmaEnc *)p, alloc, allocBig);
+  // GET_CLzmaEnc_p
+  LzmaEnc_Destruct(p, alloc, allocBig);
   ISzAlloc_Free(alloc, p);
 }
 
 
-MY_NO_INLINE
+Z7_NO_INLINE
 static SRes LzmaEnc_CodeOneBlock(CLzmaEnc *p, UInt32 maxPackSize, UInt32 maxUnpackSize)
 {
   UInt32 nowPos32, startPos32;
   if (p->needInit)
   {
-    #ifndef _7ZIP_ST
+    #ifndef Z7_ST
     if (p->mtMode)
     {
-      RINOK(MatchFinderMt_InitMt(&p->matchFinderMt));
+      RINOK(MatchFinderMt_InitMt(&p->matchFinderMt))
     }
     #endif
     p->matchFinder.Init(p->matchFinderObj);
@@ -2410,7 +2397,7 @@ static SRes LzmaEnc_CodeOneBlock(CLzmaEn
 
   if (p->finished)
     return p->result;
-  RINOK(CheckErrors(p));
+  RINOK(CheckErrors(p))
 
   nowPos32 = (UInt32)p->nowPos64;
   startPos32 = nowPos32;
@@ -2473,7 +2460,7 @@ static SRes LzmaEnc_CodeOneBlock(CLzmaEn
       const Byte *data;
       unsigned state;
 
-      RC_BIT_0(&p->rc, probs);
+      RC_BIT_0(&p->rc, probs)
       p->rc.range = range;
       data = p->matchFinder.GetPointerToCurrentPos(p->matchFinderObj) - p->additionalOffset;
       probs = LIT_PROBS(nowPos32, *(data - 1));
@@ -2487,53 +2474,53 @@ static SRes LzmaEnc_CodeOneBlock(CLzmaEn
     }
     else
     {
-      RC_BIT_1(&p->rc, probs);
+      RC_BIT_1(&p->rc, probs)
       probs = &p->isRep[p->state];
       RC_BIT_PRE(&p->rc, probs)
       
       if (dist < LZMA_NUM_REPS)
       {
-        RC_BIT_1(&p->rc, probs);
+        RC_BIT_1(&p->rc, probs)
         probs = &p->isRepG0[p->state];
         RC_BIT_PRE(&p->rc, probs)
         if (dist == 0)
         {
-          RC_BIT_0(&p->rc, probs);
+          RC_BIT_0(&p->rc, probs)
           probs = &p->isRep0Long[p->state][posState];
           RC_BIT_PRE(&p->rc, probs)
           if (len != 1)
           {
-            RC_BIT_1_BASE(&p->rc, probs);
+            RC_BIT_1_BASE(&p->rc, probs)
           }
           else
           {
-            RC_BIT_0_BASE(&p->rc, probs);
+            RC_BIT_0_BASE(&p->rc, probs)
             p->state = kShortRepNextStates[p->state];
           }
         }
         else
         {
-          RC_BIT_1(&p->rc, probs);
+          RC_BIT_1(&p->rc, probs)
           probs = &p->isRepG1[p->state];
           RC_BIT_PRE(&p->rc, probs)
           if (dist == 1)
           {
-            RC_BIT_0_BASE(&p->rc, probs);
+            RC_BIT_0_BASE(&p->rc, probs)
             dist = p->reps[1];
           }
           else
           {
-            RC_BIT_1(&p->rc, probs);
+            RC_BIT_1(&p->rc, probs)
             probs = &p->isRepG2[p->state];
             RC_BIT_PRE(&p->rc, probs)
             if (dist == 2)
             {
-              RC_BIT_0_BASE(&p->rc, probs);
+              RC_BIT_0_BASE(&p->rc, probs)
               dist = p->reps[2];
             }
             else
             {
-              RC_BIT_1_BASE(&p->rc, probs);
+              RC_BIT_1_BASE(&p->rc, probs)
               dist = p->reps[3];
               p->reps[3] = p->reps[2];
             }
@@ -2557,7 +2544,7 @@ static SRes LzmaEnc_CodeOneBlock(CLzmaEn
       else
       {
         unsigned posSlot;
-        RC_BIT_0(&p->rc, probs);
+        RC_BIT_0(&p->rc, probs)
         p->rc.range = range;
         p->state = kMatchNextStates[p->state];
 
@@ -2571,7 +2558,7 @@ static SRes LzmaEnc_CodeOneBlock(CLzmaEn
         p->reps[0] = dist + 1;
         
         p->matchPriceCount++;
-        GetPosSlot(dist, posSlot);
+        GetPosSlot(dist, posSlot)
         // RcTree_Encode_PosSlot(&p->rc, p->posSlotEncoder[GetLenToPosState(len)], posSlot);
         {
           UInt32 sym = (UInt32)posSlot + (1 << kNumPosSlotBits);
@@ -2582,7 +2569,7 @@ static SRes LzmaEnc_CodeOneBlock(CLzmaEn
             CLzmaProb *prob = probs + (sym >> kNumPosSlotBits);
             UInt32 bit = (sym >> (kNumPosSlotBits - 1)) & 1;
             sym <<= 1;
-            RC_BIT(&p->rc, prob, bit);
+            RC_BIT(&p->rc, prob, bit)
           }
           while (sym < (1 << kNumPosSlotBits * 2));
           p->rc.range = range;
@@ -2626,10 +2613,10 @@ static SRes LzmaEnc_CodeOneBlock(CLzmaEn
             {
               unsigned m = 1;
               unsigned bit;
-              bit = dist & 1; dist >>= 1; RC_BIT(&p->rc, p->posAlignEncoder + m, bit); m = (m << 1) + bit;
-              bit = dist & 1; dist >>= 1; RC_BIT(&p->rc, p->posAlignEncoder + m, bit); m = (m << 1) + bit;
-              bit = dist & 1; dist >>= 1; RC_BIT(&p->rc, p->posAlignEncoder + m, bit); m = (m << 1) + bit;
-              bit = dist & 1;             RC_BIT(&p->rc, p->posAlignEncoder + m, bit);
+              bit = dist & 1; dist >>= 1; RC_BIT(&p->rc, p->posAlignEncoder + m, bit)  m = (m << 1) + bit;
+              bit = dist & 1; dist >>= 1; RC_BIT(&p->rc, p->posAlignEncoder + m, bit)  m = (m << 1) + bit;
+              bit = dist & 1; dist >>= 1; RC_BIT(&p->rc, p->posAlignEncoder + m, bit)  m = (m << 1) + bit;
+              bit = dist & 1;             RC_BIT(&p->rc, p->posAlignEncoder + m, bit)
               p->rc.range = range;
               // p->alignPriceCount++;
             }
@@ -2704,17 +2691,17 @@ static SRes LzmaEnc_Alloc(CLzmaEnc *p, U
   if (!RangeEnc_Alloc(&p->rc, alloc))
     return SZ_ERROR_MEM;
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   p->mtMode = (p->multiThread && !p->fastMode && (MFB.btMode != 0));
   #endif
 
   {
-    unsigned lclp = p->lc + p->lp;
+    const unsigned lclp = p->lc + p->lp;
     if (!p->litProbs || !p->saveState.litProbs || p->lclp != lclp)
     {
       LzmaEnc_FreeLits(p, alloc);
-      p->litProbs = (CLzmaProb *)ISzAlloc_Alloc(alloc, ((UInt32)0x300 << lclp) * sizeof(CLzmaProb));
-      p->saveState.litProbs = (CLzmaProb *)ISzAlloc_Alloc(alloc, ((UInt32)0x300 << lclp) * sizeof(CLzmaProb));
+      p->litProbs =           (CLzmaProb *)ISzAlloc_Alloc(alloc, ((size_t)0x300 * sizeof(CLzmaProb)) << lclp);
+      p->saveState.litProbs = (CLzmaProb *)ISzAlloc_Alloc(alloc, ((size_t)0x300 * sizeof(CLzmaProb)) << lclp);
       if (!p->litProbs || !p->saveState.litProbs)
       {
         LzmaEnc_FreeLits(p, alloc);
@@ -2748,15 +2735,14 @@ static SRes LzmaEnc_Alloc(CLzmaEnc *p, U
         (numFastBytes + LZMA_MATCH_LEN_MAX + 1)
   */
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   if (p->mtMode)
   {
     RINOK(MatchFinderMt_Create(&p->matchFinderMt, dictSize, beforeSize,
         p->numFastBytes, LZMA_MATCH_LEN_MAX + 1 /* 18.04 */
-        , allocBig));
+        , allocBig))
     p->matchFinderObj = &p->matchFinderMt;
-    MFB.bigHash = (Byte)(
-        (p->dictSize > kBigHashDicLimit && MFB.hashMask >= 0xFFFFFF) ? 1 : 0);
+    MFB.bigHash = (Byte)(MFB.hashMask >= 0xFFFFFF ? 1 : 0);
     MatchFinderMt_CreateVTable(&p->matchFinderMt, &p->matchFinder);
   }
   else
@@ -2816,8 +2802,8 @@ static void LzmaEnc_Init(CLzmaEnc *p)
   }
 
   {
-    UInt32 num = (UInt32)0x300 << (p->lp + p->lc);
-    UInt32 k;
+    const size_t num = (size_t)0x300 << (p->lp + p->lc);
+    size_t k;
     CLzmaProb *probs = p->litProbs;
     for (k = 0; k < num; k++)
       probs[k] = kProbInitValue;
@@ -2872,59 +2858,53 @@ static SRes LzmaEnc_AllocAndInit(CLzmaEn
 
   p->finished = False;
   p->result = SZ_OK;
-  RINOK(LzmaEnc_Alloc(p, keepWindowSize, alloc, allocBig));
+  p->nowPos64 = 0;
+  p->needInit = 1;
+  RINOK(LzmaEnc_Alloc(p, keepWindowSize, alloc, allocBig))
   LzmaEnc_Init(p);
   LzmaEnc_InitPrices(p);
-  p->nowPos64 = 0;
   return SZ_OK;
 }
 
-static SRes LzmaEnc_Prepare(CLzmaEncHandle pp, ISeqOutStream *outStream, ISeqInStream *inStream,
+static SRes LzmaEnc_Prepare(CLzmaEncHandle p,
+    ISeqOutStreamPtr outStream,
+    ISeqInStreamPtr inStream,
     ISzAllocPtr alloc, ISzAllocPtr allocBig)
 {
-  CLzmaEnc *p = (CLzmaEnc *)pp;
-  MFB.stream = inStream;
-  p->needInit = 1;
+  // GET_CLzmaEnc_p
+  MatchFinder_SET_STREAM(&MFB, inStream)
   p->rc.outStream = outStream;
   return LzmaEnc_AllocAndInit(p, 0, alloc, allocBig);
 }
 
-SRes LzmaEnc_PrepareForLzma2(CLzmaEncHandle pp,
-    ISeqInStream *inStream, UInt32 keepWindowSize,
+SRes LzmaEnc_PrepareForLzma2(CLzmaEncHandle p,
+    ISeqInStreamPtr inStream, UInt32 keepWindowSize,
     ISzAllocPtr alloc, ISzAllocPtr allocBig)
 {
-  CLzmaEnc *p = (CLzmaEnc *)pp;
-  MFB.stream = inStream;
-  p->needInit = 1;
+  // GET_CLzmaEnc_p
+  MatchFinder_SET_STREAM(&MFB, inStream)
   return LzmaEnc_AllocAndInit(p, keepWindowSize, alloc, allocBig);
 }
 
-static void LzmaEnc_SetInputBuf(CLzmaEnc *p, const Byte *src, SizeT srcLen)
-{
-  MFB.directInput = 1;
-  MFB.bufferBase = (Byte *)src;
-  MFB.directInputRem = srcLen;
-}
-
-SRes LzmaEnc_MemPrepare(CLzmaEncHandle pp, const Byte *src, SizeT srcLen,
-    UInt32 keepWindowSize, ISzAllocPtr alloc, ISzAllocPtr allocBig)
+SRes LzmaEnc_MemPrepare(CLzmaEncHandle p,
+    const Byte *src, SizeT srcLen,
+    UInt32 keepWindowSize,
+    ISzAllocPtr alloc, ISzAllocPtr allocBig)
 {
-  CLzmaEnc *p = (CLzmaEnc *)pp;
-  LzmaEnc_SetInputBuf(p, src, srcLen);
-  p->needInit = 1;
-
-  LzmaEnc_SetDataSize(pp, srcLen);
+  // GET_CLzmaEnc_p
+  MatchFinder_SET_DIRECT_INPUT_BUF(&MFB, src, srcLen)
+  LzmaEnc_SetDataSize(p, srcLen);
   return LzmaEnc_AllocAndInit(p, keepWindowSize, alloc, allocBig);
 }
 
-void LzmaEnc_Finish(CLzmaEncHandle pp)
+void LzmaEnc_Finish(CLzmaEncHandle p)
 {
-  #ifndef _7ZIP_ST
-  CLzmaEnc *p = (CLzmaEnc *)pp;
+  #ifndef Z7_ST
+  // GET_CLzmaEnc_p
   if (p->mtMode)
     MatchFinderMt_ReleaseStream(&p->matchFinderMt);
   #else
-  UNUSED_VAR(pp);
+  UNUSED_VAR(p)
   #endif
 }
 
@@ -2933,13 +2913,13 @@ typedef struct
 {
   ISeqOutStream vt;
   Byte *data;
-  SizeT rem;
+  size_t rem;
   BoolInt overflow;
 } CLzmaEnc_SeqOutStreamBuf;
 
-static size_t SeqOutStreamBuf_Write(const ISeqOutStream *pp, const void *data, size_t size)
+static size_t SeqOutStreamBuf_Write(ISeqOutStreamPtr pp, const void *data, size_t size)
 {
-  CLzmaEnc_SeqOutStreamBuf *p = CONTAINER_FROM_VTBL(pp, CLzmaEnc_SeqOutStreamBuf, vt);
+  Z7_CONTAINER_FROM_VTBL_TO_DECL_VAR_pp_vt_p(CLzmaEnc_SeqOutStreamBuf)
   if (p->rem < size)
   {
     size = p->rem;
@@ -2956,25 +2936,25 @@ static size_t SeqOutStreamBuf_Write(cons
 
 
 /*
-UInt32 LzmaEnc_GetNumAvailableBytes(CLzmaEncHandle pp)
+UInt32 LzmaEnc_GetNumAvailableBytes(CLzmaEncHandle p)
 {
-  const CLzmaEnc *p = (CLzmaEnc *)pp;
+  GET_const_CLzmaEnc_p
   return p->matchFinder.GetNumAvailableBytes(p->matchFinderObj);
 }
 */
 
-const Byte *LzmaEnc_GetCurBuf(CLzmaEncHandle pp)
+const Byte *LzmaEnc_GetCurBuf(CLzmaEncHandle p)
 {
-  const CLzmaEnc *p = (CLzmaEnc *)pp;
+  // GET_const_CLzmaEnc_p
   return p->matchFinder.GetPointerToCurrentPos(p->matchFinderObj) - p->additionalOffset;
 }
 
 
 // (desiredPackSize == 0) is not allowed
-SRes LzmaEnc_CodeOneMemBlock(CLzmaEncHandle pp, BoolInt reInit,
+SRes LzmaEnc_CodeOneMemBlock(CLzmaEncHandle p, BoolInt reInit,
     Byte *dest, size_t *destLen, UInt32 desiredPackSize, UInt32 *unpackSize)
 {
-  CLzmaEnc *p = (CLzmaEnc *)pp;
+  // GET_CLzmaEnc_p
   UInt64 nowPos64;
   SRes res;
   CLzmaEnc_SeqOutStreamBuf outStream;
@@ -3006,12 +2986,12 @@ SRes LzmaEnc_CodeOneMemBlock(CLzmaEncHan
 }
 
 
-MY_NO_INLINE
-static SRes LzmaEnc_Encode2(CLzmaEnc *p, ICompressProgress *progress)
+Z7_NO_INLINE
+static SRes LzmaEnc_Encode2(CLzmaEnc *p, ICompressProgressPtr progress)
 {
   SRes res = SZ_OK;
 
-  #ifndef _7ZIP_ST
+  #ifndef Z7_ST
   Byte allocaDummy[0x300];
   allocaDummy[0] = 0;
   allocaDummy[1] = allocaDummy[0];
@@ -3033,7 +3013,7 @@ static SRes LzmaEnc_Encode2(CLzmaEnc *p,
     }
   }
   
-  LzmaEnc_Finish(p);
+  LzmaEnc_Finish((CLzmaEncHandle)(void *)p);
 
   /*
   if (res == SZ_OK && !Inline_MatchFinder_IsFinishedOK(&MFB))
@@ -3045,21 +3025,22 @@ static SRes LzmaEnc_Encode2(CLzmaEnc *p,
 }
 
 
-SRes LzmaEnc_Encode(CLzmaEncHandle pp, ISeqOutStream *outStream, ISeqInStream *inStream, ICompressProgress *progress,
+SRes LzmaEnc_Encode(CLzmaEncHandle p, ISeqOutStreamPtr outStream, ISeqInStreamPtr inStream, ICompressProgressPtr progress,
     ISzAllocPtr alloc, ISzAllocPtr allocBig)
 {
-  RINOK(LzmaEnc_Prepare(pp, outStream, inStream, alloc, allocBig));
-  return LzmaEnc_Encode2((CLzmaEnc *)pp, progress);
+  // GET_CLzmaEnc_p
+  RINOK(LzmaEnc_Prepare(p, outStream, inStream, alloc, allocBig))
+  return LzmaEnc_Encode2(p, progress);
 }
 
 
-SRes LzmaEnc_WriteProperties(CLzmaEncHandle pp, Byte *props, SizeT *size)
+SRes LzmaEnc_WriteProperties(CLzmaEncHandle p, Byte *props, SizeT *size)
 {
   if (*size < LZMA_PROPS_SIZE)
     return SZ_ERROR_PARAM;
   *size = LZMA_PROPS_SIZE;
   {
-    const CLzmaEnc *p = (const CLzmaEnc *)pp;
+    // GET_CLzmaEnc_p
     const UInt32 dictSize = p->dictSize;
     UInt32 v;
     props[0] = (Byte)((p->pb * 5 + p->lp) * 9 + p->lc);
@@ -3083,23 +3064,24 @@ SRes LzmaEnc_WriteProperties(CLzmaEncHan
       while (v < dictSize);
     }
 
-    SetUi32(props + 1, v);
+    SetUi32(props + 1, v)
     return SZ_OK;
   }
 }
 
 
-unsigned LzmaEnc_IsWriteEndMark(CLzmaEncHandle pp)
+unsigned LzmaEnc_IsWriteEndMark(CLzmaEncHandle p)
 {
-  return (unsigned)((CLzmaEnc *)pp)->writeEndMark;
+  // GET_CLzmaEnc_p
+  return (unsigned)p->writeEndMark;
 }
 
 
-SRes LzmaEnc_MemEncode(CLzmaEncHandle pp, Byte *dest, SizeT *destLen, const Byte *src, SizeT srcLen,
-    int writeEndMark, ICompressProgress *progress, ISzAllocPtr alloc, ISzAllocPtr allocBig)
+SRes LzmaEnc_MemEncode(CLzmaEncHandle p, Byte *dest, SizeT *destLen, const Byte *src, SizeT srcLen,
+    int writeEndMark, ICompressProgressPtr progress, ISzAllocPtr alloc, ISzAllocPtr allocBig)
 {
   SRes res;
-  CLzmaEnc *p = (CLzmaEnc *)pp;
+  // GET_CLzmaEnc_p
 
   CLzmaEnc_SeqOutStreamBuf outStream;
 
@@ -3111,7 +3093,7 @@ SRes LzmaEnc_MemEncode(CLzmaEncHandle pp
   p->writeEndMark = writeEndMark;
   p->rc.outStream = &outStream.vt;
 
-  res = LzmaEnc_MemPrepare(pp, src, srcLen, 0, alloc, allocBig);
+  res = LzmaEnc_MemPrepare(p, src, srcLen, 0, alloc, allocBig);
   
   if (res == SZ_OK)
   {
@@ -3120,7 +3102,7 @@ SRes LzmaEnc_MemEncode(CLzmaEncHandle pp
       res = SZ_ERROR_FAIL;
   }
 
-  *destLen -= outStream.rem;
+  *destLen -= (SizeT)outStream.rem;
   if (outStream.overflow)
     return SZ_ERROR_OUTPUT_EOF;
   return res;
@@ -3129,9 +3111,9 @@ SRes LzmaEnc_MemEncode(CLzmaEncHandle pp
 
 SRes LzmaEncode(Byte *dest, SizeT *destLen, const Byte *src, SizeT srcLen,
     const CLzmaEncProps *props, Byte *propsEncoded, SizeT *propsSize, int writeEndMark,
-    ICompressProgress *progress, ISzAllocPtr alloc, ISzAllocPtr allocBig)
+    ICompressProgressPtr progress, ISzAllocPtr alloc, ISzAllocPtr allocBig)
 {
-  CLzmaEnc *p = (CLzmaEnc *)LzmaEnc_Create(alloc);
+  CLzmaEncHandle p = LzmaEnc_Create(alloc);
   SRes res;
   if (!p)
     return SZ_ERROR_MEM;
@@ -3151,10 +3133,10 @@ SRes LzmaEncode(Byte *dest, SizeT *destL
 
 
 /*
-#ifndef _7ZIP_ST
-void LzmaEnc_GetLzThreads(CLzmaEncHandle pp, HANDLE lz_threads[2])
+#ifndef Z7_ST
+void LzmaEnc_GetLzThreads(CLzmaEncHandle p, HANDLE lz_threads[2])
 {
-  const CLzmaEnc *p = (CLzmaEnc *)pp;
+  GET_const_CLzmaEnc_p
   lz_threads[0] = p->matchFinderMt.hashSync.thread;
   lz_threads[1] = p->matchFinderMt.btSync.thread;
 }
