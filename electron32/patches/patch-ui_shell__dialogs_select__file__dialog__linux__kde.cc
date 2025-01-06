$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux_kde.cc.orig	2024-10-18 12:35:12.788244700 +0000
+++ ui/shell_dialogs/select_file_dialog_linux_kde.cc
@@ -468,7 +468,7 @@ void SelectFileDialogLinuxKde::CreateSel
           KDialogParams(
               "--getexistingdirectory", GetTitle(title, title_message_id),
               default_path.empty() ? *last_opened_path() : default_path, parent,
-              false, false)),
+              false, allow_multiple_selection())),
       base::BindOnce(
           &SelectFileDialogLinuxKde::OnSelectSingleFolderDialogResponse, this,
           parent));
