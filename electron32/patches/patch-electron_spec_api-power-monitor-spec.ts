$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-power-monitor-spec.ts.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/spec/api-power-monitor-spec.ts
@@ -18,7 +18,8 @@ import { ifdescribe, startRemoteControlA
 describe('powerMonitor', () => {
   let logindMock: any, dbusMockPowerMonitor: any, getCalls: any, emitSignal: any, reset: any;
 
-  ifdescribe(process.platform === 'linux' && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)('when powerMonitor module is loaded with dbus mock', () => {
+  ifdescribe((process.platform === 'linux' || process.platform === 'freebsd' ||
+                      process.platform === 'openbsd' || process.platform === 'netbsd') && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)('when powerMonitor module is loaded with dbus mock', () => {
     before(async () => {
       const systemBus = dbus.systemBus();
       const loginService = systemBus.getService('org.freedesktop.login1');
