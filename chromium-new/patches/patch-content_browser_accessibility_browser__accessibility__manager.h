$NetBSD$

--- content/browser/accessibility/browser_accessibility_manager.h.orig	2016-06-24 01:02:20.000000000 +0000
+++ content/browser/accessibility/browser_accessibility_manager.h
@@ -32,7 +32,7 @@ class BrowserAccessibilityManager;
 class BrowserAccessibilityManagerAndroid;
 #elif defined(OS_WIN)
 class BrowserAccessibilityManagerWin;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(USE_X11)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(USE_X11)
 class BrowserAccessibilityManagerAuraLinux;
 #endif
 
@@ -271,7 +271,7 @@ class CONTENT_EXPORT BrowserAccessibilit
   BrowserAccessibilityManagerAndroid* ToBrowserAccessibilityManagerAndroid();
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(USE_X11)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(USE_X11)
   BrowserAccessibilityManagerAuraLinux*
       ToBrowserAccessibilityManagerAuraLinux();
 #endif
