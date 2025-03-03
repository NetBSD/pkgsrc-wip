$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-desktop-capturer-spec.ts.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/spec/api-desktop-capturer-spec.ts
@@ -45,7 +45,8 @@ ifdescribe(!process.arch.includes('arm')
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('returns an empty display_id for window sources', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd' &&
+        process.platform !== 'openbsd' && process.platform !== 'netbsd')('returns an empty display_id for window sources', async () => {
     const w = new BrowserWindow({ width: 200, height: 200 });
     await w.loadURL('about:blank');
 
@@ -57,7 +58,8 @@ ifdescribe(!process.arch.includes('arm')
     }
   });
 
-  ifit(process.platform !== 'linux')('returns display_ids matching the Screen API', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd' &&
+        process.platform !== 'openbsd' && process.platform !== 'netbsd')('returns display_ids matching the Screen API', async () => {
     const displays = screen.getAllDisplays();
     const sources = await desktopCapturer.getSources({ types: ['screen'] });
     expect(sources).to.be.an('array').of.length(displays.length);
@@ -102,7 +104,8 @@ ifdescribe(!process.arch.includes('arm')
     // TODO(julien.isorce): investigate why |sources| is empty on the linux
     // bots while it is not on my workstation, as expected, with and without
     // the --ci parameter.
-    if (process.platform === 'linux' && sources.length === 0) {
+    if ((process.platform === 'linux' || process.platform === 'freebsd' ||
+          process.platform === 'openbsd' || process.platform === 'netbsd') && sources.length === 0) {
       it.skip('desktopCapturer.getSources returned an empty source list');
       return;
     }
@@ -138,7 +141,8 @@ ifdescribe(!process.arch.includes('arm')
     // TODO(julien.isorce): investigate why |sources| is empty on the linux
     // bots while it is not on my workstation, as expected, with and without
     // the --ci parameter.
-    if (process.platform === 'linux' && sources.length === 0) {
+    if ((process.platform === 'linux' || process.platform === 'freebsd' ||
+          process.platform === 'openbsd' || process.platform === 'netbsd') && sources.length === 0) {
       it.skip('desktopCapturer.getSources returned an empty source list');
       return;
     }
@@ -207,7 +211,8 @@ ifdescribe(!process.arch.includes('arm')
       // TODO(julien.isorce): investigate why |sources| is empty on the linux
       // bots while it is not on my workstation, as expected, with and without
       // the --ci parameter.
-      if (process.platform === 'linux' && sources.length === 0) {
+      if ((process.platform === 'linux' || process.platform === 'freebsd' ||
+            process.platform === 'openbsd' || process.platform === 'netbsd') && sources.length === 0) {
         destroyWindows();
         it.skip('desktopCapturer.getSources returned an empty source list');
         return;
