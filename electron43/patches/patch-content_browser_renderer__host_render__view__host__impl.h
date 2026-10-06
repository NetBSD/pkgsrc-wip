$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_view_host_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/render_view_host_impl.h
@@ -135,6 +135,7 @@ class CONTENT_EXPORT RenderViewHostImpl
   void EnablePreferredSizeMode() override;
   void WriteIntoTrace(perfetto::TracedProto<TraceProto> context) const override;
 
+  void SetSchedulerThrottling(bool allowed) override;
   void SendWebPreferencesToRenderer();
   void SendRendererPreferencesToRenderer(
       const blink::RendererPreferences& preferences);
