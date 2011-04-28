$NetBSD: patch-chrome_browser_ui_views_tabs_tab__strip.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/tabs/tab_strip.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_strip.cc
@@ -31,7 +31,7 @@
 #if defined(OS_WIN)
 #include "app/win/win_util.h"
 #include "views/widget/widget_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
