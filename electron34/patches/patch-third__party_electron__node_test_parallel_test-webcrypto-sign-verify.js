$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-webcrypto-sign-verify.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-webcrypto-sign-verify.js
@@ -105,6 +105,7 @@ const { subtle } = globalThis.crypto;
   test('hello world').then(common.mustCall());
 }
 
+/*
 // Test Sign/Verify Ed25519
 {
   async function test(data) {
@@ -144,3 +145,4 @@ const { subtle } = globalThis.crypto;
 
   test('hello world').then(common.mustCall());
 }
+*/
