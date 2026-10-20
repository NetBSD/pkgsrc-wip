$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/lib/renderer/security-warnings.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/lib/renderer/security-warnings.ts
@@ -25,6 +25,7 @@ const shouldLogSecurityWarnings = functi
       shouldLog = execPath.endsWith('MacOS/Electron') || execPath.includes('Electron.app/Contents/Frameworks/');
       break;
     case 'freebsd':
+    case 'netbsd':
     case 'linux':
       shouldLog = execPath.endsWith('/electron');
       break;
