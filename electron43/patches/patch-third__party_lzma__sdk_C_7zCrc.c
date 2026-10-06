$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zCrc.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zCrc.c
@@ -1,182 +1,218 @@
-/* 7zCrc.c -- CRC32 init
-2021-04-01 : Igor Pavlov : Public domain */
+/* 7zCrc.c -- CRC32 calculation and init
+2024-03-01 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
 #include "7zCrc.h"
 #include "CpuArch.h"
 
-#define kCrcPoly 0xEDB88320
+// for debug:
+// #define __ARM_FEATURE_CRC32 1
 
-#ifdef MY_CPU_LE
-  #define CRC_NUM_TABLES 8
-#else
-  #define CRC_NUM_TABLES 9
-
-  #define CRC_UINT32_SWAP(v) ((v >> 24) | ((v >> 8) & 0xFF00) | ((v << 8) & 0xFF0000) | (v << 24))
-
-  UInt32 MY_FAST_CALL CrcUpdateT1_BeT4(UInt32 v, const void *data, size_t size, const UInt32 *table);
-  UInt32 MY_FAST_CALL CrcUpdateT1_BeT8(UInt32 v, const void *data, size_t size, const UInt32 *table);
+#ifdef __ARM_FEATURE_CRC32
+// #pragma message("__ARM_FEATURE_CRC32")
+#define Z7_CRC_HW_FORCE
 #endif
 
-#ifndef MY_CPU_BE
-  UInt32 MY_FAST_CALL CrcUpdateT4(UInt32 v, const void *data, size_t size, const UInt32 *table);
-  UInt32 MY_FAST_CALL CrcUpdateT8(UInt32 v, const void *data, size_t size, const UInt32 *table);
+// #define Z7_CRC_DEBUG_BE
+#ifdef Z7_CRC_DEBUG_BE
+#undef MY_CPU_LE
+#define MY_CPU_BE
 #endif
 
-typedef UInt32 (MY_FAST_CALL *CRC_FUNC)(UInt32 v, const void *data, size_t size, const UInt32 *table);
-
-extern
-CRC_FUNC g_CrcUpdateT4;
-CRC_FUNC g_CrcUpdateT4;
-extern
-CRC_FUNC g_CrcUpdateT8;
-CRC_FUNC g_CrcUpdateT8;
-extern
-CRC_FUNC g_CrcUpdateT0_32;
-CRC_FUNC g_CrcUpdateT0_32;
-extern
-CRC_FUNC g_CrcUpdateT0_64;
-CRC_FUNC g_CrcUpdateT0_64;
-extern
-CRC_FUNC g_CrcUpdate;
-CRC_FUNC g_CrcUpdate;
-
-UInt32 g_CrcTable[256 * CRC_NUM_TABLES];
+#ifdef Z7_CRC_HW_FORCE
+  #define Z7_CRC_NUM_TABLES_USE  1
+#else
+#ifdef Z7_CRC_NUM_TABLES
+  #define Z7_CRC_NUM_TABLES_USE  Z7_CRC_NUM_TABLES
+#else
+  #define Z7_CRC_NUM_TABLES_USE  12
+#endif
+#endif
 
-UInt32 MY_FAST_CALL CrcUpdate(UInt32 v, const void *data, size_t size)
-{
-  return g_CrcUpdate(v, data, size, g_CrcTable);
-}
+#if Z7_CRC_NUM_TABLES_USE < 1
+  #error Stop_Compiling_Bad_Z7_CRC_NUM_TABLES
+#endif
 
-UInt32 MY_FAST_CALL CrcCalc(const void *data, size_t size)
-{
-  return g_CrcUpdate(CRC_INIT_VAL, data, size, g_CrcTable) ^ CRC_INIT_VAL;
-}
+#if defined(MY_CPU_LE) || (Z7_CRC_NUM_TABLES_USE == 1)
+  #define Z7_CRC_NUM_TABLES_TOTAL  Z7_CRC_NUM_TABLES_USE
+#else
+  #define Z7_CRC_NUM_TABLES_TOTAL  (Z7_CRC_NUM_TABLES_USE + 1)
+#endif
 
-#define CRC_UPDATE_BYTE_2(crc, b) (table[((crc) ^ (b)) & 0xFF] ^ ((crc) >> 8))
+#ifndef Z7_CRC_HW_FORCE
 
-UInt32 MY_FAST_CALL CrcUpdateT1(UInt32 v, const void *data, size_t size, const UInt32 *table);
-UInt32 MY_FAST_CALL CrcUpdateT1(UInt32 v, const void *data, size_t size, const UInt32 *table)
+#if Z7_CRC_NUM_TABLES_USE == 1 \
+   || (!defined(MY_CPU_LE) && !defined(MY_CPU_BE))
+#define CRC_UPDATE_BYTE_2(crc, b)   (table[((crc) ^ (b)) & 0xFF] ^ ((crc) >> 8))
+#define Z7_CRC_UPDATE_T1_FUNC_NAME  CrcUpdateGT1
+static UInt32 Z7_FASTCALL Z7_CRC_UPDATE_T1_FUNC_NAME(UInt32 v, const void *data, size_t size)
 {
+  const UInt32 *table = g_CrcTable;
   const Byte *p = (const Byte *)data;
-  const Byte *pEnd = p + size;
-  for (; p != pEnd; p++)
+  const Byte *lim = p + size;
+  for (; p != lim; p++)
     v = CRC_UPDATE_BYTE_2(v, *p);
   return v;
 }
+#endif
 
 
+#if Z7_CRC_NUM_TABLES_USE != 1
+#ifndef MY_CPU_BE
+  #define FUNC_NAME_LE_2(s)   CrcUpdateT ## s
+  #define FUNC_NAME_LE_1(s)   FUNC_NAME_LE_2(s)
+  #define FUNC_NAME_LE        FUNC_NAME_LE_1(Z7_CRC_NUM_TABLES_USE)
+  UInt32 Z7_FASTCALL FUNC_NAME_LE (UInt32 v, const void *data, size_t size, const UInt32 *table);
+#endif
+#ifndef MY_CPU_LE
+  #define FUNC_NAME_BE_2(s)   CrcUpdateT1_BeT ## s
+  #define FUNC_NAME_BE_1(s)   FUNC_NAME_BE_2(s)
+  #define FUNC_NAME_BE        FUNC_NAME_BE_1(Z7_CRC_NUM_TABLES_USE)
+  UInt32 Z7_FASTCALL FUNC_NAME_BE (UInt32 v, const void *data, size_t size, const UInt32 *table);
+#endif
+#endif
+
+#endif // Z7_CRC_HW_FORCE
+
 /* ---------- hardware CRC ---------- */
 
 #ifdef MY_CPU_LE
 
 #if defined(MY_CPU_ARM_OR_ARM64)
