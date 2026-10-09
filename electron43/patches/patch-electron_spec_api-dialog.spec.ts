$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-dialog.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/api-dialog.spec.ts
@@ -1046,7 +1046,7 @@ describe('dialog module', () => {
   // FileChooser that script/dbus_mock.py hosts on the fake session bus. The
   // mock records each request and auto-cancels the dialog.
   ifdescribe(
-    process.platform === 'linux' &&
+    (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') &&
       process.arch !== 'ia32' &&
       !process.arch.startsWith('arm') &&
       !!process.env.DBUS_SESSION_BUS_ADDRESS
