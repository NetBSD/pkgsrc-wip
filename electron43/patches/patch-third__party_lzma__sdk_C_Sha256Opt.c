$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Sha256Opt.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Sha256Opt.c
@@ -1,71 +1,53 @@
 /* Sha256Opt.c -- SHA-256 optimized code for SHA-256 hardware instructions
-2021-04-01 : Igor Pavlov : Public domain */
+: Igor Pavlov : Public domain */
 
 #include "Precomp.h"
-
-#if defined(_MSC_VER)
-#if (_MSC_VER < 1900) && (_MSC_VER >= 1200)
-// #define USE_MY_MM
-#endif
-#endif
-
+#include "Compiler.h"
 #include "CpuArch.h"
 
+// #define Z7_USE_HW_SHA_STUB // for debug
 #ifdef MY_CPU_X86_OR_AMD64
-  #if defined(__clang__)
-    #if (__clang_major__ >= 8) // fix that check
+  #if defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 1600) // fix that check
       #define USE_HW_SHA
-      #ifndef __SHA__
-        #define ATTRIB_SHA __attribute__((__target__("sha,ssse3")))
-        #if defined(_MSC_VER)
-          // SSSE3: for clang-cl:
-          #include <tmmintrin.h>
-          #define __SHA__
-        #endif
-      #endif
-
-    #endif
-  #elif defined(__GNUC__)
-    #if (__GNUC__ >= 8) // fix that check
+  #elif defined(Z7_LLVM_CLANG_VERSION)  && (Z7_LLVM_CLANG_VERSION  >= 30800) \
+     || defined(Z7_APPLE_CLANG_VERSION) && (Z7_APPLE_CLANG_VERSION >= 50100) \
+     || defined(Z7_GCC_VERSION)         && (Z7_GCC_VERSION         >= 40900)
       #define USE_HW_SHA
-      #ifndef __SHA__
+      #if !defined(__INTEL_COMPILER)
+      // icc defines __GNUC__, but icc doesn't support __attribute__(__target__)
+      #if !defined(__SHA__) || !defined(__SSSE3__)
         #define ATTRIB_SHA __attribute__((__target__("sha,ssse3")))
-        // #pragma GCC target("sha,ssse3")
       #endif
-    #endif
-  #elif defined(__INTEL_COMPILER)
-    #if (__INTEL_COMPILER >= 1800) // fix that check
-      #define USE_HW_SHA
-    #endif
+      #endif
   #elif defined(_MSC_VER)
-    #ifdef USE_MY_MM
-      #define USE_VER_MIN 1300
-    #else
-      #define USE_VER_MIN 1910
-    #endif
-    #if _MSC_VER >= USE_VER_MIN
+    #if (_MSC_VER >= 1900)
       #define USE_HW_SHA
+    #else
+      #define Z7_USE_HW_SHA_STUB
     #endif
   #endif
 // #endif // MY_CPU_X86_OR_AMD64
+#ifndef USE_HW_SHA
+  // #define Z7_USE_HW_SHA_STUB // for debug
+#endif
 
 #ifdef USE_HW_SHA
 
 // #pragma message("Sha256 HW")
-// #include <wmmintrin.h>
 
-#if !defined(_MSC_VER) || (_MSC_VER >= 1900)
-#include <immintrin.h>
-#else
-#include <emmintrin.h>
 
-#if defined(_MSC_VER) && (_MSC_VER >= 1600)
-// #include <intrin.h>
-#endif
 
-#ifdef USE_MY_MM
-#include "My_mm.h"
-#endif
+
+// sse/sse2/ssse3:
+#include <tmmintrin.h>
+// sha*:
+#include <immintrin.h>
+
+#if defined (__clang__) && defined(_MSC_VER)
+  #if !defined(__SHA__)
+    #include <shaintrin.h>
+  #endif
+#else
 
 #endif
 
@@ -94,60 +76,44 @@ SHA:
 extern
 MY_ALIGN(64)
 const UInt32 SHA256_K_ARRAY[64];
-
 #define K SHA256_K_ARRAY
 
 
-#define ADD_EPI32(dest, src) dest = _mm_add_epi32(dest, src);
-#define SHA256_MSG1(dest, src) dest = _mm_sha256msg1_epu32(dest, src);
-#define SHA25G_MSG2(dest, src) dest = _mm_sha256msg2_epu32(dest, src);
-
+#define ADD_EPI32(dest, src)      dest = _mm_add_epi32(dest, src);
+#define SHA256_MSG1(dest, src)    dest = _mm_sha256msg1_epu32(dest, src);
+#define SHA256_MSG2(dest, src)    dest = _mm_sha256msg2_epu32(dest, src);
 
 #define LOAD_SHUFFLE(m, k) \
     m = _mm_loadu_si128((const __m128i *)(const void *)(data + (k) * 16)); \
     m = _mm_shuffle_epi8(m, mask); \
 
