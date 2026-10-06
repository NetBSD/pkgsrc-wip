$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/wrappable.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ gin/wrappable.h
@@ -80,6 +80,13 @@ class GIN_EXPORT WrappableBase {
   v8::MaybeLocal<v8::Object> GetWrapperImpl(v8::Isolate* isolate,
                                             WrapperInfo* wrapper_info);
 
+  // Make this wrappable strong again. This is useful when the wrappable is
+  // destroyed outside the finalizer callbacks and we want to avoid scheduling
+  // the weak callbacks if they haven't been scheduled yet.
+  // NOTE!!! this does not prevent finalization callbacks from running if they
+  // have already been processed.
+  void ClearWeak();
+
  private:
   static void FirstWeakCallback(
       const v8::WeakCallbackInfo<WrappableBase>& data);
