$NetBSD$

--- src/timers.cc.orig	2017-11-03 17:00:29.000000000 +0000
+++ src/timers.cc
@@ -25,7 +25,7 @@
 #include <sys/time.h>
 #include <sys/types.h>  // this header must be included before 'sys/sysctl.h' to avoid compilation error on FreeBSD
 #include <unistd.h>
-#if defined BENCHMARK_OS_FREEBSD || defined BENCHMARK_OS_MACOSX
+#if defined BENCHMARK_OS_FREEBSD || defined BENCHMARK_OS_MACOSX || defined BENCHMARK_OS_NETBSD
 #include <sys/sysctl.h>
 #endif
 #if defined(BENCHMARK_OS_MACOSX)
