$NetBSD$

* Add NetBSD support

--- node_modules/.pnpm/@vscode+deviceid@0.1.5/node_modules/@vscode/deviceid/dist/index.js.orig	2026-11-24 11:16:04.361625513 +0000
+++ node_modules/.pnpm/@vscode+deviceid@0.1.5/node_modules/@vscode/deviceid/dist/index.js
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
