$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-debugger-run-after-quit-restart.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-debugger-run-after-quit-restart.js
@@ -25,7 +25,7 @@ const path = require('path');
     .then(() => cli.stepCommand('n'))
     .then(() => {
       assert.ok(
-        cli.output.includes(`break in ${script}:2`),
+        cli.output.includes(`step in ${script}:2`),
         'steps to the 2nd line'
       );
     })
