$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Sha256.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Sha256.c
@@ -1,65 +1,60 @@
 /* Sha256.c -- SHA-256 Hash
-2021-04-01 : Igor Pavlov : Public domain
+: Igor Pavlov : Public domain
 This code is based on public domain code from Wei Dai's Crypto++ library. */
 
 #include "Precomp.h"
 
 #include <string.h>
 
-#include "CpuArch.h"
-#include "RotateDefs.h"
 #include "Sha256.h"
-
-#if defined(_MSC_VER) && (_MSC_VER < 1900)
-// #define USE_MY_MM
-#endif
+#include "RotateDefs.h"
+#include "CpuArch.h"
 
 #ifdef MY_CPU_X86_OR_AMD64
-  #ifdef _MSC_VER
-    #if _MSC_VER >= 1200
-      #define _SHA_SUPPORTED
-    #endif
-  #elif defined(__clang__)
-    #if (__clang_major__ >= 8) // fix that check
-      #define _SHA_SUPPORTED
-    #endif
-  #elif defined(__GNUC__)
-    #if (__GNUC__ >= 8) // fix that check
-      #define _SHA_SUPPORTED
-    #endif
-  #elif defined(__INTEL_COMPILER)
-    #if (__INTEL_COMPILER >= 1800) // fix that check
-      #define _SHA_SUPPORTED
-    #endif
+  #if   defined(Z7_LLVM_CLANG_VERSION)  && (Z7_LLVM_CLANG_VERSION  >= 30800) \
+     || defined(Z7_APPLE_CLANG_VERSION) && (Z7_APPLE_CLANG_VERSION >= 50100) \
+     || defined(Z7_GCC_VERSION)         && (Z7_GCC_VERSION         >= 40900) \
+     || defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 1600) \
+     || defined(_MSC_VER) && (_MSC_VER >= 1200)
+      #define Z7_COMPILER_SHA256_SUPPORTED
   #endif
-// TODO(crbug.com/1338627): Enable ARM optimizations
-#elif 0 // defined(MY_CPU_ARM_OR_ARM64)
-  #ifdef _MSC_VER
-    #if _MSC_VER >= 1910
-      #define _SHA_SUPPORTED
+#elif defined(MY_CPU_ARM_OR_ARM64) && defined(MY_CPU_LE)
+
+  #if   defined(__ARM_FEATURE_SHA2) \
+     || defined(__ARM_FEATURE_CRYPTO)
+    #define Z7_COMPILER_SHA256_SUPPORTED
+  #else
+    #if  defined(MY_CPU_ARM64) \
+      || defined(__ARM_ARCH) && (__ARM_ARCH >= 4) \
+      || defined(Z7_MSC_VER_ORIGINAL)
+    #if  defined(__ARM_FP) && \
+          (   defined(Z7_CLANG_VERSION) && (Z7_CLANG_VERSION >= 30800) \
+           || defined(__GNUC__) && (__GNUC__ >= 6) \
+          ) \
+      || defined(Z7_MSC_VER_ORIGINAL) && (_MSC_VER >= 1910)
+    #if  defined(MY_CPU_ARM64) \
+      || !defined(Z7_CLANG_VERSION) \
+      || defined(__ARM_NEON) && \
+          (Z7_CLANG_VERSION < 170000 || \
+           Z7_CLANG_VERSION > 170001)
+      #define Z7_COMPILER_SHA256_SUPPORTED
     #endif
-  #elif defined(__clang__)
-    #if (__clang_major__ >= 8) // fix that check
-      #define _SHA_SUPPORTED
     #endif
-  #elif defined(__GNUC__)
-    #if (__GNUC__ >= 6) // fix that check
-      #define _SHA_SUPPORTED
     #endif
   #endif
 #endif
 
-void MY_FAST_CALL Sha256_UpdateBlocks(UInt32 state[8], const Byte *data, size_t numBlocks);
+void Z7_FASTCALL Sha256_UpdateBlocks(UInt32 state[8], const Byte *data, size_t numBlocks);
 
-#ifdef _SHA_SUPPORTED
-  void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks);
+#ifdef Z7_COMPILER_SHA256_SUPPORTED
+  void Z7_FASTCALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks);
 
