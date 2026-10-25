$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1278,7 +1278,11 @@ class CommandsTableRenderer extends Disp
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+			case 'netbsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
