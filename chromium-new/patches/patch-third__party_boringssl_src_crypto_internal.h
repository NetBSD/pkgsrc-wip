$NetBSD$

--- third_party/boringssl/src/crypto/internal.h.orig	2016-06-24 01:03:30.000000000 +0000
+++ third_party/boringssl/src/crypto/internal.h
@@ -118,8 +118,10 @@
 #define alignof __alignof
 #endif
 #else
+#if !defined(__NetBSD__)
 #include <stdalign.h>
 #endif
+#endif
 
 #if defined(OPENSSL_NO_THREADS)
 #elif defined(OPENSSL_WINDOWS)
