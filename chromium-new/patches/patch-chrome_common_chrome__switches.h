$NetBSD$

--- chrome/common/chrome_switches.h.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/common/chrome_switches.h
@@ -378,7 +378,7 @@ extern const char kAllowNaClSocketAPI[];
 extern const char kEnableWaylandServer[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[];
 extern const char kEnableInputImeAPI[];
 #endif
