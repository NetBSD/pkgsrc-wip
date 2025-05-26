$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/local_frame_client_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/frame/local_frame_client_impl.cc
@@ -294,6 +294,13 @@ void LocalFrameClientImpl::DidCreateScri
     web_frame_->Client()->DidCreateScriptContext(context, world_id);
 }
 
+void LocalFrameClientImpl::DidInstallConditionalFeatures(
+    v8::Local<v8::Context> context,
+    int32_t world_id) {
+  if (web_frame_->Client())
+    web_frame_->Client()->DidInstallConditionalFeatures(context, world_id);
+}
+
 void LocalFrameClientImpl::WillReleaseScriptContext(
     v8::Local<v8::Context> context,
     int32_t world_id) {
