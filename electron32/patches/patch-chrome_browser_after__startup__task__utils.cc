$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/after_startup_task_utils.cc.orig	2024-10-18 12:34:00.925622000 +0000
+++ chrome/browser/after_startup_task_utils.cc
@@ -117,7 +117,7 @@ void SetBrowserStartupIsComplete() {
                        TRACE_EVENT_SCOPE_GLOBAL, "BrowserCount", browser_count);
   GetStartupCompleteFlag().Set();
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();
