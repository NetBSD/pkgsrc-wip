$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-safe-storage.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/api-safe-storage.spec.ts
@@ -15,7 +15,7 @@ chai.use(chaiAsPromised);
 
 describe('safeStorage module', () => {
   before(() => {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
       safeStorage.setUsePlainTextEncryption(true);
     }
   });
@@ -33,7 +33,7 @@ describe('safeStorage module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('SafeStorage.getSelectedStorageBackend()', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')('SafeStorage.getSelectedStorageBackend()', () => {
     it('should return a valid backend', () => {
       expect(safeStorage.getSelectedStorageBackend()).to.equal('basic_text');
     });
