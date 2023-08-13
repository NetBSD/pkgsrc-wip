$NetBSD$

--- ncbi-vdb/libs/align/bam.c.orig	2023-08-13 15:08:20.104984546 +0000
+++ ncbi-vdb/libs/align/bam.c
@@ -64,6 +64,15 @@
 
 #include <os-native.h>
 
+#define	__BYTE_ORDER _BYTE_ORDER
+
+#define XSTR(x) STR(x)
+#define STR(x)  #x
+
+#pragma message "_BYTE_ORDER = " XSTR(_BYTE_ORDER)
+#pragma message "__BYTE_ORDER = " XSTR(__BYTE_ORDER)
+#pragma message "__LITTLE_ENDIAN = " XSTR(__LITTLE_ENDIAN)
+
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 static uint16_t LE2HUI16(void const *X) { uint16_t y; memmove(&y, X, sizeof(y)); return y; }
 static uint32_t LE2HUI32(void const *X) { uint32_t y; memmove(&y, X, sizeof(y)); return y; }
