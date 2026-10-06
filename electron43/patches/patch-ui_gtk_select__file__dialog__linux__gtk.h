$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gtk/select_file_dialog_linux_gtk.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gtk/select_file_dialog_linux_gtk.h
@@ -108,6 +108,12 @@ class SelectFileDialogLinuxGtk : public 
                               gint response_id,
                               bool allow_folder);
 
+  // Common function for OnSelectMultiFileDialogResponse and
+  // OnSelectMultiFolderDialogResponse.
+  void SelectMultiFileHelper(GtkWidget* dialog,
+                             gint response_id,
+                             bool allow_folder);
+
   // Common function for CreateFileOpenDialog and CreateMultiFileOpenDialog.
   GtkWidget* CreateFileOpenHelper(const std::string& title,
                                   const base::FilePath& default_path,
@@ -122,6 +128,9 @@ class SelectFileDialogLinuxGtk : public 
   // Callback for when the user responds to a Open Multiple Files dialog.
   void OnSelectMultiFileDialogResponse(GtkWidget* dialog, int response_id);
 
+  // Callback for when the user responds to a Select Multiple Folders dialog.
+  void OnSelectMultiFolderDialogResponse(GtkWidget* dialog, int response_id);
+
   // Callback for when the file chooser gets destroyed.
   void OnFileChooserDestroy(GtkWidget* dialog);
 
