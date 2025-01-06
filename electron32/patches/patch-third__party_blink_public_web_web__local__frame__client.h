$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_local_frame_client.h.orig	2024-10-18 12:34:34.704506600 +0000
+++ third_party/blink/public/web/web_local_frame_client.h
@@ -647,6 +647,9 @@ class BLINK_EXPORT WebLocalFrameClient {
   virtual void DidCreateScriptContext(v8::Local<v8::Context>,
                                       int32_t world_id) {}
 
+  virtual void DidInstallConditionalFeatures(v8::Local<v8::Context>,
+                                             int32_t world_id) {}
+
   // WebKit is about to release its reference to a v8 context for a frame.
   virtual void WillReleaseScriptContext(v8::Local<v8::Context>,
                                         int32_t world_id) {}
