$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/default_app/default_app.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/default_app/default_app.ts
@@ -94,7 +94,7 @@ async function createWindow(backgroundCo
     show: false
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
     options.icon = url.fileURLToPath(new URL('icon.png', import.meta.url));
   }
 
