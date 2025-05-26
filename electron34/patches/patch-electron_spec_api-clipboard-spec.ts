$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-clipboard-spec.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/spec/api-clipboard-spec.ts
@@ -54,7 +54,7 @@ ifdescribe(process.platform !== 'win32' 
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('clipboard.readBookmark', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('clipboard.readBookmark', () => {
     it('returns title and url', () => {
       clipboard.writeBookmark('a title', 'https://electronjs.org');
 
@@ -73,7 +73,7 @@ ifdescribe(process.platform !== 'win32' 
   });
 
   describe('clipboard.read()', () => {
-    ifit(process.platform !== 'linux')('does not crash when reading various custom clipboard types', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('does not crash when reading various custom clipboard types', () => {
       const type = process.platform === 'darwin' ? 'NSFilenamesPboardType' : 'FileNameW';
 
       expect(() => {
@@ -114,7 +114,7 @@ ifdescribe(process.platform !== 'win32' 
       const readImage = clipboard.readImage();
       expect(readImage.toDataURL()).to.equal(i.toDataURL());
 
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') {
         if (process.platform !== 'win32') {
           expect(clipboard.readBookmark()).to.deep.equal(bookmark);
         } else {
