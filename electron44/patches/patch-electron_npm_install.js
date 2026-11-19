$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/npm/install.js.orig	2026-11-18 22:25:18.000000000 +0000
+++ electron/npm/install.js
@@ -107,6 +107,7 @@ function getPlatformPath() {
     case 'darwin':
       return 'Electron.app/Contents/MacOS/Electron';
     case 'freebsd':
+    case 'netbsd':
     case 'openbsd':
     case 'linux':
       return 'electron';
