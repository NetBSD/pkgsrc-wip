$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-webcrypto-derivekey.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-webcrypto-derivekey.js
@@ -175,6 +175,7 @@ const { KeyObject } = require('crypto');
   })().then(common.mustCall());
 }
 
+/*
 // Test X25519 and X448 key derivation
 {
   async function test(name) {
@@ -209,3 +210,4 @@ const { KeyObject } = require('crypto');
   test('X25519').then(common.mustCall());
   test('X448').then(common.mustCall());
 }
+*/
