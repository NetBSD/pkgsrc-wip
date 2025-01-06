$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/pausable_script_executor.h.orig	2024-10-18 12:34:35.420176700 +0000
+++ third_party/blink/renderer/core/frame/pausable_script_executor.h
@@ -48,7 +48,8 @@ class CORE_EXPORT PausableScriptExecutor
                            mojom::blink::LoadEventBlockingOption,
                            mojom::blink::WantResultOption,
                            mojom::blink::PromiseResultOption,
-                           WebScriptExecutionCallback);
+                           WebScriptExecutionCallback,
+                           WebScriptExecutionCallbackUnmodified);
 
   class Executor : public GarbageCollected<Executor> {
    public:
@@ -65,6 +66,7 @@ class CORE_EXPORT PausableScriptExecutor
                          mojom::blink::WantResultOption,
                          mojom::blink::PromiseResultOption,
                          WebScriptExecutionCallback,
+                         WebScriptExecutionCallbackUnmodified,
                          Executor*);
   ~PausableScriptExecutor() override;
 
@@ -83,6 +85,7 @@ class CORE_EXPORT PausableScriptExecutor
 
   Member<ScriptState> script_state_;
   WebScriptExecutionCallback callback_;
+  WebScriptExecutionCallbackUnmodified raw_callback_;
   base::TimeTicks start_time_;
   const mojom::blink::UserActivationOption user_activation_option_;
   const mojom::blink::LoadEventBlockingOption blocking_option_;
