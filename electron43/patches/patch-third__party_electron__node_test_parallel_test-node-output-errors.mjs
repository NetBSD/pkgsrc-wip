$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/parallel/test-node-output-errors.mjs.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/parallel/test-node-output-errors.mjs
@@ -3,6 +3,7 @@ import * as fixtures from '../common/fix
 import * as snapshot from '../common/assertSnapshot.js';
 import * as os from 'node:os';
 import { describe, it } from 'node:test';
+import { basename } from 'node:path';
 import { pathToFileURL } from 'node:url';
 
 const skipForceColors =
@@ -20,13 +21,15 @@ function replaceForceColorsStackTrace(st
 
 describe('errors output', { concurrency: true }, () => {
   function normalize(str) {
+    const baseName = basename(process.argv0 || 'node', '.exe');
     return str.replaceAll(snapshot.replaceWindowsPaths(process.cwd()), '')
       .replaceAll(pathToFileURL(process.cwd()).pathname, '')
       .replaceAll('//', '*')
       .replaceAll(/\/(\w)/g, '*$1')
       .replaceAll('*test*', '*')
       .replaceAll('*fixtures*errors*', '*')
-      .replaceAll('file:**', 'file:*/');
+      .replaceAll('file:**', 'file:*/')
+      .replaceAll(`${baseName} --`, '* --');
   }
 
   function normalizeNoNumbers(str) {
