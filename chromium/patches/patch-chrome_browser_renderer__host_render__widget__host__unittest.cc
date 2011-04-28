$NetBSD: patch-chrome_browser_renderer__host_render__widget__host__unittest.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/renderer_host/render_widget_host_unittest.cc.orig	2011-04-13 08:01:43.000000000 +0000
+++ chrome/browser/renderer_host/render_widget_host_unittest.cc
@@ -419,7 +419,7 @@ TEST_F(RenderWidgetHostTest, ResizeThenC
 
 // Tests setting custom background
 TEST_F(RenderWidgetHostTest, Background) {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   scoped_ptr<RenderWidgetHostView> view(
       RenderWidgetHostView::CreateViewForWidget(host_.get()));
   host_->set_view(view.get());
