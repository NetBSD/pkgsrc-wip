$NetBSD: patch-chrome_browser_about__flags.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/about_flags.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/about_flags.cc
@@ -503,7 +503,7 @@ int GetCurrentPlatform() {
   return kOsWin;
 #elif defined(OS_CHROMEOS)  // Needs to be before the OS_LINUX check.
   return kOsCrOS;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #else
 #error Unknown platform
