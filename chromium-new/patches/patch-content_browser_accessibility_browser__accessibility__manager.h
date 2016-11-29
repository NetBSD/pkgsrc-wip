$NetBSD$

--- content/browser/accessibility/browser_accessibility_manager.h.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/accessibility/browser_accessibility_manager.h
@@ -33,7 +33,7 @@ class BrowserAccessibilityManager;
 class BrowserAccessibilityManagerAndroid;
 #elif defined(OS_WIN)
 class BrowserAccessibilityManagerWin;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(USE_X11)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(USE_X11)
 class BrowserAccessibilityManagerAuraLinux;
 #elif defined(OS_MACOSX)
 class BrowserAccessibilityManagerMac;
@@ -273,7 +273,7 @@ class CONTENT_EXPORT BrowserAccessibilit
   BrowserAccessibilityManagerAndroid* ToBrowserAccessibilityManagerAndroid();
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(USE_X11)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(USE_X11)
   BrowserAccessibilityManagerAuraLinux*
       ToBrowserAccessibilityManagerAuraLinux();
 #endif
