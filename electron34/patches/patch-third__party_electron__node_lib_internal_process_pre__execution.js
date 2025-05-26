$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/process/pre_execution.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/lib/internal/process/pre_execution.js
@@ -245,12 +245,14 @@ function patchProcessObject(expandArgv1)
   // the entry point.
   if (expandArgv1 && process.argv[1] && process.argv[1][0] !== '-') {
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
 
