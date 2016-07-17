$NetBSD$

--- chrome/common/chrome_switches.h.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/common/chrome_switches.h
@@ -387,7 +387,7 @@ extern const char kDisableNewTaskManager
 extern const char kEnableWaylandServer[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kEnableInputImeAPI[];
 extern const char kDisableInputImeAPI[];
 #endif
