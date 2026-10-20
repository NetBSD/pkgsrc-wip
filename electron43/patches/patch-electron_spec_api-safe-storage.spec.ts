$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-safe-storage.spec.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/spec/api-safe-storage.spec.ts
@@ -11,7 +11,7 @@ import { ifdescribe } from './lib/spec-h
 
 describe('safeStorage module', () => {
   beforeAll(() => {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
       safeStorage.setUsePlainTextEncryption(true);
     }
   });
@@ -29,7 +29,7 @@ describe('safeStorage module', () => {
     });
   });
 
-  ifdescribe(process.platform === 'linux')('SafeStorage.getSelectedStorageBackend()', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')('SafeStorage.getSelectedStorageBackend()', () => {
     it('should return a valid backend', () => {
       expect(safeStorage.getSelectedStorageBackend()).toBe('basic_text');
     });
