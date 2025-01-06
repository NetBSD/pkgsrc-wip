$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-dh-errors.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-dh-errors.js
@@ -32,9 +32,9 @@ for (const bits of [-1, 0, 1]) {
     });
   } else {
     assert.throws(() => crypto.createDiffieHellman(bits), {
-      code: 'ERR_OSSL_BN_BITS_TOO_SMALL',
+      code: /ERR_OSSL_BN_BITS_TOO_SMALL|ERR_OSSL_DH_MODULUS_TOO_LARGE/,
       name: 'Error',
-      message: /bits too small/,
+      message: /bits too small|BITS_TOO_SMALL|MODULUS_TOO_LARGE/,
     });
   }
 }
@@ -43,7 +43,7 @@ for (const g of [-1, 1]) {
   const ex = {
     code: 'ERR_OSSL_DH_BAD_GENERATOR',
     name: 'Error',
-    message: /bad generator/,
+    message: /bad generator|BAD_GENERATOR/,
   };
   assert.throws(() => crypto.createDiffieHellman('abcdef', g), ex);
   assert.throws(() => crypto.createDiffieHellman('abcdef', 'hex', g), ex);
@@ -55,7 +55,7 @@ for (const g of [Buffer.from([]),
   const ex = {
     code: 'ERR_OSSL_DH_BAD_GENERATOR',
     name: 'Error',
-    message: /bad generator/,
+    message: /bad generator|BAD_GENERATOR/,
   };
   assert.throws(() => crypto.createDiffieHellman('abcdef', g), ex);
   assert.throws(() => crypto.createDiffieHellman('abcdef', 'hex', g), ex);
