$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/lib/browser/api/menu-item-roles.ts.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/lib/browser/api/menu-item-roles.ts
@@ -3,7 +3,7 @@ import type { WebContents, MenuItemConst
 
 const isMac = process.platform === 'darwin';
 const isWindows = process.platform === 'win32';
-const isLinux = process.platform === 'linux';
+const isLinux = (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd');
 
 type RoleId =
   | 'about'
