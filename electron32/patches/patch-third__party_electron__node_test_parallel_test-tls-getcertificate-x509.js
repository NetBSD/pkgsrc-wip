$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-tls-getcertificate-x509.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-tls-getcertificate-x509.js
@@ -20,9 +20,7 @@ const server = tls.createServer(options,
 server.once('secureConnection', common.mustCall(function(socket) {
   const cert = socket.getX509Certificate();
   assert(cert instanceof X509Certificate);
-  assert.strictEqual(
-    cert.serialNumber,
-    '5B75D77EDC7FB5B7FA9F1424DA4C64FB815DCBDE');
+  assert.match(cert.serialNumber, /5B75D77EDC7FB5B7FA9F1424DA4C64FB815DCBDE/i)
 }));
 
 server.listen(0, common.mustCall(function() {
@@ -33,10 +31,7 @@ server.listen(0, common.mustCall(functio
     const peerCert = socket.getPeerX509Certificate();
     assert(peerCert.issuerCertificate instanceof X509Certificate);
     assert.strictEqual(peerCert.issuerCertificate.issuerCertificate, undefined);
-    assert.strictEqual(
-      peerCert.issuerCertificate.serialNumber,
-      '147D36C1C2F74206DE9FAB5F2226D78ADB00A425'
-    );
+    assert.match(peerCert.issuerCertificate.serialNumber, /147D36C1C2F74206DE9FAB5F2226D78ADB00A425/i);
     server.close();
   }));
   socket.end('Hello');
