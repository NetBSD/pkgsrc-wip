$NetBSD: patch-chrome_browser_ui_views_tabs_dragged__tab__view.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/tabs/dragged_tab_view.h.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/tabs/dragged_tab_view.h
@@ -14,7 +14,7 @@
 namespace views {
 #if defined(OS_WIN)
 class WidgetWin;
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 class WidgetGtk;
 #endif
 }
@@ -71,7 +71,7 @@ class DraggedTabView : public views::Vie
   // The window that contains the DraggedTabView.
 #if defined(OS_WIN)
   scoped_ptr<views::WidgetWin> container_;
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   scoped_ptr<views::WidgetGtk> container_;
 #endif
 
