$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/web_local_frame_impl.cc.orig	2024-10-18 12:34:35.428173000 +0000
+++ third_party/blink/renderer/core/frame/web_local_frame_impl.cc
@@ -1095,14 +1095,15 @@ void WebLocalFrameImpl::RequestExecuteSc
     mojom::blink::EvaluationTiming evaluation_timing,
     mojom::blink::LoadEventBlockingOption blocking_option,
     WebScriptExecutionCallback callback,
+    WebScriptExecutionCallbackUnmodified raw_callback,
     BackForwardCacheAware back_forward_cache_aware,
     mojom::blink::WantResultOption want_result_option,
     mojom::blink::PromiseResultOption promise_behavior) {
   DCHECK(GetFrame());
   GetFrame()->RequestExecuteScript(
       world_id, sources, user_gesture, evaluation_timing, blocking_option,
-      std::move(callback), back_forward_cache_aware, want_result_option,
-      promise_behavior);
+      std::move(callback), std::move(raw_callback), back_forward_cache_aware,
+      want_result_option, promise_behavior);
 }
 
 v8::MaybeLocal<v8::Value> WebLocalFrameImpl::CallFunctionEvenIfScriptDisabled(
