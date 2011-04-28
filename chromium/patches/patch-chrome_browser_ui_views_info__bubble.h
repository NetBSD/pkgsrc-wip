$NetBSD: patch-chrome_browser_ui_views_info__bubble.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/info_bubble.h.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/info_bubble.h
@@ -14,7 +14,7 @@
 
 #if defined(OS_WIN)
 #include "views/widget/widget_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
@@ -180,7 +180,7 @@ class InfoBubbleDelegate {
 class InfoBubble
 #if defined(OS_WIN)
     : public views::WidgetWin,
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
     : public views::WidgetGtk,
 #endif
       public views::AcceleratorTarget,
@@ -258,7 +258,7 @@ class InfoBubble
 #if defined(OS_WIN)
   // Overridden from WidgetWin:
   virtual void OnActivate(UINT action, BOOL minimized, HWND window);
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   // Overridden from WidgetGtk:
   virtual void IsActiveChanged();
 #endif
@@ -266,7 +266,7 @@ class InfoBubble
 #if defined(OS_WIN)
   // The window used to render the padding, border and arrow.
   BorderWidget* border_;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // The view displaying the border.
   BorderContents* border_contents_;
 #endif
