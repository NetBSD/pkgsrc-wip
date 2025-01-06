$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog.h.orig	2024-10-18 12:35:12.788244700 +0000
+++ ui/shell_dialogs/select_file_dialog.h
@@ -220,6 +220,21 @@ class SHELL_DIALOGS_EXPORT SelectFileDia
                   const GURL* caller = nullptr);
   bool HasMultipleFileTypeChoices();
 
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+  // Set the label used for the file select button.
+  virtual void SetButtonLabel(const std::string& label) = 0;
+
+  // Set whether a confirmation should be shown when attempting to overwrite an
+  // existing file.
+  virtual void SetOverwriteConfirmationShown(bool is_shown) = 0;
+
+  // Set whether hidden files should be shown.
+  virtual void SetHiddenShown(bool is_shown) = 0;
+
+  // Set whether multiple file/directory selections are allowed
+  virtual void SetMultipleSelectionsAllowed(bool is_allowed) = 0;
+#endif
+
  protected:
   friend class base::RefCountedThreadSafe<SelectFileDialog>;
 
