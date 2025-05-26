$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/main/worker_thread.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/lib/internal/main/worker_thread.js
@@ -117,7 +117,7 @@ port.on('message', (message) => {
     require('internal/worker').assignEnvironmentData(environmentData);
     setupMainThreadPort(mainThreadPort);
 
-    if (SharedArrayBuffer !== undefined && Atomics !== undefined) {
+    if (SharedArrayBuffer !== undefined) {
       // The counter is only passed to the workers created by the main thread,
       // not to workers created by other workers.
       let cachedCwd = '';
