$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-private-decrypt-gh32240.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-private-decrypt-gh32240.js
@@ -24,7 +24,7 @@ const pkeyEncrypted =
   pair.privateKey.export({
     type: 'pkcs1',
     format: 'pem',
-    cipher: 'aes128',
+    cipher: 'aes-128-cbc',
     passphrase: 'secret',
   });
 
