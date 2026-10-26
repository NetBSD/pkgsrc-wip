$NetBSD$

* Add NetBSD and FreeBSD support

--- test/automation/src/electron.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ test/automation/src/electron.ts
@@ -155,6 +155,8 @@ export function getDevElectronPath(): st
 		case 'darwin':
 			return join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', `${product.nameShort}`);
 		case 'linux':
+		case 'freebsd':
+		case 'netbsd':
 			return join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -179,7 +181,9 @@ export function getBuildElectronPath(roo
 				return join(root, 'Contents', 'MacOS', product.nameShort);
 			}
 		}
-		case 'linux': {
+		case 'linux':
+		case 'freebsd':
+		case 'netbsd': {
 			const product = require(join(root, 'resources', 'app', 'product.json'));
 			return join(root, product.applicationName);
 		}
