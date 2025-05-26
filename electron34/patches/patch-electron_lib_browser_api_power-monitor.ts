$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/lib/browser/api/power-monitor.ts.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/lib/browser/api/power-monitor.ts
@@ -17,7 +17,7 @@ class PowerMonitor extends EventEmitter 
       const pm = createPowerMonitor();
       pm.emit = this.emit.bind(this);
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
         // On Linux, we inhibit shutdown in order to give the app a chance to
         // decide whether or not it wants to prevent the shutdown. We don't
         // inhibit the shutdown event unless there's a listener for it. This
