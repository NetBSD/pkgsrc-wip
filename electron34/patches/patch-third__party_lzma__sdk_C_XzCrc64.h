$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/XzCrc64.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/XzCrc64.h
@@ -1,8 +1,8 @@
 /* XzCrc64.h -- CRC64 calculation
-2013-01-18 : Igor Pavlov : Public domain */
+2023-12-08 : Igor Pavlov : Public domain */
 
-#ifndef __XZ_CRC64_H
-#define __XZ_CRC64_H
+#ifndef ZIP7_INC_XZ_CRC64_H
+#define ZIP7_INC_XZ_CRC64_H
 
 #include <stddef.h>
 
@@ -10,16 +10,16 @@
 
 EXTERN_C_BEGIN
 
-extern UInt64 g_Crc64Table[];
+// extern UInt64 g_Crc64Table[];
 
-void MY_FAST_CALL Crc64GenerateTable(void);
+void Z7_FASTCALL Crc64GenerateTable(void);
 
 #define CRC64_INIT_VAL UINT64_CONST(0xFFFFFFFFFFFFFFFF)
 #define CRC64_GET_DIGEST(crc) ((crc) ^ CRC64_INIT_VAL)
-#define CRC64_UPDATE_BYTE(crc, b) (g_Crc64Table[((crc) ^ (b)) & 0xFF] ^ ((crc) >> 8))
+// #define CRC64_UPDATE_BYTE(crc, b) (g_Crc64Table[((crc) ^ (b)) & 0xFF] ^ ((crc) >> 8))
 
-UInt64 MY_FAST_CALL Crc64Update(UInt64 crc, const void *data, size_t size);
-UInt64 MY_FAST_CALL Crc64Calc(const void *data, size_t size);
+UInt64 Z7_FASTCALL Crc64Update(UInt64 crc, const void *data, size_t size);
+// UInt64 Z7_FASTCALL Crc64Calc(const void *data, size_t size);
 
 EXTERN_C_END
 
