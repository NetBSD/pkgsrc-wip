$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-dh-errors.js.orig	2025-04-18 18:41:29.000000000 +0000
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
