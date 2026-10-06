$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/CpuArch.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/CpuArch.h
@@ -1,8 +1,8 @@
 /* CpuArch.h -- CPU specific code
-2022-07-15 : Igor Pavlov : Public domain */
+Igor Pavlov : Public domain */
 
-#ifndef __CPU_ARCH_H
-#define __CPU_ARCH_H
+#ifndef ZIP7_INC_CPU_ARCH_H
+#define ZIP7_INC_CPU_ARCH_H
 
 #include "7zTypes.h"
 
@@ -20,6 +20,7 @@ MY_CPU_64BIT means that processor can wo
   MY_CPU_64BIT doesn't mean that (sizeof(void *) == 8)
 */
 
+#if !defined(_M_ARM64EC)
 #if  defined(_M_X64) \
   || defined(_M_AMD64) \
   || defined(__x86_64__) \
@@ -35,6 +36,7 @@ MY_CPU_64BIT means that processor can wo
   #endif
   #define MY_CPU_64BIT
 #endif
+#endif
 
 
 #if  defined(_M_IX86) \
@@ -47,11 +49,26 @@ MY_CPU_64BIT means that processor can wo
 
 
 #if  defined(_M_ARM64) \
+  || defined(_M_ARM64EC) \
   || defined(__AARCH64EL__) \
   || defined(__AARCH64EB__) \
   || defined(__aarch64__)
   #define MY_CPU_ARM64
-  #define MY_CPU_NAME "arm64"
+#if   defined(__ILP32__) \
+   || defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ == 4)
+    #define MY_CPU_NAME "arm64-32"
+    #define MY_CPU_SIZEOF_POINTER 4
+#elif defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ == 16)
+    #define MY_CPU_NAME "arm64-128"
+    #define MY_CPU_SIZEOF_POINTER 16
+#else
+#if defined(_M_ARM64EC)
+    #define MY_CPU_NAME "arm64ec"
+#else
+    #define MY_CPU_NAME "arm64"
+#endif
+    #define MY_CPU_SIZEOF_POINTER 8
+#endif
   #define MY_CPU_64BIT
 #endif
 
@@ -68,8 +85,10 @@ MY_CPU_64BIT means that processor can wo
   #define MY_CPU_ARM
 
   #if defined(__thumb__) || defined(__THUMBEL__) || defined(_M_ARMT)
+    #define MY_CPU_ARMT
     #define MY_CPU_NAME "armt"
   #else
+    #define MY_CPU_ARM32
     #define MY_CPU_NAME "arm"
   #endif
   /* #define MY_CPU_32BIT */
@@ -103,6 +122,8 @@ MY_CPU_64BIT means that processor can wo
   || defined(__PPC__) \
   || defined(_POWER)
 
+#define MY_CPU_PPC_OR_PPC64
+
 #if  defined(__ppc64__) \
   || defined(__powerpc64__) \
   || defined(_LP64) \
@@ -123,8 +144,36 @@ MY_CPU_64BIT means that processor can wo
 #endif
 
 
+#if   defined(__sparc__) \
+   || defined(__sparc)
+  #define MY_CPU_SPARC
+  #if  defined(__LP64__) \
+    || defined(_LP64) \
+    || defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ == 8)
+    #define MY_CPU_NAME "sparcv9"
+    #define MY_CPU_SIZEOF_POINTER 8
+    #define MY_CPU_64BIT
+  #elif defined(__sparc_v9__) \
+     || defined(__sparcv9)
+    #define MY_CPU_64BIT
+    #if defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ == 4)
+      #define MY_CPU_NAME "sparcv9-32"
+    #else
+      #define MY_CPU_NAME "sparcv9m"
+    #endif
+  #elif defined(__sparc_v8__) \
+     || defined(__sparcv8)
+    #define MY_CPU_NAME "sparcv8"
+    #define MY_CPU_SIZEOF_POINTER 4
+  #else
+    #define MY_CPU_NAME "sparc"
+  #endif
+#endif
+
+
 #if  defined(__riscv) \
   || defined(__riscv__)
+    #define MY_CPU_RISCV
   #if __riscv_xlen == 32
     #define MY_CPU_NAME "riscv32"
   #elif __riscv_xlen == 64
@@ -135,6 +184,39 @@ MY_CPU_64BIT means that processor can wo
 #endif
 
 
