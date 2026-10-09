$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-power-monitor.spec.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/spec/api-power-monitor.spec.ts
@@ -21,7 +21,7 @@ const require = createRequire(import.met
 describe('powerMonitor', { tags: ['serial'] }, () => {
   let logindMock: any, dbusMockPowerMonitor: any, getCalls: any, emitSignal: any, reset: any;
 
-  ifdescribe(process.platform === 'linux' && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)(
+  ifdescribe((process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)(
     'when powerMonitor module is loaded with dbus mock',
     () => {
       before(async () => {
