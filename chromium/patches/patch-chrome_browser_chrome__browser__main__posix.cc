$NetBSD$

--- chrome/browser/chrome_browser_main_posix.cc.orig	2020-07-08 21:40:33.000000000 +0000
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -70,7 +70,7 @@ void ExitHandler::ExitWhenPossibleOnUITh
     // ExitHandler takes care of deleting itself.
     new ExitHandler();
   } else {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
@@ -166,7 +166,7 @@ void ChromeBrowserMainPartsPosix::PostMa
 void ChromeBrowserMainPartsPosix::ShowMissingLocaleMessageBox() {
 #if defined(OS_CHROMEOS)
   NOTREACHED();  // Should not ever happen on ChromeOS.
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   // Not called on Mac because we load the locale files differently.
   NOTREACHED();
 #elif defined(USE_AURA)
