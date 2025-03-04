$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1141,7 +1141,7 @@ class CommandsTableRenderer extends Disp
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':  case 'freebsd': case 'netbsd': key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
