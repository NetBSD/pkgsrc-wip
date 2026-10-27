$NetBSD$

* Add NetBSD support

--- node_modules/@vscode/deviceid/dist/index.js.orig	2026-10-26 16:27:50.827844574 +0000
+++ node_modules/@vscode/deviceid/dist/index.js
@@ -21,7 +21,8 @@ Object.defineProperty(exports, "__esModu
 if (process.platform !== "win32" &&
     process.platform !== "darwin" &&
     process.platform !== "linux" &&
-    process.platform !== "freebsd") {
+    process.platform !== "freebsd" &&
+    process.platform !== "netbsd") {
     throw new Error("Unsupported platform");
 }
 __exportStar(require("./devdeviceid.js"), exports);
