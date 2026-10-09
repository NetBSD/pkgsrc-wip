$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-crash-reporter.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/api-crash-reporter.spec.ts
@@ -14,7 +14,7 @@ import { setTimeout } from 'node:timers/
 import { ifdescribe, ifit, defer, startRemoteControlApp, repeatedly, listen } from './lib/spec-helpers.ts';
 
 const isWindowsOnArm = process.platform === 'win32' && process.arch === 'arm64';
-const isLinuxOnArm = process.platform === 'linux' && process.arch.includes('arm');
+const isLinuxOnArm = ((process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') && process.arch.includes('arm'));
 
 type CrashInfo = {
   prod: string;
@@ -54,7 +54,7 @@ function checkCrash(expectedProcessType:
 
   // TODO(nornagon): minidumps are sometimes (not always) turning up empty on
   // 32-bit Linux.  Figure out why.
-  if (!(process.platform === 'linux' && process.arch === 'ia32')) {
+  if (!((process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') && process.arch === 'ia32')) {
     expect(fields.upload_file_minidump.length).to.be.greaterThan(0);
   }
 }
@@ -193,7 +193,7 @@ ifdescribe(!isLinuxOnArm && !process.mas
 
       // Ensures that passing in crashpadHandlerPID flag for Linx child processes
       // does not affect child process args.
-      ifit(process.platform === 'linux')('ensure linux child process args are not modified', async () => {
+      ifit(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')('ensure linux child process args are not modified', async () => {
         const { port, waitForCrash } = await startServer();
         let exitCode: number | null = null;
         const appPath = path.join(import.meta.dirname, 'fixtures', 'apps', 'crash');
@@ -660,7 +660,7 @@ ifdescribe(!isLinuxOnArm && !process.mas
       }
 
       const processList =
-        process.platform === 'linux'
+        (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')
           ? ['main', 'renderer', 'sandboxed-renderer']
           : ['main', 'renderer', 'sandboxed-renderer', 'node'];
       for (const crashingProcess of processList) {
@@ -677,7 +677,7 @@ ifdescribe(!isLinuxOnArm && !process.mas
               return app.getPath('crashDumps');
             });
             let reportsDir = crashesDir;
-            if (process.platform === 'darwin' || process.platform === 'linux') {
+            if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
               reportsDir = path.join(crashesDir, 'completed');
             } else if (process.platform === 'win32') {
               reportsDir = path.join(crashesDir, 'reports');
@@ -705,7 +705,7 @@ ifdescribe(!isLinuxOnArm && !process.mas
             expect(remoteCrashesDir).to.equal(crashesDir);
 
             let reportsDir = crashesDir;
-            if (process.platform === 'darwin' || process.platform === 'linux') {
+            if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
               reportsDir = path.join(crashesDir, 'completed');
             } else if (process.platform === 'win32') {
               reportsDir = path.join(crashesDir, 'reports');
