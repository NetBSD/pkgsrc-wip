$NetBSD$

* Add Free- and NetBSD support

--- scripts/copy-language-packs.mjs.orig	2026-10-28 21:49:13.000000000 +0000
+++ scripts/copy-language-packs.mjs
@@ -42,6 +42,8 @@ export async function afterPack({ appOut
     );
   } else if (
     electronPlatformName === 'linux' ||
+    electronPlatformName === 'freebsd' ||
+    electronPlatformName === 'netbsd' ||
     electronPlatformName === 'win32'
   ) {
     // Shared between windows and linux
