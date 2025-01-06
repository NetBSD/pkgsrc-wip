$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/esm/load.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/esm/load.js
@@ -10,7 +10,7 @@ const { kEmptyObject } = require('intern
 const { defaultGetFormat } = require('internal/modules/esm/get_format');
 const { validateAttributes, emitImportAssertionWarning } = require('internal/modules/esm/assert');
 const { getOptionValue } = require('internal/options');
-const { readFileSync } = require('fs');
+const fs = require('fs');
 
 // Do not eagerly grab .manifest, it may be in TDZ
 const policy = getOptionValue('--experimental-policy') ?
@@ -42,8 +42,7 @@ async function getSource(url, context) {
   let responseURL = href;
   let source;
   if (protocol === 'file:') {
-    const { readFile: readFileAsync } = require('internal/fs/promises').exports;
-    source = await readFileAsync(url);
+    source = await fs.promises.readFile(url);
   } else if (protocol === 'data:') {
     const match = RegExpPrototypeExec(DATA_URL_PATTERN, url.pathname);
     if (!match) {
@@ -82,7 +81,7 @@ function getSourceSync(url, context) {
   const responseURL = href;
   let source;
   if (protocol === 'file:') {
-    source = readFileSync(url);
+    source = fs.readFileSync(url);
   } else if (protocol === 'data:') {
     const match = RegExpPrototypeExec(DATA_URL_PATTERN, url.pathname);
     if (!match) {
@@ -133,7 +132,7 @@ async function defaultLoad(url, context 
     source = null;
     format ??= 'builtin';
   } else if (format !== 'commonjs' || defaultType === 'module') {
-    if (source == null) {
+    if (format !== 'electron' && source == null) {
       ({ responseURL, source } = await getSource(urlInstance, context));
       context = { __proto__: context, source };
     }
@@ -142,7 +141,7 @@ async function defaultLoad(url, context 
       // Now that we have the source for the module, run `defaultGetFormat` to detect its format.
       format = await defaultGetFormat(urlInstance, context);
 
-      if (format === 'commonjs') {
+      if (format === 'electron' || format === 'commonjs') {
         // For backward compatibility reasons, we need to discard the source in
         // order for the CJS loader to re-fetch it.
         source = null;
@@ -234,6 +233,7 @@ function throwIfUnsupportedURLScheme(par
     protocol !== 'file:' &&
     protocol !== 'data:' &&
     protocol !== 'node:' &&
+    protocol !== 'electron:' &&
     (
       !experimentalNetworkImports ||
       (
@@ -242,7 +242,7 @@ function throwIfUnsupportedURLScheme(par
       )
     )
   ) {
-    const schemes = ['file', 'data', 'node'];
+    const schemes = ['file', 'data', 'node', 'electron'];
     if (experimentalNetworkImports) {
       ArrayPrototypePush(schemes, 'https', 'http');
     }
