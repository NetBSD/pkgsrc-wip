$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/fixtures/test-runner/output/arbitrary-output-colored.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/test/fixtures/test-runner/output/arbitrary-output-colored.js
@@ -7,6 +7,6 @@ const fixtures = require('../../../commo
 (async function run() {
   const test = fixtures.path('test-runner/output/arbitrary-output-colored-1.js');
   const reset = fixtures.path('test-runner/output/reset-color-depth.js');
-  await once(spawn(process.execPath, ['-r', reset, '--test', test], { stdio: 'inherit' }), 'exit');
-  await once(spawn(process.execPath, ['-r', reset, '--test', '--test-reporter', 'tap', test], { stdio: 'inherit'  }), 'exit');
+  await once(spawn(process.execPath, ['-r', reset, '--test', test], { stdio: 'inherit', env: { ELECTRON_RUN_AS_NODE: 1 }}), 'exit');
+  await once(spawn(process.execPath, ['-r', reset, '--test', '--test-reporter', 'tap', test], { stdio: 'inherit', env: { ELECTRON_RUN_AS_NODE: 1 }  }), 'exit');
 })().then(common.mustCall());
