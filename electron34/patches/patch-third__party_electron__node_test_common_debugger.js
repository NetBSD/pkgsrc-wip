$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/common/debugger.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/common/debugger.js
@@ -4,7 +4,7 @@ const spawn = require('child_process').s
 
 const BREAK_MESSAGE = new RegExp('(?:' + [
   'assert', 'break', 'break on start', 'debugCommand',
-  'exception', 'other', 'promiseRejection',
+  'exception', 'other', 'promiseRejection', 'step',
 ].join('|') + ') in', 'i');
 
 let TIMEOUT = common.platformTimeout(5000);
@@ -121,13 +121,13 @@ function startCLI(args, flags = [], spaw
     get breakInfo() {
       const output = this.output;
       const breakMatch =
-        output.match(/break (?:on start )?in ([^\n]+):(\d+)\n/i);
+        output.match(/(step |break (?:on start )?)in ([^\n]+):(\d+)\n/i);
 
       if (breakMatch === null) {
         throw new Error(
           `Could not find breakpoint info in ${JSON.stringify(output)}`);
       }
-      return { filename: breakMatch[1], line: +breakMatch[2] };
+      return { filename: breakMatch[2], line: +breakMatch[3] };
     },
 
     ctrlC() {
