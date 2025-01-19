$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/process_singleton.h.orig	2024-10-18 12:34:01.889084000 +0000
+++ chrome/browser/process_singleton.h
@@ -18,6 +18,7 @@
 #include "base/functional/callback.h"
 #include "base/memory/ref_counted.h"
 #include "base/process/process.h"
+#include "base/containers/span.h"
 #include "ui/gfx/native_widget_types.h"
 
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID)
@@ -100,10 +101,20 @@ class ProcessSingleton {
   // should handle it (i.e., because the current process is shutting down).
   using NotificationCallback =
       base::RepeatingCallback<bool(base::CommandLine command_line,
-                                   const base::FilePath& current_directory)>;
+                                   const base::FilePath& current_directory,
+                                   const std::vector<uint8_t> additional_data)>;
 
+#if BUILDFLAG(IS_WIN)
+  ProcessSingleton(const std::string& program_name,
+                   const base::FilePath& user_data_dir,
+                   const base::span<const uint8_t> additional_data,
+                   bool is_sandboxed,
+                   const NotificationCallback& notification_callback);
+#else
   ProcessSingleton(const base::FilePath& user_data_dir,
+                   const base::span<const uint8_t> additional_data,
                    const NotificationCallback& notification_callback);
+#endif
 
   ProcessSingleton(const ProcessSingleton&) = delete;
   ProcessSingleton& operator=(const ProcessSingleton&) = delete;
@@ -171,11 +182,16 @@ class ProcessSingleton {
 #endif
 
  private:
+  // A callback to run when the first instance receives data from the second.
   NotificationCallback notification_callback_;  // Handler for notifications.
+  // Custom data to pass to the other instance during notify.
+  base::span<const uint8_t> additional_data_;
 
 #if BUILDFLAG(IS_WIN)
   bool EscapeVirtualization(const base::FilePath& user_data_dir);
 
+  std::string program_name_; // Used for mutexName.
+  bool is_app_sandboxed_; // Whether the Electron app is sandboxed.
   HWND remote_window_;  // The HWND_MESSAGE of another browser.
   base::win::MessageWindow window_;  // The message-only window.
   bool is_virtualized_;  // Stuck inside Microsoft Softricity VM environment.
