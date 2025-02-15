$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/fixtures/crash-cases/safe-storage/index.js.orig	2025-01-21 17:36:55.000000000 +0000
+++ electron/spec/fixtures/crash-cases/safe-storage/index.js
@@ -22,7 +22,8 @@ const { expect } = require('chai');
   await app.whenReady();
   // isEncryptionAvailable() will always return false on CI due to a mocked
   // dbus as mentioned above.
-  expect(safeStorage.isEncryptionAvailable()).to.equal(process.platform !== 'linux');
+  expect(safeStorage.isEncryptionAvailable()).to.equal(process.platform !== 'linux' && process.platform !== 'freebsd' &&
+                                                                                                 process.platform !== 'openbsd' && process.platform !== 'netbsd');
   if (safeStorage.isEncryptionAvailable()) {
     const plaintext = 'plaintext';
     const ciphertext = safeStorage.encryptString(plaintext);