+#if defined(__loongarch__)
+  #define MY_CPU_LOONGARCH
+  #if defined(__loongarch64) || defined(__loongarch_grlen) && (__loongarch_grlen == 64)
+  #define MY_CPU_64BIT
+  #endif
+  #if defined(__loongarch64)
+  #define MY_CPU_NAME "loongarch64"
+  #define MY_CPU_LOONGARCH64
+  #else
+  #define MY_CPU_NAME "loongarch"
+  #endif
+#endif
+
+
+// #undef MY_CPU_NAME
+// #undef MY_CPU_SIZEOF_POINTER
+// #define __e2k__
+// #define __SIZEOF_POINTER__ 4
+#if  defined(__e2k__)
+  #define MY_CPU_E2K
+  #if defined(__ILP32__) || defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ == 4)
+    #define MY_CPU_NAME "e2k-32"
+    #define MY_CPU_SIZEOF_POINTER 4
+  #else
+    #define MY_CPU_NAME "e2k"
+    #if defined(__LP64__) || defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ == 8)
+      #define MY_CPU_SIZEOF_POINTER 8
+    #endif
+  #endif
+  #define MY_CPU_64BIT
+#endif
+
+
 #if defined(MY_CPU_X86) || defined(MY_CPU_AMD64)
 #define MY_CPU_X86_OR_AMD64
 #endif
@@ -165,6 +247,7 @@ MY_CPU_64BIT means that processor can wo
     || defined(MY_CPU_ARM_LE) \
     || defined(MY_CPU_ARM64_LE) \
     || defined(MY_CPU_IA64_LE) \
+    || defined(_LITTLE_ENDIAN) \
     || defined(__LITTLE_ENDIAN__) \
     || defined(__ARMEL__) \
     || defined(__THUMBEL__) \
@@ -197,6 +280,9 @@ MY_CPU_64BIT means that processor can wo
   #error Stop_Compiling_Bad_Endian
 #endif
 
+#if !defined(MY_CPU_LE) && !defined(MY_CPU_BE)
+  #error Stop_Compiling_CPU_ENDIAN_must_be_detected_at_compile_time
+#endif
 
 #if defined(MY_CPU_32BIT) && defined(MY_CPU_64BIT)
   #error Stop_Compiling_Bad_32_64_BIT
@@ -238,6 +324,7 @@ MY_CPU_64BIT means that processor can wo
 
 
 #ifndef MY_CPU_NAME
+  // #define MY_CPU_IS_UNKNOWN
   #ifdef MY_CPU_LE
     #define MY_CPU_NAME "LE"
   #elif defined(MY_CPU_BE)
@@ -253,24 +340,127 @@ MY_CPU_64BIT means that processor can wo
 
 
 
