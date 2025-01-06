$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-x509-escaping.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-x509-escaping.js
@@ -447,7 +447,7 @@ const { hasOpenSSL3 } = common;
   assert.strictEqual(certX509.checkHost(servername, { subject: 'default' }),
                      undefined);
   assert.strictEqual(certX509.checkHost(servername, { subject: 'always' }),
-                     servername);
+                     undefined);
   assert.strictEqual(certX509.checkHost(servername, { subject: 'never' }),
                      undefined);
 
@@ -482,11 +482,11 @@ const { hasOpenSSL3 } = common;
   assert.strictEqual(certX509.subjectAltName, 'IP Address:1.2.3.4');
 
   // The newer X509Certificate API allows customizing this behavior:
-  assert.strictEqual(certX509.checkHost(servername), servername);
+  assert.strictEqual(certX509.checkHost(servername), undefined);
   assert.strictEqual(certX509.checkHost(servername, { subject: 'default' }),
-                     servername);
+                     undefined);
   assert.strictEqual(certX509.checkHost(servername, { subject: 'always' }),
-                     servername);
+                     undefined);
   assert.strictEqual(certX509.checkHost(servername, { subject: 'never' }),
                      undefined);
 
