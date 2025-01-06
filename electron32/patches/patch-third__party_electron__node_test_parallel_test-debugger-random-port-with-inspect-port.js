$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-debugger-random-port-with-inspect-port.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/parallel/test-debugger-random-port-with-inspect-port.js
@@ -13,6 +13,7 @@ const script = fixtures.path('debugger',
 const cli = startCLI(['--inspect-port=0', script]);
 
 (async () => {
+  await new Promise(resolve => setTimeout(resolve, 1000));
   await cli.waitForInitialBreak();
   await cli.waitForPrompt();
   assert.match(cli.output, /debug>/, 'prints a prompt');
