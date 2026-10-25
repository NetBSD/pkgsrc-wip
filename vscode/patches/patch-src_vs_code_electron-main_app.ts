$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/code/electron-main/app.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ src/vs/code/electron-main/app.ts
@@ -1227,6 +1227,8 @@ export class CodeApplication extends Dis
 				break;
 
 			case 'linux':
+			case 'freebsd':
+			case 'netbsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
