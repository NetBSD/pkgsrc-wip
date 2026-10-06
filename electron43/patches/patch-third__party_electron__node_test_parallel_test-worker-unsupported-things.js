$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-worker-unsupported-things.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-worker-unsupported-things.js
@@ -14,14 +14,16 @@ if (!process.env.HAS_STARTED_WORKER) {
 } else {
   {
     const before = process.title;
-    process.title += ' in worker';
-    assert.strictEqual(process.title, before);
+    const after = before + ' in worker';
+    process.title = after;
+    assert.strictEqual(process.title, after);
   }
 
   {
     const before = process.debugPort;
-    process.debugPort++;
-    assert.strictEqual(process.debugPort, before);
+    const after = before + 1;
+    process.debugPort = after;
+    assert.strictEqual(process.debugPort, after);
   }
 
   {
