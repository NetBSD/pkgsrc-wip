$NetBSD$

--- src/internal_macros.h.orig	2017-11-03 17:00:29.000000000 +0000
+++ src/internal_macros.h
@@ -39,6 +39,8 @@
   #endif
 #elif defined(__FreeBSD__)
 #define BENCHMARK_OS_FREEBSD 1
+#elif defined(__NetBSD__)
+#define BENCHMARK_OS_NETBSD 1
 #elif defined(__linux__)
 #define BENCHMARK_OS_LINUX 1
 #elif defined(__native_client__)
