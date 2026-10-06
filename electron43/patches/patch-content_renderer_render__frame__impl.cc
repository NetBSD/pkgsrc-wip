$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/render_frame_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/renderer/render_frame_impl.cc
@@ -4792,6 +4792,12 @@ void RenderFrameImpl::DidCreateScriptCon
     observer.DidCreateScriptContext(context, world_id);
 }
 
+void RenderFrameImpl::DidInstallConditionalFeatures(
+    v8::Local<v8::Context> context, int world_id) {
+  for (auto& observer : observers_)
+    observer.DidInstallConditionalFeatures(context, world_id);
+}
+
 void RenderFrameImpl::WillReleaseScriptContext(v8::Local<v8::Context> context,
                                                int world_id) {
   for (auto& observer : observers_)
@@ -6865,6 +6871,10 @@ WebView* RenderFrameImpl::CreateNewWindo
           request.HasUserGesture(), GetWebFrame()->IsAdFrame(),
           GetWebFrame()->IsAdScriptInStack());
 
+  params->raw_features = features.raw_features.Utf8(
+      WTF::UTF8ConversionMode::kStrictUTF8ConversionReplacingUnpairedSurrogatesWithFFFD);
+  params->body = GetRequestBodyForWebURLRequest(request);
+
   // We preserve this information before sending the message since |params| is
   // moved on send.
   bool is_background_tab =
