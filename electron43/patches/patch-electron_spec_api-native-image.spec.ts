$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-native-image.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/api-native-image.spec.ts
@@ -570,7 +570,7 @@ describe('nativeImage module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('createThumbnailFromPath(path, size)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd')('createThumbnailFromPath(path, size)', () => {
     useRemoteContext({ webPreferences: { contextIsolation: false, nodeIntegration: true } });
 
     it('throws when invalid size is passed', async () => {
