$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_impl.cc.orig	2024-10-18 12:34:13.598804500 +0000
+++ content/browser/renderer_host/render_widget_host_impl.cc
@@ -781,6 +781,9 @@ void RenderWidgetHostImpl::WasHidden() {
     return;
   }
 
+  if (disable_hidden_)
+    return;
+
   RejectPointerLockOrUnlockIfNecessary(
       blink::mojom::PointerLockResult::kWrongDocument);
 
@@ -1963,6 +1966,9 @@ void RenderWidgetHostImpl::SetCursor(con
   if (view_) {
     view_->UpdateCursor(cursor);
   }
+  if (delegate_) {
+    delegate_->OnCursorChanged(cursor);
+  }
 }
 
 void RenderWidgetHostImpl::ShowContextMenuAtPoint(
@@ -2026,9 +2032,8 @@ RenderWidgetHostImpl::GetWidgetInputHand
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
