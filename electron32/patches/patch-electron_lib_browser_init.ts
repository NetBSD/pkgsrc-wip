$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/lib/browser/init.ts.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/lib/browser/init.ts
@@ -162,7 +162,8 @@ const mainStartupScript = packageJson.ma
 const KNOWN_XDG_DESKTOP_VALUES = new Set(['Pantheon', 'Unity:Unity7', 'pop:GNOME']);
 
 function currentPlatformSupportsAppIndicator () {
-  if (process.platform !== 'linux') return false;
+  if (process.platform !== 'linux' && process.platform !== 'freebsd' &&
+       process.platform !== 'openbsd' && process.platform !== 'netbsd') return false;
   const currentDesktop = process.env.XDG_CURRENT_DESKTOP;
 
   if (!currentDesktop) return false;