-
 // #pragma message("ARM*")
 
-  #if defined(_MSC_VER)
-    #if defined(MY_CPU_ARM64)
-    #if (_MSC_VER >= 1910)
-        // #define USE_ARM64_CRC
-    #endif
-    #endif
-  #elif (defined(__clang__) && (__clang_major__ >= 3)) \
-     || (defined(__GNUC__) && (__GNUC__ > 4))
+  #if (defined(__clang__) && (__clang_major__ >= 3)) \
+     || defined(__GNUC__) && (__GNUC__ >= 6) && defined(MY_CPU_ARM64) \
+     || defined(__GNUC__) && (__GNUC__ >= 8)
       #if !defined(__ARM_FEATURE_CRC32)
-        // #define __ARM_FEATURE_CRC32 1
-          #if (!defined(__clang__) || (__clang_major__ > 3)) // fix these numbers
-            // #define ATTRIB_CRC __attribute__((__target__("arch=armv8-a+crc")))
+//        #pragma message("!defined(__ARM_FEATURE_CRC32)")
+Z7_DIAGNOSTIC_IGNORE_BEGIN_RESERVED_MACRO_IDENTIFIER
+        #define __ARM_FEATURE_CRC32 1
+Z7_DIAGNOSTIC_IGNORE_END_RESERVED_MACRO_IDENTIFIER
+        #define Z7_ARM_FEATURE_CRC32_WAS_SET
+        #if defined(__clang__)
+          #if defined(MY_CPU_ARM64)
+            #define ATTRIB_CRC __attribute__((__target__("crc")))
+          #else
+            #define ATTRIB_CRC __attribute__((__target__("armv8-a,crc")))
+          #endif
+        #else
+          #if defined(MY_CPU_ARM64)
+#if !defined(Z7_GCC_VERSION) || (Z7_GCC_VERSION >= 60000)
+            #define ATTRIB_CRC __attribute__((__target__("+crc")))
+#endif
+          #else
+#if !defined(Z7_GCC_VERSION) || (__GNUC__  >= 8)
+#if defined(__ARM_FP) && __GNUC__ >= 8
+// for -mfloat-abi=hard: similar to <arm_acle.h>
+            #define ATTRIB_CRC __attribute__((__target__("arch=armv8-a+crc+simd")))
+#else
+            #define ATTRIB_CRC __attribute__((__target__("arch=armv8-a+crc")))
+#endif
+#endif
           #endif
