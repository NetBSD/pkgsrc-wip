$NetBSD$

Endianness

--- libelf/src/config.h.orig	2019-08-24 19:56:10.000000000 +0900
+++ libelf/src/config.h	2024-01-28 08:22:01.334880989 +0900
@@ -29,6 +29,12 @@
 #ifndef EU_CONFIG_H
 #define EU_CONFIG_H	1
 
+#if defined(__NetBSD__)
+#define __BYTE_ORDER    BYTE_ORDER
+#define __LITTLE_ENDIAN LITTLE_ENDIAN
+#define __BIG_ENDIAN    BIG_ENDIAN
+#endif
+
 #ifdef USE_LOCKS
 # include <pthread.h>
 # include <assert.h>
