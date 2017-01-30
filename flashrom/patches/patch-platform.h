$NetBSD$

Macro expansion producing 'defined' has undefined behavior

--- platform.h.orig	2016-02-25 20:10:26.000000000 +0000
+++ platform.h
@@ -25,9 +25,21 @@
 #define __PLATFORM_H__ 1
 
 // Helper defines for operating systems
-#define IS_LINUX	(defined(__gnu_linux__) || defined(__linux__))
-#define IS_MACOSX	(defined(__APPLE__) && defined(__MACH__)) /* yes, both. */
-#define IS_WINDOWS	(defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__))
+#if	defined(__gnu_linux__) || defined(__linux__)
+#define IS_LINUX 1
+#else
+#define IS_LINUX 0
+#endif
+#if	defined(__APPLE__) && defined(__MACH__) /* yes, both. */
+#define IS_MACOSX 1
+#else
+#define IS_MACOSX 0
+#endif
+#if	defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__)
+#define IS_WINDOWS 1
+#else
+#define IS_WINDOWS 0
+#endif
 
 // Likewise for target architectures
 #if defined (__i386__) || defined (__x86_64__) || defined(__amd64__)
