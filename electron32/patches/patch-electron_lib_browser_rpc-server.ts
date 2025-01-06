$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/lib/browser/rpc-server.ts.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/lib/browser/rpc-server.ts
@@ -28,7 +28,7 @@ const allowedClipboardMethods = (() => {
   switch (process.platform) {
     case 'darwin':
       return new Set(['readFindText', 'writeFindText']);
-    case 'linux':
+    case 'linux': case 'freebsd': case 'openbsd': case 'netbsd':
       return new Set(Object.keys(clipboard));
     default:
       return new Set();
