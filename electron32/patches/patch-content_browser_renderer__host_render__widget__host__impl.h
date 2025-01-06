$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_impl.h.orig	2024-10-18 12:34:13.598804500 +0000
+++ content/browser/renderer_host/render_widget_host_impl.h
@@ -1000,6 +1000,9 @@ class CONTENT_EXPORT RenderWidgetHostImp
   // Requests a commit and forced redraw in the renderer compositor.
   void ForceRedrawForTesting();
 
+  // Electron: Prevents the widget from getting hidden.
+  bool disable_hidden_ = false;
+
  protected:
   // |routing_id| must not be MSG_ROUTING_NONE.
   // If this object outlives |delegate|, DetachDelegate() must be called when