+#ifdef __has_builtin
+  #define Z7_has_builtin(x)  __has_builtin(x)
+#else
+  #define Z7_has_builtin(x)  0
+#endif
+
+
+#define Z7_BSWAP32_CONST(v) \
+       ( (((UInt32)(v) << 24)                   ) \
+       | (((UInt32)(v) <<  8) & (UInt32)0xff0000) \
+       | (((UInt32)(v) >>  8) & (UInt32)0xff00  ) \
+       | (((UInt32)(v) >> 24)                   ))
+
+
+#if defined(_MSC_VER) && (_MSC_VER >= 1300)
+
+#include <stdlib.h>
+
+/* Note: these macros will use bswap instruction (486), that is unsupported in 386 cpu */
+
+#pragma intrinsic(_byteswap_ushort)
+#pragma intrinsic(_byteswap_ulong)
+#pragma intrinsic(_byteswap_uint64)
+
+#define Z7_BSWAP16(v)  _byteswap_ushort(v)
+#define Z7_BSWAP32(v)  _byteswap_ulong (v)
+#define Z7_BSWAP64(v)  _byteswap_uint64(v)
+#define Z7_CPU_FAST_BSWAP_SUPPORTED
+
+/* GCC can generate slow code that calls function for __builtin_bswap32() for:
+     - GCC for RISCV, if Zbb/XTHeadBb extension is not used.
+     - GCC for SPARC.
+   The code from CLANG for SPARC also is not fastest.
+   So we don't define Z7_CPU_FAST_BSWAP_SUPPORTED in some cases.
+*/
+#elif (!defined(MY_CPU_RISCV) || defined (__riscv_zbb) || defined(__riscv_xtheadbb)) \
+    && !defined(MY_CPU_SPARC) \
+    && ( \
+       (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))) \
+    || (defined(__clang__) && Z7_has_builtin(__builtin_bswap16)) \
+    )
+
+#define Z7_BSWAP16(v)  __builtin_bswap16(v)
+#define Z7_BSWAP32(v)  __builtin_bswap32(v)
+#define Z7_BSWAP64(v)  __builtin_bswap64(v)
+#define Z7_CPU_FAST_BSWAP_SUPPORTED
+
+#else
+
+#define Z7_BSWAP16(v) ((UInt16) \
+       ( ((UInt32)(v) << 8) \
+       | ((UInt32)(v) >> 8) \
+       ))
+
+#define Z7_BSWAP32(v) Z7_BSWAP32_CONST(v)
+
+#define Z7_BSWAP64(v) \
+       ( ( ( (UInt64)(v)                           ) << 8 * 7 ) \
+       | ( ( (UInt64)(v) & ((UInt32)0xff << 8 * 1) ) << 8 * 5 ) \
+       | ( ( (UInt64)(v) & ((UInt32)0xff << 8 * 2) ) << 8 * 3 ) \
+       | ( ( (UInt64)(v) & ((UInt32)0xff << 8 * 3) ) << 8 * 1 ) \
+       | ( ( (UInt64)(v) >> 8 * 1 ) & ((UInt32)0xff << 8 * 3) ) \
+       | ( ( (UInt64)(v) >> 8 * 3 ) & ((UInt32)0xff << 8 * 2) ) \
+       | ( ( (UInt64)(v) >> 8 * 5 ) & ((UInt32)0xff << 8 * 1) ) \
+       | ( ( (UInt64)(v) >> 8 * 7 )                           ) \
+       )
+
+#endif
+
+
 // Disable MY_CPU_LE_UNALIGN. Although the underlying ISA may be able to load
 // unaligned words, doing so via pointer casts is undefined behavior in C and
 // C++, under both strict aliasing and because it is invalid to construct
 // unaligned pointers. Instead, load the bytes generically and leave optimizing
 // this to the compiler.
-#if 0
 #ifdef MY_CPU_LE
   #if defined(MY_CPU_X86_OR_AMD64) \
-      || defined(MY_CPU_ARM64)
-    #define MY_CPU_LE_UNALIGN
-    #define MY_CPU_LE_UNALIGN_64
+      || defined(MY_CPU_ARM64) \
+      || defined(MY_CPU_RISCV) && defined(__riscv_misaligned_fast) \
+      || defined(MY_CPU_E2K) && defined(__iset__) && (__iset__ >= 6)
+    // #define MY_CPU_LE_UNALIGN
+    // #define MY_CPU_LE_UNALIGN_64
   #elif defined(__ARM_FEATURE_UNALIGNED)
-    /* gcc9 for 32-bit arm can use LDRD instruction that requires 32-bit alignment.
-       So we can't use unaligned 64-bit operations. */
-    #define MY_CPU_LE_UNALIGN
+/* === ALIGNMENT on 32-bit arm and LDRD/STRD/LDM/STM instructions.
+  Description of problems:
+problem-1 : 32-bit ARM architecture:
+  multi-access (pair of 32-bit accesses) instructions (LDRD/STRD/LDM/STM)
+  require 32-bit (WORD) alignment (by 32-bit ARM architecture).
+  So there is "Alignment fault exception", if data is not aligned for 32-bit.
+
+problem-2 : 32-bit kernels and arm64 kernels:
+  32-bit linux kernels provide fixup for these "paired" instruction "Alignment fault exception".
+  So unaligned paired-access instructions work via exception handler in kernel in 32-bit linux.
+
+  But some arm64 kernels do not handle these faults in 32-bit programs.
+  So we have unhandled exception for such instructions.
+  Probably some new arm64 kernels have fixed it, and unaligned
+  paired-access instructions work in new kernels?
+
+problem-3 : compiler for 32-bit arm:
+  Compilers use LDRD/STRD/LDM/STM for UInt64 accesses
+  and for another cases where two 32-bit accesses are fused
+  to one multi-access instruction.
+  So UInt64 variables must be aligned for 32-bit, and each
+  32-bit access must be aligned for 32-bit, if we want to
+  avoid "Alignment fault" exception (handled or unhandled).
+
+problem-4 : performace:
+  Even if unaligned access is handled by kernel, it will be slow.
+  So if we allow unaligned access, we can get fast unaligned
+  single-access, and slow unaligned paired-access.
+
+  We don't allow unaligned access on 32-bit arm, because compiler
+  genarates paired-access instructions that require 32-bit alignment,
+  and some arm64 kernels have no handler for these instructions.
+  Also unaligned paired-access instructions will be slow, if kernel handles them.
+*/
+    // it must be disabled:
+    // #define MY_CPU_LE_UNALIGN
   #endif
 #endif
