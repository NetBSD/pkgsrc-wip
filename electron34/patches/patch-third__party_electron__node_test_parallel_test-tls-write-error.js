$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-tls-write-error.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-tls-write-error.js
@@ -17,7 +17,7 @@ const server_cert = fixtures.readKey('ag
 const opts = {
   key: server_key,
   cert: server_cert,
-  ciphers: 'ALL@SECLEVEL=0'
+  // ciphers: 'ALL@SECLEVEL=0'
 };
 
 const server = https.createServer(opts, (req, res) => {
