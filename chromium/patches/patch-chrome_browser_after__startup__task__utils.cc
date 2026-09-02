$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/after_startup_task_utils.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/after_startup_task_utils.cc
@@ -123,7 +123,7 @@ void SetBrowserStartupIsComplete(Startup
   GetStartupCompleteFlag().Set();
   base::UmaHistogramEnumeration("Startup.BrowserStartupCompleteReason", reason);
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();
