$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/local_frame_client.h.orig	2024-10-18 12:34:35.416178700 +0000
+++ third_party/blink/renderer/core/frame/local_frame_client.h
@@ -300,6 +300,8 @@ class CORE_EXPORT LocalFrameClient : pub
 
   virtual void DidCreateScriptContext(v8::Local<v8::Context>,
                                       int32_t world_id) = 0;
+  virtual void DidInstallConditionalFeatures(v8::Local<v8::Context>,
+                                             int32_t world_id) = 0;
   virtual void WillReleaseScriptContext(v8::Local<v8::Context>,
                                         int32_t world_id) = 0;
   virtual bool AllowScriptExtensions() = 0;
