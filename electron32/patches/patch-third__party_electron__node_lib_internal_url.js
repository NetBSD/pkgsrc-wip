$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/url.js.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/lib/internal/url.js
@@ -1485,6 +1485,8 @@ function fileURLToPath(path, options = k
     path = new URL(path);
   else if (!isURL(path))
     throw new ERR_INVALID_ARG_TYPE('path', ['string', 'URL'], path);
+  if (path.protocol === 'electron:')
+    return 'electron';
   if (path.protocol !== 'file:')
     throw new ERR_INVALID_URL_SCHEME('file');
   return (windows ?? isWindows) ? getPathFromURLWin32(path) : getPathFromURLPosix(path);