-#endif
 
 
 #ifdef MY_CPU_LE_UNALIGN
@@ -279,13 +469,11 @@ MY_CPU_64BIT means that processor can wo
 #define GetUi32(p) (*(const UInt32 *)(const void *)(p))
 #ifdef MY_CPU_LE_UNALIGN_64
 #define GetUi64(p) (*(const UInt64 *)(const void *)(p))
+#define SetUi64(p, v) { *(UInt64 *)(void *)(p) = (v); }
 #endif
 
 #define SetUi16(p, v) { *(UInt16 *)(void *)(p) = (v); }
 #define SetUi32(p, v) { *(UInt32 *)(void *)(p) = (v); }
-#ifdef MY_CPU_LE_UNALIGN_64
-#define SetUi64(p, v) { *(UInt64 *)(void *)(p) = (v); }
-#endif
 
 #else
 
@@ -312,50 +500,33 @@ MY_CPU_64BIT means that processor can wo
 #endif
 
 
-#ifndef MY_CPU_LE_UNALIGN_64
-
+#ifndef GetUi64
 #define GetUi64(p) (GetUi32(p) | ((UInt64)GetUi32(((const Byte *)(p)) + 4) << 32))
+#endif
 
+#ifndef SetUi64
 #define SetUi64(p, v) { Byte *_ppp2_ = (Byte *)(p); UInt64 _vvv2_ = (v); \
-    SetUi32(_ppp2_    , (UInt32)_vvv2_); \
-    SetUi32(_ppp2_ + 4, (UInt32)(_vvv2_ >> 32)); }
-
+    SetUi32(_ppp2_    , (UInt32)_vvv2_) \
+    SetUi32(_ppp2_ + 4, (UInt32)(_vvv2_ >> 32)) }
 #endif
 
 
+#if defined(MY_CPU_LE_UNALIGN) && defined(Z7_CPU_FAST_BSWAP_SUPPORTED)
 
-
-#ifdef __has_builtin
-  #define MY__has_builtin(x) __has_builtin(x)
+#if 0
+// Z7_BSWAP16 can be slow for x86-msvc
+#define GetBe16_to32(p)  (Z7_BSWAP16 (*(const UInt16 *)(const void *)(p)))
 #else
-  #define MY__has_builtin(x) 0
+#define GetBe16_to32(p)  (Z7_BSWAP32 (*(const UInt16 *)(const void *)(p)) >> 16)
 #endif
 
-#if defined(MY_CPU_LE_UNALIGN) && /* defined(_WIN64) && */ defined(_MSC_VER) && (_MSC_VER >= 1300)
-
-/* Note: we use bswap instruction, that is unsupported in 386 cpu */
+#define GetBe32(p)  Z7_BSWAP32 (*(const UInt32 *)(const void *)(p))
+#define SetBe32(p, v) { (*(UInt32 *)(void *)(p)) = Z7_BSWAP32(v); }
 
-#include <stdlib.h>
-
-#pragma intrinsic(_byteswap_ushort)
-#pragma intrinsic(_byteswap_ulong)
-#pragma intrinsic(_byteswap_uint64)
-
-/* #define GetBe16(p) _byteswap_ushort(*(const UInt16 *)(const Byte *)(p)) */
-#define GetBe32(p) _byteswap_ulong (*(const UInt32 *)(const void *)(p))
-#define GetBe64(p) _byteswap_uint64(*(const UInt64 *)(const void *)(p))
-
-#define SetBe32(p, v) (*(UInt32 *)(void *)(p)) = _byteswap_ulong(v)
-
-#elif defined(MY_CPU_LE_UNALIGN) && ( \
-       (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))) \
-    || (defined(__clang__) && MY__has_builtin(__builtin_bswap16)) )
-
-/* #define GetBe16(p) __builtin_bswap16(*(const UInt16 *)(const void *)(p)) */
-#define GetBe32(p) __builtin_bswap32(*(const UInt32 *)(const void *)(p))
-#define GetBe64(p) __builtin_bswap64(*(const UInt64 *)(const void *)(p))
-
-#define SetBe32(p, v) (*(UInt32 *)(void *)(p)) = __builtin_bswap32(v)
+#if defined(MY_CPU_LE_UNALIGN_64)
+#define GetBe64(p)  Z7_BSWAP64 (*(const UInt64 *)(const void *)(p))
+#define SetBe64(p, v) { (*(UInt64 *)(void *)(p)) = Z7_BSWAP64(v); }
+#endif
 
 #else
 
