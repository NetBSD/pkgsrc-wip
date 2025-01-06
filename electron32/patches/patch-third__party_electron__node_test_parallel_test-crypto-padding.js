$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-padding.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-padding.js
@@ -87,10 +87,9 @@ assert.throws(function() {
   code: 'ERR_OSSL_WRONG_FINAL_BLOCK_LENGTH',
   reason: 'wrong final block length',
 } : {
-  message: 'error:0607F08A:digital envelope routines:EVP_EncryptFinal_ex:' +
-    'data not multiple of block length',
-  code: 'ERR_OSSL_EVP_DATA_NOT_MULTIPLE_OF_BLOCK_LENGTH',
-  reason: 'data not multiple of block length',
+  message: /error:0607F08A:digital envelope routines:EVP_EncryptFinal_ex:data not multiple of block length|error:1e00006a:Cipher functions:OPENSSL_internal:DATA_NOT_MULTIPLE_OF_BLOCK_LENGTH/,
+  code: /ERR_OSSL(_EVP)?_DATA_NOT_MULTIPLE_OF_BLOCK_LENGTH/,
+  reason: /data not multiple of block length|DATA_NOT_MULTIPLE_OF_BLOCK_LENGTH/,
 }
 );
 
@@ -114,10 +113,9 @@ assert.throws(function() {
   reason: 'bad decrypt',
   code: 'ERR_OSSL_BAD_DECRYPT',
 } : {
-  message: 'error:06065064:digital envelope routines:EVP_DecryptFinal_ex:' +
-    'bad decrypt',
-  reason: 'bad decrypt',
-  code: 'ERR_OSSL_EVP_BAD_DECRYPT',
+  message: /error:06065064:digital envelope routines:EVP_DecryptFinal_ex:bad decrypt|error:1e000065:Cipher functions:OPENSSL_internal:BAD_DECRYPT/,
+  reason: /bad decrypt|BAD_DECRYPT/,
+  code: /ERR_OSSL(_EVP)?_BAD_DECRYPT/,
 });
 
 // No-pad encrypted string should return the same:
