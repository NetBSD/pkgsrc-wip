$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/lib/browser/rpc-server.ts.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/lib/browser/rpc-server.ts
@@ -36,7 +36,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd': case 'netbsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
