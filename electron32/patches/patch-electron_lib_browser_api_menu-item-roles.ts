$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/lib/browser/api/menu-item-roles.ts.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/lib/browser/api/menu-item-roles.ts
@@ -2,7 +2,8 @@ import { app, BaseWindow, BrowserWindow,
 
 const isMac = process.platform === 'darwin';
 const isWindows = process.platform === 'win32';
-const isLinux = process.platform === 'linux';
+const isLinux = (process.platform === 'linux' || process.platform === 'freebsd' ||
+                              process.platform === 'openbsd' || process.platform === 'netbsd');
 
 type RoleId = 'about' | 'close' | 'copy' | 'cut' | 'delete' | 'forcereload' | 'front' | 'help' | 'hide' | 'hideothers' | 'minimize' |
   'paste' | 'pasteandmatchstyle' | 'quit' | 'redo' | 'reload' | 'resetzoom' | 'selectall' | 'services' | 'recentdocuments' | 'clearrecentdocuments' |
