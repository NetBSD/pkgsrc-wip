$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-https-agent-additional-options.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-https-agent-additional-options.js
@@ -13,7 +13,7 @@ const options = {
   cert: fixtures.readKey('agent1-cert.pem'),
   ca: fixtures.readKey('ca1-cert.pem'),
   minVersion: 'TLSv1.1',
-  ciphers: 'ALL@SECLEVEL=0'
+  // ciphers: 'ALL@SECLEVEL=0'
 };
 
 const server = https.Server(options, (req, res) => {
@@ -28,7 +28,7 @@ function getBaseOptions(port) {
     ca: options.ca,
     rejectUnauthorized: true,
     servername: 'agent1',
-    ciphers: 'ALL@SECLEVEL=0'
+    // ciphers: 'ALL@SECLEVEL=0'
   };
 }
 
