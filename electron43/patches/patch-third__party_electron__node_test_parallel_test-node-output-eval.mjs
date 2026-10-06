$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-node-output-eval.mjs.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-node-output-eval.mjs
@@ -1,6 +1,7 @@
 import '../common/index.mjs';
 import * as fixtures from '../common/fixtures.mjs';
 import * as snapshot from '../common/assertSnapshot.js';
+import { basename } from 'node:path';
 import { describe, it } from 'node:test';
 
 describe('eval output', { concurrency: true }, () => {
@@ -14,13 +15,19 @@ describe('eval output', { concurrency: t
     normalize,
     snapshot.replaceWindowsLineEndings,
     snapshot.replaceWindowsPaths,
-    snapshot.replaceNodeVersion
+    snapshot.replaceNodeVersion,
+    generalizeProcessName,
   );
 
   function removeStackTraces(output) {
     return output.replaceAll(/^ *at .+$/gm, '');
   }
 
+  function generalizeProcessName(output) {
+    const baseName = basename(process.argv0 || 'node', '.exe');
+    return output.replaceAll(`${baseName} --`, '* --');
+  }
+
   const tests = [
     { name: 'eval/eval_messages.js' },
     { name: 'eval/stdin_messages.js' },
