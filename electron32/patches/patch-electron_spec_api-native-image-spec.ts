$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-native-image-spec.ts.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/spec/api-native-image-spec.ts
@@ -428,7 +428,8 @@ describe('nativeImage module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('createThumbnailFromPath(path, size)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' &&
+                     process.platform !== 'openbsd' && process.platform !== 'netbsd')('createThumbnailFromPath(path, size)', () => {
     useRemoteContext({ webPreferences: { contextIsolation: false, nodeIntegration: true } });
 
     it('throws when invalid size is passed', async () => {
