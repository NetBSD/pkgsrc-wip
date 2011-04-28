$NetBSD: patch-chrome_browser_ui_views_tabs_tab__strip.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/tabs/tab_strip.h.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_strip.h
@@ -19,7 +19,7 @@ class Tab;
 
 namespace views {
 class ImageView;
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 class WidgetGtk;
 #elif defined(OS_WIN)
 class WidgetWin;
