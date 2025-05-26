$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-dh.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-dh.js
@@ -55,18 +55,17 @@ const crypto = require('crypto');
   let wrongBlockLength;
   if (common.hasOpenSSL3) {
     wrongBlockLength = {
-      message: 'error:1C80006B:Provider routines::wrong final block length',
-      code: 'ERR_OSSL_WRONG_FINAL_BLOCK_LENGTH',
-      library: 'Provider routines',
-      reason: 'wrong final block length'
+      message: /error:1C80006B:Provider routines::wrong final block length|error:1e00007b:Cipher functions:OPENSSL_internal:WRONG_FINAL_BLOCK_LENGTH/,
+      code: /ERR_OSSL_(EVP_)?WRONG_FINAL_BLOCK_LENGTH/,
+      library: /digital envelope routines|Cipher functions/,
+      reason: /wrong final block length|WRONG_FINAL_BLOCK_LENGTH/
     };
   } else {
     wrongBlockLength = {
-      message: 'error:0606506D:digital envelope' +
-        ' routines:EVP_DecryptFinal_ex:wrong final block length',
-      code: 'ERR_OSSL_EVP_WRONG_FINAL_BLOCK_LENGTH',
-      library: 'digital envelope routines',
-      reason: 'wrong final block length'
+      message: /error:0606506D:digital envelope routines:EVP_DecryptFinal_ex:wrong final block length|error:1e00007b:Cipher functions:OPENSSL_internal:WRONG_FINAL_BLOCK_LENGTH/,
+      code: /ERR_OSSL_(EVP_)?WRONG_FINAL_BLOCK_LENGTH/,
+      library: /digital envelope routines|Cipher functions/,
+      reason: /wrong final block length|WRONG_FINAL_BLOCK_LENGTH/
     };
   }
 
@@ -100,10 +99,16 @@ const crypto = require('crypto');
 // Through a fluke of history, g=0 defaults to DH_GENERATOR (2).
 {
   const g = 0;
-  crypto.createDiffieHellman('abcdef', g);
+  assert.throws(() => crypto.createDiffieHellman('abcdef', g), {
+    code: /INVALID_PARAMETERS/,
+    name: 'Error'
+  });
   crypto.createDiffieHellman('abcdef', 'hex', g);
 }
 
 {
-  crypto.createDiffieHellman('abcdef', Buffer.from([2]));  // OK
+  assert.throws(() => crypto.createDiffieHellman('abcdef', Buffer.from([2])), {
+    code: /INVALID_PARAMETERS/,
+    name: 'Error'
+  });
 }
