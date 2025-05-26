$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-net-log-spec.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/spec/api-net-log-spec.ts
@@ -121,7 +121,7 @@ describe('netLog module', () => {
     expect(JSON.parse(dump).events.some((x: any) => x.params && x.params.bytes && Buffer.from(x.params.bytes, 'base64').includes(unique))).to.be.true('uuid present in dump');
   });
 
-  ifit(process.platform !== 'linux')('should begin and end logging automatically when --log-net-log is passed', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('should begin and end logging automatically when --log-net-log is passed', async () => {
     const appProcess = ChildProcess.spawn(process.execPath,
       [appPath], {
         env: {
@@ -134,7 +134,7 @@ describe('netLog module', () => {
     expect(fs.existsSync(dumpFile)).to.be.true('dump file exists');
   });
 
-  ifit(process.platform !== 'linux')('should begin and end logging automatically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('should begin and end logging automatically when --log-net-log is passed, and behave correctly when .startLogging() and .stopLogging() is called', async () => {
     const appProcess = ChildProcess.spawn(process.execPath,
       [appPath], {
         env: {
@@ -150,7 +150,7 @@ describe('netLog module', () => {
     expect(fs.existsSync(dumpFileDynamic)).to.be.true('dynamic dump file exists');
   });
 
-  ifit(process.platform !== 'linux')('should end logging automatically when only .startLogging() is called', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('should end logging automatically when only .startLogging() is called', async () => {
     const appProcess = ChildProcess.spawn(process.execPath,
       [appPath], {
         env: {
