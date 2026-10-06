$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-x509.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-x509.js
@@ -323,6 +323,7 @@ oans248kpal88CGqsN2so/wZKxVnpiXlPHMdiNL7
     legacyObjectCheck.serialNumberPattern);
 }
 
+/*
 {
   // This X.509 Certificate can be parsed by OpenSSL because it contains a
   // structurally sound TBSCertificate structure. However, the SPKI field of the
@@ -361,3 +362,4 @@ UcXd/5qu2GhokrKU2cPttU+XAN2Om6a0
 
   assert.strictEqual(cert.checkIssued(cert), false);
 }
+*/
