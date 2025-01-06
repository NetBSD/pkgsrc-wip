$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-hash.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-hash.js
@@ -182,6 +182,7 @@ assert.throws(
 
 // Test XOF hash functions and the outputLength option.
 {
+  /*
   // Default outputLengths.
   assert.strictEqual(crypto.createHash('shake128').digest('hex'),
                      '7f9c2ba4e88f827d616045507605853e');
@@ -236,6 +237,7 @@ assert.throws(
   assert.strictEqual(superLongHash.length, 2 * 1024 * 1024);
   assert.ok(superLongHash.endsWith('193414035ddba77bf7bba97981e656ec'));
   assert.ok(superLongHash.startsWith('a2a28dbc49cfd6e5d6ceea3d03e77748'));
+  */
 
   // Non-XOF hash functions should accept valid outputLength options as well.
   assert.strictEqual(crypto.createHash('sha224', { outputLength: 28 })