-#define SM1(g0, g1, g2, g3) \
-    SHA256_MSG1(g3, g0); \
-
-#define SM2(g0, g1, g2, g3) \
-    tmp = _mm_alignr_epi8(g1, g0, 4); \
-    ADD_EPI32(g2, tmp); \
-    SHA25G_MSG2(g2, g1); \
-
-// #define LS0(k, g0, g1, g2, g3) LOAD_SHUFFLE(g0, k)
-// #define LS1(k, g0, g1, g2, g3) LOAD_SHUFFLE(g1, k+1)
+#define NNN(m0, m1, m2, m3)
 
+#define SM1(m1, m2, m3, m0) \
+    SHA256_MSG1(m0, m1); \
 
-#define NNN(g0, g1, g2, g3)
-
+#define SM2(m2, m3, m0, m1) \
+    ADD_EPI32(m0, _mm_alignr_epi8(m3, m2, 4)) \
+    SHA256_MSG2(m0, m3); \
 
 #define RND2(t0, t1) \
     t0 = _mm_sha256rnds2_epu32(t0, t1, msg);
 
-#define RND2_0(m, k) \
-    msg = _mm_add_epi32(m, *(const __m128i *) (const void *) &K[(k) * 4]); \
-    RND2(state0, state1); \
-    msg = _mm_shuffle_epi32(msg, 0x0E); \
 
 
-#define RND2_1 \
+#define R4(k, m0, m1, m2, m3, OP0, OP1) \
+    msg = _mm_add_epi32(m0, *(const __m128i *) (const void *) &K[(k) * 4]); \
+    RND2(state0, state1); \
+    msg = _mm_shuffle_epi32(msg, 0x0E); \
+    OP0(m0, m1, m2, m3) \
     RND2(state1, state0); \
-
-
-// We use scheme with 3 rounds ahead for SHA256_MSG1 / 2 rounds ahead for SHA256_MSG2
-
-#define R4(k, g0, g1, g2, g3, OP0, OP1) \
-    RND2_0(g0, k); \
-    OP0(g0, g1, g2, g3); \
-    RND2_1; \
-    OP1(g0, g1, g2, g3); \
+    OP1(m0, m1, m2, m3) \
 
 #define R16(k, OP0, OP1, OP2, OP3, OP4, OP5, OP6, OP7) \
-    R4 ( (k)*4+0, m0, m1, m2, m3, OP0, OP1 ) \
-    R4 ( (k)*4+1, m1, m2, m3, m0, OP2, OP3 ) \
-    R4 ( (k)*4+2, m2, m3, m0, m1, OP4, OP5 ) \
-    R4 ( (k)*4+3, m3, m0, m1, m2, OP6, OP7 ) \
+    R4 ( (k)*4+0, m0,m1,m2,m3, OP0, OP1 ) \
+    R4 ( (k)*4+1, m1,m2,m3,m0, OP2, OP3 ) \
+    R4 ( (k)*4+2, m2,m3,m0,m1, OP4, OP5 ) \
+    R4 ( (k)*4+3, m3,m0,m1,m2, OP6, OP7 ) \
 
 #define PREPARE_STATE \
     tmp    = _mm_shuffle_epi32(state0, 0x1B); /* abcd */ \
@@ -157,15 +123,16 @@ const UInt32 SHA256_K_ARRAY[64];
     state1 = _mm_unpackhi_epi64(state1, tmp); /* abef */ \
 
 
-void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks);
+void Z7_FASTCALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks);
 #ifdef ATTRIB_SHA
 ATTRIB_SHA
 #endif
