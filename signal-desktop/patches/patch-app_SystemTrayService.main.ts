$NetBSD$

* Add Free- and NetBSD support

--- app/SystemTrayService.main.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ app/SystemTrayService.main.ts
@@ -310,7 +310,7 @@ function getIcon(unreadCount: number) {
 
   let image: NativeImage;
 
-  if (platform === 'linux') {
+  if (platform === 'linux' || platform === 'freebsd' || platform === 'netbsd') {
     // Linux: Static tray icons
     // Use a single tray icon for Linux, as it does not support scale factors.
     // We choose the best icon based on the highest display scale factor.
