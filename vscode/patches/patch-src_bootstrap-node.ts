$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/bootstrap-node.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ src/bootstrap-node.ts
@@ -227,7 +227,7 @@ export function configurePortable(produc
 			return process.env['VSCODE_PORTABLE'];
 		}
 
-		if (process.platform === 'win32' || process.platform === 'linux') {
+		if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
 			return path.join(getApplicationPath(), 'data');
 		}
 
