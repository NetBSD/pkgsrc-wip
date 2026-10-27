$NetBSD$

* Add NetBSD support

--- node_modules/@vscode/deviceid/dist/storage.js.orig	2026-10-26 17:06:28.000000000 +0000
+++ node_modules/@vscode/deviceid/dist/storage.js
@@ -42,7 +42,7 @@ function getDirectory() {
     if (process.platform === "darwin") {
         folder = path.join(process.env.HOME, "Library", "Application Support");
     }
-    else if (process.platform === "linux" || process.platform === "freebsd") {
+    else if (process.platform === "linux" || process.platform === "freebsd" || process.platform === "netbsd") {
         folder =
             process.env.XDG_CACHE_HOME ?? path.join(process.env.HOME, ".cache");
     }
@@ -105,4 +105,4 @@ async function setDeviceId(deviceId) {
     }
 }
 exports.setDeviceId = setDeviceId;
-//# sourceMappingURL=storage.js.map
\ No newline at end of file
+//# sourceMappingURL=storage.js.map
