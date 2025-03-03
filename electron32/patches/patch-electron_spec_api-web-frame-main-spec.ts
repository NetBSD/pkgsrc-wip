$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-web-frame-main-spec.ts.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/spec/api-web-frame-main-spec.ts
@@ -292,7 +292,8 @@ describe('webFrameMain module', () => {
     });
 
     // TODO(jkleinsc) fix this flaky test on linux
-    ifit(process.platform !== 'linux')('throws upon accessing properties when disposed', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd' &&
+          process.platform !== 'openbsd' && process.platform !== 'netbsd')('throws upon accessing properties when disposed', async () => {
       await w.loadFile(path.join(subframesPath, 'frame-with-frame-container.html'));
       const { mainFrame } = w.webContents;
       w.destroy();