-void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks)
+void Z7_FASTCALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks)
 {
   const __m128i mask = _mm_set_epi32(0x0c0d0e0f, 0x08090a0b, 0x04050607, 0x00010203);
-  __m128i tmp;
-  __m128i state0, state1;
+
+
+  __m128i tmp, state0, state1;
 
   if (numBlocks == 0)
     return;
@@ -192,13 +159,13 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW
 
 
 
-    R16 ( 0, NNN, NNN, SM1, NNN, SM1, SM2, SM1, SM2 );
-    R16 ( 1, SM1, SM2, SM1, SM2, SM1, SM2, SM1, SM2 );
-    R16 ( 2, SM1, SM2, SM1, SM2, SM1, SM2, SM1, SM2 );
-    R16 ( 3, SM1, SM2, NNN, SM2, NNN, NNN, NNN, NNN );
+    R16 ( 0, NNN, NNN, SM1, NNN, SM1, SM2, SM1, SM2 )
+    R16 ( 1, SM1, SM2, SM1, SM2, SM1, SM2, SM1, SM2 )
+    R16 ( 2, SM1, SM2, SM1, SM2, SM1, SM2, SM1, SM2 )
+    R16 ( 3, SM1, SM2, NNN, SM2, NNN, NNN, NNN, NNN )
     
-    ADD_EPI32(state0, state0_save);
-    ADD_EPI32(state1, state1_save);
+    ADD_EPI32(state0, state0_save)
+    ADD_EPI32(state1, state1_save)
     
     data += 64;
   }
@@ -212,19 +179,28 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW
 
 #endif // USE_HW_SHA
 
-#elif defined(MY_CPU_ARM_OR_ARM64)
+#elif defined(MY_CPU_ARM_OR_ARM64) && defined(MY_CPU_LE)
 
-  #if defined(__clang__)
-    #if (__clang_major__ >= 8) // fix that check
+  #if   defined(__ARM_FEATURE_SHA2) \
+     || defined(__ARM_FEATURE_CRYPTO)
+    #define USE_HW_SHA
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
       #define USE_HW_SHA
     #endif
-  #elif defined(__GNUC__)
-    #if (__GNUC__ >= 6) // fix that check
-      #define USE_HW_SHA
     #endif
-  #elif defined(_MSC_VER)
-    #if _MSC_VER >= 1910
-      #define USE_HW_SHA
     #endif
   #endif
 
@@ -232,63 +208,144 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW
 
 // #pragma message("=== Sha256 HW === ")
 
+
 #if defined(__clang__) || defined(__GNUC__)
+#if !defined(__ARM_FEATURE_SHA2) && \
+    !defined(__ARM_FEATURE_CRYPTO)
   #ifdef MY_CPU_ARM64
+#if defined(__clang__)
+    #define ATTRIB_SHA __attribute__((__target__("crypto")))
+#else
     #define ATTRIB_SHA __attribute__((__target__("+crypto")))
+#endif
   #else
+#if defined(__clang__) && (__clang_major__ >= 1)
+    #define ATTRIB_SHA __attribute__((__target__("armv8-a,sha2")))
+#else
     #define ATTRIB_SHA __attribute__((__target__("fpu=crypto-neon-fp-armv8")))
+#endif
   #endif
+#endif
 #else
   // _MSC_VER
   // for arm32
   #define _ARM_USE_NEW_NEON_INTRINSICS
 #endif
 
-#if defined(_MSC_VER) && defined(MY_CPU_ARM64)
+#if defined(Z7_MSC_VER_ORIGINAL) && defined(MY_CPU_ARM64)
 #include <arm64_neon.h>
 #else
+
+#if defined(__clang__) && __clang_major__ < 16
+#if !defined(__ARM_FEATURE_SHA2) && \
+    !defined(__ARM_FEATURE_CRYPTO)
+//     #pragma message("=== we set __ARM_FEATURE_CRYPTO 1 === ")
+    Z7_DIAGNOSTIC_IGNORE_BEGIN_RESERVED_MACRO_IDENTIFIER
+    #define Z7_ARM_FEATURE_CRYPTO_WAS_SET 1
+// #if defined(__clang__) && __clang_major__ < 13
+    #define __ARM_FEATURE_CRYPTO 1
+// #else
+    #define __ARM_FEATURE_SHA2 1
+// #endif
+    Z7_DIAGNOSTIC_IGNORE_END_RESERVED_MACRO_IDENTIFIER
+#endif
+#endif // clang
+
+#if defined(__clang__)
+
+#if defined(__ARM_ARCH) && __ARM_ARCH < 8
+    Z7_DIAGNOSTIC_IGNORE_BEGIN_RESERVED_MACRO_IDENTIFIER
+//    #pragma message("#define __ARM_ARCH 8")
+    #undef  __ARM_ARCH
+    #define __ARM_ARCH 8
+    Z7_DIAGNOSTIC_IGNORE_END_RESERVED_MACRO_IDENTIFIER
+#endif
+
+#endif // clang
+
 #include <arm_neon.h>
