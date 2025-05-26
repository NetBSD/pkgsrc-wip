$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux_portal.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/shell_dialogs/select_file_dialog_linux_portal.h
@@ -47,6 +47,9 @@ class SelectFileDialogLinuxPortal : publ
   // availability test has not yet completed.
   static bool IsPortalAvailable();
 
+  // Get version of portal if available.
+  static int GetPortalVersion();
+
   // Destroys the connection to the bus.
   static void DestroyPortalConnection();
 
@@ -120,6 +123,8 @@ class SelectFileDialogLinuxPortal : publ
     Type type;
     // The task runner the SelectFileImpl method was called on.
     scoped_refptr<base::SequencedTaskRunner> main_task_runner;
+    std::string button_label;
+    bool allow_multiple_selection = false;
 
    private:
     friend class base::RefCountedThreadSafe<DialogInfo>;
@@ -176,7 +181,8 @@ class SelectFileDialogLinuxPortal : publ
   };
 
   // D-Bus configuration and initialization.
-  static void CheckPortalAvailabilityOnBusThread();
+  static void CheckPortalAvailabilityOnBusThread(
+      unsigned int xdg_portal_required_version);
 
   // Returns a flag, written by the D-Bus thread and read by the UI thread,
   // indicating whether or not the availability test has completed.
@@ -208,6 +214,9 @@ class SelectFileDialogLinuxPortal : publ
   // Written by the D-Bus thread and read by the UI thread.
   static bool is_portal_available_;
 
+  // Written by the D-Bus thread and read by the UI thread.
+  static unsigned int available_portal_version_;
+
   // Used by the D-Bus thread to generate unique handle tokens.
   static int handle_token_counter_;
 
