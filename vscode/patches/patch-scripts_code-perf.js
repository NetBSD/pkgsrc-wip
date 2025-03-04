$NetBSD$

* Add support to NetBSD and FreeBSD

--- scripts/code-perf.js.orig	2025-02-10 13:07:56.000000000 +0000
+++ scripts/code-perf.js
@@ -65,7 +65,7 @@ function getExePath(buildPath) {
 		case 'darwin':
 			relativeExePath = path.join('Contents', 'MacOS', 'Electron');
 			break;
-		case 'linux': {
+		case 'linux': case 'freebsd': case 'netbsd': {
 			const product = require(path.join(buildPath, 'resources', 'app', 'product.json'));
 			relativeExePath = product.applicationName;
 			break;
