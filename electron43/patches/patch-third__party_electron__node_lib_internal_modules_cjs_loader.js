$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/cjs/loader.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/cjs/loader.js
@@ -141,7 +141,7 @@ const {
 const assert = require('internal/assert');
 const fs = require('fs');
 const path = require('path');
-const { internalModuleStat } = internalBinding('fs');
+const internalFsBinding = internalBinding('fs');
 const { safeGetenv } = internalBinding('credentials');
 const {
   privateSymbols: {
@@ -188,6 +188,13 @@ const {
   CHAR_FORWARD_SLASH,
 } = require('internal/constants');
 
+// Store the "global" variable from global scope into a local scope, so we can
+// still reference it from this file even after we deleted the "global" variable
+// from the global scope.
+const localGlobal = (typeof global !== 'undefined') ? global : undefined;
+// Do the same for "Buffer".
+const localBuffer = (typeof Buffer !== 'undefined') ? Buffer : undefined;
+
 const {
   isProxy,
 } = require('internal/util/types');
@@ -229,7 +236,7 @@ function stat(filename) {
     const result = statCache.get(filename);
     if (result !== undefined) { return result; }
   }
-  const result = internalModuleStat(filename);
+  const result = internalFsBinding.internalModuleStat(filename);
   if (statCache !== null && result >= 0) {
     // Only set cache when `internalModuleStat(filename)` succeeds.
     statCache.set(filename, result);
@@ -1523,11 +1530,20 @@ Module.prototype._compile = function(con
   this[kIsExecuting] = true;
   if (this[kIsMainSymbol] && getOptionValue('--inspect-brk')) {
     const { callAndPauseOnStart } = internalBinding('inspector');
+    // process._firstFileName is used by Embedders to tell node what
+    // the first "real" file is when they use themselves as the entry
+    // point
+    if (process._firstFileName) {
+      resolvedArgv = process._firstFileName;
+      delete process._firstFileName;
+    }
     result = callAndPauseOnStart(compiledWrapper, thisValue, exports,
-                                 require, module, filename, dirname);
+                                 require, module, filename, dirname,
+                                 process, localGlobal, localBuffer);
   } else {
     result = ReflectApply(compiledWrapper, thisValue,
-                          [exports, require, module, filename, dirname]);
+                          [exports, require, module, filename, dirname,
+                            process, localGlobal, localBuffer]);
   }
   this[kIsExecuting] = false;
   if (requireDepth === 0) { statCache = null; }
