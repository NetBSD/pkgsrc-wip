$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-tray-spec.ts.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/spec/api-tray-spec.ts
@@ -131,7 +131,8 @@ describe('tray module', () => {
   describe('tray.getBounds()', () => {
     afterEach(() => { tray.destroy(); });
 
-    ifit(process.platform !== 'linux')('returns a bounds object', function () {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd' &&
+          process.platform !== 'openbsd' && process.platform !== 'netbsd')('returns a bounds object', function () {
       const bounds = tray.getBounds();
       expect(bounds).to.be.an('object').and.to.have.all.keys('x', 'y', 'width', 'height');
     });
