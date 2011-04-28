$NetBSD: patch-chrome_browser_ui_views_extensions_extension__view.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/extensions/extension_view.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/extensions/extension_view.cc
@@ -14,7 +14,7 @@
 #include "chrome/browser/renderer_host/render_widget_host_view_win.h"
 #elif defined(TOUCH_UI)
 #include "chrome/browser/renderer_host/render_widget_host_view_views.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/renderer_host/render_widget_host_view_gtk.h"
 #endif
 
