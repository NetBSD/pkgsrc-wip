$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-buffer-tostring-range.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-buffer-tostring-range.js
@@ -103,6 +103,8 @@ assert.throws(() => {
 // Cannot test on 32bit machine as we are testing the case
 // when start and end are above the threshold
 common.skipIf32Bits();
+/* Disabled due to incompatiblity with v8 memory cage
 const threshold = 0xFFFFFFFF;
 const largeBuffer = Buffer.alloc(threshold);
 largeBuffer.toString('utf8', threshold + 0xF, threshold + 0xFF);
+*/
\ No newline at end of file
