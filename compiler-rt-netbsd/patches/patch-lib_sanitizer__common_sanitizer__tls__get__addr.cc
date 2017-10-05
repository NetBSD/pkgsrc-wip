$NetBSD$

--- lib/sanitizer_common/sanitizer_tls_get_addr.cc.orig	2017-07-20 14:23:41.000000000 +0000
+++ lib/sanitizer_common/sanitizer_tls_get_addr.cc
@@ -34,7 +34,9 @@ struct Glibc_2_19_tls_header {
 };
 
 // This must be static TLS
+#if !SANITIZER_NETBSD
 __attribute__((tls_model("initial-exec")))
+#endif
 static __thread DTLS dtls;
 
 // Make sure we properly destroy the DTLS objects:
