$NetBSD: patch-chrome_browser_ui_browser__list.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/browser_list.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/browser_list.cc
@@ -430,7 +430,7 @@ void BrowserList::SessionEnding() {
   // At this point the message loop is still running yet we've shut everything
   // down. If any messages are processed we'll likely crash. Exit now.
   ExitProcess(ResultCodes::NORMAL_EXIT);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   _exit(ResultCodes::NORMAL_EXIT);
 #else
   NOTIMPLEMENTED();
