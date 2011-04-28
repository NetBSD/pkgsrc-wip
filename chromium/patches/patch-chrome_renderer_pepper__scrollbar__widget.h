$NetBSD: patch-chrome_renderer_pepper__scrollbar__widget.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/pepper_scrollbar_widget.h.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/pepper_scrollbar_widget.h
@@ -38,7 +38,7 @@ class PepperScrollbarWidget : public Pep
   virtual void getTickmarks(WebKit::WebScrollbar*,
                             WebKit::WebVector<WebKit::WebRect>*) const;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   static void SetScrollbarColors(unsigned inactive_color,
                                  unsigned active_color,
                                  unsigned track_color);
