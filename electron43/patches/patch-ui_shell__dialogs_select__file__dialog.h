$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- ui/shell_dialogs/select_file_dialog.h.orig	2026-10-20 08:24:51.841463779 +0000
+++ ui/shell_dialogs/select_file_dialog.h
@@ -224,7 +224,7 @@ class SHELL_DIALOGS_EXPORT SelectFileDia
                   const GURL* caller = nullptr);
   bool HasMultipleFileTypeChoices();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the label used for the file select button.
   virtual void SetButtonLabel(const std::string& label) = 0;
 
