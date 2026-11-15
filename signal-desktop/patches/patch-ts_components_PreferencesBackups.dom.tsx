$NetBSD$

* Add Free- and NetBSD support

--- ts/components/PreferencesBackups.dom.tsx.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/components/PreferencesBackups.dom.tsx
@@ -95,7 +95,7 @@ export function PreferencesBackups({
   locale: string;
   onBackupKeyViewed: ({ backupKeyHash }: { backupKeyHash: string }) => void;
   openFileInFolder: (path: string) => void;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | 'netbsd' | undefined;
   settingsLocation: SettingsLocation;
   backupMediaDownloadStatus: BackupMediaDownloadStatusType | undefined;
   cancelBackupMediaDownload: () => void;
