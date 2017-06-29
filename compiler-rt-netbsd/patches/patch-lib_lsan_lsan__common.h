$NetBSD$

--- lib/lsan/lsan_common.h.orig	2017-06-03 23:53:56.000000000 +0000
+++ lib/lsan/lsan_common.h
@@ -30,7 +30,7 @@
 // To enable LeakSanitizer on new architecture, one need to implement
 // internal_clone function as well as (probably) adjust TLS machinery for
 // new architecture inside sanitizer library.
-#if (SANITIZER_LINUX && !SANITIZER_ANDROID || SANITIZER_MAC) && \
+#if (SANITIZER_LINUX && !SANITIZER_ANDROID || SANITIZER_MAC || SANITIZER_NETBSD) && \
     (SANITIZER_WORDSIZE == 64) &&                               \
     (defined(__x86_64__) || defined(__mips64) || defined(__aarch64__) || \
      defined(__powerpc64__))
