$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/run_main.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/run_main.js
@@ -2,6 +2,7 @@
 
 const {
   StringPrototypeEndsWith,
+  StringPrototypeStartsWith,
 } = primordials;
 
 const { getOptionValue } = require('internal/options');
@@ -21,6 +22,13 @@ const {
  * @param {string} main - Entry point path
  */
 function resolveMainPath(main) {
+  // For built-in modules used as the main entry point we _never_
+  // want to waste cycles resolving them to file paths on disk
+  // that actually might exist
+  if (typeof main === 'string' && StringPrototypeStartsWith(main, 'electron/js2c')) {
+    return main;
+  }
+
   const defaultType = getOptionValue('--experimental-default-type');
   /** @type {string} */
   let mainPath;
@@ -57,6 +65,13 @@ function resolveMainPath(main) {
  * @param {string} mainPath - Absolute path to the main entry point
  */
 function shouldUseESMLoader(mainPath) {
+  // For built-in modules used as the main entry point we _never_
+  // want to waste cycles resolving them to file paths on disk
+  // that actually might exist
+  if (typeof mainPath === 'string' && StringPrototypeStartsWith(mainPath, 'electron/js2c')) {
+    return false;
+  }
+
   if (getOptionValue('--experimental-default-type') === 'module') { return true; }
 
   /**
