$NetBSD$

* Add support to NetBSD and FreeBSD

--- node_modules/playwright/node_modules/playwright-core/lib/serverRegistry.js.orig	2026-10-24 14:36:35.000000000 +0000
+++ node_modules/playwright/node_modules/playwright-core/lib/serverRegistry.js
@@ -7277,7 +7277,7 @@ async function canConnectTo(descriptor) 
   });
 }
 var defaultCacheDirectory = (() => {
-  if (process.platform === "linux")
+  if (process.platform === "linux" || process.platform === "freebsd" || process.platform === "netbsd")
     return process.env.XDG_CACHE_HOME || import_path2.default.join(import_os.default.homedir(), ".cache");
   if (process.platform === "darwin")
     return import_path2.default.join(import_os.default.homedir(), "Library", "Caches");
