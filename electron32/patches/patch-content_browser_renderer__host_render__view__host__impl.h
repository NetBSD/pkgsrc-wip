$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_view_host_impl.h.orig	2024-10-18 12:34:13.578814700 +0000
+++ content/browser/renderer_host/render_view_host_impl.h
@@ -139,6 +139,7 @@ class CONTENT_EXPORT RenderViewHostImpl
   void EnablePreferredSizeMode() override;
   void WriteIntoTrace(perfetto::TracedProto<TraceProto> context) const override;
 
+  void SetSchedulerThrottling(bool allowed) override;
   void SendWebPreferencesToRenderer();
   void SendRendererPreferencesToRenderer(
       const blink::RendererPreferences& preferences);
