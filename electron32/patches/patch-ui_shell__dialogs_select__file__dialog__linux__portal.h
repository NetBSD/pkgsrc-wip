$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux_portal.h.orig	2024-10-18 12:35:12.788244700 +0000
+++ ui/shell_dialogs/select_file_dialog_linux_portal.h
@@ -44,6 +44,9 @@ class SelectFileDialogLinuxPortal : publ
   // test from above has not yet completed (which should generally not happen).
   static bool IsPortalAvailable();
 
+  // Get version of portal if available.
+  static int GetPortalVersion();
+
   // Destroys the connection to the bus.
   static void DestroyPortalConnection();
 
@@ -117,6 +120,8 @@ class SelectFileDialogLinuxPortal : publ
     Type type;
     // The task runner the SelectFileImpl method was called on.
     scoped_refptr<base::SequencedTaskRunner> main_task_runner;
+    std::string button_label;
+    bool allow_multiple_selection = false;
 
    private:
     friend class base::RefCountedThreadSafe<DialogInfo>;
@@ -173,7 +178,8 @@ class SelectFileDialogLinuxPortal : publ
   };
 
   // D-Bus configuration and initialization.
-  static void CheckPortalAvailabilityOnBusThread();
+  static void CheckPortalAvailabilityOnBusThread(
+      unsigned int xdg_portal_required_version);
   static bool IsPortalRunningOnBusThread(dbus::ObjectProxy* dbus_proxy);
   static bool IsPortalActivatableOnBusThread(dbus::ObjectProxy* dbus_proxy);
 
@@ -207,6 +213,9 @@ class SelectFileDialogLinuxPortal : publ
   // Written by the D-Bus thread and read by the UI thread.
   static bool is_portal_available_;
 
+  // Written by the D-Bus thread and read by the UI thread.
+  static unsigned int available_portal_version_;
+
   // Used by the D-Bus thread to generate unique handle tokens.
   static int handle_token_counter_;
 
