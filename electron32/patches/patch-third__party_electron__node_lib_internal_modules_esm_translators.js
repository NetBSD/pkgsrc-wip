$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/esm/translators.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/esm/translators.js
@@ -36,7 +36,7 @@ const {
 
 const { BuiltinModule } = require('internal/bootstrap/realm');
 const assert = require('internal/assert');
-const { readFileSync } = require('fs');
+const fs = require('fs');
 const { dirname, extname, isAbsolute } = require('path');
 const {
   loadBuiltinModule,
@@ -272,7 +272,7 @@ function createCJSModuleWrap(url, source
 
   const { exportNames, module } = cjsPreparseModuleExports(filename, source);
   cjsCache.set(url, module);
-  const namesWithDefault = exportNames.has('default') ?
+  const namesWithDefault = filename === 'electron' ? ['default', ...Object.keys(module.exports)] : exportNames.has('default') ?
     [...exportNames] : ['default', ...exportNames];
 
   if (isMain) {
@@ -294,8 +294,8 @@ function createCJSModuleWrap(url, source
       ({ exports } = module);
     }
     for (const exportName of exportNames) {
-      if (!ObjectPrototypeHasOwnProperty(exports, exportName) ||
-          exportName === 'default') {
+      if (exportName === 'default' ||
+          !ObjectPrototypeHasOwnProperty(exports, exportName)) {
         continue;
       }
       // We might trigger a getter -> dont fail.
@@ -329,6 +329,10 @@ translators.set('require-commonjs', (url
   return createCJSModuleWrap(url, source);
 });
 
+translators.set('electron', () => {
+  return createCJSModuleWrap('electron', '');
+});
+
 // Handle CommonJS modules referenced by `import` statements or expressions,
 // or as the initial entry point when the ESM loader handles a CommonJS entry.
 translators.set('commonjs', async function commonjsStrategy(url, source,
@@ -352,7 +356,7 @@ translators.set('commonjs', async functi
 
   try {
     // We still need to read the FS to detect the exports.
-    source ??= readFileSync(new URL(url), 'utf8');
+    source ??= fs.readFileSync(new URL(url), 'utf8');
   } catch {
     // Continue regardless of error.
   }
@@ -371,6 +375,9 @@ function cjsPreparseModuleExports(filena
   if (module && module[kModuleExportNames] !== undefined) {
     return { module, exportNames: module[kModuleExportNames] };
   }
+  if (filename === 'electron') {
+    return { module, exportNames: new SafeSet(['default', ...Object.keys(module.exports)]) };
+  }
   const loaded = Boolean(module);
   if (!loaded) {
     module = new CJSModule(filename);
@@ -420,7 +427,7 @@ function cjsPreparseModuleExports(filena
       isAbsolute(resolved)) {
         // TODO: this should be calling the `load` hook chain to get the source
         // (and fallback to reading the FS only if the source is nullish).
-        const source = readFileSync(resolved, 'utf-8');
+        const source = fs.readFileSync(resolved, 'utf-8');
         const { exportNames: reexportNames } = cjsPreparseModuleExports(resolved, source);
         for (const name of reexportNames) {
           exportNames.add(name);
