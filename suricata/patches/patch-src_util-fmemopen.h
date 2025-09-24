$NetBSD$

--- src/util-fmemopen.h.orig	2025-09-16 02:07:13.000000000 +0000
+++ src/util-fmemopen.h
@@ -37,6 +37,10 @@
 #define USE_FMEM_WRAPPER 1
 #endif
 
+#ifdef __NetBSD__
+#define USE_FMEM_WRAPPER 1
+#endif
+
 #ifdef __OpenBSD__
 #define USE_FMEM_WRAPPER 1
 #endif
