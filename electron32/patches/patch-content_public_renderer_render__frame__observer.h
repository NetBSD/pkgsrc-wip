$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/renderer/render_frame_observer.h.orig	2024-10-18 12:34:14.474352800 +0000
+++ content/public/renderer/render_frame_observer.h
@@ -145,6 +145,8 @@ class CONTENT_EXPORT RenderFrameObserver
   virtual void DidHandleOnloadEvents() {}
   virtual void DidCreateScriptContext(v8::Local<v8::Context> context,
                                       int32_t world_id) {}
+  virtual void DidInstallConditionalFeatures(v8::Local<v8::Context> context,
+                                             int32_t world_id) {}
   virtual void WillReleaseScriptContext(v8::Local<v8::Context> context,
                                         int32_t world_id) {}
   virtual void DidClearWindowObject() {}