-  static SHA256_FUNC_UPDATE_BLOCKS g_FUNC_UPDATE_BLOCKS = Sha256_UpdateBlocks;
-  static SHA256_FUNC_UPDATE_BLOCKS g_FUNC_UPDATE_BLOCKS_HW;
+  static SHA256_FUNC_UPDATE_BLOCKS g_SHA256_FUNC_UPDATE_BLOCKS = Sha256_UpdateBlocks;
+  static SHA256_FUNC_UPDATE_BLOCKS g_SHA256_FUNC_UPDATE_BLOCKS_HW;
 
-  #define UPDATE_BLOCKS(p) p->func_UpdateBlocks
+  #define SHA256_UPDATE_BLOCKS(p) p->v.vars.func_UpdateBlocks
 #else
-  #define UPDATE_BLOCKS(p) Sha256_UpdateBlocks
+  #define SHA256_UPDATE_BLOCKS(p) Sha256_UpdateBlocks
 #endif
 
 
@@ -67,16 +62,16 @@ BoolInt Sha256_SetFunction(CSha256 *p, u
 {
   SHA256_FUNC_UPDATE_BLOCKS func = Sha256_UpdateBlocks;
   
-  #ifdef _SHA_SUPPORTED
+  #ifdef Z7_COMPILER_SHA256_SUPPORTED
     if (algo != SHA256_ALGO_SW)
     {
       if (algo == SHA256_ALGO_DEFAULT)
-        func = g_FUNC_UPDATE_BLOCKS;
+        func = g_SHA256_FUNC_UPDATE_BLOCKS;
       else
       {
         if (algo != SHA256_ALGO_HW)
           return False;
-        func = g_FUNC_UPDATE_BLOCKS_HW;
+        func = g_SHA256_FUNC_UPDATE_BLOCKS_HW;
         if (!func)
           return False;
       }
@@ -86,24 +81,25 @@ BoolInt Sha256_SetFunction(CSha256 *p, u
       return False;
   #endif
 
-  p->func_UpdateBlocks = func;
+  p->v.vars.func_UpdateBlocks = func;
   return True;
 }
 
 
 /* define it for speed optimization */
 
-#ifdef _SFX
+#ifdef Z7_SFX
   #define STEP_PRE 1
   #define STEP_MAIN 1
 #else
   #define STEP_PRE 2
   #define STEP_MAIN 4
-  // #define _SHA256_UNROLL
+  // #define Z7_SHA256_UNROLL
 #endif
 
+#undef Z7_SHA256_BIG_W
 #if STEP_MAIN != 16
-  #define _SHA256_BIG_W
+  #define Z7_SHA256_BIG_W
 #endif
 
 
@@ -111,7 +107,7 @@ BoolInt Sha256_SetFunction(CSha256 *p, u
 
 void Sha256_InitState(CSha256 *p)
 {
-  p->count = 0;
+  p->v.vars.count = 0;
   p->state[0] = 0x6a09e667;
   p->state[1] = 0xbb67ae85;
   p->state[2] = 0x3c6ef372;
@@ -122,21 +118,28 @@ void Sha256_InitState(CSha256 *p)
   p->state[7] = 0x5be0cd19;
 }
 
+
+
+
+
+
+
+
 void Sha256_Init(CSha256 *p)
 {
-  p->func_UpdateBlocks =
-  #ifdef _SHA_SUPPORTED
-      g_FUNC_UPDATE_BLOCKS;
+  p->v.vars.func_UpdateBlocks =
+  #ifdef Z7_COMPILER_SHA256_SUPPORTED
+      g_SHA256_FUNC_UPDATE_BLOCKS;
   #else
       NULL;
   #endif
   Sha256_InitState(p);
 }
 
-#define S0(x) (rotrFixed(x, 2) ^ rotrFixed(x,13) ^ rotrFixed(x, 22))
-#define S1(x) (rotrFixed(x, 6) ^ rotrFixed(x,11) ^ rotrFixed(x, 25))
+#define S0(x) (rotrFixed(x, 2) ^ rotrFixed(x,13) ^ rotrFixed(x,22))
+#define S1(x) (rotrFixed(x, 6) ^ rotrFixed(x,11) ^ rotrFixed(x,25))
 #define s0(x) (rotrFixed(x, 7) ^ rotrFixed(x,18) ^ (x >> 3))
-#define s1(x) (rotrFixed(x,17) ^ rotrFixed(x,19) ^ (x >> 10))
+#define s1(x) (rotrFixed(x,17) ^ rotrFixed(x,19) ^ (x >>10))
 
 #define Ch(x,y,z) (z^(x&(y^z)))
 #define Maj(x,y,z) ((x&y)|(z&(x|y)))
@@ -146,7 +149,7 @@ void Sha256_Init(CSha256 *p)
 
 #define blk2_main(j, i)  s1(w(j, (i)-2)) + w(j, (i)-7) + s0(w(j, (i)-15))
 
-#ifdef _SHA256_BIG_W
+#ifdef Z7_SHA256_BIG_W
     // we use +i instead of +(i) to change the order to solve CLANG compiler warning for signed/unsigned.
     #define w(j, i)     W[(size_t)(j) + i]
     #define blk2(j, i)  (w(j, i) = w(j, (i)-16) + blk2_main(j, i))
@@ -177,7 +180,7 @@ void Sha256_Init(CSha256 *p)
 #define R1_PRE(i)  T1( W_PRE, i)
 #define R1_MAIN(i) T1( W_MAIN, i)
 
-#if (!defined(_SHA256_UNROLL) || STEP_MAIN < 8) && (STEP_MAIN >= 4)
+#if (!defined(Z7_SHA256_UNROLL) || STEP_MAIN < 8) && (STEP_MAIN >= 4)
 #define R2_MAIN(i) \
     R1_MAIN(i) \
     R1_MAIN(i + 1) \
@@ -186,7 +189,7 @@ void Sha256_Init(CSha256 *p)
 
 
 
-#if defined(_SHA256_UNROLL) && STEP_MAIN >= 8
+#if defined(Z7_SHA256_UNROLL) && STEP_MAIN >= 8
 
 #define T4( a,b,c,d,e,f,g,h, wx, i) \
     h += S1(e) + Ch(e,f,g) + K[(i)+(size_t)(j)] + wx(i); \
@@ -224,14 +227,10 @@ void Sha256_Init(CSha256 *p)
 
 #endif
 
-void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks);
 
-// static
-extern MY_ALIGN(64)
-const UInt32 SHA256_K_ARRAY[64];
-
-MY_ALIGN(64)
-const UInt32 SHA256_K_ARRAY[64] = {
+extern
+MY_ALIGN(64) const UInt32 SHA256_K_ARRAY[64];
+MY_ALIGN(64) const UInt32 SHA256_K_ARRAY[64] = {
   0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
   0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
@@ -250,27 +249,29 @@ const UInt32 SHA256_K_ARRAY[64] = {
   0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
 };
 
-#define K SHA256_K_ARRAY
 
 
-MY_NO_INLINE
-void MY_FAST_CALL Sha256_UpdateBlocks(UInt32 state[8], const Byte *data, size_t numBlocks)
+
+
+#define K SHA256_K_ARRAY
+
+Z7_NO_INLINE
+void Z7_FASTCALL Sha256_UpdateBlocks(UInt32 state[8], const Byte *data, size_t numBlocks)
 {
   UInt32 W
-  #ifdef _SHA256_BIG_W
+#ifdef Z7_SHA256_BIG_W
       [64];
-  #else
+#else
       [16];
-  #endif
-
+#endif
   unsigned j;
-
   UInt32 a,b,c,d,e,f,g,h;
-
-  #if !defined(_SHA256_UNROLL) || (STEP_MAIN <= 4) || (STEP_PRE <= 4)
+#if !defined(Z7_SHA256_UNROLL) || (STEP_MAIN <= 4) || (STEP_PRE <= 4)
   UInt32 tmp;
-  #endif
+#endif
   
+  if (numBlocks == 0) return;
+
   a = state[0];
   b = state[1];
   c = state[2];
@@ -280,7 +281,7 @@ void MY_FAST_CALL Sha256_UpdateBlocks(UI
   g = state[6];
   h = state[7];
 
-  while (numBlocks)
+  do
   {
 
   for (j = 0; j < 16; j += STEP_PRE)
@@ -298,12 +299,12 @@ void MY_FAST_CALL Sha256_UpdateBlocks(UI
 
     #else
 
-      R1_PRE(0);
+      R1_PRE(0)
       #if STEP_PRE >= 2
-      R1_PRE(1);
+      R1_PRE(1)
       #if STEP_PRE >= 4
-      R1_PRE(2);
-      R1_PRE(3);
+      R1_PRE(2)
+      R1_PRE(3)
       #endif
       #endif
     
@@ -312,32 +313,32 @@ void MY_FAST_CALL Sha256_UpdateBlocks(UI
 
   for (j = 16; j < 64; j += STEP_MAIN)
   {
-    #if defined(_SHA256_UNROLL) && STEP_MAIN >= 8
+    #if defined(Z7_SHA256_UNROLL) && STEP_MAIN >= 8
 
       #if STEP_MAIN < 8
-      R4_MAIN(0);
+      R4_MAIN(0)
       #else
-      R8_MAIN(0);
+      R8_MAIN(0)
       #if STEP_MAIN == 16
-      R8_MAIN(8);
+      R8_MAIN(8)
       #endif
       #endif
 
     #else
       
-      R1_MAIN(0);
+      R1_MAIN(0)
       #if STEP_MAIN >= 2
-      R1_MAIN(1);
+      R1_MAIN(1)
       #if STEP_MAIN >= 4
-      R2_MAIN(2);
+      R2_MAIN(2)
       #if STEP_MAIN >= 8
-      R2_MAIN(4);
-      R2_MAIN(6);
+      R2_MAIN(4)
+      R2_MAIN(6)
       #if STEP_MAIN >= 16
-      R2_MAIN(8);
-      R2_MAIN(10);
-      R2_MAIN(12);
-      R2_MAIN(14);
+      R2_MAIN(8)
+      R2_MAIN(10)
+      R2_MAIN(12)
+      R2_MAIN(14)
       #endif
       #endif
       #endif
@@ -354,40 +355,27 @@ void MY_FAST_CALL Sha256_UpdateBlocks(UI
   g += state[6]; state[6] = g;
   h += state[7]; state[7] = h;
 
-  data += 64;
-  numBlocks--;
+  data += SHA256_BLOCK_SIZE;
   }
-
-  /* Wipe variables */
-  /* memset(W, 0, sizeof(W)); */
+  while (--numBlocks);
 }
 
-#undef S0
-#undef S1
-#undef s0
-#undef s1
-#undef K
 
-#define Sha256_UpdateBlock(p) UPDATE_BLOCKS(p)(p->state, p->buffer, 1)
+#define Sha256_UpdateBlock(p) SHA256_UPDATE_BLOCKS(p)(p->state, p->buffer, 1)
 
 void Sha256_Update(CSha256 *p, const Byte *data, size_t size)
 {
   if (size == 0)
     return;
-
   {
-    unsigned pos = (unsigned)p->count & 0x3F;
-    unsigned num;
-    
-    p->count += size;
-    
-    num = 64 - pos;
+    const unsigned pos = (unsigned)p->v.vars.count & (SHA256_BLOCK_SIZE - 1);
+    const unsigned num = SHA256_BLOCK_SIZE - pos;
+    p->v.vars.count += size;
     if (num > size)
     {
       memcpy(p->buffer + pos, data, size);
       return;
     }
-    
     if (pos != 0)
     {
       size -= num;
@@ -397,9 +385,10 @@ void Sha256_Update(CSha256 *p, const Byt
     }
   }
   {
-    size_t numBlocks = size >> 6;
-    UPDATE_BLOCKS(p)(p->state, data, numBlocks);
-    size &= 0x3F;
+    const size_t numBlocks = size >> 6;
+    // if (numBlocks)
+    SHA256_UPDATE_BLOCKS(p)(p->state, data, numBlocks);
+    size &= SHA256_BLOCK_SIZE - 1;
     if (size == 0)
       return;
     data += (numBlocks << 6);
@@ -410,78 +399,94 @@ void Sha256_Update(CSha256 *p, const Byt
 
 void Sha256_Final(CSha256 *p, Byte *digest)
 {
-  unsigned pos = (unsigned)p->count & 0x3F;
-  unsigned i;
-  
+  unsigned pos = (unsigned)p->v.vars.count & (SHA256_BLOCK_SIZE - 1);
   p->buffer[pos++] = 0x80;
-  
-  if (pos > (64 - 8))
+  if (pos > (SHA256_BLOCK_SIZE - 4 * 2))
   {
-    while (pos != 64) { p->buffer[pos++] = 0; }
-    // memset(&p->buf.buffer[pos], 0, 64 - pos);
+    while (pos != SHA256_BLOCK_SIZE) { p->buffer[pos++] = 0; }
+    // memset(&p->buf.buffer[pos], 0, SHA256_BLOCK_SIZE - pos);
     Sha256_UpdateBlock(p);
     pos = 0;
   }
-
-  /*
-  if (pos & 3)
+  memset(&p->buffer[pos], 0, (SHA256_BLOCK_SIZE - 4 * 2) - pos);
   {
-    p->buffer[pos] = 0;
-    p->buffer[pos + 1] = 0;
-    p->buffer[pos + 2] = 0;
-    pos += 3;
-    pos &= ~3;
+    const UInt64 numBits = p->v.vars.count << 3;
+    SetBe32(p->buffer + SHA256_BLOCK_SIZE - 4 * 2, (UInt32)(numBits >> 32))
+    SetBe32(p->buffer + SHA256_BLOCK_SIZE - 4 * 1, (UInt32)(numBits))
   }
+  Sha256_UpdateBlock(p);
+#if 1 && defined(MY_CPU_BE)
+  memcpy(digest, p->state, SHA256_DIGEST_SIZE);
+#else
   {
-    for (; pos < 64 - 8; pos += 4)
-      *(UInt32 *)(&p->buffer[pos]) = 0;
+    unsigned i;
+    for (i = 0; i < 8; i += 2)
+    {
+      const UInt32 v0 = p->state[i];
+      const UInt32 v1 = p->state[(size_t)i + 1];
+      SetBe32(digest    , v0)
+      SetBe32(digest + 4, v1)
+      digest += 4 * 2;
+    }
   }
-  */
 
-  memset(&p->buffer[pos], 0, (64 - 8) - pos);
 
-  {
-    UInt64 numBits = (p->count << 3);
-    SetBe32(p->buffer + 64 - 8, (UInt32)(numBits >> 32));
-    SetBe32(p->buffer + 64 - 4, (UInt32)(numBits));
-  }
-  
-  Sha256_UpdateBlock(p);
 
-  for (i = 0; i < 8; i += 2)
-  {
-    UInt32 v0 = p->state[i];
-    UInt32 v1 = p->state[(size_t)i + 1];
-    SetBe32(digest    , v0);
-    SetBe32(digest + 4, v1);
-    digest += 8;
-  }
-  
+
+#endif
   Sha256_InitState(p);
 }
 
 
-void Sha256Prepare()
+void Sha256Prepare(void)
 {
-  #ifdef _SHA_SUPPORTED
+#ifdef Z7_COMPILER_SHA256_SUPPORTED
   SHA256_FUNC_UPDATE_BLOCKS f, f_hw;
   f = Sha256_UpdateBlocks;
   f_hw = NULL;
-  #ifdef MY_CPU_X86_OR_AMD64
-  #ifndef USE_MY_MM
+#ifdef MY_CPU_X86_OR_AMD64
   if (CPU_IsSupported_SHA()
       && CPU_IsSupported_SSSE3()
-      // && CPU_IsSupported_SSE41()
       )
-  #endif
-  #else
+#else
   if (CPU_IsSupported_SHA2())
-  #endif
+#endif
   {
     // printf("\n========== HW SHA256 ======== \n");
     f = f_hw = Sha256_UpdateBlocks_HW;
   }
-  g_FUNC_UPDATE_BLOCKS    = f;
-  g_FUNC_UPDATE_BLOCKS_HW = f_hw;
-  #endif
+  g_SHA256_FUNC_UPDATE_BLOCKS    = f;
+  g_SHA256_FUNC_UPDATE_BLOCKS_HW = f_hw;
+#endif
 }
+
+#undef U64C
+#undef K
+#undef S0
+#undef S1
+#undef s0
+#undef s1
+#undef Ch
+#undef Maj
+#undef W_MAIN
+#undef W_PRE
+#undef w
+#undef blk2_main
+#undef blk2
+#undef T1
+#undef T4
+#undef T8
+#undef R1_PRE
+#undef R1_MAIN
+#undef R2_MAIN
+#undef R4
+#undef R4_PRE
+#undef R4_MAIN
+#undef R8
+#undef R8_PRE
+#undef R8_MAIN
+#undef STEP_PRE
+#undef STEP_MAIN
+#undef Z7_SHA256_BIG_W
+#undef Z7_SHA256_UNROLL
+#undef Z7_COMPILER_SHA256_SUPPORTED
