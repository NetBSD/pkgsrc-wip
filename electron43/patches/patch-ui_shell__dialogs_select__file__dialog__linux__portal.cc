$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux_portal.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/shell_dialogs/select_file_dialog_linux_portal.cc
@@ -11,6 +11,7 @@
 
 #include <string_view>
 
+#include "base/command_line.h"
 #include "base/functional/bind.h"
 #include "base/logging.h"
 #include "base/no_destructor.h"
@@ -40,6 +41,8 @@ namespace {
 constexpr char kXdgPortalService[] = "org.freedesktop.portal.Desktop";
 constexpr char kXdgPortalObject[] = "/org/freedesktop/portal/desktop";
 
+// Version 4 includes support for current_folder option to the OpenFile method via
+// https://github.com/flatpak/xdg-desktop-portal/commit/71165a5.
 constexpr int kXdgPortalRequiredVersion = 3;
 
 constexpr char kXdgPortalRequestInterfaceName[] =
@@ -66,6 +69,8 @@ constexpr int kFileChooserFilterKindGlob
 
 constexpr char kFileUriPrefix[] = "file://";
 
+const char kXdgPortalRequiredVersionFlag[] = "xdg-portal-required-version";
+
 struct FileChooserProperties : dbus::PropertySet {
   dbus::Property<uint32_t> version;
 
@@ -171,10 +176,18 @@ void SelectFileDialogLinuxPortal::StartA
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
@@ -186,6 +199,11 @@ bool SelectFileDialogLinuxPortal::IsPort
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
@@ -214,6 +232,8 @@ void SelectFileDialogLinuxPortal::Select
                      weak_factory_.GetWeakPtr()));
   info_->type = type;
   info_->main_task_runner = base::SequencedTaskRunner::GetCurrentDefault();
+  info_->button_label = button_label();
+  info_->allow_multiple_selection = allow_multiple_selection();
 
   if (owning_window) {
     if (auto* root = owning_window->GetRootWindow()) {
@@ -260,7 +280,8 @@ bool SelectFileDialogLinuxPortal::HasMul
 }
 
 // static
-void SelectFileDialogLinuxPortal::CheckPortalAvailabilityOnBusThread() {
+void SelectFileDialogLinuxPortal::CheckPortalAvailabilityOnBusThread(
+    unsigned int xdg_portal_required_version) {
   DCHECK(dbus_thread_linux::GetTaskRunner()->RunsTasksInCurrentSequence());
   base::AtomicFlag* availability_test_complete =
       GetAvailabilityTestCompletionFlag();
@@ -274,6 +295,7 @@ void SelectFileDialogLinuxPortal::CheckP
       base::BindOnce(
           [](scoped_refptr<dbus::Bus> bus,
              base::AtomicFlag* availability_test_complete,
+             unsigned int xdg_portal_required_version,
              std::optional<bool> name_has_owner) {
             if (name_has_owner.value_or(false)) {
               // The portal service has an owner, proceed to check the version.
@@ -285,15 +307,22 @@ void SelectFileDialogLinuxPortal::CheckP
               if (!properties.GetAndBlock(&properties.version)) {
                 LOG(ERROR) << "Failed to read portal version property";
               } else if (properties.version.value() >=
-                         kXdgPortalRequiredVersion) {
+                         xdg_portal_required_version) {
                 is_portal_available_ = true;
+                available_portal_version_ = properties.version.value();
+              } else {
+                VLOG(1) << "File chooser portal available version: "
+                        << properties.version.value();
+                available_portal_version_ = properties.version.value();
               }
             }
+            VLOG(1) << "File chooser portal expected version: "
+                    << xdg_portal_required_version;
             VLOG(1) << "File chooser portal available: "
                     << (is_portal_available_ ? "yes" : "no");
             availability_test_complete->Set();
           },
-          bus, availability_test_complete));
+          bus, availability_test_complete, xdg_portal_required_version));
 }
 
 // static
@@ -471,7 +500,9 @@ void SelectFileDialogLinuxPortal::Dialog
                      response_handle_token);
 
   if (type == SelectFileDialog::Type::SELECT_UPLOAD_FOLDER) {
-    AppendStringOption(&options_writer, kFileChooserOptionAcceptLabel,
+    const std::string accept_label =
+        button_label.empty() ? kFileChooserOptionAcceptLabel : button_label;
+    AppendStringOption(&options_writer, accept_label,
                        l10n_util::GetStringUTF8(
                            IDS_SELECT_UPLOAD_FOLDER_DIALOG_UPLOAD_BUTTON));
   }
@@ -480,6 +511,8 @@ void SelectFileDialogLinuxPortal::Dialog
       type == SelectFileDialog::Type::SELECT_UPLOAD_FOLDER ||
       type == SelectFileDialog::Type::SELECT_EXISTING_FOLDER) {
     AppendBoolOption(&options_writer, kFileChooserOptionDirectory, true);
+    AppendBoolOption(&options_writer, kFileChooserOptionMultiple,
+                     allow_multiple_selection);
   } else if (type == SelectFileDialog::Type::SELECT_OPEN_MULTI_FILE) {
     AppendBoolOption(&options_writer, kFileChooserOptionMultiple, true);
   }
@@ -820,6 +853,7 @@ SelectFileDialogLinuxPortal::DialogInfo:
 SelectFileDialogLinuxPortal::DialogInfo::~DialogInfo() = default;
 
 bool SelectFileDialogLinuxPortal::is_portal_available_ = false;
+unsigned int SelectFileDialogLinuxPortal::available_portal_version_ = 0;
 int SelectFileDialogLinuxPortal::handle_token_counter_ = 0;
 
 }  // namespace ui