+
+#if defined(Z7_ARM_FEATURE_CRYPTO_WAS_SET) && \
+    defined(__ARM_FEATURE_CRYPTO) && \
+    defined(__ARM_FEATURE_SHA2)
+Z7_DIAGNOSTIC_IGNORE_BEGIN_RESERVED_MACRO_IDENTIFIER
+    #undef __ARM_FEATURE_CRYPTO
+    #undef __ARM_FEATURE_SHA2
+    #undef Z7_ARM_FEATURE_CRYPTO_WAS_SET
+Z7_DIAGNOSTIC_IGNORE_END_RESERVED_MACRO_IDENTIFIER
+//    #pragma message("=== we undefine __ARM_FEATURE_CRYPTO === ")
 #endif
 
+#endif // Z7_MSC_VER_ORIGINAL
+
 typedef uint32x4_t v128;
 // typedef __n128 v128; // MSVC
 
 #ifdef MY_CPU_BE
-  #define MY_rev32_for_LE(x)
+  #define MY_rev32_for_LE(x) x
 #else
-  #define MY_rev32_for_LE(x) x = vreinterpretq_u32_u8(vrev32q_u8(vreinterpretq_u8_u32(x)))
+  #define MY_rev32_for_LE(x) vrev32q_u8(x)
 #endif
 
-#define LOAD_128(_p)      (*(const v128 *)(const void *)(_p))
-#define STORE_128(_p, _v) *(v128 *)(void *)(_p) = (_v)
+#if 1 // 0 for debug
+// for arm32: it works slower by some reason than direct code
+/*
+for arm32 it generates:
+MSVC-2022, GCC-9:
+    vld1.32 {d18,d19}, [r10]
+    vst1.32 {d4,d5}, [r3]
+    vld1.8  {d20-d21}, [r4]
+there is no align hint (like [r10:128]).  So instruction allows unaligned access
+*/
+#define LOAD_128_32(_p)       vld1q_u32(_p)
+#define LOAD_128_8(_p)        vld1q_u8 (_p)
+#define STORE_128_32(_p, _v)  vst1q_u32(_p, _v)
+#else
+/*
+for arm32:
+MSVC-2022:
+    vldm r10,{d18,d19}
+    vstm r3,{d4,d5}
+    does it require strict alignment?
+GCC-9:
+    vld1.64 {d30-d31}, [r0:64]
+    vldr  d28, [r0, #16]
+    vldr  d29, [r0, #24]
+    vst1.64 {d30-d31}, [r0:64]
+    vstr  d28, [r0, #16]
+    vstr  d29, [r0, #24]
+there is hint [r0:64], so does it requires 64-bit alignment.
+*/
+#define LOAD_128_32(_p)       (*(const v128 *)(const void *)(_p))
+#define LOAD_128_8(_p)        vreinterpretq_u8_u32(*(const v128 *)(const void *)(_p))
+#define STORE_128_32(_p, _v)  *(v128 *)(void *)(_p) = (_v)
+#endif
 
 #define LOAD_SHUFFLE(m, k) \
-    m = LOAD_128((data + (k) * 16)); \
-    MY_rev32_for_LE(m); \
+    m = vreinterpretq_u32_u8( \
+        MY_rev32_for_LE( \
+        LOAD_128_8(data + (k) * 16))); \
 
 // K array must be aligned for 16-bytes at least.
 extern
 MY_ALIGN(64)
 const UInt32 SHA256_K_ARRAY[64];
-
 #define K SHA256_K_ARRAY
 
-
 #define SHA256_SU0(dest, src)        dest = vsha256su0q_u32(dest, src);
-#define SHA25G_SU1(dest, src2, src3) dest = vsha256su1q_u32(dest, src2, src3);
+#define SHA256_SU1(dest, src2, src3) dest = vsha256su1q_u32(dest, src2, src3);
 
-#define SM1(g0, g1, g2, g3)  SHA256_SU0(g3, g0)
-#define SM2(g0, g1, g2, g3)  SHA25G_SU1(g2, g0, g1)
-#define NNN(g0, g1, g2, g3)
+#define SM1(m0, m1, m2, m3)  SHA256_SU0(m3, m0)
+#define SM2(m0, m1, m2, m3)  SHA256_SU1(m2, m0, m1)
+#define NNN(m0, m1, m2, m3)
 
-
-#define R4(k, g0, g1, g2, g3, OP0, OP1) \
-    msg = vaddq_u32(g0, *(const v128 *) (const void *) &K[(k) * 4]); \
+#define R4(k, m0, m1, m2, m3, OP0, OP1) \
+    msg = vaddq_u32(m0, *(const v128 *) (const void *) &K[(k) * 4]); \
     tmp = state0; \
     state0 = vsha256hq_u32( state0, state1, msg ); \
     state1 = vsha256h2q_u32( state1, tmp, msg ); \
