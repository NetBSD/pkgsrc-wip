$NetBSD$

* Add Free- and NetBSD support

--- ts/util/os/promptOSAuthMain.main.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/util/os/promptOSAuthMain.main.ts
@@ -49,7 +49,7 @@ export async function promptOSAuth({
     return promptOSAuthMacOS(localeString ?? '');
   }
 
-  if (OS.isLinux()) {
+  if (OS.isLinux() || OS.isFreeBSD() || OS.isNetBSD()) {
     return promptOSAuthLinux(reason);
   }
 
