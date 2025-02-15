$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/default_app/default_app.ts.orig	2025-01-21 17:36:55.000000000 +0000
+++ electron/default_app/default_app.ts
@@ -61,7 +61,8 @@ async function createWindow (backgroundC
     show: false
   };
 
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd' ||
+       process.platform === 'openbsd' || process.platform === 'netbsd' ) {
     options.icon = url.fileURLToPath(new URL('icon.png', import.meta.url));
   }
 
