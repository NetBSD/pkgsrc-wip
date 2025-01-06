$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-certificate.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-certificate.js
@@ -40,8 +40,10 @@ function copyArrayBuffer(buf) {
 }
 
 function checkMethods(certificate) {
-
+  /* spkacValid has a md5 based signature which is not allowed in boringssl
+  https://boringssl.googlesource.com/boringssl/+/33d7e32ce40c04e8f1b99c05964956fda187819f
   assert.strictEqual(certificate.verifySpkac(spkacValid), true);
+  */
   assert.strictEqual(certificate.verifySpkac(spkacFail), false);
 
   assert.strictEqual(
@@ -56,10 +58,12 @@ function checkMethods(certificate) {
   );
   assert.strictEqual(certificate.exportChallenge(spkacFail), '');
 
+  /* spkacValid has a md5 based signature which is not allowed in boringssl
   const ab = copyArrayBuffer(spkacValid);
   assert.strictEqual(certificate.verifySpkac(ab), true);
   assert.strictEqual(certificate.verifySpkac(new Uint8Array(ab)), true);
   assert.strictEqual(certificate.verifySpkac(new DataView(ab)), true);
+  */
 }
 
 {
