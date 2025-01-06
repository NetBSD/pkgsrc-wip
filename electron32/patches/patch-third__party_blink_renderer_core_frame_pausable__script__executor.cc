$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/pausable_script_executor.cc.orig	2024-10-18 12:34:35.420176700 +0000
+++ third_party/blink/renderer/core/frame/pausable_script_executor.cc
@@ -255,7 +255,7 @@ void PausableScriptExecutor::CreateAndRu
           script_state, mojom::blink::UserActivationOption::kDoNotActivate,
           mojom::blink::LoadEventBlockingOption::kDoNotBlock,
           want_result_option, mojom::blink::PromiseResultOption::kDoNotWait,
-          std::move(callback),
+          std::move(callback), base::NullCallback(),
           MakeGarbageCollected<V8FunctionExecutor>(
               script_state->GetIsolate(), function, receiver, argc, argv));
   executor->Run();
@@ -270,10 +270,11 @@ void PausableScriptExecutor::CreateAndRu
     mojom::blink::LoadEventBlockingOption blocking_option,
     mojom::blink::WantResultOption want_result_option,
     mojom::blink::PromiseResultOption promise_result_option,
-    WebScriptExecutionCallback callback) {
+    WebScriptExecutionCallback callback,
+    WebScriptExecutionCallbackUnmodified raw_callback) {
   auto* executor = MakeGarbageCollected<PausableScriptExecutor>(
       script_state, user_activation_option, blocking_option, want_result_option,
-      promise_result_option, std::move(callback),
+      promise_result_option, std::move(callback), std::move(raw_callback),
       MakeGarbageCollected<WebScriptExecutor>(std::move(sources),
                                               execute_script_policy));
   switch (evaluation_timing) {
@@ -295,6 +296,14 @@ void PausableScriptExecutor::ContextDest
     ScriptState::Scope script_scope(script_state_);
     std::move(callback_).Run({}, {});
   }
+  if (raw_callback_) {
+    // Though the context is (about to be) destroyed, the callback is invoked
+    // with a vector of v8::Local<>s, which implies that creating v8::Locals
+    // is permitted. Ensure a valid scope is present for the callback.
+    // See https://crbug.com/840719.
+    ScriptState::Scope script_scope(script_state_);
+    std::move(raw_callback_).Run(Vector<v8::Local<v8::Value>>());
+  }
   Dispose();
 }
 
@@ -305,10 +314,12 @@ PausableScriptExecutor::PausableScriptEx
     mojom::blink::WantResultOption want_result_option,
     mojom::blink::PromiseResultOption promise_result_option,
     WebScriptExecutionCallback callback,
+    WebScriptExecutionCallbackUnmodified raw_callback,
     Executor* executor)
     : ExecutionContextLifecycleObserver(ExecutionContext::From(script_state)),
       script_state_(script_state),
       callback_(std::move(callback)),
+      raw_callback_(std::move(raw_callback)),
       user_activation_option_(user_activation_option),
       blocking_option_(blocking_option),
       want_result_option_(want_result_option),
@@ -432,6 +443,9 @@ void PausableScriptExecutor::HandleResul
     std::move(callback_).Run(std::move(value), start_time_);
   }
 
+  if (raw_callback_)
+    std::move(raw_callback_).Run(results);
+
   Dispose();
 }
 
