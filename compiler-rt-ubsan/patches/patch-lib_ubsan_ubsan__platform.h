$NetBSD$

--- lib/ubsan/ubsan_platform.h.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/ubsan/ubsan_platform.h
@@ -14,7 +14,7 @@
 #define UBSAN_PLATFORM_H
 
 // Other platforms should be easy to add, and probably work as-is.
-#if (defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)) && \
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)) && \
     (defined(__x86_64__) || defined(__i386__) || defined(__arm__) || \
      defined(__aarch64__) || defined(__mips__) || defined(__powerpc64__) || \
      defined(__s390__))
