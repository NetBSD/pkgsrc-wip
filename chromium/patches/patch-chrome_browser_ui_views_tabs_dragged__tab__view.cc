$NetBSD: patch-chrome_browser_ui_views_tabs_dragged__tab__view.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/tabs/dragged_tab_view.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/tabs/dragged_tab_view.cc
@@ -11,7 +11,7 @@
 
 #if defined(OS_WIN)
 #include "views/widget/widget_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
