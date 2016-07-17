$NetBSD$

--- third_party/boringssl/src/crypto/bio/internal.h.orig	2016-06-24 01:03:30.000000000 +0000
+++ third_party/boringssl/src/crypto/bio/internal.h
@@ -59,6 +59,10 @@
 
 #include <openssl/base.h>
 
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE 1
+#endif
+
 #if !defined(OPENSSL_WINDOWS)
 #if defined(OPENSSL_PNACL)
 /* newlib uses u_short in socket.h without defining it. */
