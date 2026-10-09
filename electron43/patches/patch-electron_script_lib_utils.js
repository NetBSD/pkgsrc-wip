$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/script/lib/utils.js.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/script/lib/utils.js
@@ -20,7 +20,7 @@ function getElectronExec() {
       return `out/${OUT_DIR}/Electron.app/Contents/MacOS/Electron`;
     case 'win32':
       return `out/${OUT_DIR}/electron.exe`;
-    case 'linux':
+    case 'linux': case 'freebsd': case 'netbsd':
       return `out/${OUT_DIR}/electron`;
     default:
       throw new Error('Unknown platform');
