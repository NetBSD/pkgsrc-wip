$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/script/lib/utils.js.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/script/lib/utils.js
@@ -19,7 +19,7 @@ function getElectronExec () {
       return `out/${OUT_DIR}/Electron.app/Contents/MacOS/Electron`;
     case 'win32':
       return `out/${OUT_DIR}/electron.exe`;
-    case 'linux':
+    case 'linux': case 'freebsd': case 'openbsd': case 'netbsd':
       return `out/${OUT_DIR}/electron`;
     default:
       throw new Error('Unknown platform');
