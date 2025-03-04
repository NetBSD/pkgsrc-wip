$NetBSD$

* Add support to NetBSD and FreeBSD

--- extensions/emmet/src/test/testUtils.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ extensions/emmet/src/test/testUtils.ts
@@ -31,7 +31,7 @@ export function createRandomFile(content
 }
 
 export function pathEquals(path1: string, path2: string): boolean {
-	if (process.platform !== 'linux') {
+	if (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') {
 		path1 = path1.toLowerCase();
 		path2 = path2.toLowerCase();
 	}
