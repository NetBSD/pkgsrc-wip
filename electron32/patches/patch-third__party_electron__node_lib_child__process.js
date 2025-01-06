$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/child_process.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/child_process.js
@@ -61,6 +61,7 @@ let debug = require('internal/util/debug
 );
 const { Buffer } = require('buffer');
 const { Pipe, constants: PipeConstants } = internalBinding('pipe_wrap');
+const { getCrashdumpSignalFD, getCrashpadHandlerPID } = process._linkedBinding('electron_common_crashpad_support');
 
 const {
   AbortError,
@@ -154,7 +155,6 @@ function fork(modulePath, args = [], opt
       ArrayPrototypeSplice(execArgv, index - 1, 2);
     }
   }
-
   args = [...execArgv, modulePath, ...args];
 
   if (typeof options.stdio === 'string') {
@@ -618,6 +618,22 @@ function normalizeSpawnArguments(file, a
                     'options.windowsVerbatimArguments');
   }
 
+  const env = options.env || process.env;
+
+  if ((process.platform === 'linux') &&
+      ObjectPrototypeHasOwnProperty(env, 'ELECTRON_RUN_AS_NODE') &&
+      (file === process.execPath)) {
+    // On Linux, pass the file descriptor which crashpad handler process
+    // uses to monitor the child process and PID of the handler process.
+    // https://source.chromium.org/chromium/chromium/src/+/110.0.5415.0:components/crash/core/app/crashpad_linux.cc;l=199-206
+    const fd = getCrashdumpSignalFD();
+    const pid = getCrashpadHandlerPID();
+    if (fd !== -1 && pid !== -1) {
+      env.CRASHDUMP_SIGNAL_FD = fd;
+      env.CRASHPAD_HANDLER_PID = pid;
+    }
+  }
+
   if (options.shell) {
     validateArgumentNullCheck(options.shell, 'options.shell');
     const command = ArrayPrototypeJoin([file, ...args], ' ');
@@ -651,7 +667,6 @@ function normalizeSpawnArguments(file, a
     ArrayPrototypeUnshift(args, file);
   }
 
-  const env = options.env || process.env;
   const envPairs = [];
 
   // process.env.NODE_V8_COVERAGE always propagates, making it possible to
