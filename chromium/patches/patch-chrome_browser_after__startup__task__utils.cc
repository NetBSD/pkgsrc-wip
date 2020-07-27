$NetBSD$

--- chrome/browser/after_startup_task_utils.cc.orig	2020-07-08 21:40:33.000000000 +0000
+++ chrome/browser/after_startup_task_utils.cc
@@ -32,7 +32,7 @@
 #include "chrome/browser/ui/tabs/tab_strip_model.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -119,7 +119,7 @@ void QueueTask(std::unique_ptr<AfterStar
 
 void SetBrowserStartupIsComplete() {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();
@@ -136,7 +136,7 @@ void SetBrowserStartupIsComplete() {
   g_after_startup_tasks.Get().clear();
   g_after_startup_tasks.Get().shrink_to_fit();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Make sure we complete the startup notification sequence, or launchers will
   // get confused by not receiving the expected message from the main process.
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
