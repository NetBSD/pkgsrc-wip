$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/text_input_manager.cc.orig	2024-10-18 12:34:13.654775400 +0000
+++ content/browser/renderer_host/text_input_manager.cc
@@ -167,6 +167,7 @@ void TextInputManager::UpdateTextInputSt
 
   if (text_input_state.type == ui::TEXT_INPUT_TYPE_NONE &&
       active_view_ != view) {
+    NotifyFocusedInputElementChanged(active_view_);
     // We reached here because an IPC is received to reset the TextInputState
     // for |view|. But |view| != |active_view_|, which suggests that at least
     // one other view has become active and we have received the corresponding
@@ -454,6 +455,12 @@ void TextInputManager::NotifyObserversAb
     observer.OnUpdateTextInputStateCalled(this, updated_view, did_update_state);
 }
 
+void TextInputManager::NotifyFocusedInputElementChanged(
+    RenderWidgetHostViewBase* view) {
+  for (auto& observer : observer_list_)
+    observer.OnFocusedInputElementChanged(this, view);
+}
+
 TextInputManager::SelectionRegion::SelectionRegion() = default;
 
 TextInputManager::SelectionRegion::SelectionRegion(
