$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/spec/api-notification-dbus.spec.ts.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/spec/api-notification-dbus.spec.ts
@@ -23,7 +23,7 @@ const require = createRequire(import.met
 
 const fixturesPath = path.join(import.meta.dirname, 'fixtures');
 
-const skip = process.platform !== 'linux' || !process.env.DBUS_SESSION_BUS_ADDRESS;
+const skip = (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') || !process.env.DBUS_SESSION_BUS_ADDRESS;
 
 ifdescribe(!skip)('Notification module (dbus)', { tags: ['serial'] }, () => {
   let mock: any, Notification: any, getCalls: any, emitSignal: any, reset: any;
