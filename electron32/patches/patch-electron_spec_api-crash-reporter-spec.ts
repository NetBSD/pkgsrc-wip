$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-crash-reporter-spec.ts.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/spec/api-crash-reporter-spec.ts
@@ -14,7 +14,8 @@ import { setTimeout } from 'node:timers/
 import { ifdescribe, ifit, defer, startRemoteControlApp, repeatedly, listen } from './lib/spec-helpers';
 
 const isWindowsOnArm = process.platform === 'win32' && process.arch === 'arm64';
-const isLinuxOnArm = process.platform === 'linux' && process.arch.includes('arm');
+const isLinuxOnArm = ((process.platform === 'linux' || process.platform === 'freebsd' ||
+                                            process.platform === 'openbsd' || process.platform === 'netbsd') && process.arch.includes('arm'));
 
 type CrashInfo = {
   prod: string
@@ -47,7 +48,8 @@ function checkCrash (expectedProcessType
 
   // TODO(nornagon): minidumps are sometimes (not always) turning up empty on
   // 32-bit Linux.  Figure out why.
-  if (!(process.platform === 'linux' && process.arch === 'ia32')) {
+  if (!((process.platform === 'linux' || process.platform === 'freebsd' ||
+          process.platform === 'openbsd' || process.platform === 'netbsd') && process.arch === 'ia32')) {
     expect(fields.upload_file_minidump.length).to.be.greaterThan(0);
   }
 }
@@ -184,7 +186,8 @@ ifdescribe(!isLinuxOnArm && !process.mas
 
     // Ensures that passing in crashpadHandlerPID flag for Linx child processes
     // does not affect child proocess args.
-    ifit(process.platform === 'linux')('ensure linux child process args are not modified', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd' ||
+          process.platform === 'openbsd' || process.platform === 'netbsd')('ensure linux child process args are not modified', async () => {
       const { port, waitForCrash } = await startServer();
       let exitCode: number | null = null;
       const appPath = path.join(__dirname, 'fixtures', 'apps', 'crash');
@@ -533,7 +536,8 @@ ifdescribe(!isLinuxOnArm && !process.mas
       }
     }
 
-    const processList = process.platform === 'linux'
+    const processList = (process.platform === 'linux' || process.platform === 'freebsd' ||
+                                         process.platform === 'openbsd' || process.platform === 'netbsd')
       ? ['main', 'renderer', 'sandboxed-renderer']
       : ['main', 'renderer', 'sandboxed-renderer', 'node'];
     for (const crashingProcess of processList) {
@@ -546,7 +550,8 @@ ifdescribe(!isLinuxOnArm && !process.mas
             return app.getPath('crashDumps');
           });
           let reportsDir = crashesDir;
-          if (process.platform === 'darwin' || process.platform === 'linux') {
+          if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd' ||
+               process.platform === 'openbsd' || process.platform === 'netbsd') {
             reportsDir = path.join(crashesDir, 'completed');
           } else if (process.platform === 'win32') {
             reportsDir = path.join(crashesDir, 'reports');
@@ -570,7 +575,8 @@ ifdescribe(!isLinuxOnArm && !process.mas
           expect(remoteCrashesDir).to.equal(crashesDir);
 
           let reportsDir = crashesDir;
-          if (process.platform === 'darwin' || process.platform === 'linux') {
+          if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd' ||
+               process.platform === 'openbsd' || process.platform === 'netbsd') {
             reportsDir = path.join(crashesDir, 'completed');
           } else if (process.platform === 'win32') {
             reportsDir = path.join(crashesDir, 'reports');
