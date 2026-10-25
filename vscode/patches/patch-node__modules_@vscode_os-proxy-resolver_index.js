$NetBSD$

* Use own os-proxy-resolver

--- node_modules/@vscode/os-proxy-resolver/index.js.orig	2026-10-24 14:52:34.731523761 +0000
+++ node_modules/@vscode/os-proxy-resolver/index.js
@@ -12,6 +12,10 @@ const packages = {
 	'linux-x64-musl': '@vscode/os-proxy-resolver-linux-x64-musl',
 	'win32-arm64': '@vscode/os-proxy-resolver-win32-arm64-msvc',
 	'win32-x64': '@vscode/os-proxy-resolver-win32-x64-msvc',
+	'freebsd-arm64': '@vscode/os-proxy-resolver-pkgsrc-arm64',
+	'freebsd-x64': '@vscode/os-proxy-resolver-pkgsrc-x64'
+	'netbsd-arm64': '@vscode/os-proxy-resolver-pkgsrc-arm64',
+	'netbsd-x64': '@vscode/os-proxy-resolver-pkgsrc-x64'
 };
 
 const platform = getPlatformPackage();
