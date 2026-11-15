$NetBSD$

* Add Free- and NetBSD support

--- ts/components/PlaintextExportWorkflow.dom.tsx.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/components/PlaintextExportWorkflow.dom.tsx
@@ -24,7 +24,7 @@ export type PropsType = {
   clearWorkflow: () => unknown;
   i18n: LocalizerType;
   openFileInFolder: (path: string) => unknown;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | 'netbsd' | undefined;
   verifyWithOSForExport: (includeMedia: boolean) => unknown;
   workflow: PlaintextExportWorkflowType;
 };
@@ -204,7 +204,7 @@ export function PlaintextExportWorkflow(
       showInFolderText = i18n(
         'icu:PlaintextExport--CompleteDialog--ShowFiles--Mac'
       );
-    } else if (osName === 'linux') {
+    } else if (osName === 'linux' || osName === 'freebsd' || osName === 'netbsd') {
       showInFolderText = i18n(
         'icu:PlaintextExport--CompleteDialog--ShowFiles--Linux'
       );
