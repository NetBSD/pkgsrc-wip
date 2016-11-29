$NetBSD$

--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -90,7 +90,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD))
 #include "ui/events/devices/x11/touch_factory_x11.h"
 #endif
 
