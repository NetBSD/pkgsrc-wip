$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/boringssl/src/decrepit/evp/evp_do_all.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/boringssl/src/decrepit/evp/evp_do_all.c
@@ -20,8 +20,10 @@ void EVP_CIPHER_do_all_sorted(void (*cal
                                                const char *unused, void *arg),
                               void *arg) {
   callback(EVP_aes_128_cbc(), "AES-128-CBC", NULL, arg);
+  callback(EVP_aes_128_cfb128(), "AES-128-CFB", NULL, arg);
   callback(EVP_aes_192_cbc(), "AES-192-CBC", NULL, arg);
   callback(EVP_aes_256_cbc(), "AES-256-CBC", NULL, arg);
+  callback(EVP_aes_256_cfb128(), "AES-256-CFB", NULL, arg);
   callback(EVP_aes_128_ctr(), "AES-128-CTR", NULL, arg);
   callback(EVP_aes_192_ctr(), "AES-192-CTR", NULL, arg);
   callback(EVP_aes_256_ctr(), "AES-256-CTR", NULL, arg);
@@ -34,9 +36,13 @@ void EVP_CIPHER_do_all_sorted(void (*cal
   callback(EVP_aes_128_gcm(), "AES-128-GCM", NULL, arg);
   callback(EVP_aes_192_gcm(), "AES-192-GCM", NULL, arg);
   callback(EVP_aes_256_gcm(), "AES-256-GCM", NULL, arg);
+  callback(EVP_bf_cbc(), "BF-CBC", NULL, arg);
+  callback(EVP_bf_cfb(), "BF-CFB", NULL, arg);
+  callback(EVP_bf_ecb(), "BF-ECB", NULL, arg);
   callback(EVP_des_cbc(), "DES-CBC", NULL, arg);
   callback(EVP_des_ecb(), "DES-ECB", NULL, arg);
   callback(EVP_des_ede(), "DES-EDE", NULL, arg);
+  callback(EVP_des_ede3(), "DES-EDE3", NULL, arg);
   callback(EVP_des_ede_cbc(), "DES-EDE-CBC", NULL, arg);
   callback(EVP_des_ede3_cbc(), "DES-EDE3-CBC", NULL, arg);
   callback(EVP_rc2_cbc(), "RC2-CBC", NULL, arg);
@@ -44,8 +50,10 @@ void EVP_CIPHER_do_all_sorted(void (*cal
 
   // OpenSSL returns everything twice, the second time in lower case.
   callback(EVP_aes_128_cbc(), "aes-128-cbc", NULL, arg);
+  callback(EVP_aes_128_cfb128(), "aes-128-cfb", NULL, arg);
   callback(EVP_aes_192_cbc(), "aes-192-cbc", NULL, arg);
   callback(EVP_aes_256_cbc(), "aes-256-cbc", NULL, arg);
+  callback(EVP_aes_256_cfb128(), "aes-256-cfb", NULL, arg);
   callback(EVP_aes_128_ctr(), "aes-128-ctr", NULL, arg);
   callback(EVP_aes_192_ctr(), "aes-192-ctr", NULL, arg);
   callback(EVP_aes_256_ctr(), "aes-256-ctr", NULL, arg);
@@ -58,9 +66,13 @@ void EVP_CIPHER_do_all_sorted(void (*cal
   callback(EVP_aes_128_gcm(), "aes-128-gcm", NULL, arg);
   callback(EVP_aes_192_gcm(), "aes-192-gcm", NULL, arg);
   callback(EVP_aes_256_gcm(), "aes-256-gcm", NULL, arg);
+  callback(EVP_bf_cbc(), "bf-cbc", NULL, arg);
+  callback(EVP_bf_cfb(), "bf-cfb", NULL, arg);
+  callback(EVP_bf_ecb(), "bf-ecb", NULL, arg);
   callback(EVP_des_cbc(), "des-cbc", NULL, arg);
   callback(EVP_des_ecb(), "des-ecb", NULL, arg);
   callback(EVP_des_ede(), "des-ede", NULL, arg);
+  callback(EVP_des_ede3(), "des-ede3", NULL, arg);
   callback(EVP_des_ede_cbc(), "des-ede-cbc", NULL, arg);
   callback(EVP_des_ede3_cbc(), "des-ede3-cbc", NULL, arg);
   callback(EVP_rc2_cbc(), "rc2-cbc", NULL, arg);
@@ -79,6 +91,7 @@ void EVP_MD_do_all_sorted(void (*callbac
   callback(EVP_sha384(), "SHA384", NULL, arg);
   callback(EVP_sha512(), "SHA512", NULL, arg);
   callback(EVP_sha512_256(), "SHA512-256", NULL, arg);
+  callback(EVP_ripemd160(), "ripemd160", NULL, arg);
 
   callback(EVP_md4(), "md4", NULL, arg);
   callback(EVP_md5(), "md5", NULL, arg);
@@ -88,6 +101,7 @@ void EVP_MD_do_all_sorted(void (*callbac
   callback(EVP_sha384(), "sha384", NULL, arg);
   callback(EVP_sha512(), "sha512", NULL, arg);
   callback(EVP_sha512_256(), "sha512-256", NULL, arg);
+  callback(EVP_ripemd160(), "ripemd160", NULL, arg);
 }
 
 void EVP_MD_do_all(void (*callback)(const EVP_MD *cipher, const char *name,
