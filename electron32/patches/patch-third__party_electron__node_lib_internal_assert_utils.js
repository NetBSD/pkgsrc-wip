$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/assert/utils.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/assert/utils.js
@@ -25,6 +25,7 @@ const AssertionError = require('internal
 const { openSync, closeSync, readSync } = require('fs');
 const { EOL } = require('internal/constants');
 const { BuiltinModule } = require('internal/bootstrap/realm');
+const { getEmbedderOptions } = require('internal/options');
 const { isError } = require('internal/util');
 
 const errorCache = new SafeMap();
@@ -167,8 +168,16 @@ function getErrMessage(message, fn) {
   ErrorCaptureStackTrace(err, fn);
   if (errorStackTraceLimitIsWritable) Error.stackTraceLimit = tmpLimit;
 
-  overrideStackTrace.set(err, (_, stack) => stack);
-  const call = err.stack[0];
+  let call;
+  if (getEmbedderOptions().hasPrepareStackTraceCallback) {
+    overrideStackTrace.set(err, (_, stack) => stack);
+    call = err.stack[0];
+  } else {
+    const tmpPrepare = Error.prepareStackTrace;
+    Error.prepareStackTrace = (_, stack) => stack;
+    call = err.stack[0];
+    Error.prepareStackTrace = tmpPrepare;
+  }
 
   let filename = call.getFileName();
   const line = call.getLineNumber() - 1;
