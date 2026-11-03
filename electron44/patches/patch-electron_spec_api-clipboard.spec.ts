$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-clipboard.spec.ts.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/spec/api-clipboard.spec.ts
@@ -149,7 +149,7 @@ describe('clipboard module', { tags: ['s
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('reading bookmarks via clipboard.read()', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('reading bookmarks via clipboard.read()', () => {
     it('returns title and url via the electron application/bookmark MIME type', async () => {
       await clipboard.write([
         new ClipboardItem({
@@ -176,7 +176,7 @@ describe('clipboard module', { tags: ['s
   });
 
   describe('clipboard.read()', () => {
-    ifit(process.platform !== 'linux')('does not crash when reading various custom clipboard types', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('does not crash when reading various custom clipboard types', async () => {
       const rawFormat = process.platform === 'darwin' ? 'NSFilenamesPboardType' : 'FileNameW';
       // Raw platform formats with no standard MIME mapping are surfaced
       // under the `electron application/osclipboard;format="..."` MIME.
@@ -235,7 +235,7 @@ describe('clipboard module', { tags: ['s
       const readImage = nativeImage.createFromBuffer(imageBuffer!);
       expect(readImage.toDataURL()).toBe(i.toDataURL());
 
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') {
         const readBookmarkValue = await readBookmark();
         expect(readBookmarkValue).toBeTypeOf('object');
         if (process.platform !== 'win32') {
@@ -486,7 +486,7 @@ describe('clipboard module', { tags: ['s
   // but operates against a *separate* system buffer, so writes to the
   // selection clipboard must not affect the regular system clipboard and
   // vice-versa.
-  ifdescribe(process.platform === 'linux')('clipboard.selection (Linux)', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')('clipboard.selection (Linux)', () => {
     it('exposes a selection namespace mirroring the top-level surface', () => {
       expect(clipboard.selection).toBeTypeOf('object');
       expect(clipboard.selection!.read).toBeTypeOf('function');
@@ -543,7 +543,7 @@ describe('clipboard module', { tags: ['s
     });
   });
 
-  ifit(process.platform !== 'linux')('does not expose clipboard.selection off Linux', () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('does not expose clipboard.selection off Linux', () => {
     expect(clipboard.selection).toBeUndefined();
   });
 });
