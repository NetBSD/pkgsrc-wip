$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/local_frame.cc.orig	2024-10-18 12:34:35.416178700 +0000
+++ third_party/blink/renderer/core/frame/local_frame.cc
@@ -733,10 +733,6 @@ bool LocalFrame::DetachImpl(FrameDetachT
   }
   DCHECK(!view_ || !view_->IsAttached());
 
-  // This is the earliest that scripting can be disabled:
-  // - FrameLoader::Detach() can fire XHR abort events
-  // - Document::Shutdown() can dispose plugins which can run script.
-  ScriptForbiddenScope forbid_script;
   if (!Client())
     return false;
 
@@ -788,6 +784,11 @@ bool LocalFrame::DetachImpl(FrameDetachT
   DCHECK(!view_->IsAttached());
   Client()->WillBeDetached();
 
+  // This is the earliest that scripting can be disabled:
+  // - FrameLoader::Detach() can fire XHR abort events
+  // - Document::Shutdown() can dispose plugins which can run script.
+  ScriptForbiddenScope forbid_script;
+
   // TODO(crbug.com/729196): Trace why LocalFrameView::DetachFromLayout crashes.
   CHECK(!view_->IsAttached());
   SetView(nullptr);
@@ -3109,6 +3110,7 @@ void LocalFrame::RequestExecuteScript(
     mojom::blink::EvaluationTiming evaluation_timing,
     mojom::blink::LoadEventBlockingOption blocking_option,
     WebScriptExecutionCallback callback,
+    WebScriptExecutionCallbackUnmodified raw_callback,
     BackForwardCacheAware back_forward_cache_aware,
     mojom::blink::WantResultOption want_result_option,
     mojom::blink::PromiseResultOption promise_behavior) {
@@ -3142,7 +3144,7 @@ void LocalFrame::RequestExecuteScript(
   PausableScriptExecutor::CreateAndRun(
       script_state, std::move(script_sources), execute_script_policy,
       user_gesture, evaluation_timing, blocking_option, want_result_option,
-      promise_behavior, std::move(callback));
+      promise_behavior, std::move(callback), std::move(raw_callback));
 }
 
 void LocalFrame::SetEvictCachedSessionStorageOnFreezeOrUnload() {
