$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/render_frame_impl.h.orig	2024-10-18 12:34:14.606285000 +0000
+++ content/renderer/render_frame_impl.h
@@ -643,6 +643,8 @@ class CONTENT_EXPORT RenderFrameImpl
   void DidObserveLayoutShift(double score, bool after_input_or_scroll) override;
   void DidCreateScriptContext(v8::Local<v8::Context> context,
                               int world_id) override;
+  void DidInstallConditionalFeatures(v8::Local<v8::Context> context,
+                                     int world_id) override;
   void WillReleaseScriptContext(v8::Local<v8::Context> context,
                                 int world_id) override;
   void DidChangeScrollOffset() override;
