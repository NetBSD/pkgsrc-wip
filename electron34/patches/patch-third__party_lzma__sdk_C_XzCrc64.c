$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/XzCrc64.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/XzCrc64.c
@@ -1,5 +1,5 @@
 /* XzCrc64.c -- CRC64 calculation
-2017-05-23 : Igor Pavlov : Public domain */
+2023-12-08 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -8,45 +8,76 @@
 
 #define kCrc64Poly UINT64_CONST(0xC96C5795D7870F42)
 
-#ifdef MY_CPU_LE
-  #define CRC64_NUM_TABLES 4
+// for debug only : define Z7_CRC64_DEBUG_BE to test big-endian code in little-endian cpu
+// #define Z7_CRC64_DEBUG_BE
+#ifdef Z7_CRC64_DEBUG_BE
+#undef MY_CPU_LE
+#define MY_CPU_BE
+#endif
+
+#ifdef Z7_CRC64_NUM_TABLES
+  #define Z7_CRC64_NUM_TABLES_USE  Z7_CRC64_NUM_TABLES
 #else
-  #define CRC64_NUM_TABLES 5
-  #define CRC_UINT64_SWAP(v) \
-      ((v >> 56) \
-    | ((v >> 40) & ((UInt64)0xFF <<  8)) \
-    | ((v >> 24) & ((UInt64)0xFF << 16)) \
-    | ((v >>  8) & ((UInt64)0xFF << 24)) \
-    | ((v <<  8) & ((UInt64)0xFF << 32)) \
-    | ((v << 24) & ((UInt64)0xFF << 40)) \
-    | ((v << 40) & ((UInt64)0xFF << 48)) \
-    | ((v << 56)))
+  #define Z7_CRC64_NUM_TABLES_USE  12
+#endif
 
-  UInt64 MY_FAST_CALL XzCrc64UpdateT1_BeT4(UInt64 v, const void *data, size_t size, const UInt64 *table);
+#if Z7_CRC64_NUM_TABLES_USE < 1
+  #error Stop_Compiling_Bad_Z7_CRC_NUM_TABLES
 #endif
 
+
+#if Z7_CRC64_NUM_TABLES_USE != 1
+
 #ifndef MY_CPU_BE
-  UInt64 MY_FAST_CALL XzCrc64UpdateT4(UInt64 v, const void *data, size_t size, const UInt64 *table);
+  #define FUNC_NAME_LE_2(s)   XzCrc64UpdateT ## s
+  #define FUNC_NAME_LE_1(s)   FUNC_NAME_LE_2(s)
+  #define FUNC_NAME_LE        FUNC_NAME_LE_1(Z7_CRC64_NUM_TABLES_USE)
+  UInt64 Z7_FASTCALL FUNC_NAME_LE (UInt64 v, const void *data, size_t size, const UInt64 *table);
+#endif
+#ifndef MY_CPU_LE
+  #define FUNC_NAME_BE_2(s)   XzCrc64UpdateBeT ## s
+  #define FUNC_NAME_BE_1(s)   FUNC_NAME_BE_2(s)
+  #define FUNC_NAME_BE        FUNC_NAME_BE_1(Z7_CRC64_NUM_TABLES_USE)
+  UInt64 Z7_FASTCALL FUNC_NAME_BE (UInt64 v, const void *data, size_t size, const UInt64 *table);
+#endif
+
+#if defined(MY_CPU_LE)
+  #define FUNC_REF  FUNC_NAME_LE
+#elif defined(MY_CPU_BE)
+  #define FUNC_REF  FUNC_NAME_BE
+#else
+  #define FUNC_REF  g_Crc64Update
+  static UInt64 (Z7_FASTCALL *FUNC_REF)(UInt64 v, const void *data, size_t size, const UInt64 *table);
 #endif
 
-typedef UInt64 (MY_FAST_CALL *CRC64_FUNC)(UInt64 v, const void *data, size_t size, const UInt64 *table);
+#endif
 
-static CRC64_FUNC g_Crc64Update;
-UInt64 g_Crc64Table[256 * CRC64_NUM_TABLES];
 
-UInt64 MY_FAST_CALL Crc64Update(UInt64 v, const void *data, size_t size)
-{
-  return g_Crc64Update(v, data, size, g_Crc64Table);
-}
+MY_ALIGN(64)
+static UInt64 g_Crc64Table[256 * Z7_CRC64_NUM_TABLES_USE];
+
 
