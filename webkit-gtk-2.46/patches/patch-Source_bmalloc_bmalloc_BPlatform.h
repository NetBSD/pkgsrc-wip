$NetBSD$

--- Source/bmalloc/bmalloc/BPlatform.h.orig	2024-08-19 06:28:40.235246200 +0000
+++ Source/bmalloc/bmalloc/BPlatform.h
@@ -52,6 +52,10 @@
 #define BOS_FREEBSD 1
 #endif
 
+#if defined(__NetBSD__)
+#define BOS_NETBSD 1
+#endif
+
 #if defined(WIN32) || defined(_WIN32)
 #define BOS_WINDOWS 1
 #endif
