$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/asar.spec.ts.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/spec/asar.spec.ts
@@ -749,7 +749,7 @@ describe('asar package', () => {
         expect(code).toBe(0);
       });
 
-      ifit(process.platform === 'linux')(
+      ifit(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')(
         'starts an app from an archive under a non-ASCII directory with LC_ALL=C',
         async () => {
           const app = j(tmp, unicodeDir, 'main-app.asar');
