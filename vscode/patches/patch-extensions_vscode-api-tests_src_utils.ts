$NetBSD$

* Add support to NetBSD and FreeBSD

--- extensions/vscode-api-tests/src/utils.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ extensions/vscode-api-tests/src/utils.ts
@@ -38,7 +38,7 @@ export async function deleteFile(file: v
 }
 
 export function pathEquals(path1: string, path2: string): boolean {
-	if (process.platform !== 'linux') {
+	if (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') {
 		path1 = path1.toLowerCase();
 		path2 = path2.toLowerCase();
 	}
