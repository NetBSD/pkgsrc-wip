$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-safe-storage-spec.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/spec/api-safe-storage-spec.ts
@@ -29,7 +29,7 @@ describe('safeStorage module', () => {
 
 describe('safeStorage module', () => {
   before(() => {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
       safeStorage.setUsePlainTextEncryption(true);
     }
   });
@@ -47,7 +47,7 @@ describe('safeStorage module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('SafeStorage.getSelectedStorageBackend()', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')('SafeStorage.getSelectedStorageBackend()', () => {
     it('should return a valid backend', () => {
       expect(safeStorage.getSelectedStorageBackend()).to.equal('basic_text');
     });
