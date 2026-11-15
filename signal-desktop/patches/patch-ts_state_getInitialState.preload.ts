$NetBSD$

* Add Free- and NetBSD support

--- ts/state/getInitialState.preload.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/state/getInitialState.preload.ts
@@ -212,7 +212,7 @@ function generateUserState({
     window.ConversationController.getOurConversationId();
   const ourDeviceId = itemStorage.user.getDeviceId();
 
-  let osName: 'windows' | 'macos' | 'linux' | undefined;
+  let osName: 'windows' | 'macos' | 'linux' | 'freebsd' | 'netbsd' | undefined;
 
   if (OS.isWindows()) {
     osName = 'windows';
@@ -220,6 +220,10 @@ function generateUserState({
     osName = 'macos';
   } else if (OS.isLinux()) {
     osName = 'linux';
+  } else if (OS.isFreeBSD()) {
+    osName = 'freebsd';
+  } else if (OS.isNetBSD()) {
+    osName = 'netbsd';
   }
 
   return {
