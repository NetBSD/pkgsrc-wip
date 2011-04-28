$NetBSD: patch-chrome_renderer_render__view.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/render_view.h.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/render_view.h
@@ -1112,7 +1112,7 @@ class RenderView : public RenderWidget,
   // periodic timer so we don't send too many messages.
   void SyncNavigationState();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void UpdateFontRenderingFromRendererPrefs();
 #else
   void UpdateFontRenderingFromRendererPrefs() {}
