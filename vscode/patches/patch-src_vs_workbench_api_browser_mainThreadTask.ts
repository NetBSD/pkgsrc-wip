$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -678,7 +678,7 @@ export class MainThreadTask extends Disp
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd': case 'netbsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
