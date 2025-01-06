$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/win/chrome_process_finder.cc.orig	2024-10-18 12:34:03.772042500 +0000
+++ chrome/browser/win/chrome_process_finder.cc
@@ -41,7 +41,9 @@ HWND FindRunningChromeWindow(const base:
   return base::win::MessageWindow::FindWindow(user_data_dir.value());
 }
 
-NotifyChromeResult AttemptToNotifyRunningChrome(HWND remote_window) {
+NotifyChromeResult AttemptToNotifyRunningChrome(
+    HWND remote_window,
+    const base::span<const uint8_t> additional_data) {
   TRACE_EVENT0("startup", "AttemptToNotifyRunningChrome");
 
   DCHECK(remote_window);
@@ -70,12 +72,29 @@ NotifyChromeResult AttemptToNotifyRunnin
     new_command_line.AppendSwitchNative(switches::kSourceShortcut, si.lpTitle);
 
   // Send the command line to the remote chrome window.
-  // Format is "START\0<<<current directory>>>\0<<<commandline>>>".
+  // Format is
+  // "START\0<current-directory>\0<command-line>\0<additional-data-length>\0<additional-data>".
   std::wstring to_send = base::StrCat(
       {std::wstring_view{L"START\0", 6}, cur_dir.value(),
        std::wstring_view{L"\0", 1}, new_command_line.GetCommandLineString(),
        std::wstring_view{L"\0", 1}});
 
+  size_t additional_data_size = additional_data.size_bytes();
+  if (additional_data_size) {
+    // Send over the size, because the reinterpret cast to wchar_t could
+    // add padding.
+    to_send.append(base::UTF8ToWide(base::NumberToString(additional_data_size)));
+    to_send.append(L"\0", 1);  // Null separator.
+
+    size_t padded_size = additional_data_size / sizeof(wchar_t);
+    if (additional_data_size % sizeof(wchar_t) != 0) {
+      padded_size++;
+    }
+    to_send.append(reinterpret_cast<const wchar_t*>(additional_data.data()),
+                   padded_size);
+    to_send.append(L"\0", 1);  // Null separator.
+  }
+
   // Allow the current running browser window to make itself the foreground
   // window (otherwise it will just flash in the taskbar).
   ::AllowSetForegroundWindow(process_id);
