$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/render_widget_host_impl.cc
@@ -789,6 +789,10 @@ void RenderWidgetHostImpl::WasHidden() {
     return;
   }
 
+  if (disable_hidden_) {
+    return;
+  }
+
   // Cancel pending pointer lock requests, unless there's an open user prompt.
   // Prompts should remain open and functional across tab switches.
   if (!delegate_->IsWaitingForPointerLockPrompt(this)) {
@@ -1978,6 +1982,9 @@ void RenderWidgetHostImpl::SetCursor(con
   if (view_) {
     view_->UpdateCursor(cursor);
   }
+  if (delegate_) {
+    delegate_->OnCursorChanged(cursor);
+  }
 }
 
 void RenderWidgetHostImpl::ShowContextMenuAtPoint(
@@ -2041,9 +2048,8 @@ RenderWidgetHostImpl::GetWidgetInputHand
 void RenderWidgetHostImpl::NotifyScreenInfoChanged() {
   // The resize message (which may not happen immediately) will carry with it
   // the screen info as well as the new size (if the screen has changed scale
-  // factor). Force sending the new visual properties even if there is one in
-  // flight to ensure proper IPC ordering for features like the Fullscreen API.
-  SynchronizeVisualPropertiesIgnoringPendingAck();
+  // factor).
+  SynchronizeVisualProperties();
 
   // The device scale factor will be same for all the views contained by the
   // primary main frame, so just set it once.
