$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/http.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/lib/internal/http.js
@@ -8,8 +8,8 @@ const {
 const { setUnrefTimeout } = require('internal/timers');
 const { getCategoryEnabledBuffer, trace } = internalBinding('trace_events');
 const {
-  CHAR_LOWERCASE_B,
-  CHAR_LOWERCASE_E,
+  CHAR_UPPERCASE_B,
+  CHAR_UPPERCASE_E,
 } = require('internal/constants');
 
 let utcCache;
@@ -44,11 +44,13 @@ function isTraceHTTPEnabled() {
 const traceEventCategory = 'node,node.http';
 
 function traceBegin(...args) {
-  trace(CHAR_LOWERCASE_B, traceEventCategory, ...args);
+  // See v8/src/builtins/builtins-trace.cc - must be uppercase for perfetto
+  trace(CHAR_UPPERCASE_B, traceEventCategory, ...args);
 }
 
 function traceEnd(...args) {
-  trace(CHAR_LOWERCASE_E, traceEventCategory, ...args);
+  // See v8/src/builtins/builtins-trace.cc - must be uppercase for perfetto
+  trace(CHAR_UPPERCASE_E, traceEventCategory, ...args);
 }
 
 module.exports = {
