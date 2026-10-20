$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/lib/browser/api/power-monitor.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/lib/browser/api/power-monitor.ts
@@ -18,7 +18,7 @@ class PowerMonitor extends EventEmitter 
       pm = createPowerMonitor();
       pm.emit = this.emit.bind(this);
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
         // On Linux, we inhibit shutdown in order to give the app a chance to
         // decide whether or not it wants to prevent the shutdown. We don't
         // inhibit the shutdown event unless there's a listener for it. This
