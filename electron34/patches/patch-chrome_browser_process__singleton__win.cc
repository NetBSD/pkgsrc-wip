$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/process_singleton_win.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/process_singleton_win.cc
@@ -29,7 +29,9 @@
 #include "base/win/wmi.h"
 #include "chrome/browser/process_singleton_internal.h"
 #include "chrome/browser/shell_integration.h"
+#if 0
 #include "chrome/browser/ui/simple_message_box.h"
+#endif
 #include "chrome/browser/win/chrome_process_finder.h"
 #include "chrome/common/chrome_constants.h"
 #include "chrome/common/chrome_paths.h"
@@ -79,10 +81,12 @@ BOOL CALLBACK BrowserWindowEnumeration(H
 
 bool ParseCommandLine(const COPYDATASTRUCT* cds,
                       base::CommandLine* parsed_command_line,
-                      base::FilePath* current_directory) {
+                      base::FilePath* current_directory,
+                      std::vector<uint8_t>* parsed_additional_data) {
   // We should have enough room for the shortest command (min_message_size)
   // and also be a multiple of wchar_t bytes. The shortest command
-  // possible is L"START\0\0" (empty current directory and command line).
+  // possible is L"START\0\0" (empty command line, current directory,
+  // and additional data).
   static const int min_message_size = 7;
   if (cds->cbData < min_message_size * sizeof(wchar_t) ||
       cds->cbData % sizeof(wchar_t) != 0) {
@@ -132,6 +136,37 @@ bool ParseCommandLine(const COPYDATASTRU
     const std::wstring cmd_line =
         msg.substr(second_null + 1, third_null - second_null);
     *parsed_command_line = base::CommandLine::FromString(cmd_line);
+
+    const std::wstring::size_type fourth_null =
+        msg.find_first_of(L'\0', third_null + 1);
+    if (fourth_null == std::wstring::npos ||
+        fourth_null == msg.length()) {
+      // No additional data was provided.
+      return true;
+    }
+
+    // Get length of the additional data.
+    const std::wstring additional_data_length_string =
+        msg.substr(third_null + 1, fourth_null - third_null);
+    size_t additional_data_length;
+    base::StringToSizeT(additional_data_length_string, &additional_data_length);
+
+    const std::wstring::size_type fifth_null =
+        msg.find_first_of(L'\0', fourth_null + 1);
+    if (fifth_null == std::wstring::npos ||
+        fifth_null == msg.length()) {
+      LOG(WARNING) << "Invalid format for start command, we need a string in 6 "
+        "parts separated by NULLs";
+    }
+
+    // Get the actual additional data.
+    const std::wstring additional_data =
+        msg.substr(fourth_null + 1, fifth_null - fourth_null);
+    const uint8_t* additional_data_bytes =
+        reinterpret_cast<const uint8_t*>(additional_data.c_str());
+    *parsed_additional_data = std::vector<uint8_t>(additional_data_bytes,
+        additional_data_bytes + additional_data_length);
+
     return true;
   }
   return false;
@@ -153,17 +188,19 @@ bool ProcessLaunchNotification(
 
   base::CommandLine parsed_command_line(base::CommandLine::NO_PROGRAM);
   base::FilePath current_directory;
-  if (!ParseCommandLine(cds, &parsed_command_line, &current_directory)) {
+  std::vector<uint8_t> additional_data;
+  if (!ParseCommandLine(cds, &parsed_command_line, &current_directory, &additional_data)) {
     *result = TRUE;
     return true;
   }
 
-  *result = notification_callback.Run(parsed_command_line, current_directory) ?
-      TRUE : FALSE;
+  *result = notification_callback.Run(parsed_command_line,
+      current_directory, std::move(additional_data)) ? TRUE : FALSE;
   return true;
 }
 
 bool DisplayShouldKillMessageBox() {
+#if 0
   TRACE_EVENT0("startup", "ProcessSingleton:DisplayShouldKillMessageBox");
 
   // Ensure there is an instance of ResourceBundle that is initialized for
@@ -174,6 +211,10 @@ bool DisplayShouldKillMessageBox() {
              NULL, l10n_util::GetStringUTF16(IDS_PRODUCT_NAME),
              l10n_util::GetStringUTF16(IDS_BROWSER_HUNGBROWSER_MESSAGE)) !=
          chrome::MESSAGE_BOX_RESULT_NO;
+#endif
+  // This is called when the secondary process can't ping the primary
+  // process.
+  return false;
 }
 
 // Function was copied from Process::Terminate.
@@ -256,9 +297,15 @@ bool ProcessSingleton::EscapeVirtualizat
 }
 
 ProcessSingleton::ProcessSingleton(
+    const std::string& program_name,
     const base::FilePath& user_data_dir,
+    const base::raw_span<const uint8_t> additional_data,
+    bool is_app_sandboxed,
     const NotificationCallback& notification_callback)
     : notification_callback_(notification_callback),
+      additional_data_(additional_data),
+      program_name_(program_name),
+      is_app_sandboxed_(is_app_sandboxed),
       is_virtualized_(false),
       lock_file_(INVALID_HANDLE_VALUE),
       user_data_dir_(user_data_dir),
@@ -283,7 +330,7 @@ ProcessSingleton::NotifyResult ProcessSi
     return PROCESS_NONE;
   }
 
-  switch (AttemptToNotifyRunningChrome(remote_window_)) {
+  switch (AttemptToNotifyRunningChrome(remote_window_, additional_data_)) {
     case NotifyChromeResult::NOTIFY_SUCCESS:
       return PROCESS_NOTIFIED;
     case NotifyChromeResult::NOTIFY_FAILED:
@@ -381,7 +428,7 @@ ProcessSingleton::NotifyOtherProcessOrCr
 bool ProcessSingleton::Create() {
   TRACE_EVENT0("startup", "ProcessSingleton::Create");
 
-  static const wchar_t kMutexName[] = L"Local\\ChromeProcessSingletonStartup!";
+  std::wstring mutexName = base::UTF8ToWide("Local\\" + program_name_ + "ProcessSingletonStartup");
 
   remote_window_ = FindRunningChromeWindow(user_data_dir_);
   if (!remote_window_ && !EscapeVirtualization(user_data_dir_)) {
@@ -390,7 +437,7 @@ bool ProcessSingleton::Create() {
     // access. As documented, it's clearer to NOT request ownership on creation
     // since it isn't guaranteed we will get it. It is better to create it
     // without ownership and explicitly get the ownership afterward.
-    base::win::ScopedHandle only_me(::CreateMutex(NULL, FALSE, kMutexName));
+    base::win::ScopedHandle only_me(::CreateMutex(NULL, FALSE, mutexName.c_str()));
     if (!only_me.IsValid()) {
       DPLOG(FATAL) << "CreateMutex failed";
       return false;
@@ -429,6 +476,17 @@ bool ProcessSingleton::Create() {
             window_.CreateNamed(base::BindRepeating(&ProcessLaunchNotification,
                                                     notification_callback_),
                                 user_data_dir_.value());
+
+        // When the app is sandboxed, firstly, the app should not be in
+        // admin mode, and even if it somehow is, messages from an unelevated
+        // instance should not be able to be sent to it.
+        if (!is_app_sandboxed_) {
+          // NB: Ensure that if the primary app gets started as elevated
+          // admin inadvertently, secondary windows running not as elevated
+          // will still be able to send messages.
+          ::ChangeWindowMessageFilterEx(window_.hwnd(), WM_COPYDATA, MSGFLT_ALLOW,
+                                        NULL);
+        }
         CHECK(result && window_.hwnd());
       }
     }
