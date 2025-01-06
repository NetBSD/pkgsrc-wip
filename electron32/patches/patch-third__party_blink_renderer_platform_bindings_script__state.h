$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/bindings/script_state.h.orig	2024-10-18 12:34:36.475692300 +0000
+++ third_party/blink/renderer/platform/bindings/script_state.h
@@ -184,7 +184,12 @@ class PLATFORM_EXPORT ScriptState : publ
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
@@ -251,9 +256,15 @@ class PLATFORM_EXPORT ScriptState : publ
   static void SetCreateCallback(CreateCallback);
   friend class ScriptStateImpl;
 
+  static void* const kScriptStateTagPtr;
+  static int const kScriptStateTag;
   static constexpr int kV8ContextPerContextDataIndex =
       static_cast<int>(gin::kPerContextDataStartIndex) +
       static_cast<int>(gin::kEmbedderBlink);
+  static constexpr int kV8ContextPerContextDataTagIndex =
+      static_cast<int>(gin::kPerContextDataStartIndex) +
+      static_cast<int>(gin::kEmbedderBlink) +
+      static_cast<int>(gin::kEmbedderBlinkTag);
 };
 
 // ScriptStateProtectingContext keeps the context associated with the
