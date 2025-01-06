$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux.cc.orig	2024-10-18 12:35:12.788244700 +0000
+++ ui/shell_dialogs/select_file_dialog_linux.cc
@@ -37,4 +37,17 @@ bool SelectFileDialogLinux::CallDirector
   return base::DirectoryExists(path);
 }
 
+void SelectFileDialogLinux::SetButtonLabel(const std::string& label) {
+  button_label_ = label;
+}
+void SelectFileDialogLinux::SetOverwriteConfirmationShown(bool is_shown) {
+  show_overwrite_confirmation_ = is_shown;
+}
+void SelectFileDialogLinux::SetHiddenShown(bool is_shown) {
+  show_hidden_ = is_shown;
+}
+void SelectFileDialogLinux::SetMultipleSelectionsAllowed(bool is_allowed) {
+  allow_multiple_selection_ = is_allowed;
+}
+
 }  // namespace ui
