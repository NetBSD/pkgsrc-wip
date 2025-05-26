$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gtk/select_file_dialog_linux_gtk.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gtk/select_file_dialog_linux_gtk.cc
@@ -259,8 +259,12 @@ void SelectFileDialogLinuxGtk::SelectFil
     case SELECT_EXISTING_FOLDER:
       dialog = CreateSelectFolderDialog(type, title_string, default_path,
                                         owning_window);
-      connect("response",
-              &SelectFileDialogLinuxGtk::OnSelectSingleFolderDialogResponse);
+      if (allow_multiple_selection())
+        connect("response",
+                &SelectFileDialogLinuxGtk::OnSelectMultiFolderDialogResponse);
+      else
+        connect("response",
+                &SelectFileDialogLinuxGtk::OnSelectSingleFolderDialogResponse);
       break;
     case SELECT_OPEN_FILE:
       dialog = CreateFileOpenDialog(title_string, default_path, owning_window);
@@ -407,9 +411,11 @@ GtkWidget* SelectFileDialogLinuxGtk::Cre
     const std::string& title,
     const base::FilePath& default_path,
     gfx::NativeWindow parent) {
+  const char* accept_button_label =
+      button_label().empty() ? GetOpenLabel() : button_label().c_str();
   GtkWidget* dialog = GtkFileChooserDialogNew(
       title.c_str(), nullptr, GTK_FILE_CHOOSER_ACTION_OPEN, GetCancelLabel(),
-      GTK_RESPONSE_CANCEL, GetOpenLabel(), GTK_RESPONSE_ACCEPT);
+      GTK_RESPONSE_CANCEL, accept_button_label, GTK_RESPONSE_ACCEPT);
   SetGtkTransientForAura(dialog, parent);
   AddFilters(GTK_FILE_CHOOSER(dialog));
 
@@ -425,6 +431,7 @@ GtkWidget* SelectFileDialogLinuxGtk::Cre
     GtkFileChooserSetCurrentFolder(GTK_FILE_CHOOSER(dialog),
                                    *last_opened_path());
   }
+  gtk_file_chooser_set_show_hidden(GTK_FILE_CHOOSER(dialog), show_hidden());
   return dialog;
 }
 
@@ -440,11 +447,15 @@ GtkWidget* SelectFileDialogLinuxGtk::Cre
             ? l10n_util::GetStringUTF8(IDS_SELECT_UPLOAD_FOLDER_DIALOG_TITLE)
             : l10n_util::GetStringUTF8(IDS_SELECT_FOLDER_DIALOG_TITLE);
   }
-  std::string accept_button_label =
-      (type == SELECT_UPLOAD_FOLDER)
-          ? l10n_util::GetStringUTF8(
-                IDS_SELECT_UPLOAD_FOLDER_DIALOG_UPLOAD_BUTTON)
-          : GetOpenLabel();
+
+  std::string accept_button_label = button_label();
+  if (accept_button_label.empty()) {
+    accept_button_label =
+        (type == SELECT_UPLOAD_FOLDER)
+            ? l10n_util::GetStringUTF8(
+                  IDS_SELECT_UPLOAD_FOLDER_DIALOG_UPLOAD_BUTTON)
+            : GetOpenLabel();
+  }
 
   GtkWidget* dialog = GtkFileChooserDialogNew(
       title_string.c_str(), nullptr, GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER,
@@ -466,7 +477,8 @@ GtkWidget* SelectFileDialogLinuxGtk::Cre
   gtk_file_filter_add_mime_type(only_folders, "inode/directory");
   gtk_file_filter_add_mime_type(only_folders, "text/directory");
   gtk_file_chooser_add_filter(chooser, only_folders);
-  gtk_file_chooser_set_select_multiple(chooser, FALSE);
+  gtk_file_chooser_set_select_multiple(chooser, allow_multiple_selection());
+  gtk_file_chooser_set_show_hidden(chooser, show_hidden());
   return dialog;
 }
 
@@ -503,10 +515,11 @@ GtkWidget* SelectFileDialogLinuxGtk::Cre
   std::string title_string =
       !title.empty() ? title
                      : l10n_util::GetStringUTF8(IDS_SAVE_AS_DIALOG_TITLE);
-
+  const char* accept_button_label =
+      button_label().empty() ? GetSaveLabel() : button_label().c_str();
   GtkWidget* dialog = GtkFileChooserDialogNew(
       title_string.c_str(), nullptr, GTK_FILE_CHOOSER_ACTION_SAVE,
-      GetCancelLabel(), GTK_RESPONSE_CANCEL, GetSaveLabel(),
+      GetCancelLabel(), GTK_RESPONSE_CANCEL, accept_button_label,
       GTK_RESPONSE_ACCEPT);
   SetGtkTransientForAura(dialog, parent);
 
@@ -532,9 +545,10 @@ GtkWidget* SelectFileDialogLinuxGtk::Cre
   gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(dialog), FALSE);
   // Overwrite confirmation is always enabled in GTK4.
   if (!GtkCheckVersion(4)) {
-    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog),
-                                                   TRUE);
+    gtk_file_chooser_set_do_overwrite_confirmation(
+        GTK_FILE_CHOOSER(dialog), show_overwrite_confirmation());
   }
+  gtk_file_chooser_set_show_hidden(GTK_FILE_CHOOSER(dialog), show_hidden());
   return dialog;
 }
 
@@ -589,15 +603,29 @@ void SelectFileDialogLinuxGtk::OnSelectS
 void SelectFileDialogLinuxGtk::OnSelectMultiFileDialogResponse(
     GtkWidget* dialog,
     int response_id) {
+  SelectMultiFileHelper(dialog, response_id, false);
+}
+
+void SelectFileDialogLinuxGtk::OnSelectMultiFolderDialogResponse(
+    GtkWidget* dialog,
+    int response_id) {
+  SelectMultiFileHelper(dialog, response_id, true);
+}
+
+void SelectFileDialogLinuxGtk::SelectMultiFileHelper(GtkWidget* dialog,
+                                                     int response_id,
+                                                     bool allow_folder) {
   if (IsCancelResponse(response_id)) {
     FileNotSelected(dialog);
     return;
   }
 
   auto filenames = GtkFileChooserGetFilenames(dialog);
-  std::erase_if(filenames, [this](const base::FilePath& path) {
-    return CallDirectoryExistsOnUIThread(path);
+  std::erase_if(filenames, [this, &allow_folder](const base::FilePath& path) {
+    bool directory_exists = CallDirectoryExistsOnUIThread(path);
+    return !allow_folder && directory_exists;
   });
+
   if (filenames.empty()) {
     FileNotSelected(dialog);
     return;
