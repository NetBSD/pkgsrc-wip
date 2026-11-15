$NetBSD$

* Add Free- and NetBSD support

--- ts/state/ducks/user.preload.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/state/ducks/user.preload.ts
@@ -23,7 +23,7 @@ export type UserStateType = Readonly<{
   isMainWindowMaximized: boolean;
   localeMessages: LocaleMessagesType;
   menuOptions: MenuOptionsType;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | 'netbsd' | undefined;
   ourAci: AciString | undefined;
   ourConversationId: string | undefined;
   ourDeviceId: number | undefined;
@@ -113,7 +113,7 @@ const intlNotSetup = () => {
 // Reducer
 
 export function getEmptyState(): UserStateType {
-  let osName: 'windows' | 'macos' | 'linux' | undefined;
+  let osName: 'windows' | 'macos' | 'linux' | 'freebsd' | 'netbsd' | undefined;
 
   if (OS.isWindows()) {
     osName = 'windows';
@@ -121,6 +121,10 @@ export function getEmptyState(): UserSta
     osName = 'macos';
   } else if (OS.isLinux()) {
     osName = 'linux';
+  } else if (OS.isFreeBSD()) {
+    osName = 'freebsd';
+  } else if (OS.isNetBSD()) {
+    osName = 'netbsd';
   }
 
   return {
