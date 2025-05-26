$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/bindings/core/v8/worker_or_worklet_script_controller.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/bindings/core/v8/worker_or_worklet_script_controller.cc
@@ -302,6 +302,7 @@ void WorkerOrWorkletScriptController::Pr
   V8PerContextData* per_context_data = script_state_->PerContextData();
   std::ignore =
       per_context_data->ConstructorForType(global_scope_->GetWrapperTypeInfo());
+  Platform::Current()->WorkerScriptReadyForEvaluation(script_state_->GetContext());
   // Inform V8 that origin trial information is now connected with the context,
   // and V8 can extend the context with origin trial features.
   isolate_->InstallConditionalFeatures(script_state_->GetContext());
