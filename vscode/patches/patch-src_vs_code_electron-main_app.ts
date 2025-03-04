$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/code/electron-main/app.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ src/vs/code/electron-main/app.ts
@@ -1008,7 +1008,7 @@ export class CodeApplication extends Dis
 				services.set(IUpdateService, new SyncDescriptor(Win32UpdateService));
 				break;
 
-			case 'linux':
+			case 'linux': case 'freebsd': case 'netbsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
