$NetBSD: patch-chrome_browser_web__applications_web__app.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/browser/web_applications/web_app.cc.orig	2011-05-24 08:01:39.000000000 +0000
+++ chrome/browser/web_applications/web_app.cc
@@ -34,9 +34,9 @@
 #include "content/browser/browser_thread.h"
 #include "content/browser/tab_contents/tab_contents.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include "base/win/win_util.h"
@@ -274,7 +274,7 @@ void CreateShortcutTask::Run() {
 bool CreateShortcutTask::CreateShortcut() {
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::FILE));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   scoped_ptr<base::Environment> env(base::Environment::Create());
 
   std::string shortcut_template;
