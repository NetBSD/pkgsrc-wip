$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-debugger-break.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-debugger-break.js
@@ -27,7 +27,7 @@ const cli = startCLI(['--port=0', script
 
   await cli.stepCommand('n');
   assert.ok(
-    cli.output.includes(`break in ${script}:2`),
+    cli.output.includes(`step in ${script}:2`),
     'pauses in next line of the script');
   assert.match(
     cli.output,
@@ -36,7 +36,7 @@ const cli = startCLI(['--port=0', script
 
   await cli.stepCommand('next');
   assert.ok(
-    cli.output.includes(`break in ${script}:3`),
+    cli.output.includes(`step in ${script}:3`),
     'pauses in next line of the script');
   assert.match(
     cli.output,
@@ -89,7 +89,7 @@ const cli = startCLI(['--port=0', script
   await cli.stepCommand('');
   assert.match(
     cli.output,
-    /break in node:timers/,
+    /step in node:timers/,
     'entered timers.js');
 
   await cli.stepCommand('cont');