-    OP0(g0, g1, g2, g3); \
-    OP1(g0, g1, g2, g3); \
+    OP0(m0, m1, m2, m3); \
+    OP1(m0, m1, m2, m3); \
 
 
 #define R16(k, OP0, OP1, OP2, OP3, OP4, OP5, OP6, OP7) \
@@ -298,19 +355,19 @@ const UInt32 SHA256_K_ARRAY[64];
     R4 ( (k)*4+3, m3, m0, m1, m2, OP6, OP7 ) \
 
 
-void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks);
+void Z7_FASTCALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks);
 #ifdef ATTRIB_SHA
 ATTRIB_SHA
 #endif
-void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks)
+void Z7_FASTCALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks)
 {
   v128 state0, state1;
 
   if (numBlocks == 0)
     return;
 
-  state0 = LOAD_128(&state[0]);
-  state1 = LOAD_128(&state[4]);
+  state0 = LOAD_128_32(&state[0]);
+  state1 = LOAD_128_32(&state[4]);
   
   do
   {
@@ -326,10 +383,10 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW
     LOAD_SHUFFLE (m2, 2)
     LOAD_SHUFFLE (m3, 3)
 
-    R16 ( 0, NNN, NNN, SM1, NNN, SM1, SM2, SM1, SM2 );
-    R16 ( 1, SM1, SM2, SM1, SM2, SM1, SM2, SM1, SM2 );
-    R16 ( 2, SM1, SM2, SM1, SM2, SM1, SM2, SM1, SM2 );
-    R16 ( 3, SM1, SM2, NNN, SM2, NNN, NNN, NNN, NNN );
+    R16 ( 0, NNN, NNN, SM1, NNN, SM1, SM2, SM1, SM2 )
+    R16 ( 1, SM1, SM2, SM1, SM2, SM1, SM2, SM1, SM2 )
+    R16 ( 2, SM1, SM2, SM1, SM2, SM1, SM2, SM1, SM2 )
+    R16 ( 3, SM1, SM2, NNN, SM2, NNN, NNN, NNN, NNN )
     
     state0 = vaddq_u32(state0, state0_save);
     state1 = vaddq_u32(state1, state1_save);
@@ -338,8 +395,8 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW
   }
   while (--numBlocks);
 
-  STORE_128(&state[0], state0);
-  STORE_128(&state[4], state1);
+  STORE_128_32(&state[0], state0);
+  STORE_128_32(&state[4], state1);
 }
 
 #endif // USE_HW_SHA
@@ -347,18 +404,19 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW
 #endif // MY_CPU_ARM_OR_ARM64
 
 
-#ifndef USE_HW_SHA
-
+#if !defined(USE_HW_SHA) && defined(Z7_USE_HW_SHA_STUB)
 // #error Stop_Compiling_UNSUPPORTED_SHA
 // #include <stdlib.h>
-
+// We can compile this file with another C compiler,
+// or we can compile asm version.
+// So we can generate real code instead of this stub function.
 // #include "Sha256.h"
-void MY_FAST_CALL Sha256_UpdateBlocks(UInt32 state[8], const Byte *data, size_t numBlocks);
-
+// #if defined(_MSC_VER)
 #pragma message("Sha256 HW-SW stub was used")
-
-void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks);
-void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks)
+// #endif
+void Z7_FASTCALL Sha256_UpdateBlocks   (UInt32 state[8], const Byte *data, size_t numBlocks);
+void Z7_FASTCALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks);
+void Z7_FASTCALL Sha256_UpdateBlocks_HW(UInt32 state[8], const Byte *data, size_t numBlocks)
 {
   Sha256_UpdateBlocks(state, data, numBlocks);
   /*
@@ -369,5 +427,25 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW
   return;
   */
 }
-
 #endif
+
+
+#undef K
+#undef RND2
+#undef MY_rev32_for_LE
+
+#undef NNN
+#undef LOAD_128
+#undef STORE_128
+#undef LOAD_SHUFFLE
+#undef SM1
+#undef SM2
+
+
+#undef R4
+#undef R16
+#undef PREPARE_STATE
+#undef USE_HW_SHA
+#undef ATTRIB_SHA
+#undef USE_VER_MIN
+#undef Z7_USE_HW_SHA_STUB
