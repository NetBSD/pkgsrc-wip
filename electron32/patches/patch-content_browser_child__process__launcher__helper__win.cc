$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/child_process_launcher_helper_win.cc.orig	2024-10-18 12:34:12.251504000 +0000
+++ content/browser/child_process_launcher_helper_win.cc
@@ -24,6 +24,8 @@
 #include "mojo/public/cpp/platform/named_platform_channel.h"
 #include "mojo/public/cpp/platform/platform_channel.h"
 
+#include <windows.h>
+
 namespace {
 
 // Helper to avoid marking the log file as non-executable every time we launch a
@@ -132,6 +134,30 @@ bool ChildProcessLauncherHelper::BeforeL
     mojo_channel_->PrepareToPassRemoteEndpoint(&options->handles_to_inherit,
                                                command_line());
   }
+
+  if (file_data_->stdout_handle.IsValid() || file_data_->stderr_handle.IsValid()) {
+    // base::LaunchProcess requires that if any of the stdio handle is customized then
+    // the other two handles should also be set.
+    // https://source.chromium.org/chromium/chromium/src/+/main:base/process/launch_win.cc;l=341-350
+    options->stdin_handle = INVALID_HANDLE_VALUE;
+    if (file_data_->stdout_handle.IsValid()) {
+      options->stdout_handle = file_data_->stdout_handle.get();
+    } else {
+      options->stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
+    }
+
+    if (file_data_->stderr_handle.IsValid()) {
+      options->stderr_handle = file_data_->stderr_handle.get();
+    } else {
+      options->stderr_handle = GetStdHandle(STD_ERROR_HANDLE);
+    }
+    options->handles_to_inherit.push_back(options->stdout_handle);
+    options->handles_to_inherit.push_back(options->stderr_handle);
+  }
+
+  options->current_directory = delegate_->GetCurrentDirectory();
+  options->environment = delegate_->GetEnvironment();
+  options->clear_environment = !delegate_->ShouldInheritEnvironment();
   return true;
 }
 
@@ -159,7 +185,7 @@ ChildProcessLauncherHelper::LaunchProces
   ChildProcessLauncherHelper::Process process;
   *launch_result =
       StartSandboxedProcess(delegate_.get(), *command_line(),
-                            options->handles_to_inherit, &process.process);
+                            options, &process.process);
   return process;
 }
 
