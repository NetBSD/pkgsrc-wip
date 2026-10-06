$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-tls-getprotocol.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-tls-getprotocol.js
@@ -27,7 +27,7 @@ const clientConfigs = [
 
 const serverConfig = {
   secureProtocol: 'TLS_method',
-  ciphers: 'RSA@SECLEVEL=0',
+  // ciphers: 'RSA@SECLEVEL=0',
   key: fixtures.readKey('agent2-key.pem'),
   cert: fixtures.readKey('agent2-cert.pem')
 };
