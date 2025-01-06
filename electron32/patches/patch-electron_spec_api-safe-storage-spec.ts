$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-safe-storage-spec.ts.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/spec/api-safe-storage-spec.ts
@@ -29,7 +29,8 @@ describe('safeStorage module', () => {
 
 describe('safeStorage module', () => {
   before(() => {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd' ||
+         process.platform === 'openbsd' || process.platform === 'netbsd') {
       safeStorage.setUsePlainTextEncryption(true);
     }
   });
@@ -47,7 +48,8 @@ describe('safeStorage module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('SafeStorage.getSelectedStorageBackend()', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd' ||
+                     process.platform === 'openbsd' || process.platform === 'netbsd')('SafeStorage.getSelectedStorageBackend()', () => {
     it('should return a valid backend', () => {
       expect(safeStorage.getSelectedStorageBackend()).to.equal('basic_text');
     });
