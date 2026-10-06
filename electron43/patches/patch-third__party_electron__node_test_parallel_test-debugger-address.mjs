$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-debugger-address.mjs.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-debugger-address.mjs
@@ -56,6 +56,7 @@ function launchTarget(...args) {
     const { childProc, host, port } = await launchTarget('--inspect=0', script);
     target = childProc;
     cli = startCLI([`${host || '127.0.0.1'}:${port}`]);
+    await new Promise(resolve => setTimeout(resolve, 1000));
     await cli.waitForPrompt();
     await cli.command('sb("alive.js", 3)');
     await cli.waitFor(/break/);
