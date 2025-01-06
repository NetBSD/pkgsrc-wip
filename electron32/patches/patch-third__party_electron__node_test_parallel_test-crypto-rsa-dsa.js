$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-rsa-dsa.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-rsa-dsa.js
@@ -28,12 +28,11 @@ const dsaPkcs8KeyPem = fixtures.readKey(
 const ec = new TextEncoder();
 
 const openssl1DecryptError = {
-  message: 'error:06065064:digital envelope routines:EVP_DecryptFinal_ex:' +
-    'bad decrypt',
-  code: 'ERR_OSSL_EVP_BAD_DECRYPT',
-  reason: 'bad decrypt',
-  function: 'EVP_DecryptFinal_ex',
-  library: 'digital envelope routines',
+  message: /error:06065064:digital envelope routines:EVP_DecryptFinal_ex:bad decrypt|error:1e000065:Cipher functions:OPENSSL_internal:BAD_DECRYPT/,
+  code: /ERR_OSSL(_EVP)?_BAD_DECRYPT/,
+  reason: /bad decrypt|BAD_DECRYPT/,
+  function: /EVP_DecryptFinal_ex|OPENSSL_internal/,
+  library: /digital envelope routines|Cipher functions/,
 };
 
 const decryptError = common.hasOpenSSL3 ?
@@ -222,7 +221,8 @@ function test_rsa(padding, encryptOaepHa
   }, bufferToEncrypt);
 
 
-  if (padding === constants.RSA_PKCS1_PADDING) {
+  // BoringSSL does not support RSA_PKCS1_PADDING.
+  if (false) {
     if (!process.config.variables.node_shared_openssl) {
       assert.throws(() => {
         crypto.privateDecrypt({
@@ -466,7 +466,7 @@ assert.throws(() => {
   assert.strictEqual(verify2.verify(publicKey, signature, 'hex'), true);
 }
 
-
+/*
 //
 // Test DSA signing and verification
 //
@@ -541,3 +541,4 @@ const input = 'I AM THE WALRUS';
 
   assert.strictEqual(verify.verify(dsaPubPem, signature, 'hex'), true);
 }
+*/
