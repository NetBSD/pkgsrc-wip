$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-crypto-hash-stream-pipe.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-crypto-hash-stream-pipe.js
@@ -30,11 +30,11 @@ const crypto = require('crypto');
 
 const stream = require('stream');
 const s = new stream.PassThrough();
-const h = crypto.createHash('sha3-512');
-const expect = '36a38a2a35e698974d4e5791a3f05b05' +
-               '198235381e864f91a0e8cd6a26b677ec' +
-               'dcde8e2b069bd7355fabd68abd6fc801' +
-               '19659f25e92f8efc961ee3a7c815c758';
+const h = crypto.createHash('sha512');
+const expect = 'fba055c6fd0c5b6645407749ed7a8b41' +
+               'b8f629f2163c3ca3701d864adabda1f8' +
+               '93c37bf82b22fdd151ba8e357f611da4' +
+               '88a74b6a5525dd9b69554c6ce5138ad7';
 
 s.pipe(h).on('data', common.mustCall(function(c) {
   assert.strictEqual(c, expect);
