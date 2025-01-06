$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/crash-spec.ts.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/spec/crash-spec.ts
@@ -47,7 +47,8 @@ const shouldRunCase = (crashCase: string
       if (process.platform === 'win32') {
         return process.arch !== 'ia32';
       } else {
-        return (process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm'));
+        return ((process.platform !== 'linux' && process.platform !== 'freebsd' &&
+                        process.platform !== 'openbsd' && process.platform !== 'netbsd') || (process.arch !== 'arm64' && process.arch !== 'arm'));
       }
     }
     default: {
