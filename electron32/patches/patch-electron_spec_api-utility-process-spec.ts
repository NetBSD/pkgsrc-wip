$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-utility-process-spec.ts.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/spec/api-utility-process-spec.ts
@@ -438,7 +438,8 @@ describe('utilityProcess module', () => 
       expect(output).to.include(result);
     });
 
-    ifit(process.platform !== 'linux')('can access exposed main process modules from the utility process', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd' &&
+          process.platform !== 'openbsd' && process.platform !== 'netbsd')('can access exposed main process modules from the utility process', async () => {
       const message = 'Message from utility process';
       const child = utilityProcess.fork(path.join(fixturesPath, 'expose-main-process-module.js'));
       await once(child, 'spawn');
@@ -475,7 +476,8 @@ describe('utilityProcess module', () => 
       await closeWindow(w);
     });
 
-    ifit(process.platform === 'linux')('allows executing a setuid binary with child_process', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd' ||
+          process.platform === 'openbsd' || process.platform === 'netbsd')('allows executing a setuid binary with child_process', async () => {
       const child = utilityProcess.fork(path.join(fixturesPath, 'suid.js'));
       await once(child, 'spawn');
       const [data] = await once(child, 'message');
