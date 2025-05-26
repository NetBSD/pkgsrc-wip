$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/boringssl/src/include/openssl/cipher.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/boringssl/src/include/openssl/cipher.h
@@ -476,6 +476,7 @@ OPENSSL_EXPORT const EVP_CIPHER *EVP_des
 
 // EVP_aes_128_cfb128 is only available in decrepit.
 OPENSSL_EXPORT const EVP_CIPHER *EVP_aes_128_cfb128(void);
+OPENSSL_EXPORT const EVP_CIPHER *EVP_aes_256_cfb128(void);
 
 // EVP_aes_128_cfb is an alias for |EVP_aes_128_cfb128| and is only available in
 // decrepit.
