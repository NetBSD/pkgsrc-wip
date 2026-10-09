$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/crash.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/crash.spec.ts
@@ -53,7 +53,7 @@ const shouldRunCase = (crashCase: string
       if (process.platform === 'win32') {
         return process.arch !== 'ia32';
       } else {
-        return process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm');
+        return (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') || (process.arch !== 'arm64' && process.arch !== 'arm');
       }
     }
     default: {
