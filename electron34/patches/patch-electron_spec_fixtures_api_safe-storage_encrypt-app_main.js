$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/fixtures/api/safe-storage/encrypt-app/main.js.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/spec/fixtures/api/safe-storage/encrypt-app/main.js
@@ -7,7 +7,7 @@ const pathToEncryptedString = path.resol
 const writeFile = fs.writeFile;
 
 app.whenReady().then(async () => {
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
     safeStorage.setUsePlainTextEncryption(true);
   }
   const encrypted = safeStorage.encryptString('plaintext');
