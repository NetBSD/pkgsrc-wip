$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/platform/environment/node/userDataPath.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ src/vs/platform/environment/node/userDataPath.ts
@@ -96,6 +96,8 @@ export function getDefaultUserDataPath(p
 			appDataPath = join(homedir(), 'Library', 'Application Support');
 			break;
 		case 'linux':
+		case 'freebsd':
+		case 'netbsd':
 			appDataPath = process.env['XDG_CONFIG_HOME'] || join(homedir(), '.config');
 			break;
 		default:
