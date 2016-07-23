$NetBSD$

--- third_party/boringssl/src/crypto/mem.c.orig	2016-06-24 01:03:30.000000000 +0000
+++ third_party/boringssl/src/crypto/mem.c
@@ -56,6 +56,7 @@
 
 #if !defined(_POSIX_C_SOURCE)
 #define _POSIX_C_SOURCE 201410L  /* needed for strdup, snprintf, vprintf etc */
+#define _XOPEN_SOURCE
 #endif
 
 #include <openssl/mem.h>
