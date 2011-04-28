$NetBSD: patch-chrome_browser_ui_views_notifications_balloon__view__host.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/notifications/balloon_view_host.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/notifications/balloon_view_host.cc
@@ -10,7 +10,7 @@
 #if defined(OS_WIN)
 #include "chrome/browser/renderer_host/render_widget_host_view_win.h"
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(TOUCH_UI)
 #include "chrome/browser/renderer_host/render_widget_host_view_views.h"
 #else
@@ -21,7 +21,7 @@
 #if defined(OS_WIN)
 #include "views/widget/widget_win.h"
 #endif
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
@@ -74,7 +74,7 @@ void BalloonViewHost::InitRenderWidgetHo
   HWND hwnd = view_win->Create(parent_native_view_);
   view_win->ShowWindow(SW_SHOW);
   native_host_->Attach(hwnd);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #if defined(TOUCH_UI)
   RenderWidgetHostViewViews* view_views =
       static_cast<RenderWidgetHostViewViews*>(render_widget_host_view_);
