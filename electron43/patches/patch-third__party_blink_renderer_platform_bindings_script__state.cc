$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/bindings/script_state.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/bindings/script_state.cc
@@ -13,6 +13,10 @@ namespace blink {
 
 ScriptState::CreateCallback ScriptState::s_create_callback_ = nullptr;
 
+int const ScriptState::kScriptStateTag = 0x6e6f64;
+void* const ScriptState::kScriptStateTagPtr = const_cast<void*>(
+    static_cast<const void*>(&ScriptState::kScriptStateTag));
+
 // static
 void ScriptState::SetCreateCallback(CreateCallback create_callback) {
   DCHECK(create_callback);
@@ -37,6 +41,8 @@ ScriptState::ScriptState(v8::Local<v8::C
   DCHECK(world_);
   context_.SetWeak(this, &OnV8ContextCollectedCallback);
   context->SetAlignedPointerInEmbedderData(kV8ContextPerContextDataIndex, this);
+  context->SetAlignedPointerInEmbedderData(
+      kV8ContextPerContextDataTagIndex, ScriptState::kScriptStateTagPtr);
   RendererResourceCoordinator::Get()->OnScriptStateCreated(this,
                                                            execution_context);
 }
@@ -79,6 +85,8 @@ void ScriptState::DissociateContext() {
   // Cut the reference from V8 context to ScriptState.
   GetContext()->SetAlignedPointerInEmbedderData(kV8ContextPerContextDataIndex,
                                                 nullptr);
+  GetContext()->SetAlignedPointerInEmbedderData(
+      kV8ContextPerContextDataTagIndex, nullptr);
   reference_from_v8_context_.Clear();
 
   // Cut the reference from ScriptState to V8 context.
