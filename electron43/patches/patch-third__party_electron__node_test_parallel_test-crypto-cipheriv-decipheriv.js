$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-cipheriv-decipheriv.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-cipheriv-decipheriv.js
@@ -60,6 +60,10 @@ function testCipher2(key, iv) {
 
 
 function testCipher3(key, iv) {
+  if (!crypto.getCiphers().includes('id-aes128-wrap')) {
+    common.printSkipMessage(`unsupported id-aes128-wrap test`);
+    return;
+  }
   // Test encryption and decryption with explicit key and iv.
   // AES Key Wrap test vector comes from RFC3394
   const plaintext = Buffer.from('00112233445566778899AABBCCDDEEFF', 'hex');
