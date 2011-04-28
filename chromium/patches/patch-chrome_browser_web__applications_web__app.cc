$NetBSD: patch-chrome_browser_web__applications_web__app.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/web_applications/web_app.cc.orig	2011-04-13 08:01:40.000000000 +0000
+++ chrome/browser/web_applications/web_app.cc
@@ -34,9 +34,9 @@
 #include "chrome/common/url_constants.h"
 #include "chrome/common/web_apps.h"
 
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
