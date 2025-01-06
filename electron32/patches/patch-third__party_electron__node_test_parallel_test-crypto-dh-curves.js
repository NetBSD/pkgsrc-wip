$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-dh-curves.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-dh-curves.js
@@ -16,7 +16,7 @@ const p = 'FFFFFFFFFFFFFFFFC90FDAA22168C
 crypto.createDiffieHellman(p, 'hex');
 
 // Confirm DH_check() results are exposed for optional examination.
-const bad_dh = crypto.createDiffieHellman('02', 'hex');
+const bad_dh = crypto.createDiffieHellman('abcd', 'hex', 0);
 assert.notStrictEqual(bad_dh.verifyError, 0);
 
 const availableCurves = new Set(crypto.getCurves());