+        #endif
       #endif
       #if defined(__ARM_FEATURE_CRC32)
-        // #define USE_ARM64_CRC
-        // #include <arm_acle.h>
+      // #pragma message("<arm_acle.h>")
+/*
+arm_acle.h (GGC):
+    before Nov 17, 2017:
+#ifdef __ARM_FEATURE_CRC32
+
+    Nov 17, 2017: gcc10.0  (gcc 9.2.0) checked"
+#if __ARM_ARCH >= 8
+#pragma GCC target ("arch=armv8-a+crc")
+
+    Aug 22, 2019: GCC 8.4?, 9.2.1, 10.1:
+#ifdef __ARM_FEATURE_CRC32
+#ifdef __ARM_FP
+#pragma GCC target ("arch=armv8-a+crc+simd")
+#else
+#pragma GCC target ("arch=armv8-a+crc")
+#endif
+*/
+#if defined(__ARM_ARCH) && __ARM_ARCH < 8
+#if defined(Z7_GCC_VERSION) && (__GNUC__ ==   8) && (Z7_GCC_VERSION <  80400) \
+ || defined(Z7_GCC_VERSION) && (__GNUC__ ==   9) && (Z7_GCC_VERSION <  90201) \
+ || defined(Z7_GCC_VERSION) && (__GNUC__ ==  10) && (Z7_GCC_VERSION < 100100)
+Z7_DIAGNOSTIC_IGNORE_BEGIN_RESERVED_MACRO_IDENTIFIER
+// #pragma message("#define __ARM_ARCH 8")
+#undef  __ARM_ARCH
+#define __ARM_ARCH 8
+Z7_DIAGNOSTIC_IGNORE_END_RESERVED_MACRO_IDENTIFIER
+#endif
+#endif
+        #define Z7_CRC_HW_USE
+        #include <arm_acle.h>
       #endif
+  #elif defined(_MSC_VER)
+    #if defined(MY_CPU_ARM64)
+    #if (_MSC_VER >= 1910)
+    #ifdef __clang__
+       // #define Z7_CRC_HW_USE
+       // #include <arm_acle.h>
+    #else
+       #define Z7_CRC_HW_USE
+       #include <intrin.h>
+    #endif
+    #endif
+    #endif
   #endif
 
-#else
-
-// no hardware CRC
-
-// #define USE_CRC_EMU
+#else // non-ARM*
 
-#ifdef USE_CRC_EMU
-
-#pragma message("ARM64 CRC emulation")
-
-MY_FORCE_INLINE
-UInt32 __crc32b(UInt32 v, UInt32 data)
-{
-  const UInt32 *table = g_CrcTable;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data);
-  return v;
-}
-
-MY_FORCE_INLINE
-UInt32 __crc32w(UInt32 v, UInt32 data)
-{
-  const UInt32 *table = g_CrcTable;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  return v;
-}
+// #define Z7_CRC_HW_USE // for debug : we can test HW-branch of code
+#ifdef Z7_CRC_HW_USE
+#include "7zCrcEmu.h"
+#endif
 
