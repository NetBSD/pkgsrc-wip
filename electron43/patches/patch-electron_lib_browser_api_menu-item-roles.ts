$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/lib/browser/api/menu-item-roles.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/lib/browser/api/menu-item-roles.ts
@@ -3,7 +3,7 @@ import type { WebContents, MenuItemConst
 
 const isMac = process.platform === 'darwin';
 const isWindows = process.platform === 'win32';
-const isLinux = process.platform === 'linux';
+const isLinux = (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd');
 
 type RoleId =
   | 'about'
