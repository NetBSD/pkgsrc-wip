$NetBSD$

* Add Free- and NetBSD support

--- ts/components/PreferencesLocalBackups.dom.tsx.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/components/PreferencesLocalBackups.dom.tsx
@@ -72,7 +72,7 @@ export function PreferencesLocalBackups(
   localBackupFolder: string | undefined;
   onBackupKeyViewed: ({ backupKeyHash }: { backupKeyHash: string }) => void;
   openFileInFolder: (path: string) => void;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | 'netbsd' | undefined;
   settingsLocation: SettingsLocation;
   pickLocalBackupFolder: () => Promise<string | undefined>;
   previouslyViewedBackupKeyHash: string | undefined;
@@ -185,7 +185,7 @@ export function PreferencesLocalBackups(
     showInFolderText = i18n(
       'icu:PlaintextExport--CompleteDialog--ShowFiles--Mac'
     );
-  } else if (osName === 'linux') {
+  } else if (osName === 'linux' || osName === 'freebsd' || osName === 'netbsd') {
     showInFolderText = i18n(
       'icu:PlaintextExport--CompleteDialog--ShowFiles--Linux'
     );
