$NetBSD$

--- chrome/app/chrome_command_ids.h.orig	2016-11-10 20:02:09.000000000 +0000
+++ chrome/app/chrome_command_ids.h
@@ -75,7 +75,7 @@
 #define IDC_VISIT_DESKTOP_OF_LRU_USER_2 34049
 #define IDC_VISIT_DESKTOP_OF_LRU_USER_3 34050
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #endif
 
