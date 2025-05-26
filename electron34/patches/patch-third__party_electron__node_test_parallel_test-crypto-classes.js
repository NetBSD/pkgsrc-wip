$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-classes.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-classes.js
@@ -22,8 +22,8 @@ const TEST_CASES = {
 };
 
 if (!common.hasFipsCrypto) {
-  TEST_CASES.Cipher = ['aes192', 'secret'];
-  TEST_CASES.Decipher = ['aes192', 'secret'];
+  TEST_CASES.Cipher = ['aes-192-cbc', 'secret'];
+  TEST_CASES.Decipher = ['aes-192-cbc', 'secret'];
   TEST_CASES.DiffieHellman = [common.hasOpenSSL3 ? 1024 : 256];
 }
 
