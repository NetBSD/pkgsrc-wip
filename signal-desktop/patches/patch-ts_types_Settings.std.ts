$NetBSD$

* Add Free- and NetBSD support

--- ts/types/Settings.std.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/types/Settings.std.ts
@@ -24,7 +24,7 @@ export const isDrawAttentionSupported = 
  * option with a command line flag, but that is not officially supported.
  */
 export const isSystemTraySupported = (OS: OSType): boolean =>
-  OS.isWindows() || OS.isLinux();
+  OS.isWindows() || OS.isLinux() || OS.isFreeBSD() || OS.isNetBSD();
 
 export const isContentProtectionSupported = (OS: OSType): boolean =>
   OS.isWindows();
@@ -42,7 +42,7 @@ export const getDefaultSystemTraySetting
 
   // System tray on linux may not be well supported, so we default to it being off in
   // production
-  if (OS.isLinux() && isProduction(appVersion)) {
+  if ((OS.isLinux() || OS.isFreeBSD() || OS.isNetBSD()) && isProduction(appVersion)) {
     return SystemTraySetting.DoNotUseSystemTray;
   }
 
