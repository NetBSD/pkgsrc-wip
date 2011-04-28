$NetBSD: patch-chrome_browser_ui_views_accessible__view__helper.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/accessible_view_helper.h.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/accessible_view_helper.h
@@ -15,7 +15,7 @@
 #include "chrome/browser/accessibility_events.h"
 #include "gfx/native_widget_types.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/gtk/accessible_widget_helper_gtk.h"
 #endif
 
@@ -73,7 +73,7 @@ class AccessibleViewHelper {
   std::string window_title_;
   std::vector<views::View*> managed_views_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   scoped_ptr<AccessibleWidgetHelper> widget_helper_;
 #endif
 
