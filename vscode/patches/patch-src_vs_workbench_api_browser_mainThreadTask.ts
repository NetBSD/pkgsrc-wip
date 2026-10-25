$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -727,6 +727,8 @@ export class MainThreadTask extends Disp
 				platform = Platform.Platform.Mac;
 				break;
 			case 'linux':
+			case 'freebsd':
+			case 'netbsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
