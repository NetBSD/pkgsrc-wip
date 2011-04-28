$NetBSD: patch-chrome_browser_ui_views_frame_app__panel__browser__frame__view.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/frame/app_panel_browser_frame_view.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/frame/app_panel_browser_frame_view.cc
@@ -22,7 +22,7 @@
 #include "views/window/window.h"
 #include "views/window/window_resources.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "views/window/hit_test.h"
 #endif
 
