$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-https-agent-session-eviction.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-https-agent-session-eviction.js
@@ -14,7 +14,7 @@ const options = {
   key: readKey('agent1-key.pem'),
   cert: readKey('agent1-cert.pem'),
   secureOptions: SSL_OP_NO_TICKET,
-  ciphers: 'RSA@SECLEVEL=0'
+  // ciphers: 'RSA@SECLEVEL=0'
 };
 
 // Create TLS1.2 server
