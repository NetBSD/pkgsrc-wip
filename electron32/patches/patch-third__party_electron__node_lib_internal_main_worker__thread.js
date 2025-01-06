$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/main/worker_thread.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/main/worker_thread.js
@@ -113,7 +113,7 @@ port.on('message', (message) => {
 
     require('internal/worker').assignEnvironmentData(environmentData);
 
-    if (SharedArrayBuffer !== undefined && Atomics !== undefined) {
+    if (SharedArrayBuffer !== undefined) {
       // The counter is only passed to the workers created by the main thread,
       // not to workers created by other workers.
       let cachedCwd = '';