-MY_FORCE_INLINE
-UInt32 __crc32d(UInt32 v, UInt64 data)
-{
-  const UInt32 *table = g_CrcTable;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  v = CRC_UPDATE_BYTE_2(v, (Byte)data); data >>= 8;
-  return v;
-}
+#endif // non-ARM*
 
-#endif // USE_CRC_EMU
 
-#endif // defined(MY_CPU_ARM64) && defined(MY_CPU_LE)
 
+#if defined(Z7_CRC_HW_USE)
 
+// #pragma message("USE ARM HW CRC")
 
-#if defined(USE_ARM64_CRC) || defined(USE_CRC_EMU)
+#ifdef MY_CPU_64BIT
+  #define CRC_HW_WORD_TYPE  UInt64
+  #define CRC_HW_WORD_FUNC  __crc32d
+#else
+  #define CRC_HW_WORD_TYPE  UInt32
+  #define CRC_HW_WORD_FUNC  __crc32w
+#endif
 
-#define T0_32_UNROLL_BYTES (4 * 4)
-#define T0_64_UNROLL_BYTES (4 * 8)
+#define CRC_HW_UNROLL_BYTES (sizeof(CRC_HW_WORD_TYPE) * 4)
 
-#ifndef ATTRIB_CRC
-#define ATTRIB_CRC
+#ifdef ATTRIB_CRC
+  ATTRIB_CRC
 #endif