@@ -365,8 +536,6 @@ MY_CPU_64BIT means that processor can wo
     ((UInt32)((const Byte *)(p))[2] <<  8) | \
              ((const Byte *)(p))[3] )
 
-#define GetBe64(p) (((UInt64)GetBe32(p) << 32) | GetBe32(((const Byte *)(p)) + 4))
-
 #define SetBe32(p, v) { Byte *_ppp_ = (Byte *)(p); UInt32 _vvv_ = (v); \
     _ppp_[0] = (Byte)(_vvv_ >> 24); \
     _ppp_[1] = (Byte)(_vvv_ >> 16); \
@@ -375,53 +544,113 @@ MY_CPU_64BIT means that processor can wo
 
 #endif
 
+#ifndef GetBe64
+#define GetBe64(p) (((UInt64)GetBe32(p) << 32) | GetBe32(((const Byte *)(p)) + 4))
+#endif
 
-#ifndef GetBe16
+#ifndef SetBe64
+#define SetBe64(p, v) { Byte *_ppp_ = (Byte *)(p); UInt64 _vvv_ = (v); \
+    _ppp_[0] = (Byte)(_vvv_ >> 56); \
+    _ppp_[1] = (Byte)(_vvv_ >> 48); \
+    _ppp_[2] = (Byte)(_vvv_ >> 40); \
+    _ppp_[3] = (Byte)(_vvv_ >> 32); \
+    _ppp_[4] = (Byte)(_vvv_ >> 24); \
+    _ppp_[5] = (Byte)(_vvv_ >> 16); \
+    _ppp_[6] = (Byte)(_vvv_ >> 8); \
+    _ppp_[7] = (Byte)_vvv_; }
+#endif
 
+#ifndef GetBe16
+#ifdef GetBe16_to32
+#define GetBe16(p) ( (UInt16) GetBe16_to32(p))
+#else
 #define GetBe16(p) ( (UInt16) ( \
     ((UInt16)((const Byte *)(p))[0] << 8) | \
              ((const Byte *)(p))[1] ))
+#endif
+#endif
 
+
+#if defined(MY_CPU_BE)
+#define Z7_CONV_BE_TO_NATIVE_CONST32(v)  (v)
+#define Z7_CONV_LE_TO_NATIVE_CONST32(v)  Z7_BSWAP32_CONST(v)
+#define Z7_CONV_NATIVE_TO_BE_32(v)       (v)
+#elif defined(MY_CPU_LE)
+#define Z7_CONV_BE_TO_NATIVE_CONST32(v)  Z7_BSWAP32_CONST(v)
+#define Z7_CONV_LE_TO_NATIVE_CONST32(v)  (v)
+#define Z7_CONV_NATIVE_TO_BE_32(v)       Z7_BSWAP32(v)
+#else
+#error Stop_Compiling_Unknown_Endian_CONV
 #endif
 
 
+#if defined(MY_CPU_BE)
 
-#ifdef MY_CPU_X86_OR_AMD64
+#define GetBe64a(p)      (*(const UInt64 *)(const void *)(p))
+#define GetBe32a(p)      (*(const UInt32 *)(const void *)(p))
+#define GetBe16a(p)      (*(const UInt16 *)(const void *)(p))
+#define SetBe32a(p, v)   { *(UInt32 *)(void *)(p) = (v); }
+#define SetBe16a(p, v)   { *(UInt16 *)(void *)(p) = (v); }
+
+#define GetUi64a(p)      GetUi64(p)
+#define GetUi32a(p)      GetUi32(p)
+#define GetUi16a(p)      GetUi16(p)
+#define SetUi32a(p, v)   SetUi32(p, v)
+#define SetUi16a(p, v)   SetUi16(p, v)
+
+#elif defined(MY_CPU_LE)
+
+#define GetUi64a(p)      (*(const UInt64 *)(const void *)(p))
+#define GetUi32a(p)      (*(const UInt32 *)(const void *)(p))
+#define GetUi16a(p)      (*(const UInt16 *)(const void *)(p))
+#define SetUi32a(p, v)   { *(UInt32 *)(void *)(p) = (v); }
+#define SetUi16a(p, v)   { *(UInt16 *)(void *)(p) = (v); }
+
+#define GetBe64a(p)      GetBe64(p)
+#define GetBe32a(p)      GetBe32(p)
+#define GetBe16a(p)      GetBe16(p)
+#define SetBe32a(p, v)   SetBe32(p, v)
+#define SetBe16a(p, v)   SetBe16(p, v)
 
