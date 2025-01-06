$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux_portal.cc.orig	2024-10-18 12:35:12.788244700 +0000
+++ ui/shell_dialogs/select_file_dialog_linux_portal.cc
@@ -39,7 +39,7 @@ constexpr char kMethodStartServiceByName
 constexpr char kXdgPortalService[] = "org.freedesktop.portal.Desktop";
 constexpr char kXdgPortalObject[] = "/org/freedesktop/portal/desktop";
 
-constexpr int kXdgPortalRequiredVersion = 3;
+constexpr int kXdgPortalRequiredVersion = 4;
 
 constexpr char kXdgPortalRequestInterfaceName[] =
     "org.freedesktop.portal.Request";
@@ -216,6 +216,8 @@ void SelectFileDialogLinuxPortal::Select
                      weak_factory_.GetWeakPtr()));
   info_->type = type;
   info_->main_task_runner = base::SequencedTaskRunner::GetCurrentDefault();
+  info_->button_label = button_label();
+  info_->allow_multiple_selection = allow_multiple_selection();
 
   if (owning_window) {
     if (auto* root = owning_window->GetRootWindow()) {
@@ -552,7 +554,9 @@ void SelectFileDialogLinuxPortal::Dialog
                      response_handle_token);
 
   if (type == SelectFileDialog::Type::SELECT_UPLOAD_FOLDER) {
-    AppendStringOption(&options_writer, kFileChooserOptionAcceptLabel,
+    const std::string accept_label =
+        button_label.empty() ? kFileChooserOptionAcceptLabel : button_label;
+    AppendStringOption(&options_writer, accept_label,
                        l10n_util::GetStringUTF8(
                            IDS_SELECT_UPLOAD_FOLDER_DIALOG_UPLOAD_BUTTON));
   }
@@ -561,12 +565,13 @@ void SelectFileDialogLinuxPortal::Dialog
       type == SelectFileDialog::Type::SELECT_UPLOAD_FOLDER ||
       type == SelectFileDialog::Type::SELECT_EXISTING_FOLDER) {
     AppendBoolOption(&options_writer, kFileChooserOptionDirectory, true);
+    AppendBoolOption(&options_writer, kFileChooserOptionMultiple,
+                     allow_multiple_selection);
   } else if (type == SelectFileDialog::Type::SELECT_OPEN_MULTI_FILE) {
     AppendBoolOption(&options_writer, kFileChooserOptionMultiple, true);
   }
 
-  if (type == SelectFileDialog::Type::SELECT_SAVEAS_FILE &&
-      !default_path.empty()) {
+  if (!default_path.empty()) {
     if (default_path_exists) {
       // If this is an existing directory, navigate to that directory, with no
       // filename.
