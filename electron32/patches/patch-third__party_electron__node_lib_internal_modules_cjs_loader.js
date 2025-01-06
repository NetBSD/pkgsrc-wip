$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/cjs/loader.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/cjs/loader.js
@@ -138,7 +138,7 @@ const {
 const assert = require('internal/assert');
 const fs = require('fs');
 const path = require('path');
-const { internalModuleStat } = internalBinding('fs');
+const internalFsBinding = internalBinding('fs');
 const { safeGetenv } = internalBinding('credentials');
 const {
   privateSymbols: {
@@ -185,6 +185,13 @@ const {
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
@@ -226,7 +233,7 @@ function stat(filename) {
     const result = statCache.get(filename);
     if (result !== undefined) { return result; }
   }
-  const result = internalModuleStat(filename);
+  const result = internalFsBinding.internalModuleStat(filename);
   if (statCache !== null && result >= 0) {
     // Only set cache when `internalModuleStat(filename)` succeeds.
     statCache.set(filename, result);
@@ -1434,6 +1441,13 @@ Module.prototype._compile = function(con
   if (getOptionValue('--inspect-brk') && process._eval == null) {
     if (!resolvedArgv) {
       // We enter the repl if we're not given a filename argument.
+      // process._firstFileName is used by Embedders to tell node what
+      // the first "real" file is when they use themselves as the entry
+      // point
+      if (process._firstFileName) {
+        resolvedArgv = process._firstFileName
+        delete process._firstFileName
+      } else
       if (process.argv[1]) {
         try {
           resolvedArgv = Module._resolveFilename(process.argv[1], null, false);
@@ -1464,10 +1478,12 @@ Module.prototype._compile = function(con
   this[kIsExecuting] = true;
   if (inspectorWrapper) {
     result = inspectorWrapper(compiledWrapper, thisValue, exports,
-                              require, module, filename, dirname);
+                              require, module, filename, dirname,
+                              process, localGlobal, localBuffer);
   } else {
     result = ReflectApply(compiledWrapper, thisValue,
-                          [exports, require, module, filename, dirname]);
+                          [exports, require, module, filename,
+                           dirname, process, localGlobal, localBuffer]);
   }
   this[kIsExecuting] = false;
   if (requireDepth === 0) { statCache = null; }
