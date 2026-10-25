$NetBSD$

* Add support to NetBSD and FreeBSD

--- extensions/microsoft-authentication/esbuild.mts.orig	2026-10-24 16:08:35.415172524 +0000
+++ extensions/microsoft-authentication/esbuild.mts
@@ -21,6 +21,8 @@ switch (process.platform) {
 	case 'win32': platformFolder = 'windows'; break;
 	case 'darwin': platformFolder = 'macos'; break;
 	case 'linux': platformFolder = 'linux'; break;
+	case 'freebsd': platformFolder = 'freebsd'; break
+	case 'netbsd': platformFolder = 'netbsd'; break
 	default: throw new Error(`Unsupported platform: ${process.platform}`);
 }
 
