$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/win/chrome_process_finder.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/win/chrome_process_finder.h
@@ -7,6 +7,7 @@
 
 #include <windows.h>
 
+#include "base/memory/raw_span.h"
 #include "base/time/time.h"
 
 namespace base {
@@ -25,7 +26,9 @@ HWND FindRunningChromeWindow(const base:
 // Attempts to send the current command line to an already running instance of
 // Chrome via a WM_COPYDATA message.
 // Returns true if a running Chrome is found and successfully notified.
-NotifyChromeResult AttemptToNotifyRunningChrome(HWND remote_window);
+NotifyChromeResult AttemptToNotifyRunningChrome(
+    HWND remote_window,
+    const base::raw_span<const uint8_t> additional_data);
 
 // Changes the notification timeout to |new_timeout|, returns the old timeout.
 base::TimeDelta SetNotificationTimeoutForTesting(base::TimeDelta new_timeout);
