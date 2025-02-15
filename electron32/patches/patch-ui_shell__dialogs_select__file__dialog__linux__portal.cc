$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux_portal.cc.orig	2024-10-18 12:35:12.788244700 +0000
+++ ui/shell_dialogs/select_file_dialog_linux_portal.cc
@@ -7,6 +7,7 @@
 #include <string_view>
 
 #include "base/containers/contains.h"
+#include "base/command_line.h"
 #include "base/functional/bind.h"
 #include "base/logging.h"
 #include "base/no_destructor.h"
@@ -39,6 +40,8 @@ constexpr char kMethodStartServiceByName
 constexpr char kXdgPortalService[] = "org.freedesktop.portal.Desktop";
 constexpr char kXdgPortalObject[] = "/org/freedesktop/portal/desktop";
 
+// Version 4 includes support for current_folder option to the OpenFile method via
+// https://github.com/flatpak/xdg-desktop-portal/commit/71165a5.
 constexpr int kXdgPortalRequiredVersion = 3;
 
 constexpr char kXdgPortalRequestInterfaceName[] =
@@ -67,6 +70,7 @@ constexpr char kFileUriPrefix[] = "file:
 
 // Time to wait for the notification service to start, in milliseconds.
 constexpr base::TimeDelta kStartServiceTimeout = base::Seconds(1);
+const char kXdgPortalRequiredVersionFlag[] = "xdg-portal-required-version";
 
 struct FileChooserProperties : dbus::PropertySet {
   dbus::Property<uint32_t> version;
@@ -173,10 +177,18 @@ void SelectFileDialogLinuxPortal::StartA
   if (GetAvailabilityTestCompletionFlag()->IsSet())
     return;
 
+  auto* cmd = base::CommandLine::ForCurrentProcess();
+  unsigned int xdg_portal_required_version;
+  if (!base::StringToUint(cmd->GetSwitchValueASCII(kXdgPortalRequiredVersionFlag),
+                          &xdg_portal_required_version)) {
+    xdg_portal_required_version = kXdgPortalRequiredVersion;
+  }
+
   dbus_thread_linux::GetTaskRunner()->PostTask(
       FROM_HERE,
       base::BindOnce(
-          &SelectFileDialogLinuxPortal::CheckPortalAvailabilityOnBusThread));
+          &SelectFileDialogLinuxPortal::CheckPortalAvailabilityOnBusThread,
+          xdg_portal_required_version));
 }
 
 // static
@@ -188,6 +200,11 @@ bool SelectFileDialogLinuxPortal::IsPort
 }
 
 // static
+int SelectFileDialogLinuxPortal::GetPortalVersion() {
+  return available_portal_version_;
+}
+
+// static
 void SelectFileDialogLinuxPortal::DestroyPortalConnection() {
   dbus_thread_linux::GetTaskRunner()->PostTask(
       FROM_HERE, base::BindOnce(&DestroyBusOnBusThread));
@@ -216,6 +233,8 @@ void SelectFileDialogLinuxPortal::Select
                      weak_factory_.GetWeakPtr()));
   info_->type = type;
   info_->main_task_runner = base::SequencedTaskRunner::GetCurrentDefault();
+  info_->button_label = button_label();
+  info_->allow_multiple_selection = allow_multiple_selection();
 
   if (owning_window) {
     if (auto* root = owning_window->GetRootWindow()) {
@@ -262,7 +281,8 @@ bool SelectFileDialogLinuxPortal::HasMul
 }
 
 // static
-void SelectFileDialogLinuxPortal::CheckPortalAvailabilityOnBusThread() {
+void SelectFileDialogLinuxPortal::CheckPortalAvailabilityOnBusThread(
+    unsigned int xdg_portal_required_version) {
   DCHECK(dbus_thread_linux::GetTaskRunner()->RunsTasksInCurrentSequence());
   base::AtomicFlag* availability_test_complete =
       GetAvailabilityTestCompletionFlag();
@@ -283,11 +303,18 @@ void SelectFileDialogLinuxPortal::CheckP
     FileChooserProperties properties(portal);
     if (!properties.GetAndBlock(&properties.version)) {
       LOG(ERROR) << "Failed to read portal version property";
-    } else if (properties.version.value() >= kXdgPortalRequiredVersion) {
+    } else if (properties.version.value() >= xdg_portal_required_version) {
       is_portal_available_ = true;
+      available_portal_version_ = properties.version.value();
+    } else {
+      VLOG(1) << "File chooser portal available version: "
+              << properties.version.value();
+      available_portal_version_ = properties.version.value();
     }
   }
 
+  VLOG(1) << "File chooser portal expected version: "
+          << xdg_portal_required_version;
   VLOG(1) << "File chooser portal available: "
           << (is_portal_available_ ? "yes" : "no");
   availability_test_complete->Set();
@@ -552,7 +579,9 @@ void SelectFileDialogLinuxPortal::Dialog
                      response_handle_token);
 
   if (type == SelectFileDialog::Type::SELECT_UPLOAD_FOLDER) {
-    AppendStringOption(&options_writer, kFileChooserOptionAcceptLabel,
+    const std::string accept_label =
+        button_label.empty() ? kFileChooserOptionAcceptLabel : button_label;
+    AppendStringOption(&options_writer, accept_label,
                        l10n_util::GetStringUTF8(
                            IDS_SELECT_UPLOAD_FOLDER_DIALOG_UPLOAD_BUTTON));
   }
@@ -561,6 +590,8 @@ void SelectFileDialogLinuxPortal::Dialog
       type == SelectFileDialog::Type::SELECT_UPLOAD_FOLDER ||
       type == SelectFileDialog::Type::SELECT_EXISTING_FOLDER) {
     AppendBoolOption(&options_writer, kFileChooserOptionDirectory, true);
+    AppendBoolOption(&options_writer, kFileChooserOptionMultiple,
+                     allow_multiple_selection);
   } else if (type == SelectFileDialog::Type::SELECT_OPEN_MULTI_FILE) {
     AppendBoolOption(&options_writer, kFileChooserOptionMultiple, true);
   }
@@ -874,6 +905,7 @@ SelectFileDialogLinuxPortal::DialogInfo:
 }
 
 bool SelectFileDialogLinuxPortal::is_portal_available_ = false;
+unsigned int SelectFileDialogLinuxPortal::available_portal_version_ = 0;
 int SelectFileDialogLinuxPortal::handle_token_counter_ = 0;
 
 }  // namespace ui
