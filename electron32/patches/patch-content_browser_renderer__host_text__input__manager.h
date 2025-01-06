$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/text_input_manager.h.orig	2024-10-18 12:34:13.658773400 +0000
+++ content/browser/renderer_host/text_input_manager.h
@@ -71,6 +71,10 @@ class CONTENT_EXPORT TextInputManager {
     virtual void OnTextSelectionChanged(
         TextInputManager* text_input_manager,
         RenderWidgetHostViewBase* updated_view) {}
+    // Called when focused input element has changed
+    virtual void OnFocusedInputElementChanged(
+        TextInputManager* text_input_manager,
+        RenderWidgetHostViewBase* updated_view) {}
   };
 
   // Text selection bounds.
@@ -275,6 +279,7 @@ class CONTENT_EXPORT TextInputManager {
 
   void NotifyObserversAboutInputStateUpdate(RenderWidgetHostViewBase* view,
                                             bool did_update_state);
+  void NotifyFocusedInputElementChanged(RenderWidgetHostViewBase* view);
 
   // The view with active text input state, i.e., a focused <input> element.
   // It will be nullptr if no such view exists. Note that the active view
