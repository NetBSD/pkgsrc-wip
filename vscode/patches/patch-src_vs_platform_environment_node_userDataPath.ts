$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/platform/environment/node/userDataPath.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ src/vs/platform/environment/node/userDataPath.ts
@@ -76,7 +76,7 @@ function doGetUserDataPath(cliArgs: Nati
 		case 'darwin':
 			appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 			break;
-		case 'linux':
+		case 'linux': case 'freebsd': case 'netbsd':
 			appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 			break;
 		default:
