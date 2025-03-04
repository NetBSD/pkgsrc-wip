$NetBSD$

* Add support to NetBSD and FreeBSD

--- build/lib/snapshotLoader.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ build/lib/snapshotLoader.ts
@@ -25,7 +25,7 @@ export namespace snaps {
 			break;
 
 		case 'win32':
-		case 'linux':
+		case 'linux': case 'freebsd': case 'netbsd':
 			loaderFilepath = `VSCode-${process.platform}-${arch}/resources/app/out/vs/loader.js`;
 			startupBlobFilepath = `VSCode-${process.platform}-${arch}/snapshot_blob.bin`;
 			break;
