$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/lib/renderer/api/clipboard.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/lib/renderer/api/clipboard.ts
@@ -27,7 +27,7 @@ const makeRemoteMethod = function (metho
   };
 };
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
   // On Linux we could not access clipboard in renderer process.
   for (const method of Object.keys(originalClipboard) as (keyof Electron.Clipboard)[]) {
     clipboard[method] = makeRemoteMethod(method);
