$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-scrypt.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-scrypt.js
@@ -178,7 +178,7 @@ for (const options of bad) {
 
 for (const options of toobig) {
   const expected = {
-    message: /Invalid scrypt params:.*memory limit exceeded/,
+    message: /Invalid scrypt params/,
     code: 'ERR_CRYPTO_INVALID_SCRYPT_PARAMS',
   };
   assert.throws(() => crypto.scrypt('pass', 'salt', 1, options, () => {}),
