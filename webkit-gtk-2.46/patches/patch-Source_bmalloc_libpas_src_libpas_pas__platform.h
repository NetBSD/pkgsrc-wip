$NetBSD$

--- Source/bmalloc/libpas/src/libpas/pas_platform.h.orig	2025-10-29 10:30:36.719827256 +0000
+++ Source/bmalloc/libpas/src/libpas/pas_platform.h
@@ -140,6 +140,14 @@
 #define PAS_OS_FREEBSD 1
 #endif
 
+#if defined(__NetBSD__)
+#define PAS_OS_NETBSD 1
+#endif
+
+#if defined(__OpenBSD__)
+#define PAS_OS_OPENBSD 1
+#endif
+
 #if defined(WIN32) || defined(_WIN32)
 #define PAS_OS_WINDOWS 1
 #endif
