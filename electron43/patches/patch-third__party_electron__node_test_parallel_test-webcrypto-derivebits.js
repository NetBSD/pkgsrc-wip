$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-webcrypto-derivebits.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-webcrypto-derivebits.js
@@ -101,6 +101,7 @@ const { subtle } = globalThis.crypto;
   tests.then(common.mustCall());
 }
 
+/*
 // Test X25519 and X448 bit derivation
 {
   async function test(name) {
@@ -126,3 +127,4 @@ const { subtle } = globalThis.crypto;
   test('X25519').then(common.mustCall());
   test('X448').then(common.mustCall());
 }
+*/
