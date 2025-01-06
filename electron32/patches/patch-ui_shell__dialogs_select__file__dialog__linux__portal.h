$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux_portal.h.orig	2024-10-18 12:35:12.788244700 +0000
+++ ui/shell_dialogs/select_file_dialog_linux_portal.h
@@ -117,6 +117,8 @@ class SelectFileDialogLinuxPortal : publ
     Type type;
     // The task runner the SelectFileImpl method was called on.
     scoped_refptr<base::SequencedTaskRunner> main_task_runner;
+    std::string button_label;
+    bool allow_multiple_selection = false;
 
    private:
     friend class base::RefCountedThreadSafe<DialogInfo>;
