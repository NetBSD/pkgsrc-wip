$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/bindings/script_state.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/bindings/script_state.h
@@ -185,7 +185,12 @@ class PLATFORM_EXPORT ScriptState : publ
                                 v8::Local<v8::Context> context) {
     DCHECK(!context.IsEmpty());
     if (context->GetNumberOfEmbedderDataFields() <=
-        kV8ContextPerContextDataIndex) {
+        kV8ContextPerContextDataTagIndex) {
+      return nullptr;
+    }
+    if (context->GetAlignedPointerFromEmbedderData(
+            kV8ContextPerContextDataTagIndex) !=
+        ScriptState::kScriptStateTagPtr) {
       return nullptr;
     }
     ScriptState* script_state =
@@ -263,6 +268,8 @@ class PLATFORM_EXPORT ScriptState : publ
   static void SetCreateCallback(CreateCallback);
   friend class ScriptStateImpl;
 
+  static void* const kScriptStateTagPtr;
+  static int const kScriptStateTag;
   static constexpr int kV8ContextPerContextDataIndex =
       static_cast<int>(gin::kPerContextDataStartIndex) +
       static_cast<int>(gin::kEmbedderBlink);
@@ -271,6 +278,10 @@ class PLATFORM_EXPORT ScriptState : publ
   // internals.idl.
   String last_compiled_script_file_name_;
   bool last_compiled_script_used_code_cache_ = false;
+
+  static constexpr int kV8ContextPerContextDataTagIndex =
+      static_cast<int>(gin::kPerContextDataStartIndex) +
+      static_cast<int>(gin::kEmbedderBlinkTag);
 };
 
 // ScriptStateProtectingContext keeps the context associated with the
