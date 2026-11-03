$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/lib/browser/init.ts.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/lib/browser/init.ts
@@ -132,7 +132,7 @@ if (packageJson.productName != null) {
   app.name = `${packageJson.name}`.trim();
 }
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
   const { defaultDesktopName } =
     require('@electron/internal/browser/desktop-name') as typeof import('@electron/internal/browser/desktop-name');
   app.setDesktopName(packageJson.desktopName || defaultDesktopName(app.name));
