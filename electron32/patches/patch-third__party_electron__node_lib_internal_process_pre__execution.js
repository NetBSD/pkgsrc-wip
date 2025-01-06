$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/process/pre_execution.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/process/pre_execution.js
@@ -247,12 +247,14 @@ function patchProcessObject(expandArgv1)
   if (expandArgv1 && process.argv[1] &&
       !StringPrototypeStartsWith(process.argv[1], '-')) {
     // Expand process.argv[1] into a full path.
-    const path = require('path');
-    try {
-      mainEntry = path.resolve(process.argv[1]);
-      process.argv[1] = mainEntry;
-    } catch {
-      // Continue regardless of error.
+    if (!process.argv[1] || !process.argv[1].startsWith('electron/js2c')) {
+      const path = require('path');
+      try {
+        mainEntry = path.resolve(process.argv[1]);
+        process.argv[1] = mainEntry;
+      } catch {
+        // Continue regardless of error.
+      }
     }
   }
 
