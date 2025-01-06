$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/worker.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/worker.js
@@ -101,8 +101,7 @@ let cwdCounter;
 const environmentData = new SafeMap();
 
 // SharedArrayBuffers can be disabled with --no-harmony-sharedarraybuffer.
-// Atomics can be disabled with --no-harmony-atomics.
-if (isMainThread && SharedArrayBuffer !== undefined && Atomics !== undefined) {
+if (isMainThread && SharedArrayBuffer !== undefined) {
   cwdCounter = new Uint32Array(new SharedArrayBuffer(4));
   const originalChdir = process.chdir;
   process.chdir = function(path) {
