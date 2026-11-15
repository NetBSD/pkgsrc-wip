$NetBSD$

* Add Free- and NetBSD support

--- ts/components/Preferences.dom.tsx.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/components/Preferences.dom.tsx
@@ -187,7 +187,7 @@ export type PropsDataType = {
   lastSyncTime?: number;
   notificationContent: NotificationSettingType;
   notifyWhileMuted: NotifyWhileMuted;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | 'netbsd' | undefined;
   phoneNumber: string | undefined;
   selectedCamera?: string;
   selectedMicrophone?: AudioDevice;
