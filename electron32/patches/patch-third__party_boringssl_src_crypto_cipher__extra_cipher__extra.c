$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/boringssl/src/crypto/cipher_extra/cipher_extra.c.orig	2024-10-18 12:37:00.445640000 +0000
+++ third_party/boringssl/src/crypto/cipher_extra/cipher_extra.c
@@ -73,6 +73,7 @@ static const struct {
   const EVP_CIPHER *(*func)(void);
 } kCiphers[] = {
     {NID_aes_128_cbc, "aes-128-cbc", EVP_aes_128_cbc},
+    {NID_aes_128_cfb128, "aes-128-cfb", EVP_aes_128_cfb128},
     {NID_aes_128_ctr, "aes-128-ctr", EVP_aes_128_ctr},
     {NID_aes_128_ecb, "aes-128-ecb", EVP_aes_128_ecb},
     {NID_aes_128_gcm, "aes-128-gcm", EVP_aes_128_gcm},
@@ -83,17 +84,23 @@ static const struct {
     {NID_aes_192_gcm, "aes-192-gcm", EVP_aes_192_gcm},
     {NID_aes_192_ofb128, "aes-192-ofb", EVP_aes_192_ofb},
     {NID_aes_256_cbc, "aes-256-cbc", EVP_aes_256_cbc},
+    {NID_aes_256_cfb128, "aes-256-cfb", EVP_aes_256_cfb128},
     {NID_aes_256_ctr, "aes-256-ctr", EVP_aes_256_ctr},
     {NID_aes_256_ecb, "aes-256-ecb", EVP_aes_256_ecb},
     {NID_aes_256_gcm, "aes-256-gcm", EVP_aes_256_gcm},
     {NID_aes_256_ofb128, "aes-256-ofb", EVP_aes_256_ofb},
+    {NID_bf_cbc, "bf-cbc", EVP_bf_cbc},
+    {NID_bf_cfb64, "bf-cfb", EVP_bf_cfb},
+    {NID_bf_ecb, "bf-ecb", EVP_bf_ecb},
     {NID_des_cbc, "des-cbc", EVP_des_cbc},
     {NID_des_ecb, "des-ecb", EVP_des_ecb},
     {NID_des_ede_cbc, "des-ede-cbc", EVP_des_ede_cbc},
     {NID_des_ede_ecb, "des-ede", EVP_des_ede},
+    {NID_des_ede3_ecb, "des-ede3", EVP_des_ede3},
     {NID_des_ede3_cbc, "des-ede3-cbc", EVP_des_ede3_cbc},
     {NID_rc2_cbc, "rc2-cbc", EVP_rc2_cbc},
     {NID_rc4, "rc4", EVP_rc4},
+    {NID_rc2_40_cbc, "rc2-40-cbc", EVP_rc2_40_cbc}
 };
 
 const EVP_CIPHER *EVP_get_cipherbynid(int nid) {
