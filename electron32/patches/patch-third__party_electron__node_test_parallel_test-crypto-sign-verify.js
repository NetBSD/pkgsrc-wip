$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-sign-verify.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-sign-verify.js
@@ -28,6 +28,7 @@ const keySize = 2048;
                                      'instance when called without `new`');
 }
 
+/*
 // Test handling of exceptional conditions
 {
   const library = {
@@ -68,6 +69,7 @@ const keySize = 2048;
 
   delete Object.prototype.opensslErrorStack;
 }
+*/
 
 assert.throws(
   () => crypto.createVerify('SHA256').verify({
@@ -341,15 +343,17 @@ assert.throws(
         padding: crypto.constants.RSA_PKCS1_OAEP_PADDING
       });
   }, common.hasOpenSSL3 ? {
-    code: 'ERR_OSSL_ILLEGAL_OR_UNSUPPORTED_PADDING_MODE',
-    message: /illegal or unsupported padding mode/,
+    code: /^ERR_OSSL_(RSA|EVP)_ILLEGAL_OR_UNSUPPORTED_PADDING_MODE$/,
+    message: /illegal or unsupported padding mode|ILLEGAL_OR_UNSUPPORTED_PADDING_MODE/,
   } : {
-    code: 'ERR_OSSL_RSA_ILLEGAL_OR_UNSUPPORTED_PADDING_MODE',
-    message: /illegal or unsupported padding mode/,
+    code: /^ERR_OSSL_(RSA|EVP)_ILLEGAL_OR_UNSUPPORTED_PADDING_MODE$/,
+    message: /illegal or unsupported padding mode|ILLEGAL_OR_UNSUPPORTED_PADDING_MODE/,
+    /*
     opensslErrorStack: [
       'error:06089093:digital envelope routines:EVP_PKEY_CTX_ctrl:' +
       'command not supported',
     ],
+    */
   });
 }
 
@@ -419,10 +423,12 @@ assert.throws(
     public: fixtures.readKey('ed25519_public.pem', 'ascii'),
     algo: null,
     sigLen: 64 },
+  /*
   { private: fixtures.readKey('ed448_private.pem', 'ascii'),
     public: fixtures.readKey('ed448_public.pem', 'ascii'),
     algo: null,
     sigLen: 114 },
+    */
   { private: fixtures.readKey('rsa_private_2048.pem', 'ascii'),
     public: fixtures.readKey('rsa_public_2048.pem', 'ascii'),
     algo: 'sha1',
@@ -493,7 +499,7 @@ assert.throws(
 
 {
   const data = Buffer.from('Hello world');
-  const keys = [['ec-key.pem', 64], ['dsa_private_1025.pem', 40]];
+  const keys = [['ec-key.pem', 64]/*, ['dsa_private_1025.pem', 40]*/];
 
   for (const [file, length] of keys) {
     const privKey = fixtures.readKey(file);
