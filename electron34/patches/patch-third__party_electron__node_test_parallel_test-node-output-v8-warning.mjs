$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-node-output-v8-warning.mjs.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-node-output-v8-warning.mjs
@@ -2,11 +2,18 @@ import '../common/index.mjs';
 import * as fixtures from '../common/fixtures.mjs';
 import * as snapshot from '../common/assertSnapshot.js';
 import { describe, it } from 'node:test';
+import { basename } from 'node:path';
 
 function replaceNodeVersion(str) {
   return str.replaceAll(process.version, '*');
 }
 
+function replaceExecName(str) {
+  // Copied from lib/internal/process/warning.js
+  const baseName = basename(process.argv0 || 'node', '.exe');
+  return str.replaceAll(`${baseName} --`, '* --');
+}
+
 describe('v8 output', { concurrency: true }, () => {
   function normalize(str) {
     return str.replaceAll(snapshot.replaceWindowsPaths(process.cwd()), '')
@@ -15,10 +22,10 @@ describe('v8 output', { concurrency: tru
     .replaceAll('*test*', '*')
     .replaceAll(/.*?\*fixtures\*v8\*/g, '(node:*) V8: *') // Replace entire path before fixtures/v8
     .replaceAll('*fixtures*v8*', '*')
-    .replaceAll('node --', '* --');
   }
+
   const common = snapshot
-    .transform(snapshot.replaceWindowsLineEndings, snapshot.replaceWindowsPaths, replaceNodeVersion);
+    .transform(snapshot.replaceWindowsLineEndings, snapshot.replaceWindowsPaths, replaceNodeVersion, replaceExecName);
   const defaultTransform = snapshot.transform(common, normalize);
   const tests = [
     { name: 'v8/v8_warning.js' },
