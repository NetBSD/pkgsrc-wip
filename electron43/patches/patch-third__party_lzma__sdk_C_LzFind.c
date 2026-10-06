$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/LzFind.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/LzFind.c
@@ -1,5 +1,5 @@
 /* LzFind.c -- Match finder for LZ algorithms
-2021-11-29 : Igor Pavlov : Public domain */
+2024-03-01 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -17,7 +17,7 @@
 #define kEmptyHashValue 0
 
 #define kMaxValForNormalize ((UInt32)0)
-// #define kMaxValForNormalize ((UInt32)(1 << 20) + 0xFFF) // for debug
+// #define kMaxValForNormalize ((UInt32)(1 << 20) + 0xfff) // for debug
 
 // #define kNormalizeAlign (1 << 7) // alignment for speculated accesses
 
@@ -67,10 +67,10 @@
 
 static void LzInWindow_Free(CMatchFinder *p, ISzAllocPtr alloc)
 {
-  if (!p->directInput)
+  // if (!p->directInput)
   {
-    ISzAlloc_Free(alloc, p->bufferBase);
-    p->bufferBase = NULL;
+    ISzAlloc_Free(alloc, p->bufBase);
+    p->bufBase = NULL;
   }
 }
 
@@ -79,7 +79,7 @@ static int LzInWindow_Create2(CMatchFind
 {
   if (blockSize == 0)
     return 0;
-  if (!p->bufferBase || p->blockSize != blockSize)
+  if (!p->bufBase || p->blockSize != blockSize)
   {
     // size_t blockSizeT;
     LzInWindow_Free(p, alloc);
@@ -101,19 +101,25 @@ static int LzInWindow_Create2(CMatchFind
     #endif
     */
     
-    p->bufferBase = (Byte *)ISzAlloc_Alloc(alloc, blockSize);
-    // printf("\nbufferBase = %p\n", p->bufferBase);
+    p->bufBase = (Byte *)ISzAlloc_Alloc(alloc, blockSize);
+    // printf("\nbufferBase = %p\n", p->bufBase);
     // return 0; // for debug
   }
-  return (p->bufferBase != NULL);
+  return (p->bufBase != NULL);
 }
 
-static const Byte *MatchFinder_GetPointerToCurrentPos(CMatchFinder *p) { return p->buffer; }
+static const Byte *MatchFinder_GetPointerToCurrentPos(void *p)
+{
+  return ((CMatchFinder *)p)->buffer;
+}
 
-static UInt32 MatchFinder_GetNumAvailableBytes(CMatchFinder *p) { return GET_AVAIL_BYTES(p); }
+static UInt32 MatchFinder_GetNumAvailableBytes(void *p)
+{
+  return GET_AVAIL_BYTES((CMatchFinder *)p);
+}
 
 
-MY_NO_INLINE
+Z7_NO_INLINE
 static void MatchFinder_ReadBlock(CMatchFinder *p)
 {
   if (p->streamEndWasReached || p->result != SZ_OK)
@@ -127,8 +133,8 @@ static void MatchFinder_ReadBlock(CMatch
     UInt32 curSize = 0xFFFFFFFF - GET_AVAIL_BYTES(p);
     if (curSize > p->directInputRem)
       curSize = (UInt32)p->directInputRem;
-    p->directInputRem -= curSize;
     p->streamPos += curSize;
+    p->directInputRem -= curSize;
     if (p->directInputRem == 0)
       p->streamEndWasReached = 1;
     return;
@@ -136,8 +142,8 @@ static void MatchFinder_ReadBlock(CMatch
   
   for (;;)
   {
-    Byte *dest = p->buffer + GET_AVAIL_BYTES(p);
-    size_t size = (size_t)(p->bufferBase + p->blockSize - dest);
+    const Byte *dest = p->buffer + GET_AVAIL_BYTES(p);
+    size_t size = (size_t)(p->bufBase + p->blockSize - dest);
     if (size == 0)
     {
       /* we call ReadBlock() after NeedMove() and MoveBlock().
@@ -153,7 +159,14 @@ static void MatchFinder_ReadBlock(CMatch
     // #define kRead 3
     // if (size > kRead) size = kRead; // for debug
 
-    p->result = ISeqInStream_Read(p->stream, dest, &size);
+    /*
+    // we need cast (Byte *)dest.
+    #ifdef __clang__
+      #pragma GCC diagnostic ignored "-Wcast-qual"
+    #endif
+    */
+    p->result = ISeqInStream_Read(p->stream,
+        p->bufBase + (dest - p->bufBase), &size);
     if (p->result != SZ_OK)
       return;
     if (size == 0)
@@ -173,14 +186,14 @@ static void MatchFinder_ReadBlock(CMatch
 
 
 
-MY_NO_INLINE
+Z7_NO_INLINE
 void MatchFinder_MoveBlock(CMatchFinder *p)
 {
-  const size_t offset = (size_t)(p->buffer - p->bufferBase) - p->keepSizeBefore;
+  const size_t offset = (size_t)(p->buffer - p->bufBase) - p->keepSizeBefore;
   const size_t keepBefore = (offset & (kBlockMoveAlign - 1)) + p->keepSizeBefore;
-  p->buffer = p->bufferBase + keepBefore;
-  memmove(p->bufferBase,
-      p->bufferBase + (offset & ~((size_t)kBlockMoveAlign - 1)),
+  p->buffer = p->bufBase + keepBefore;
+  memmove(p->bufBase,
+      p->bufBase + (offset & ~((size_t)kBlockMoveAlign - 1)),
       keepBefore + (size_t)GET_AVAIL_BYTES(p));
 }
 
@@ -198,7 +211,7 @@ int MatchFinder_NeedMove(CMatchFinder *p
     return 0;
   if (p->streamEndWasReached || p->result != SZ_OK)
     return 0;
-  return ((size_t)(p->bufferBase + p->blockSize - p->buffer) <= p->keepSizeAfter);
+  return ((size_t)(p->bufBase + p->blockSize - p->buffer) <= p->keepSizeAfter);
 }
 
 void MatchFinder_ReadIfRequired(CMatchFinder *p)
@@ -214,6 +227,8 @@ static void MatchFinder_SetDefaultSettin
   p->cutValue = 32;
   p->btMode = 1;
   p->numHashBytes = 4;
+  p->numHashBytes_Min = 2;
+  p->numHashOutBits = 0;
   p->bigHash = 0;
 }
 
@@ -222,8 +237,10 @@ static void MatchFinder_SetDefaultSettin
 void MatchFinder_Construct(CMatchFinder *p)
 {
   unsigned i;
-  p->bufferBase = NULL;
+  p->buffer = NULL;
+  p->bufBase = NULL;
   p->directInput = 0;
+  p->stream = NULL;
   p->hash = NULL;
   p->expectedDataSize = (UInt64)(Int64)-1;
   MatchFinder_SetDefaultSettings(p);
@@ -238,6 +255,8 @@ void MatchFinder_Construct(CMatchFinder 
   }
 }
 
+#undef kCrcPoly
+
 static void MatchFinder_FreeThisClassMemory(CMatchFinder *p, ISzAllocPtr alloc)
 {
   ISzAlloc_Free(alloc, p->hash);
@@ -252,7 +271,7 @@ void MatchFinder_Free(CMatchFinder *p, I
 
 static CLzRef* AllocRefs(size_t num, ISzAllocPtr alloc)
 {
-  size_t sizeInBytes = (size_t)num * sizeof(CLzRef);
+  const size_t sizeInBytes = (size_t)num * sizeof(CLzRef);
   if (sizeInBytes / sizeof(CLzRef) != num)
     return NULL;
   return (CLzRef *)ISzAlloc_Alloc(alloc, sizeInBytes);
@@ -298,6 +317,62 @@ static UInt32 GetBlockSize(CMatchFinder 
 }
 
 
+// input is historySize
+static UInt32 MatchFinder_GetHashMask2(CMatchFinder *p, UInt32 hs)
+{
+  if (p->numHashBytes == 2)
+    return (1 << 16) - 1;
+  if (hs != 0)
+    hs--;
+  hs |= (hs >> 1);
+  hs |= (hs >> 2);
+  hs |= (hs >> 4);
+  hs |= (hs >> 8);
+  // we propagated 16 bits in (hs). Low 16 bits must be set later
+  if (hs >= (1 << 24))
+  {
+    if (p->numHashBytes == 3)
+      hs = (1 << 24) - 1;
+    /* if (bigHash) mode, GetHeads4b() in LzFindMt.c needs (hs >= ((1 << 24) - 1))) */
+  }
+  // (hash_size >= (1 << 16)) : Required for (numHashBytes > 2)
+  hs |= (1 << 16) - 1; /* don't change it! */
+  // bt5: we adjust the size with recommended minimum size
+  if (p->numHashBytes >= 5)
+    hs |= (256 << kLzHash_CrcShift_2) - 1;
+  return hs;
+}
+
+// input is historySize
+static UInt32 MatchFinder_GetHashMask(CMatchFinder *p, UInt32 hs)
+{
+  if (p->numHashBytes == 2)
+    return (1 << 16) - 1;
+  if (hs != 0)
+    hs--;
+  hs |= (hs >> 1);
+  hs |= (hs >> 2);
+  hs |= (hs >> 4);
+  hs |= (hs >> 8);
+  // we propagated 16 bits in (hs). Low 16 bits must be set later
+  hs >>= 1;
+  if (hs >= (1 << 24))
+  {
+    if (p->numHashBytes == 3)
+      hs = (1 << 24) - 1;
+    else
+      hs >>= 1;
+    /* if (bigHash) mode, GetHeads4b() in LzFindMt.c needs (hs >= ((1 << 24) - 1))) */
+  }
+  // (hash_size >= (1 << 16)) : Required for (numHashBytes > 2)
+  hs |= (1 << 16) - 1; /* don't change it! */
+  // bt5: we adjust the size with recommended minimum size
+  if (p->numHashBytes >= 5)
+    hs |= (256 << kLzHash_CrcShift_2) - 1;
+  return hs;
+}
+
+
 int MatchFinder_Create(CMatchFinder *p, UInt32 historySize,
     UInt32 keepAddBufferBefore, UInt32 matchMaxLen, UInt32 keepAddBufferAfter,
     ISzAllocPtr alloc)
@@ -318,78 +393,91 @@ int MatchFinder_Create(CMatchFinder *p, 
     p->blockSize = 0;
   if (p->directInput || LzInWindow_Create2(p, GetBlockSize(p, historySize), alloc))
   {
-    const UInt32 newCyclicBufferSize = historySize + 1; // do not change it
-    UInt32 hs;
-    p->matchMaxLen = matchMaxLen;
+    size_t hashSizeSum;
     {
-      // UInt32 hs4;
-      p->fixedHashSize = 0;
-      hs = (1 << 16) - 1;
-      if (p->numHashBytes != 2)
+      UInt32 hs;
+      UInt32 hsCur;
+
+      if (p->numHashOutBits != 0)
       {
-        hs = historySize;
-        if (hs > p->expectedDataSize)
-          hs = (UInt32)p->expectedDataSize;
-        if (hs != 0)
-          hs--;
-        hs |= (hs >> 1);
-        hs |= (hs >> 2);
-        hs |= (hs >> 4);
-        hs |= (hs >> 8);
-        // we propagated 16 bits in (hs). Low 16 bits must be set later
-        hs >>= 1;
-        if (hs >= (1 << 24))
-        {
-          if (p->numHashBytes == 3)
-            hs = (1 << 24) - 1;
-          else
-            hs >>= 1;
-          /* if (bigHash) mode, GetHeads4b() in LzFindMt.c needs (hs >= ((1 << 24) - 1))) */
-        }
-        
-        // hs = ((UInt32)1 << 25) - 1; // for test
-        
+        unsigned numBits = p->numHashOutBits;
+        const unsigned nbMax =
+            (p->numHashBytes == 2 ? 16 :
+            (p->numHashBytes == 3 ? 24 : 32));
+        if (numBits > nbMax)
+          numBits = nbMax;
+        if (numBits >= 32)
+          hs = (UInt32)0 - 1;
+        else
+          hs = ((UInt32)1 << numBits) - 1;
         // (hash_size >= (1 << 16)) : Required for (numHashBytes > 2)
         hs |= (1 << 16) - 1; /* don't change it! */
-        
-        // bt5: we adjust the size with recommended minimum size
         if (p->numHashBytes >= 5)
           hs |= (256 << kLzHash_CrcShift_2) - 1;
+        {
+          const UInt32 hs2 = MatchFinder_GetHashMask2(p, historySize);
+          if (hs > hs2)
+            hs = hs2;
+        }
+        hsCur = hs;
+        if (p->expectedDataSize < historySize)
+        {
+          const UInt32 hs2 = MatchFinder_GetHashMask2(p, (UInt32)p->expectedDataSize);
+          if (hsCur > hs2)
+            hsCur = hs2;
+        }
+      }
+      else
+      {
+        hs = MatchFinder_GetHashMask(p, historySize);
+        hsCur = hs;
+        if (p->expectedDataSize < historySize)
+        {
+          hsCur = MatchFinder_GetHashMask(p, (UInt32)p->expectedDataSize);
+          if (hsCur > hs) // is it possible?
+            hsCur = hs;
+        }
       }
-      p->hashMask = hs;
-      hs++;
 
-      /*
-      hs4 = (1 << 20);
-      if (hs4 > hs)
-        hs4 = hs;
-      // hs4 = (1 << 16); // for test
-      p->hash4Mask = hs4 - 1;
-      */
+      p->hashMask = hsCur;
 
-      if (p->numHashBytes > 2) p->fixedHashSize += kHash2Size;
-      if (p->numHashBytes > 3) p->fixedHashSize += kHash3Size;
-      // if (p->numHashBytes > 4) p->fixedHashSize += hs4; // kHash4Size;
-      hs += p->fixedHashSize;
+      hashSizeSum = hs;
+      hashSizeSum++;
+      if (hashSizeSum < hs)
+        return 0;
+      {
+        UInt32 fixedHashSize = 0;
+        if (p->numHashBytes > 2 && p->numHashBytes_Min <= 2) fixedHashSize += kHash2Size;
+        if (p->numHashBytes > 3 && p->numHashBytes_Min <= 3) fixedHashSize += kHash3Size;
+        // if (p->numHashBytes > 4) p->fixedHashSize += hs4; // kHash4Size;
+        hashSizeSum += fixedHashSize;
+        p->fixedHashSize = fixedHashSize;
+      }
     }
 
+    p->matchMaxLen = matchMaxLen;
+
     {
       size_t newSize;
       size_t numSons;
+      const UInt32 newCyclicBufferSize = historySize + 1; // do not change it
       p->historySize = historySize;
-      p->hashSizeSum = hs;
       p->cyclicBufferSize = newCyclicBufferSize; // it must be = (historySize + 1)
       
       numSons = newCyclicBufferSize;
       if (p->btMode)
         numSons <<= 1;
-      newSize = hs + numSons;
+      newSize = hashSizeSum + numSons;
+
+      if (numSons < newCyclicBufferSize || newSize < numSons)
+        return 0;
 
       // aligned size is not required here, but it can be better for some loops
       #define NUM_REFS_ALIGN_MASK 0xF
       newSize = (newSize + NUM_REFS_ALIGN_MASK) & ~(size_t)NUM_REFS_ALIGN_MASK;
 
-      if (p->hash && p->numRefs == newSize)
+      // 22.02: we don't reallocate buffer, if old size is enough
+      if (p->hash && p->numRefs >= newSize)
         return 1;
       
       MatchFinder_FreeThisClassMemory(p, alloc);
@@ -398,7 +486,7 @@ int MatchFinder_Create(CMatchFinder *p, 
       
       if (p->hash)
       {
-        p->son = p->hash + p->hashSizeSum;
+        p->son = p->hash + hashSizeSum;
         return 1;
       }
     }
@@ -470,7 +558,8 @@ void MatchFinder_Init_HighHash(CMatchFin
 
 void MatchFinder_Init_4(CMatchFinder *p)
 {
-  p->buffer = p->bufferBase;
+  if (!p->directInput)
+    p->buffer = p->bufBase;
   {
     /* kEmptyHashValue = 0 (Zero) is used in hash tables as NO-VALUE marker.
        the code in CMatchFinderMt expects (pos = 1) */
@@ -488,8 +577,9 @@ void MatchFinder_Init_4(CMatchFinder *p)
 #define CYC_TO_POS_OFFSET 0
 // #define CYC_TO_POS_OFFSET 1 // for debug
 
-void MatchFinder_Init(CMatchFinder *p)
+void MatchFinder_Init(void *_p)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   MatchFinder_Init_HighHash(p);
   MatchFinder_Init_LowHash(p);
   MatchFinder_Init_4(p);
@@ -507,165 +597,173 @@ void MatchFinder_Init(CMatchFinder *p)
 
 #if 0
 #ifdef MY_CPU_X86_OR_AMD64
-  #if defined(__clang__) && (__clang_major__ >= 8) \
-    || defined(__GNUC__) && (__GNUC__ >= 8) \
-    || defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 1900)
-      #define USE_SATUR_SUB_128
-      #define USE_AVX2
-      #define ATTRIB_SSE41 __attribute__((__target__("sse4.1")))
-      #define ATTRIB_AVX2 __attribute__((__target__("avx2")))
+  #if defined(__clang__) && (__clang_major__ >= 4) \
+    || defined(Z7_GCC_VERSION) && (Z7_GCC_VERSION >= 40701)
+    // || defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 1900)
+
+      #define USE_LZFIND_SATUR_SUB_128
+      #define USE_LZFIND_SATUR_SUB_256
+      #define LZFIND_ATTRIB_SSE41 __attribute__((__target__("sse4.1")))
+      #define LZFIND_ATTRIB_AVX2  __attribute__((__target__("avx2")))
   #elif defined(_MSC_VER)
     #if (_MSC_VER >= 1600)
-      #define USE_SATUR_SUB_128
-      #if (_MSC_VER >= 1900)
-        #define USE_AVX2
-        #include <immintrin.h> // avx
-      #endif
+      #define USE_LZFIND_SATUR_SUB_128
+    #endif
+    #if (_MSC_VER >= 1900)
+      #define USE_LZFIND_SATUR_SUB_256
     #endif
   #endif
 
-// #elif defined(MY_CPU_ARM_OR_ARM64)
-#elif defined(MY_CPU_ARM64)
+#elif defined(MY_CPU_ARM64) \
+  /* || (defined(__ARM_ARCH) && (__ARM_ARCH >= 7)) */
 
-  #if defined(__clang__) && (__clang_major__ >= 8) \
-    || defined(__GNUC__) && (__GNUC__ >= 8)
-      #define USE_SATUR_SUB_128
+  #if  defined(Z7_CLANG_VERSION) && (Z7_CLANG_VERSION >= 30800) \
+    || defined(__GNUC__) && (__GNUC__ >= 6)
+      #define USE_LZFIND_SATUR_SUB_128
     #ifdef MY_CPU_ARM64
-      // #define ATTRIB_SSE41 __attribute__((__target__("")))
+      // #define LZFIND_ATTRIB_SSE41 __attribute__((__target__("")))
     #else
-      // #define ATTRIB_SSE41 __attribute__((__target__("fpu=crypto-neon-fp-armv8")))
+      #define LZFIND_ATTRIB_SSE41 __attribute__((__target__("fpu=neon")))
     #endif
 
   #elif defined(_MSC_VER)
     #if (_MSC_VER >= 1910)
-      #define USE_SATUR_SUB_128
+      #define USE_LZFIND_SATUR_SUB_128
     #endif
   #endif
 
-  #if defined(_MSC_VER) && defined(MY_CPU_ARM64)
+  #if defined(Z7_MSC_VER_ORIGINAL) && defined(MY_CPU_ARM64)
     #include <arm64_neon.h>
   #else
     #include <arm_neon.h>
   #endif
 
 #endif
-#endif
-
-/*
-#ifndef ATTRIB_SSE41
-  #define ATTRIB_SSE41
-#endif
-#ifndef ATTRIB_AVX2
-  #define ATTRIB_AVX2
-#endif
-*/
+#endif // #if 0
 
-#ifdef USE_SATUR_SUB_128
+#ifdef USE_LZFIND_SATUR_SUB_128
 
-// #define _SHOW_HW_STATUS
+// #define Z7_SHOW_HW_STATUS
 
-#ifdef _SHOW_HW_STATUS
+#ifdef Z7_SHOW_HW_STATUS
 #include <stdio.h>
-#define _PRF(x) x
-_PRF(;)
+#define PRF(x) x
+PRF(;)
 #else
-#define _PRF(x)
+#define PRF(x)
 #endif
 
+
 #ifdef MY_CPU_ARM_OR_ARM64
 
 #ifdef MY_CPU_ARM64
-// #define FORCE_SATUR_SUB_128
+// #define FORCE_LZFIND_SATUR_SUB_128
 #endif
+typedef uint32x4_t LzFind_v128;
+#define SASUB_128_V(v, s) \
+  vsubq_u32(vmaxq_u32(v, s), s)
 
-typedef uint32x4_t v128;
-#define SASUB_128(i) \
-   *(v128 *)(void *)(items + (i) * 4) = \
-  vsubq_u32(vmaxq_u32(*(const v128 *)(const void *)(items + (i) * 4), sub2), sub2);
-
-#else
+#else // MY_CPU_ARM_OR_ARM64
 
 #include <smmintrin.h> // sse4.1
 
-typedef __m128i v128;
-#define SASUB_128(i) \
-  *(v128 *)(void *)(items + (i) * 4) = \
-  _mm_sub_epi32(_mm_max_epu32(*(const v128 *)(const void *)(items + (i) * 4), sub2), sub2); // SSE 4.1
+typedef __m128i LzFind_v128;
+// SSE 4.1
+#define SASUB_128_V(v, s)   \
+  _mm_sub_epi32(_mm_max_epu32(v, s), s)
+
+#endif // MY_CPU_ARM_OR_ARM64
 
-#endif
 
+#define SASUB_128(i) \
+  *(      LzFind_v128 *)(      void *)(items + (i) * 4) = SASUB_128_V( \
+  *(const LzFind_v128 *)(const void *)(items + (i) * 4), sub2);
 
 
-MY_NO_INLINE
+Z7_NO_INLINE
 static
-#ifdef ATTRIB_SSE41
-ATTRIB_SSE41
+#ifdef LZFIND_ATTRIB_SSE41
+LZFIND_ATTRIB_SSE41
 #endif
 void
-MY_FAST_CALL
+Z7_FASTCALL
 LzFind_SaturSub_128(UInt32 subValue, CLzRef *items, const CLzRef *lim)
 {
-  v128 sub2 =
+  const LzFind_v128 sub2 =
     #ifdef MY_CPU_ARM_OR_ARM64
       vdupq_n_u32(subValue);
     #else
       _mm_set_epi32((Int32)subValue, (Int32)subValue, (Int32)subValue, (Int32)subValue);
     #endif
+  Z7_PRAGMA_OPT_DISABLE_LOOP_UNROLL_VECTORIZE
   do
   {
-    SASUB_128(0)
-    SASUB_128(1)
-    SASUB_128(2)
-    SASUB_128(3)
-    items += 4 * 4;
+    SASUB_128(0)  SASUB_128(1)  items += 2 * 4;
+    SASUB_128(0)  SASUB_128(1)  items += 2 * 4;
   }
   while (items != lim);
 }
 
 
 
-#ifdef USE_AVX2
+#ifdef USE_LZFIND_SATUR_SUB_256
 
 #include <immintrin.h> // avx
+/*
+clang :immintrin.h uses
+#if !(defined(_MSC_VER) || defined(__SCE__)) || __has_feature(modules) ||      \
+    defined(__AVX2__)
+#include <avx2intrin.h>
+#endif
+so we need <avxintrin.h> for clang-cl */
 
-#define SASUB_256(i) *(__m256i *)(void *)(items + (i) * 8) = _mm256_sub_epi32(_mm256_max_epu32(*(const __m256i *)(const void *)(items + (i) * 8), sub2), sub2); // AVX2
+#if defined(__clang__)
+#include <avxintrin.h>
+#include <avx2intrin.h>
+#endif
+
+// AVX2:
+#define SASUB_256(i) \
+    *(      __m256i *)(      void *)(items + (i) * 8) = \
+   _mm256_sub_epi32(_mm256_max_epu32( \
+    *(const __m256i *)(const void *)(items + (i) * 8), sub2), sub2);
 
-MY_NO_INLINE
+Z7_NO_INLINE
 static
-#ifdef ATTRIB_AVX2
-ATTRIB_AVX2
+#ifdef LZFIND_ATTRIB_AVX2
+LZFIND_ATTRIB_AVX2
 #endif
 void
-MY_FAST_CALL
+Z7_FASTCALL
 LzFind_SaturSub_256(UInt32 subValue, CLzRef *items, const CLzRef *lim)
 {
-  __m256i sub2 = _mm256_set_epi32(
+  const __m256i sub2 = _mm256_set_epi32(
       (Int32)subValue, (Int32)subValue, (Int32)subValue, (Int32)subValue,
       (Int32)subValue, (Int32)subValue, (Int32)subValue, (Int32)subValue);
+  Z7_PRAGMA_OPT_DISABLE_LOOP_UNROLL_VECTORIZE
   do
   {
-    SASUB_256(0)
-    SASUB_256(1)
-    items += 2 * 8;
+    SASUB_256(0)  SASUB_256(1)  items += 2 * 8;
+    SASUB_256(0)  SASUB_256(1)  items += 2 * 8;
   }
   while (items != lim);
 }
-#endif // USE_AVX2
+#endif // USE_LZFIND_SATUR_SUB_256
 
-#ifndef FORCE_SATUR_SUB_128
-typedef void (MY_FAST_CALL *LZFIND_SATUR_SUB_CODE_FUNC)(
+#ifndef FORCE_LZFIND_SATUR_SUB_128
+typedef void (Z7_FASTCALL *LZFIND_SATUR_SUB_CODE_FUNC)(
     UInt32 subValue, CLzRef *items, const CLzRef *lim);
 static LZFIND_SATUR_SUB_CODE_FUNC g_LzFind_SaturSub;
-#endif // FORCE_SATUR_SUB_128
+#endif // FORCE_LZFIND_SATUR_SUB_128
 
-#endif // USE_SATUR_SUB_128
+#endif // USE_LZFIND_SATUR_SUB_128
 
 
 // kEmptyHashValue must be zero
-// #define SASUB_32(i) v = items[i];  m = v - subValue;  if (v < subValue) m = kEmptyHashValue;  items[i] = m;
-#define SASUB_32(i) v = items[i];  if (v < subValue) v = subValue; items[i] = v - subValue;
+// #define SASUB_32(i)  { UInt32 v = items[i];  UInt32 m = v - subValue;  if (v < subValue) m = kEmptyHashValue;  items[i] = m; }
+#define SASUB_32(i)  { UInt32 v = items[i];  if (v < subValue) v = subValue; items[i] = v - subValue; }
 
-#ifdef FORCE_SATUR_SUB_128
+#ifdef FORCE_LZFIND_SATUR_SUB_128
 
 #define DEFAULT_SaturSub LzFind_SaturSub_128
 
@@ -673,24 +771,19 @@ static LZFIND_SATUR_SUB_CODE_FUNC g_LzFi
 
 #define DEFAULT_SaturSub LzFind_SaturSub_32
 
-MY_NO_INLINE
+Z7_NO_INLINE
 static
 void
-MY_FAST_CALL
+Z7_FASTCALL
 LzFind_SaturSub_32(UInt32 subValue, CLzRef *items, const CLzRef *lim)
 {
+  Z7_PRAGMA_OPT_DISABLE_LOOP_UNROLL_VECTORIZE
   do
   {
-    UInt32 v;
-    SASUB_32(0)
-    SASUB_32(1)
-    SASUB_32(2)
-    SASUB_32(3)
-    SASUB_32(4)
-    SASUB_32(5)
-    SASUB_32(6)
-    SASUB_32(7)
-    items += 8;
+    SASUB_32(0)  SASUB_32(1)  items += 2;
+    SASUB_32(0)  SASUB_32(1)  items += 2;
+    SASUB_32(0)  SASUB_32(1)  items += 2;
+    SASUB_32(0)  SASUB_32(1)  items += 2;
   }
   while (items != lim);
 }
@@ -698,27 +791,23 @@ LzFind_SaturSub_32(UInt32 subValue, CLzR
 #endif
 
 
-MY_NO_INLINE
+Z7_NO_INLINE
 void MatchFinder_Normalize3(UInt32 subValue, CLzRef *items, size_t numItems)
 {
-  #define K_NORM_ALIGN_BLOCK_SIZE (1 << 6)
-  
-  CLzRef *lim;
-
-  for (; numItems != 0 && ((unsigned)(ptrdiff_t)items & (K_NORM_ALIGN_BLOCK_SIZE - 1)) != 0; numItems--)
+  #define LZFIND_NORM_ALIGN_BLOCK_SIZE (1 << 7)
+  Z7_PRAGMA_OPT_DISABLE_LOOP_UNROLL_VECTORIZE
+  for (; numItems != 0 && ((unsigned)(ptrdiff_t)items & (LZFIND_NORM_ALIGN_BLOCK_SIZE - 1)) != 0; numItems--)
   {
-    UInt32 v;
-    SASUB_32(0);
+    SASUB_32(0)
     items++;
   }
-
   {
-    #define K_NORM_ALIGN_MASK (K_NORM_ALIGN_BLOCK_SIZE / 4 - 1)
-    lim = items + (numItems & ~(size_t)K_NORM_ALIGN_MASK);
-    numItems &= K_NORM_ALIGN_MASK;
+    const size_t k_Align_Mask = (LZFIND_NORM_ALIGN_BLOCK_SIZE / 4 - 1);
+    CLzRef *lim = items + (numItems & ~(size_t)k_Align_Mask);
+    numItems &= k_Align_Mask;
     if (items != lim)
     {
-      #if defined(USE_SATUR_SUB_128) && !defined(FORCE_SATUR_SUB_128)
+      #if defined(USE_LZFIND_SATUR_SUB_128) && !defined(FORCE_LZFIND_SATUR_SUB_128)
         if (g_LzFind_SaturSub)
           g_LzFind_SaturSub(subValue, items, lim);
         else
@@ -727,12 +816,10 @@ void MatchFinder_Normalize3(UInt32 subVa
     }
     items = lim;
   }
-
-
+  Z7_PRAGMA_OPT_DISABLE_LOOP_UNROLL_VECTORIZE
   for (; numItems != 0; numItems--)
   {
-    UInt32 v;
-    SASUB_32(0);
+    SASUB_32(0)
     items++;
   }
 }
@@ -741,7 +828,7 @@ void MatchFinder_Normalize3(UInt32 subVa
 
 // call MatchFinder_CheckLimits() only after (p->pos++) update
 
-MY_NO_INLINE
+Z7_NO_INLINE
 static void MatchFinder_CheckLimits(CMatchFinder *p)
 {
   if (// !p->streamEndWasReached && p->result == SZ_OK &&
@@ -769,11 +856,14 @@ static void MatchFinder_CheckLimits(CMat
     const UInt32 subValue = (p->pos - p->historySize - 1) /* & ~(UInt32)(kNormalizeAlign - 1) */;
     // const UInt32 subValue = (1 << 15); // for debug
     // printf("\nMatchFinder_Normalize() subValue == 0x%x\n", subValue);
-    size_t numSonRefs = p->cyclicBufferSize;
-    if (p->btMode)
-      numSonRefs <<= 1;
-    Inline_MatchFinder_ReduceOffsets(p, subValue);
-    MatchFinder_Normalize3(subValue, p->hash, (size_t)p->hashSizeSum + numSonRefs);
+    MatchFinder_REDUCE_OFFSETS(p, subValue)
+    MatchFinder_Normalize3(subValue, p->hash, (size_t)p->hashMask + 1 + p->fixedHashSize);
+    {
+      size_t numSonRefs = p->cyclicBufferSize;
+      if (p->btMode)
+        numSonRefs <<= 1;
+      MatchFinder_Normalize3(subValue, p->son, numSonRefs);
+    }
   }
 
   if (p->cyclicBufferPos == p->cyclicBufferSize)
@@ -786,7 +876,7 @@ static void MatchFinder_CheckLimits(CMat
 /*
   (lenLimit > maxLen)
 */
-MY_FORCE_INLINE
+Z7_FORCE_INLINE
 static UInt32 * Hc_GetMatchesSpec(size_t lenLimit, UInt32 curMatch, UInt32 pos, const Byte *cur, CLzRef *son,
     size_t _cyclicBufferPos, UInt32 _cyclicBufferSize, UInt32 cutValue,
     UInt32 *d, unsigned maxLen)
@@ -868,7 +958,7 @@ static UInt32 * Hc_GetMatchesSpec(size_t
 }
 
 
-MY_FORCE_INLINE
+Z7_FORCE_INLINE
 UInt32 * GetMatchesSpec1(UInt32 lenLimit, UInt32 curMatch, UInt32 pos, const Byte *cur, CLzRef *son,
     size_t _cyclicBufferPos, UInt32 _cyclicBufferSize, UInt32 cutValue,
     UInt32 *d, UInt32 maxLen)
@@ -999,13 +1089,15 @@ static void SkipMatchesSpec(UInt32 lenLi
 
 
 #define MOVE_POS \
-  ++p->cyclicBufferPos; \
+  p->cyclicBufferPos++; \
   p->buffer++; \
-  { const UInt32 pos1 = p->pos + 1; p->pos = pos1; if (pos1 == p->posLimit) MatchFinder_CheckLimits(p); }
+  { const UInt32 pos1 = p->pos + 1; \
+    p->pos = pos1; \
+    if (pos1 == p->posLimit) MatchFinder_CheckLimits(p); }
 
 #define MOVE_POS_RET MOVE_POS return distances;
 
-MY_NO_INLINE
+Z7_NO_INLINE
 static void MatchFinder_MovePos(CMatchFinder *p)
 {
   /* we go here at the end of stream data, when (avail < num_hash_bytes)
@@ -1016,24 +1108,30 @@ static void MatchFinder_MovePos(CMatchFi
      if (p->btMode)
         p->sons[(p->cyclicBufferPos << p->btMode) + 1] = 0;  // kEmptyHashValue
   */
-  MOVE_POS;
+  MOVE_POS
 }
 
 #define GET_MATCHES_HEADER2(minLen, ret_op) \
-  unsigned lenLimit; UInt32 hv; Byte *cur; UInt32 curMatch; \
-  lenLimit = (unsigned)p->lenLimit; { if (lenLimit < minLen) { MatchFinder_MovePos(p); ret_op; }} \
+  UInt32 hv; const Byte *cur; UInt32 curMatch; \
+  UInt32 lenLimit = p->lenLimit; \
+  if (lenLimit < minLen) { MatchFinder_MovePos(p);  ret_op; } \
   cur = p->buffer;
 
 #define GET_MATCHES_HEADER(minLen) GET_MATCHES_HEADER2(minLen, return distances)
-#define SKIP_HEADER(minLen)   do { GET_MATCHES_HEADER2(minLen, continue)
+#define SKIP_HEADER(minLen)  \
+  do { GET_MATCHES_HEADER2(minLen, continue)
 
-#define MF_PARAMS(p)  lenLimit, curMatch, p->pos, p->buffer, p->son, p->cyclicBufferPos, p->cyclicBufferSize, p->cutValue
+#define MF_PARAMS(p)  lenLimit, curMatch, p->pos, p->buffer, p->son, \
+    p->cyclicBufferPos, p->cyclicBufferSize, p->cutValue
 
-#define SKIP_FOOTER  SkipMatchesSpec(MF_PARAMS(p)); MOVE_POS; } while (--num);
+#define SKIP_FOOTER  \
+    SkipMatchesSpec(MF_PARAMS(p)); \
+    MOVE_POS \
+  } while (--num);
 
 #define GET_MATCHES_FOOTER_BASE(_maxLen_, func) \
-  distances = func(MF_PARAMS(p), \
-  distances, (UInt32)_maxLen_); MOVE_POS_RET;
+  distances = func(MF_PARAMS(p), distances, (UInt32)_maxLen_); \
+  MOVE_POS_RET
 
 #define GET_MATCHES_FOOTER_BT(_maxLen_) \
   GET_MATCHES_FOOTER_BASE(_maxLen_, GetMatchesSpec1)
@@ -1050,10 +1148,11 @@ static void MatchFinder_MovePos(CMatchFi
     for (; c != lim; c++) if (*(c + diff) != *c) break; \
     maxLen = (unsigned)(c - cur); }
 
-static UInt32* Bt2_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances)
+static UInt32* Bt2_MatchFinder_GetMatches(void *_p, UInt32 *distances)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   GET_MATCHES_HEADER(2)
-  HASH2_CALC;
+  HASH2_CALC
   curMatch = p->hash[hv];
   p->hash[hv] = p->pos;
   GET_MATCHES_FOOTER_BT(1)
@@ -1062,7 +1161,7 @@ static UInt32* Bt2_MatchFinder_GetMatche
 UInt32* Bt3Zip_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances)
 {
   GET_MATCHES_HEADER(3)
-  HASH_ZIP_CALC;
+  HASH_ZIP_CALC
   curMatch = p->hash[hv];
   p->hash[hv] = p->pos;
   GET_MATCHES_FOOTER_BT(2)
@@ -1075,15 +1174,16 @@ UInt32* Bt3Zip_MatchFinder_GetMatches(CM
     mmm = pos;
 
 
-static UInt32* Bt3_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances)
+static UInt32* Bt3_MatchFinder_GetMatches(void *_p, UInt32 *distances)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   UInt32 mmm;
   UInt32 h2, d2, pos;
   unsigned maxLen;
   UInt32 *hash;
   GET_MATCHES_HEADER(3)
 
-  HASH3_CALC;
+  HASH3_CALC
 
   hash = p->hash;
   pos = p->pos;
@@ -1108,7 +1208,7 @@ static UInt32* Bt3_MatchFinder_GetMatche
     if (maxLen == lenLimit)
     {
       SkipMatchesSpec(MF_PARAMS(p));
-      MOVE_POS_RET;
+      MOVE_POS_RET
     }
   }
   
@@ -1116,15 +1216,16 @@ static UInt32* Bt3_MatchFinder_GetMatche
 }
 
 
-static UInt32* Bt4_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances)
+static UInt32* Bt4_MatchFinder_GetMatches(void *_p, UInt32 *distances)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   UInt32 mmm;
   UInt32 h2, h3, d2, d3, pos;
   unsigned maxLen;
   UInt32 *hash;
   GET_MATCHES_HEADER(4)
 
-  HASH4_CALC;
+  HASH4_CALC
 
   hash = p->hash;
   pos = p->pos;
@@ -1184,14 +1285,16 @@ static UInt32* Bt4_MatchFinder_GetMatche
 }
 
 
-static UInt32* Bt5_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances)
+static UInt32* Bt5_MatchFinder_GetMatches(void *_p, UInt32 *distances)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   UInt32 mmm;
-  UInt32 h2, h3, d2, d3, maxLen, pos;
+  UInt32 h2, h3, d2, d3, pos;
+  unsigned maxLen;
   UInt32 *hash;
   GET_MATCHES_HEADER(5)
 
-  HASH5_CALC;
+  HASH5_CALC
 
   hash = p->hash;
   pos = p->pos;
@@ -1247,7 +1350,7 @@ static UInt32* Bt5_MatchFinder_GetMatche
     if (maxLen == lenLimit)
     {
       SkipMatchesSpec(MF_PARAMS(p));
-      MOVE_POS_RET;
+      MOVE_POS_RET
     }
     break;
   }
@@ -1256,15 +1359,16 @@ static UInt32* Bt5_MatchFinder_GetMatche
 }
 
 
-static UInt32* Hc4_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances)
+static UInt32* Hc4_MatchFinder_GetMatches(void *_p, UInt32 *distances)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   UInt32 mmm;
   UInt32 h2, h3, d2, d3, pos;
   unsigned maxLen;
   UInt32 *hash;
   GET_MATCHES_HEADER(4)
 
-  HASH4_CALC;
+  HASH4_CALC
 
   hash = p->hash;
   pos = p->pos;
@@ -1315,23 +1419,25 @@ static UInt32* Hc4_MatchFinder_GetMatche
     if (maxLen == lenLimit)
     {
       p->son[p->cyclicBufferPos] = curMatch;
-      MOVE_POS_RET;
+      MOVE_POS_RET
     }
     break;
   }
   
-  GET_MATCHES_FOOTER_HC(maxLen);
+  GET_MATCHES_FOOTER_HC(maxLen)
 }
 
 
-static UInt32 * Hc5_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances)
+static UInt32 * Hc5_MatchFinder_GetMatches(void *_p, UInt32 *distances)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   UInt32 mmm;
-  UInt32 h2, h3, d2, d3, maxLen, pos;
+  UInt32 h2, h3, d2, d3, pos;
+  unsigned maxLen;
   UInt32 *hash;
   GET_MATCHES_HEADER(5)
 
-  HASH5_CALC;
+  HASH5_CALC
 
   hash = p->hash;
   pos = p->pos;
@@ -1383,34 +1489,35 @@ static UInt32 * Hc5_MatchFinder_GetMatch
     if (*(cur - d2 + 3) != cur[3])
       break;
     UPDATE_maxLen
-    distances[-2] = maxLen;
+    distances[-2] = (UInt32)maxLen;
     if (maxLen == lenLimit)
     {
       p->son[p->cyclicBufferPos] = curMatch;
-      MOVE_POS_RET;
+      MOVE_POS_RET
     }
     break;
   }
   
-  GET_MATCHES_FOOTER_HC(maxLen);
+  GET_MATCHES_FOOTER_HC(maxLen)
 }
 
 
 UInt32* Hc3Zip_MatchFinder_GetMatches(CMatchFinder *p, UInt32 *distances)
 {
   GET_MATCHES_HEADER(3)
-  HASH_ZIP_CALC;
+  HASH_ZIP_CALC
   curMatch = p->hash[hv];
   p->hash[hv] = p->pos;
   GET_MATCHES_FOOTER_HC(2)
 }
 
 
-static void Bt2_MatchFinder_Skip(CMatchFinder *p, UInt32 num)
+static void Bt2_MatchFinder_Skip(void *_p, UInt32 num)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   SKIP_HEADER(2)
   {
-    HASH2_CALC;
+    HASH2_CALC
     curMatch = p->hash[hv];
     p->hash[hv] = p->pos;
   }
@@ -1421,20 +1528,21 @@ void Bt3Zip_MatchFinder_Skip(CMatchFinde
 {
   SKIP_HEADER(3)
   {
-    HASH_ZIP_CALC;
+    HASH_ZIP_CALC
     curMatch = p->hash[hv];
     p->hash[hv] = p->pos;
   }
   SKIP_FOOTER
 }
 
-static void Bt3_MatchFinder_Skip(CMatchFinder *p, UInt32 num)
+static void Bt3_MatchFinder_Skip(void *_p, UInt32 num)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   SKIP_HEADER(3)
   {
     UInt32 h2;
     UInt32 *hash;
-    HASH3_CALC;
+    HASH3_CALC
     hash = p->hash;
     curMatch = (hash + kFix3HashSize)[hv];
     hash[h2] =
@@ -1443,13 +1551,14 @@ static void Bt3_MatchFinder_Skip(CMatchF
   SKIP_FOOTER
 }
 
-static void Bt4_MatchFinder_Skip(CMatchFinder *p, UInt32 num)
+static void Bt4_MatchFinder_Skip(void *_p, UInt32 num)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   SKIP_HEADER(4)
   {
     UInt32 h2, h3;
     UInt32 *hash;
-    HASH4_CALC;
+    HASH4_CALC
     hash = p->hash;
     curMatch = (hash + kFix4HashSize)[hv];
     hash                  [h2] =
@@ -1459,13 +1568,14 @@ static void Bt4_MatchFinder_Skip(CMatchF
   SKIP_FOOTER
 }
 
-static void Bt5_MatchFinder_Skip(CMatchFinder *p, UInt32 num)
+static void Bt5_MatchFinder_Skip(void *_p, UInt32 num)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   SKIP_HEADER(5)
   {
     UInt32 h2, h3;
     UInt32 *hash;
-    HASH5_CALC;
+    HASH5_CALC
     hash = p->hash;
     curMatch = (hash + kFix5HashSize)[hv];
     hash                  [h2] =
@@ -1479,7 +1589,7 @@ static void Bt5_MatchFinder_Skip(CMatchF
 
 #define HC_SKIP_HEADER(minLen) \
     do { if (p->lenLimit < minLen) { MatchFinder_MovePos(p); num--; continue; } { \
-    Byte *cur; \
+    const Byte *cur; \
     UInt32 *hash; \
     UInt32 *son; \
     UInt32 pos = p->pos; \
@@ -1506,12 +1616,13 @@ static void Bt5_MatchFinder_Skip(CMatchF
     }} while(num); \
 
 
-static void Hc4_MatchFinder_Skip(CMatchFinder *p, UInt32 num)
+static void Hc4_MatchFinder_Skip(void *_p, UInt32 num)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   HC_SKIP_HEADER(4)
 
     UInt32 h2, h3;
-    HASH4_CALC;
+    HASH4_CALC
     curMatch = (hash + kFix4HashSize)[hv];
     hash                  [h2] =
     (hash + kFix3HashSize)[h3] =
@@ -1521,8 +1632,9 @@ static void Hc4_MatchFinder_Skip(CMatchF
 }
 
 
-static void Hc5_MatchFinder_Skip(CMatchFinder *p, UInt32 num)
+static void Hc5_MatchFinder_Skip(void *_p, UInt32 num)
 {
+  CMatchFinder *p = (CMatchFinder *)_p;
   HC_SKIP_HEADER(5)
   
     UInt32 h2, h3;
@@ -1541,7 +1653,7 @@ void Hc3Zip_MatchFinder_Skip(CMatchFinde
 {
   HC_SKIP_HEADER(3)
 
-    HASH_ZIP_CALC;
+    HASH_ZIP_CALC
     curMatch = hash[hv];
     hash[hv] = pos;
 
@@ -1551,57 +1663,57 @@ void Hc3Zip_MatchFinder_Skip(CMatchFinde
 
 void MatchFinder_CreateVTable(CMatchFinder *p, IMatchFinder2 *vTable)
 {
-  vTable->Init = (Mf_Init_Func)MatchFinder_Init;
-  vTable->GetNumAvailableBytes = (Mf_GetNumAvailableBytes_Func)MatchFinder_GetNumAvailableBytes;
-  vTable->GetPointerToCurrentPos = (Mf_GetPointerToCurrentPos_Func)MatchFinder_GetPointerToCurrentPos;
+  vTable->Init = MatchFinder_Init;
+  vTable->GetNumAvailableBytes = MatchFinder_GetNumAvailableBytes;
+  vTable->GetPointerToCurrentPos = MatchFinder_GetPointerToCurrentPos;
   if (!p->btMode)
   {
     if (p->numHashBytes <= 4)
     {
-      vTable->GetMatches = (Mf_GetMatches_Func)Hc4_MatchFinder_GetMatches;
-      vTable->Skip = (Mf_Skip_Func)Hc4_MatchFinder_Skip;
+      vTable->GetMatches = Hc4_MatchFinder_GetMatches;
+      vTable->Skip = Hc4_MatchFinder_Skip;
     }
     else
     {
-      vTable->GetMatches = (Mf_GetMatches_Func)Hc5_MatchFinder_GetMatches;
-      vTable->Skip = (Mf_Skip_Func)Hc5_MatchFinder_Skip;
+      vTable->GetMatches = Hc5_MatchFinder_GetMatches;
+      vTable->Skip = Hc5_MatchFinder_Skip;
     }
   }
   else if (p->numHashBytes == 2)
   {
-    vTable->GetMatches = (Mf_GetMatches_Func)Bt2_MatchFinder_GetMatches;
-    vTable->Skip = (Mf_Skip_Func)Bt2_MatchFinder_Skip;
+    vTable->GetMatches = Bt2_MatchFinder_GetMatches;
+    vTable->Skip = Bt2_MatchFinder_Skip;
   }
   else if (p->numHashBytes == 3)
   {
-    vTable->GetMatches = (Mf_GetMatches_Func)Bt3_MatchFinder_GetMatches;
-    vTable->Skip = (Mf_Skip_Func)Bt3_MatchFinder_Skip;
+    vTable->GetMatches = Bt3_MatchFinder_GetMatches;
+    vTable->Skip = Bt3_MatchFinder_Skip;
   }
   else if (p->numHashBytes == 4)
   {
-    vTable->GetMatches = (Mf_GetMatches_Func)Bt4_MatchFinder_GetMatches;
-    vTable->Skip = (Mf_Skip_Func)Bt4_MatchFinder_Skip;
+    vTable->GetMatches = Bt4_MatchFinder_GetMatches;
+    vTable->Skip = Bt4_MatchFinder_Skip;
   }
   else
   {
-    vTable->GetMatches = (Mf_GetMatches_Func)Bt5_MatchFinder_GetMatches;
-    vTable->Skip = (Mf_Skip_Func)Bt5_MatchFinder_Skip;
+    vTable->GetMatches = Bt5_MatchFinder_GetMatches;
+    vTable->Skip = Bt5_MatchFinder_Skip;
   }
 }
 
 
 
-void LzFindPrepare()
+void LzFindPrepare(void)
 {
-  #ifndef FORCE_SATUR_SUB_128
-  #ifdef USE_SATUR_SUB_128
+  #ifndef FORCE_LZFIND_SATUR_SUB_128
+  #ifdef USE_LZFIND_SATUR_SUB_128
   LZFIND_SATUR_SUB_CODE_FUNC f = NULL;
   #ifdef MY_CPU_ARM_OR_ARM64
   {
     if (CPU_IsSupported_NEON())
     {
       // #pragma message ("=== LzFind NEON")
-      _PRF(printf("\n=== LzFind NEON\n"));
+      PRF(printf("\n=== LzFind NEON\n"));
       f = LzFind_SaturSub_128;
     }
     // f = 0; // for debug
@@ -1610,20 +1722,25 @@ void LzFindPrepare()
   if (CPU_IsSupported_SSE41())
   {
     // #pragma message ("=== LzFind SSE41")
-    _PRF(printf("\n=== LzFind SSE41\n"));
+    PRF(printf("\n=== LzFind SSE41\n"));
     f = LzFind_SaturSub_128;
 
-    #ifdef USE_AVX2
+    #ifdef USE_LZFIND_SATUR_SUB_256
     if (CPU_IsSupported_AVX2())
     {
       // #pragma message ("=== LzFind AVX2")
-      _PRF(printf("\n=== LzFind AVX2\n"));
+      PRF(printf("\n=== LzFind AVX2\n"));
       f = LzFind_SaturSub_256;
     }
     #endif
   }
   #endif // MY_CPU_ARM_OR_ARM64
   g_LzFind_SaturSub = f;
-  #endif // USE_SATUR_SUB_128
-  #endif // FORCE_SATUR_SUB_128
+  #endif // USE_LZFIND_SATUR_SUB_128
+  #endif // FORCE_LZFIND_SATUR_SUB_128
 }
+
+
+#undef MOVE_POS
+#undef MOVE_POS_RET
+#undef PRF
