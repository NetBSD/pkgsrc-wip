$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-menu.spec.ts.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/spec/api-menu.spec.ts
@@ -1007,7 +1007,7 @@ describe('Menu module', () => {
     // https://github.com/electron/electron/issues/35724
     // Maximizing window is enough to trigger the bug
     // FIXME(dsanders11): Test always passes on CI, even pre-fix
-    ifit(process.platform === 'linux' && !process.env.CI)(
+    ifit((process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') && !process.env.CI)(
       'does not trigger issue #35724',
       () =>
         new Promise<void>((resolve, reject) => {
