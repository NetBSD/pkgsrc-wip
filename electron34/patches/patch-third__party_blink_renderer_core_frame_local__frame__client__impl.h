$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/local_frame_client_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/frame/local_frame_client_impl.h
@@ -83,6 +83,8 @@ class CORE_EXPORT LocalFrameClientImpl f
 
   void DidCreateScriptContext(v8::Local<v8::Context>,
                               int32_t world_id) override;
+  void DidInstallConditionalFeatures(v8::Local<v8::Context>,
+                                     int32_t world_id) override;
   void WillReleaseScriptContext(v8::Local<v8::Context>,
                                 int32_t world_id) override;
 
