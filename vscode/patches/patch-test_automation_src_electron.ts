$NetBSD$

* Add support to NetBSD and FreeBSD

--- test/automation/src/electron.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ test/automation/src/electron.ts
@@ -103,7 +103,7 @@ export function getDevElectronPath(): st
 	switch (process.platform) {
 		case 'darwin':
 			return join(buildPath, 'electron', `${product.nameLong}.app`, 'Contents', 'MacOS', 'Electron');
-		case 'linux':
+		case 'linux': case 'freebsd': case 'netbsd':
 			return join(buildPath, 'electron', `${product.applicationName}`);
 		case 'win32':
 			return join(buildPath, 'electron', `${product.nameShort}.exe`);
@@ -116,7 +116,7 @@ export function getBuildElectronPath(roo
 	switch (process.platform) {
 		case 'darwin':
 			return join(root, 'Contents', 'MacOS', 'Electron');
-		case 'linux': {
+		case 'linux': case 'freebsd': case 'netbsd': {
 			const product = require(join(root, 'resources', 'app', 'product.json'));
 			return join(root, product.applicationName);
 		}
