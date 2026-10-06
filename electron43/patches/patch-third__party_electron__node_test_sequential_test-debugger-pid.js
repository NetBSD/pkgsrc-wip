$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/sequential/test-debugger-pid.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/sequential/test-debugger-pid.js
@@ -20,6 +20,7 @@ const runTest = async () => {
     await cli.command('sb("alive.js", 3)');
     await cli.waitFor(/break/);
     await cli.waitForPrompt();
+    await new Promise(resolve => setTimeout(resolve, 1000));
     assert.match(
       cli.output,
       /> 3 {3}\+\+x;/,
