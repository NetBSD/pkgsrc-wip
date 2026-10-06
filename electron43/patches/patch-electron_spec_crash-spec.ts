$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/crash-spec.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/spec/crash-spec.ts
@@ -52,7 +52,7 @@ const shouldRunCase = (crashCase: string
       if (process.platform === 'win32') {
         return process.arch !== 'ia32';
       } else {
-        return (process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm'));
+        return ((process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') || (process.arch !== 'arm64' && process.arch !== 'arm'));
       }
     }
     default: {
