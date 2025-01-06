$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_view_base.cc.orig	2024-10-18 12:34:13.626790000 +0000
+++ content/browser/renderer_host/render_widget_host_view_base.cc
@@ -779,6 +779,13 @@ bool RenderWidgetHostViewBase::ScreenRec
   return false;
 }
 
+RenderWidgetHostViewBase* RenderWidgetHostViewBase::CreateViewForWidget(
+    RenderWidgetHost* render_widget_host,
+    RenderWidgetHost* embedder_render_widget_host,
+    WebContentsView* web_contents_view) {
+  return web_contents_view->CreateViewForWidget(render_widget_host);
+}
+
 void RenderWidgetHostViewBase::ProcessMouseEvent(
     const blink::WebMouseEvent& event,
     const ui::LatencyInfo& latency) {
