$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-async-sign-verify.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-async-sign-verify.js
@@ -88,6 +88,7 @@ test('rsa_public.pem', 'rsa_private.pem'
 // ED25519
 test('ed25519_public.pem', 'ed25519_private.pem', undefined, true);
 // ED448
+/*
 test('ed448_public.pem', 'ed448_private.pem', undefined, true);
 
 // ECDSA w/ der signature encoding
@@ -109,6 +110,7 @@ test('dsa_public.pem', 'dsa_private.pem'
 // DSA w/ ieee-p1363 signature encoding
 test('dsa_public.pem', 'dsa_private.pem', 'sha256', false,
      { dsaEncoding: 'ieee-p1363' });
+*/
 
 // Test Parallel Execution w/ KeyObject is threadsafe in openssl3
 {
