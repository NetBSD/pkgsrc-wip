$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/crash.spec.ts.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/spec/crash.spec.ts
@@ -47,7 +47,7 @@ const shouldRunCase = (crashCase: string
   switch (crashCase) {
     // TODO(jkleinsc) fix this test on Linux on arm64
     case 'js-execute-iframe': {
-      return process.platform !== 'linux' || process.arch !== 'arm64';
+      return (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') || process.arch !== 'arm64';
     }
     default: {
       return true;
