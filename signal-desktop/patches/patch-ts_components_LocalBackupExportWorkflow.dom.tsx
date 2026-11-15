$NetBSD$

* Add Free- and NetBSD support

--- ts/components/LocalBackupExportWorkflow.dom.tsx.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/components/LocalBackupExportWorkflow.dom.tsx
@@ -23,7 +23,7 @@ export type PropsType = {
   clearWorkflow: () => void;
   i18n: LocalizerType;
   openFileInFolder: (path: string) => void;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd'  | 'netbsd'  | undefined;
   workflow: LocalBackupExportWorkflowType;
 };
 
@@ -123,7 +123,7 @@ export function LocalBackupExportWorkflo
       showInFolderText = i18n(
         'icu:PlaintextExport--CompleteDialog--ShowFiles--Mac'
       );
-    } else if (osName === 'linux') {
+    } else if (osName === 'linux' || osName === 'freebsd' || osName === 'netbsd') {
       showInFolderText = i18n(
         'icu:PlaintextExport--CompleteDialog--ShowFiles--Linux'
       );
