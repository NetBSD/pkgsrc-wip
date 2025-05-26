$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/boringssl/src/ssl/ssl_lib.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/boringssl/src/ssl/ssl_lib.cc
@@ -1339,7 +1339,7 @@ int SSL_get_error(const SSL *ssl, int re
   }
 
   if (ret_code == 0) {
-    if (ssl->s3->rwstate == SSL_ERROR_ZERO_RETURN) {
+    if (ssl->s3->read_shutdown == ssl_shutdown_close_notify) {
       return SSL_ERROR_ZERO_RETURN;
     }
     // An EOF was observed which violates the protocol, and the underlying
@@ -2711,13 +2711,7 @@ void *SSL_CTX_get_ex_data(const SSL_CTX 
   return CRYPTO_get_ex_data(&ctx->ex_data, idx);
 }
 
-int SSL_want(const SSL *ssl) {
-  // Historically, OpenSSL did not track |SSL_ERROR_ZERO_RETURN| as an |rwstate|
-  // value. We do, but map it back to |SSL_ERROR_NONE| to preserve the original
-  // behavior.
-  return ssl->s3->rwstate == SSL_ERROR_ZERO_RETURN ? SSL_ERROR_NONE
-                                                   : ssl->s3->rwstate;
-}
+int SSL_want(const SSL *ssl) { return ssl->s3->rwstate; }
 
 void SSL_CTX_set_tmp_rsa_callback(SSL_CTX *ctx,
                                   RSA *(*cb)(SSL *ssl, int is_export,