-// #pragma message("USE ARM HW CRC")
-
-ATTRIB_CRC
-UInt32 MY_FAST_CALL CrcUpdateT0_32(UInt32 v, const void *data, size_t size, const UInt32 *table);
-ATTRIB_CRC
-UInt32 MY_FAST_CALL CrcUpdateT0_32(UInt32 v, const void *data, size_t size, const UInt32 *table)
+Z7_NO_INLINE
+#ifdef Z7_CRC_HW_FORCE
+         UInt32 Z7_FASTCALL CrcUpdate
+#else
+  static UInt32 Z7_FASTCALL CrcUpdate_HW
+#endif
+    (UInt32 v, const void *data, size_t size)
 {
   const Byte *p = (const Byte *)data;
-  UNUSED_VAR(table);
-
-  for (; size != 0 && ((unsigned)(ptrdiff_t)p & (T0_32_UNROLL_BYTES - 1)) != 0; size--)
+  for (; size != 0 && ((unsigned)(ptrdiff_t)p & (CRC_HW_UNROLL_BYTES - 1)) != 0; size--)
     v = __crc32b(v, *p++);
-
-  if (size >= T0_32_UNROLL_BYTES)
+  if (size >= CRC_HW_UNROLL_BYTES)
   {
     const Byte *lim = p + size;
-    size &= (T0_32_UNROLL_BYTES - 1);
+    size &= CRC_HW_UNROLL_BYTES - 1;
     lim -= size;
     do
     {
-      v = __crc32w(v, *(const UInt32 *)(const void *)(p));
-      v = __crc32w(v, *(const UInt32 *)(const void *)(p + 4)); p += 2 * 4;
-      v = __crc32w(v, *(const UInt32 *)(const void *)(p));
-      v = __crc32w(v, *(const UInt32 *)(const void *)(p + 4)); p += 2 * 4;
+      v = CRC_HW_WORD_FUNC(v, *(const CRC_HW_WORD_TYPE *)(const void *)(p));
+      v = CRC_HW_WORD_FUNC(v, *(const CRC_HW_WORD_TYPE *)(const void *)(p + sizeof(CRC_HW_WORD_TYPE)));
+      p += 2 * sizeof(CRC_HW_WORD_TYPE);
+      v = CRC_HW_WORD_FUNC(v, *(const CRC_HW_WORD_TYPE *)(const void *)(p));
+      v = CRC_HW_WORD_FUNC(v, *(const CRC_HW_WORD_TYPE *)(const void *)(p + sizeof(CRC_HW_WORD_TYPE)));
+      p += 2 * sizeof(CRC_HW_WORD_TYPE);
     }
     while (p != lim);
   }
@@ -187,136 +223,198 @@ UInt32 MY_FAST_CALL CrcUpdateT0_32(UInt3
   return v;
 }
 
-ATTRIB_CRC
-UInt32 MY_FAST_CALL CrcUpdateT0_64(UInt32 v, const void *data, size_t size, const UInt32 *table);
-ATTRIB_CRC
-UInt32 MY_FAST_CALL CrcUpdateT0_64(UInt32 v, const void *data, size_t size, const UInt32 *table)
+#ifdef Z7_ARM_FEATURE_CRC32_WAS_SET
+Z7_DIAGNOSTIC_IGNORE_BEGIN_RESERVED_MACRO_IDENTIFIER
+#undef __ARM_FEATURE_CRC32
+Z7_DIAGNOSTIC_IGNORE_END_RESERVED_MACRO_IDENTIFIER
+#undef Z7_ARM_FEATURE_CRC32_WAS_SET
+#endif
+
+#endif // defined(Z7_CRC_HW_USE)
+#endif // MY_CPU_LE
+
+
+
+#ifndef Z7_CRC_HW_FORCE
+
+#if defined(Z7_CRC_HW_USE) || defined(Z7_CRC_UPDATE_T1_FUNC_NAME)
+/*
+typedef UInt32 (Z7_FASTCALL *Z7_CRC_UPDATE_WITH_TABLE_FUNC)
+    (UInt32 v, const void *data, size_t size, const UInt32 *table);
+Z7_CRC_UPDATE_WITH_TABLE_FUNC g_CrcUpdate;
+*/
+static unsigned g_Crc_Algo;
+#if (!defined(MY_CPU_LE) && !defined(MY_CPU_BE))
+static unsigned g_Crc_Be;
+#endif
+#endif // defined(Z7_CRC_HW_USE) || defined(Z7_CRC_UPDATE_T1_FUNC_NAME)
+
+
+
+Z7_NO_INLINE
+#ifdef Z7_CRC_HW_USE
+  static UInt32 Z7_FASTCALL CrcUpdate_Base
+#else
+         UInt32 Z7_FASTCALL CrcUpdate
+#endif
+    (UInt32 crc, const void *data, size_t size)
 {
-  const Byte *p = (const Byte *)data;
-  UNUSED_VAR(table);
+#if Z7_CRC_NUM_TABLES_USE == 1
+    return Z7_CRC_UPDATE_T1_FUNC_NAME(crc, data, size);
+#else // Z7_CRC_NUM_TABLES_USE != 1
+#ifdef Z7_CRC_UPDATE_T1_FUNC_NAME
+  if (g_Crc_Algo == 1)
+    return Z7_CRC_UPDATE_T1_FUNC_NAME(crc, data, size);
+#endif
 
-  for (; size != 0 && ((unsigned)(ptrdiff_t)p & (T0_64_UNROLL_BYTES - 1)) != 0; size--)
-    v = __crc32b(v, *p++);
+#ifdef MY_CPU_LE
+    return FUNC_NAME_LE(crc, data, size, g_CrcTable);
+#elif defined(MY_CPU_BE)
+    return FUNC_NAME_BE(crc, data, size, g_CrcTable);
+#else
+  if (g_Crc_Be)
+    return FUNC_NAME_BE(crc, data, size, g_CrcTable);
+  else
+    return FUNC_NAME_LE(crc, data, size, g_CrcTable);
+#endif
+#endif // Z7_CRC_NUM_TABLES_USE != 1
+}
 
-  if (size >= T0_64_UNROLL_BYTES)
-  {
-    const Byte *lim = p + size;
-    size &= (T0_64_UNROLL_BYTES - 1);
-    lim -= size;
-    do
-    {
-      v = __crc32d(v, *(const UInt64 *)(const void *)(p));
-      v = __crc32d(v, *(const UInt64 *)(const void *)(p + 8)); p += 2 * 8;
-      v = __crc32d(v, *(const UInt64 *)(const void *)(p));
-      v = __crc32d(v, *(const UInt64 *)(const void *)(p + 8)); p += 2 * 8;
-    }
-    while (p != lim);
-  }
-  
-  for (; size != 0; size--)
-    v = __crc32b(v, *p++);
 
-  return v;
+#ifdef Z7_CRC_HW_USE
+Z7_NO_INLINE
+UInt32 Z7_FASTCALL CrcUpdate(UInt32 crc, const void *data, size_t size)
+{
+  if (g_Crc_Algo == 0)
+    return CrcUpdate_HW(crc, data, size);
+  return CrcUpdate_Base(crc, data, size);
 }
+#endif
 
-#endif // defined(USE_ARM64_CRC) || defined(USE_CRC_EMU)
+#endif // !defined(Z7_CRC_HW_FORCE)
 
-#endif // MY_CPU_LE
 
 
+UInt32 Z7_FASTCALL CrcCalc(const void *data, size_t size)
+{
+  return CrcUpdate(CRC_INIT_VAL, data, size) ^ CRC_INIT_VAL;
+}
+
+
+MY_ALIGN(64)
+UInt32 g_CrcTable[256 * Z7_CRC_NUM_TABLES_TOTAL];
 
 
-void MY_FAST_CALL CrcGenerateTable()
+void Z7_FASTCALL CrcGenerateTable(void)
 {
   UInt32 i;
   for (i = 0; i < 256; i++)
   {
+#if defined(Z7_CRC_HW_FORCE)
+    g_CrcTable[i] = __crc32b(i, 0);
+#else
+    #define kCrcPoly 0xEDB88320
     UInt32 r = i;
     unsigned j;
     for (j = 0; j < 8; j++)
       r = (r >> 1) ^ (kCrcPoly & ((UInt32)0 - (r & 1)));
     g_CrcTable[i] = r;
+#endif
   }
-  for (i = 256; i < 256 * CRC_NUM_TABLES; i++)
+  for (i = 256; i < 256 * Z7_CRC_NUM_TABLES_USE; i++)
   {
-    UInt32 r = g_CrcTable[(size_t)i - 256];
+    const UInt32 r = g_CrcTable[(size_t)i - 256];
     g_CrcTable[i] = g_CrcTable[r & 0xFF] ^ (r >> 8);
   }
 
-  #if CRC_NUM_TABLES < 4
-  
-  g_CrcUpdate = CrcUpdateT1;
-  
-  #else
- 
-  #ifdef MY_CPU_LE
+#if !defined(Z7_CRC_HW_FORCE) && \
+    (defined(Z7_CRC_HW_USE) || defined(Z7_CRC_UPDATE_T1_FUNC_NAME) || defined(MY_CPU_BE))
 
-    g_CrcUpdateT4 = CrcUpdateT4;
-    g_CrcUpdate = CrcUpdateT4;
-
-    #if CRC_NUM_TABLES >= 8
-      g_CrcUpdateT8 = CrcUpdateT8;
-  
-      #ifdef MY_CPU_X86_OR_AMD64
-      if (!CPU_Is_InOrder())
-      #endif
-        g_CrcUpdate = CrcUpdateT8;
-    #endif
-
-  #else
+#if Z7_CRC_NUM_TABLES_USE <= 1
+    g_Crc_Algo = 1;
+#else // Z7_CRC_NUM_TABLES_USE <= 1
+
+#if defined(MY_CPU_LE)
+    g_Crc_Algo = Z7_CRC_NUM_TABLES_USE;
+#else // !defined(MY_CPU_LE)
   {
-    #ifndef MY_CPU_BE
+#ifndef MY_CPU_BE
     UInt32 k = 0x01020304;
     const Byte *p = (const Byte *)&k;
     if (p[0] == 4 && p[1] == 3)
-    {
-      g_CrcUpdateT4 = CrcUpdateT4;
-      g_CrcUpdate = CrcUpdateT4;
-      #if CRC_NUM_TABLES >= 8
-      g_CrcUpdateT8 = CrcUpdateT8;
-      g_CrcUpdate = CrcUpdateT8;
-      #endif
-    }
+      g_Crc_Algo = Z7_CRC_NUM_TABLES_USE;
     else if (p[0] != 1 || p[1] != 2)
-      g_CrcUpdate = CrcUpdateT1;
+      g_Crc_Algo = 1;
     else
-    #endif
+#endif // MY_CPU_BE
     {
-      for (i = 256 * CRC_NUM_TABLES - 1; i >= 256; i--)
+      for (i = 256 * Z7_CRC_NUM_TABLES_TOTAL - 1; i >= 256; i--)
       {
-        UInt32 x = g_CrcTable[(size_t)i - 256];
-        g_CrcTable[i] = CRC_UINT32_SWAP(x);
+        const UInt32 x = g_CrcTable[(size_t)i - 256];
+        g_CrcTable[i] = Z7_BSWAP32(x);
       }
-      g_CrcUpdateT4 = CrcUpdateT1_BeT4;
-      g_CrcUpdate = CrcUpdateT1_BeT4;
-      #if CRC_NUM_TABLES >= 8
-      g_CrcUpdateT8 = CrcUpdateT1_BeT8;
-      g_CrcUpdate = CrcUpdateT1_BeT8;
-      #endif
+#if defined(Z7_CRC_UPDATE_T1_FUNC_NAME)
+      g_Crc_Algo = Z7_CRC_NUM_TABLES_USE;
+#endif
+#if (!defined(MY_CPU_LE) && !defined(MY_CPU_BE))
+      g_Crc_Be = 1;
+#endif
     }
   }
-  #endif
-  #endif
+#endif  // !defined(MY_CPU_LE)
 
-  #ifdef MY_CPU_LE
-    #ifdef USE_ARM64_CRC
-      if (CPU_IsSupported_CRC32())
-      {
-        g_CrcUpdateT0_32 = CrcUpdateT0_32;
-        g_CrcUpdateT0_64 = CrcUpdateT0_64;
-        g_CrcUpdate =
-          #if defined(MY_CPU_ARM)
-            CrcUpdateT0_32;
-          #else
-            CrcUpdateT0_64;
-          #endif
-      }
-    #endif
-    
-    #ifdef USE_CRC_EMU
-      g_CrcUpdateT0_32 = CrcUpdateT0_32;
-      g_CrcUpdateT0_64 = CrcUpdateT0_64;
-      g_CrcUpdate = CrcUpdateT0_64;
-    #endif
+#ifdef MY_CPU_LE
+#ifdef Z7_CRC_HW_USE
+  if (CPU_IsSupported_CRC32())
+    g_Crc_Algo = 0;
+#endif // Z7_CRC_HW_USE
+#endif // MY_CPU_LE
+
+#endif // Z7_CRC_NUM_TABLES_USE <= 1
+#endif // g_Crc_Algo was declared
+}
+
+Z7_CRC_UPDATE_FUNC z7_GetFunc_CrcUpdate(unsigned algo)
+{
+  if (algo == 0)
+    return &CrcUpdate;
+
+#if defined(Z7_CRC_HW_USE)
+  if (algo == sizeof(CRC_HW_WORD_TYPE) * 8)
+  {
+#ifdef Z7_CRC_HW_FORCE
+    return &CrcUpdate;
+#else
+    if (g_Crc_Algo == 0)
+      return &CrcUpdate_HW;
+#endif
+  }
+#endif
+
+#ifndef Z7_CRC_HW_FORCE
+  if (algo == Z7_CRC_NUM_TABLES_USE)
+    return
+  #ifdef Z7_CRC_HW_USE
+      &CrcUpdate_Base;
+  #else
+      &CrcUpdate;
   #endif
+#endif
+
+  return NULL;
 }
+
+#undef kCrcPoly
+#undef Z7_CRC_NUM_TABLES_USE
+#undef Z7_CRC_NUM_TABLES_TOTAL
+#undef CRC_UPDATE_BYTE_2
+#undef FUNC_NAME_LE_2
+#undef FUNC_NAME_LE_1
+#undef FUNC_NAME_LE
+#undef FUNC_NAME_BE_2
+#undef FUNC_NAME_BE_1
+#undef FUNC_NAME_BE
+
+#undef CRC_HW_UNROLL_BYTES
+#undef CRC_HW_WORD_FUNC
+#undef CRC_HW_WORD_TYPE
