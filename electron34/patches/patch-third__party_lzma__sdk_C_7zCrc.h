$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zCrc.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zCrc.h
@@ -1,8 +1,8 @@
 /* 7zCrc.h -- CRC32 calculation
-2013-01-18 : Igor Pavlov : Public domain */
+2024-01-22 : Igor Pavlov : Public domain */
 
-#ifndef __7Z_CRC_H
-#define __7Z_CRC_H
+#ifndef ZIP7_INC_7Z_CRC_H
+#define ZIP7_INC_7Z_CRC_H
 
 #include "7zTypes.h"
 
@@ -11,14 +11,17 @@ EXTERN_C_BEGIN
 extern UInt32 g_CrcTable[];
 
 /* Call CrcGenerateTable one time before other CRC functions */
-void MY_FAST_CALL CrcGenerateTable(void);
+void Z7_FASTCALL CrcGenerateTable(void);
 
 #define CRC_INIT_VAL 0xFFFFFFFF
 #define CRC_GET_DIGEST(crc) ((crc) ^ CRC_INIT_VAL)
 #define CRC_UPDATE_BYTE(crc, b) (g_CrcTable[((crc) ^ (b)) & 0xFF] ^ ((crc) >> 8))
 
-UInt32 MY_FAST_CALL CrcUpdate(UInt32 crc, const void *data, size_t size);
-UInt32 MY_FAST_CALL CrcCalc(const void *data, size_t size);
+UInt32 Z7_FASTCALL CrcUpdate(UInt32 crc, const void *data, size_t size);
+UInt32 Z7_FASTCALL CrcCalc(const void *data, size_t size);
+
+typedef UInt32 (Z7_FASTCALL *Z7_CRC_UPDATE_FUNC)(UInt32 v, const void *data, size_t size);
+Z7_CRC_UPDATE_FUNC z7_GetFunc_CrcUpdate(unsigned algo);
 
 EXTERN_C_END
 
