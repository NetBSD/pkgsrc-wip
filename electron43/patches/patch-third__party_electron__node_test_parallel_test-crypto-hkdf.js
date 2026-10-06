$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-hkdf.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-hkdf.js
@@ -124,8 +124,6 @@ const algorithms = [
   ['sha256', '', 'salt', '', 10],
   ['sha512', 'secret', 'salt', '', 15],
 ];
-if (!common.hasOpenSSL3)
-  algorithms.push(['whirlpool', 'secret', '', 'info', 20]);
 
 algorithms.forEach(([ hash, secret, salt, info, length ]) => {
   {
