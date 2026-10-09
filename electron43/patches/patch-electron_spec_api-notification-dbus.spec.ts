$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-notification-dbus.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/api-notification-dbus.spec.ts
@@ -24,7 +24,7 @@ const require = createRequire(import.met
 const fixturesPath = path.join(import.meta.dirname, 'fixtures');
 
 const skip =
-  process.platform !== 'linux' ||
+  (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') ||
   process.arch === 'ia32' ||
   process.arch.indexOf('arm') === 0 ||
   !process.env.DBUS_SESSION_BUS_ADDRESS;
