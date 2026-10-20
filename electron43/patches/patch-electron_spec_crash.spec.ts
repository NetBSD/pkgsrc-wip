$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/crash.spec.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/spec/crash.spec.ts
@@ -54,7 +54,7 @@ const shouldRunCase = (crashCase: string
       if (process.platform === 'win32') {
         return process.arch !== 'ia32';
       } else {
-        return process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm');
+        return (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') || (process.arch !== 'arm64' && process.arch !== 'arm');
       }
     }
     default: {
