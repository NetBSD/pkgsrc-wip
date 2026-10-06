$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/lib/renderer/api/clipboard.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/lib/renderer/api/clipboard.ts
@@ -7,7 +7,7 @@ const makeRemoteMethod = function (metho
   return (...args: any[]) => ipcRendererUtils.invokeSync(IPC_MESSAGES.BROWSER_CLIPBOARD_SYNC, method, ...args);
 };
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
   // On Linux we could not access clipboard in renderer process.
   for (const method of Object.keys(clipboard) as (keyof Electron.Clipboard)[]) {
     clipboard[method] = makeRemoteMethod(method);
