$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/renderer/render_frame_observer.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/renderer/render_frame_observer.h
@@ -150,6 +150,8 @@ class CONTENT_EXPORT RenderFrameObserver
   virtual void DidHandleOnloadEvents() {}
   virtual void DidCreateScriptContext(v8::Local<v8::Context> context,
                                       int32_t world_id) {}
+  virtual void DidInstallConditionalFeatures(v8::Local<v8::Context> context,
+                                             int32_t world_id) {}
   virtual void WillReleaseScriptContext(v8::Local<v8::Context> context,
                                         int32_t world_id) {}
   virtual void DidClearWindowObject() {}