-typedef struct
-{
-  UInt32 maxFunc;
-  UInt32 vendor[3];
-  UInt32 ver;
-  UInt32 b;
-  UInt32 c;
-  UInt32 d;
-} Cx86cpuid;
-
-enum
-{
-  CPU_FIRM_INTEL,
-  CPU_FIRM_AMD,
-  CPU_FIRM_VIA
-};
-
-void MyCPUID(UInt32 function, UInt32 *a, UInt32 *b, UInt32 *c, UInt32 *d);
-
-BoolInt x86cpuid_CheckAndRead(Cx86cpuid *p);
-int x86cpuid_GetFirm(const Cx86cpuid *p);
-
-#define x86cpuid_GetFamily(ver) (((ver >> 16) & 0xFF0) | ((ver >> 8) & 0xF))
-#define x86cpuid_GetModel(ver)  (((ver >> 12) &  0xF0) | ((ver >> 4) & 0xF))
-#define x86cpuid_GetStepping(ver) (ver & 0xF)
+#else
+#error Stop_Compiling_Unknown_Endian_CPU_a
+#endif
+
+
+#ifndef GetBe16_to32
+#define GetBe16_to32(p) GetBe16(p)
+#endif
+
+
+#if defined(MY_CPU_X86_OR_AMD64) \
+  || defined(MY_CPU_ARM_OR_ARM64) \
+  || defined(MY_CPU_PPC_OR_PPC64)
+  #define Z7_CPU_FAST_ROTATE_SUPPORTED
+#endif
 
-BoolInt CPU_Is_InOrder(void);
+
+#ifdef MY_CPU_X86_OR_AMD64
+
+void Z7_FASTCALL z7_x86_cpuid(UInt32 a[4], UInt32 function);
+UInt32 Z7_FASTCALL z7_x86_cpuid_GetMaxFunc(void);
+#if defined(MY_CPU_AMD64)
+#define Z7_IF_X86_CPUID_SUPPORTED
+#else
+#define Z7_IF_X86_CPUID_SUPPORTED if (z7_x86_cpuid_GetMaxFunc())
+#endif
 
 BoolInt CPU_IsSupported_AES(void);
+BoolInt CPU_IsSupported_AVX(void);
 BoolInt CPU_IsSupported_AVX2(void);
+BoolInt CPU_IsSupported_AVX512F_AVX512VL(void);
 BoolInt CPU_IsSupported_VAES_AVX2(void);
+BoolInt CPU_IsSupported_CMOV(void);
+BoolInt CPU_IsSupported_SSE(void);
+BoolInt CPU_IsSupported_SSE2(void);
 BoolInt CPU_IsSupported_SSSE3(void);
 BoolInt CPU_IsSupported_SSE41(void);
 BoolInt CPU_IsSupported_SHA(void);
+BoolInt CPU_IsSupported_SHA512(void);
 BoolInt CPU_IsSupported_PageGB(void);
 
 #elif defined(MY_CPU_ARM_OR_ARM64)
@@ -439,12 +668,13 @@ BoolInt CPU_IsSupported_SHA1(void);
 BoolInt CPU_IsSupported_SHA2(void);
 BoolInt CPU_IsSupported_AES(void);
 #endif
+BoolInt CPU_IsSupported_SHA512(void);
 
 #endif
 
 #if defined(__APPLE__)
-int My_sysctlbyname_Get(const char *name, void *buf, size_t *bufSize);
-int My_sysctlbyname_Get_UInt32(const char *name, UInt32 *val);
+int z7_sysctlbyname_Get(const char *name, void *buf, size_t *bufSize);
+int z7_sysctlbyname_Get_UInt32(const char *name, UInt32 *val);
 #endif
 
 EXTERN_C_END
