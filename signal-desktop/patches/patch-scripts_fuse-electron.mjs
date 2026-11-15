$NetBSD$

* Add Free- and NetBSD support

--- scripts/fuse-electron.mjs.orig	2026-10-28 21:49:13.000000000 +0000
+++ scripts/fuse-electron.mjs
@@ -18,7 +18,7 @@ export async function afterPack({ appOut
     target = `${productFilename}.app`;
   } else if (electronPlatformName === 'win32') {
     target = `${productFilename}.exe`;
-  } else if (electronPlatformName === 'linux') {
+  } else if (electronPlatformName === 'linux' || electronPlatformName === 'freebsd' || electronPlatformName === 'netbsd') {
     target = /** @type {LinuxPackager} */ (packager).executableName;
   } else {
     throw new Error(`Unsupported platform: ${electronPlatformName}`);
