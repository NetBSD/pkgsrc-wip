$NetBSD: patch-chrome_browser_ui_views_fullscreen__exit__bubble.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/fullscreen_exit_bubble.h.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/fullscreen_exit_bubble.h
@@ -16,7 +16,7 @@ namespace ui {
 class SlideAnimation;
 }
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 namespace views {
 class WidgetGtk;
 }
@@ -78,7 +78,7 @@ class FullscreenExitBubble : public view
   // The popup itself, which is a slightly modified WidgetWin.  We need to use
   // a WidgetWin (and thus an HWND) to make the popup float over other HWNDs.
   FullscreenExitPopup* popup_;
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   views::WidgetGtk* popup_;
 #endif
 
