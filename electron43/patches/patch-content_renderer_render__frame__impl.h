$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/render_frame_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/renderer/render_frame_impl.h
@@ -651,6 +651,8 @@ class CONTENT_EXPORT RenderFrameImpl
   void DidObserveLayoutShift(double score, bool after_input_or_scroll) override;
   void DidCreateScriptContext(v8::Local<v8::Context> context,
                               int world_id) override;
+  void DidInstallConditionalFeatures(v8::Local<v8::Context> context,
+                                     int world_id) override;
   void WillReleaseScriptContext(v8::Local<v8::Context> context,
                                 int world_id) override;
   void DidChangeScrollOffset() override;