-UInt64 MY_FAST_CALL Crc64Calc(const void *data, size_t size)
+UInt64 Z7_FASTCALL Crc64Update(UInt64 v, const void *data, size_t size)
 {
-  return g_Crc64Update(CRC64_INIT_VAL, data, size, g_Crc64Table) ^ CRC64_INIT_VAL;
+#if Z7_CRC64_NUM_TABLES_USE == 1
+  #define CRC64_UPDATE_BYTE_2(crc, b)  (table[((crc) ^ (b)) & 0xFF] ^ ((crc) >> 8))
+  const UInt64 *table = g_Crc64Table;
+  const Byte *p = (const Byte *)data;
+  const Byte *lim = p + size;
+  for (; p != lim; p++)
+    v = CRC64_UPDATE_BYTE_2(v, *p);
+  return v;
+  #undef CRC64_UPDATE_BYTE_2
+#else
+  return FUNC_REF (v, data, size, g_Crc64Table);
+#endif
 }
 
-void MY_FAST_CALL Crc64GenerateTable()
+
+Z7_NO_INLINE
+void Z7_FASTCALL Crc64GenerateTable(void)
 {
-  UInt32 i;
+  unsigned i;
   for (i = 0; i < 256; i++)
   {
     UInt64 r = i;
@@ -55,32 +86,55 @@ void MY_FAST_CALL Crc64GenerateTable()
       r = (r >> 1) ^ (kCrc64Poly & ((UInt64)0 - (r & 1)));
     g_Crc64Table[i] = r;
   }
-  for (i = 256; i < 256 * CRC64_NUM_TABLES; i++)
+
+#if Z7_CRC64_NUM_TABLES_USE != 1
+#if 1 || 1 && defined(MY_CPU_X86) // low register count
+  for (i = 0; i < 256 * (Z7_CRC64_NUM_TABLES_USE - 1); i++)
   {
-    UInt64 r = g_Crc64Table[(size_t)i - 256];
-    g_Crc64Table[i] = g_Crc64Table[r & 0xFF] ^ (r >> 8);
+    const UInt64 r0 = g_Crc64Table[(size_t)i];
+    g_Crc64Table[(size_t)i + 256] = g_Crc64Table[(Byte)r0] ^ (r0 >> 8);
   }
-  
-  #ifdef MY_CPU_LE
-
-  g_Crc64Update = XzCrc64UpdateT4;
+#else
+  for (i = 0; i < 256 * (Z7_CRC64_NUM_TABLES_USE - 1); i += 2)
+  {
+    UInt64 r0 = g_Crc64Table[(size_t)(i)    ];
+    UInt64 r1 = g_Crc64Table[(size_t)(i) + 1];
+    r0 = g_Crc64Table[(Byte)r0] ^ (r0 >> 8);
+    r1 = g_Crc64Table[(Byte)r1] ^ (r1 >> 8);
+    g_Crc64Table[(size_t)i + 256    ] = r0;
+    g_Crc64Table[(size_t)i + 256 + 1] = r1;
+  }
+#endif
 
-  #else
+#ifndef MY_CPU_LE
   {
-    #ifndef MY_CPU_BE
+#ifndef MY_CPU_BE
     UInt32 k = 1;
     if (*(const Byte *)&k == 1)
-      g_Crc64Update = XzCrc64UpdateT4;
+      FUNC_REF = FUNC_NAME_LE;
     else
-    #endif
+#endif
     {
-      for (i = 256 * CRC64_NUM_TABLES - 1; i >= 256; i--)
+#ifndef MY_CPU_BE
+      FUNC_REF = FUNC_NAME_BE;
+#endif
+      for (i = 0; i < 256 * Z7_CRC64_NUM_TABLES_USE; i++)
       {
-        UInt64 x = g_Crc64Table[(size_t)i - 256];
-        g_Crc64Table[i] = CRC_UINT64_SWAP(x);
+        const UInt64 x = g_Crc64Table[i];
+        g_Crc64Table[i] = Z7_BSWAP64(x);
       }
-      g_Crc64Update = XzCrc64UpdateT1_BeT4;
     }
   }
-  #endif
+#endif // ndef MY_CPU_LE
+#endif // Z7_CRC64_NUM_TABLES_USE != 1
 }
+
+#undef kCrc64Poly
+#undef Z7_CRC64_NUM_TABLES_USE
+#undef FUNC_REF
+#undef FUNC_NAME_LE_2
+#undef FUNC_NAME_LE_1
+#undef FUNC_NAME_LE
+#undef FUNC_NAME_BE_2
+#undef FUNC_NAME_BE_1
+#undef FUNC_NAME_BE
