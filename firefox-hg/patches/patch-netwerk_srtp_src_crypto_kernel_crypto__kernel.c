$NetBSD$

Fix conflict with libc's hmac().

--- netwerk/srtp/src/crypto/kernel/crypto_kernel.c.orig	2016-09-02 05:50:26.917287944 +0000
+++ netwerk/srtp/src/crypto/kernel/crypto_kernel.c
@@ -77,7 +77,7 @@ extern cipher_type_t aes_cbc;
  */
 
 extern auth_type_t null_auth;
-extern auth_type_t hmac;
+extern auth_type_t hmacv;
 
 /* crypto_kernel is a global variable, the only one of its datatype */
 
@@ -162,7 +162,7 @@ crypto_kernel_init() {
   status = crypto_kernel_load_auth_type(&null_auth, NULL_AUTH);
   if (status)
     return status;
-  status = crypto_kernel_load_auth_type(&hmac, HMAC_SHA1);
+  status = crypto_kernel_load_auth_type(&hmacv, HMAC_SHA1);
   if (status)
     return status;
 
