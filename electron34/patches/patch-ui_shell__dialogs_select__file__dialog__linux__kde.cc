$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux_kde.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/shell_dialogs/select_file_dialog_linux_kde.cc
@@ -8,6 +8,7 @@
 #include <string_view>
 
 #include "base/command_line.h"
+#include "base/files/file_util.h"
 #include "base/functional/bind.h"
 #include "base/functional/callback_helpers.h"
 #include "base/logging.h"
@@ -154,9 +155,20 @@ class SelectFileDialogLinuxKde : public 
   void OnSelectMultiFileDialogResponse(
       gfx::AcceleratedWidget parent,
       std::unique_ptr<KDialogOutputParams> results);
+
+  // Common function for OnSelectSingleFolderDialogResponse and
+  // OnSelectMultiFileDialogResponse.
+  void SelectMultiFileDialogHelper(
+      bool allow_folder,
+      gfx::AcceleratedWidget parent,
+      std::unique_ptr<KDialogOutputParams> results);
+
   void OnSelectSingleFolderDialogResponse(
       gfx::AcceleratedWidget parent,
       std::unique_ptr<KDialogOutputParams> results);
+  void OnSelectMultiFolderDialogResponse(
+      gfx::AcceleratedWidget parent,
+      std::unique_ptr<KDialogOutputParams> results);
 
   // Should be either DESKTOP_ENVIRONMENT_KDE3, KDE4, KDE5, or KDE6.
   base::nix::DesktopEnvironment desktop_;
@@ -413,10 +425,16 @@ void SelectFileDialogLinuxKde::GetKDialo
   }
   command_line->AppendSwitch(type);
   // The path should never be empty. If it is, set it to PWD.
-  if (path.empty())
-    command_line->AppendArgPath(base::FilePath("."));
-  else
+  auto pwd = base::FilePath(".");
+  if (path.empty()) {
+    command_line->AppendArgPath(pwd);
+  } else if (path.IsAbsolute()) {
     command_line->AppendArgPath(path);
+  } else {
+    // KDialog won't set the default name in the Name field for relative paths.
+    auto abs_path = base::MakeAbsoluteFilePathNoResolveSymbolicLinks(path);
+    command_line->AppendArgPath(abs_path.value_or(pwd));
+  }
   // Depending on the type of the operation we need, get the path to the
   // file/folder and set up mime type filters.
   if (file_operation)
@@ -461,6 +479,7 @@ void SelectFileDialogLinuxKde::CreateSel
   int title_message_id = (type == SELECT_UPLOAD_FOLDER)
                              ? IDS_SELECT_UPLOAD_FOLDER_DIALOG_TITLE
                              : IDS_SELECT_FOLDER_DIALOG_TITLE;
+  bool multiple_selection = allow_multiple_selection();
   pipe_task_runner_->PostTaskAndReplyWithResult(
       FROM_HERE,
       base::BindOnce(
@@ -468,10 +487,12 @@ void SelectFileDialogLinuxKde::CreateSel
           KDialogParams(
               "--getexistingdirectory", GetTitle(title, title_message_id),
               default_path.empty() ? *last_opened_path() : default_path, parent,
-              false, false)),
+              false, multiple_selection)),
       base::BindOnce(
-          &SelectFileDialogLinuxKde::OnSelectSingleFolderDialogResponse, this,
-          parent));
+          multiple_selection
+              ? &SelectFileDialogLinuxKde::OnSelectMultiFolderDialogResponse
+              : &SelectFileDialogLinuxKde::OnSelectSingleFolderDialogResponse,
+          this, parent));
 }
 
 void SelectFileDialogLinuxKde::CreateFileOpenDialog(
@@ -561,7 +582,8 @@ void SelectFileDialogLinuxKde::OnSelectS
   SelectSingleFileHelper(true, std::move(results));
 }
 
-void SelectFileDialogLinuxKde::OnSelectMultiFileDialogResponse(
+void SelectFileDialogLinuxKde::SelectMultiFileDialogHelper(
+    bool allow_folder,
     gfx::AcceleratedWidget parent,
     std::unique_ptr<KDialogOutputParams> results) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -579,7 +601,7 @@ void SelectFileDialogLinuxKde::OnSelectM
        base::SplitStringPiece(results->output, "\n", base::KEEP_WHITESPACE,
                               base::SPLIT_WANT_NONEMPTY)) {
     base::FilePath path(line);
-    if (CallDirectoryExistsOnUIThread(path))
+    if (!allow_folder && CallDirectoryExistsOnUIThread(path))
       continue;
     filenames_fp.push_back(path);
   }
@@ -591,4 +613,16 @@ void SelectFileDialogLinuxKde::OnSelectM
   MultiFilesSelected(filenames_fp);
 }
 
+void SelectFileDialogLinuxKde::OnSelectMultiFolderDialogResponse(
+    gfx::AcceleratedWidget parent,
+    std::unique_ptr<KDialogOutputParams> results) {
+  SelectMultiFileDialogHelper(true, parent, std::move(results));
+}
+
+void SelectFileDialogLinuxKde::OnSelectMultiFileDialogResponse(
+    gfx::AcceleratedWidget parent,
+    std::unique_ptr<KDialogOutputParams> results) {
+  SelectMultiFileDialogHelper(false, parent, std::move(results));
+}
+
 }  // namespace ui
