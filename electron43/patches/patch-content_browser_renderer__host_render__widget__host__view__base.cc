$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_view_base.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/render_widget_host_view_base.cc
@@ -634,6 +634,13 @@ void RenderWidgetHostViewBase::OnFrameTo
     host()->DidProcessFrame(frame_token, activation_time);
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
