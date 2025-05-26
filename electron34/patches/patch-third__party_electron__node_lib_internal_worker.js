$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/worker.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/lib/internal/worker.js
@@ -102,8 +102,7 @@ let cwdCounter;
 const environmentData = new SafeMap();
 
 // SharedArrayBuffers can be disabled with --no-harmony-sharedarraybuffer.
-// Atomics can be disabled with --no-harmony-atomics.
-if (isMainThread && SharedArrayBuffer !== undefined && Atomics !== undefined) {
+if (isMainThread && SharedArrayBuffer !== undefined) {
   cwdCounter = new Uint32Array(new SharedArrayBuffer(4));
   const originalChdir = process.chdir;
   process.chdir = function(path) {
