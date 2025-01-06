$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_view_mac.mm.orig	2024-10-18 12:34:13.646779500 +0000
+++ content/browser/renderer_host/render_widget_host_view_mac.mm
@@ -272,8 +272,10 @@ RenderWidgetHostViewMac::~RenderWidgetHo
 void RenderWidgetHostViewMac::MigrateNSViewBridge(
     remote_cocoa::mojom::Application* remote_cocoa_application,
     uint64_t parent_ns_view_id) {
+#if !IS_MAS_BUILD()
   // Destroy the previous remote accessibility element.
   remote_window_accessible_ = nil;
+#endif
 
   // Reset `ns_view_` before resetting `remote_ns_view_` to avoid dangling
   // pointers. `ns_view_` gets reinitialized later in this method.
@@ -555,7 +557,11 @@ void RenderWidgetHostViewMac::WasOcclude
     return;
 
   host()->WasHidden();
-  browser_compositor_->SetRenderWidgetHostIsHidden(true);
+  // Consider the RWHV occluded only if it is not attached to a window
+  // (e.g. unattached BrowserView). Otherwise we treat it as visible to
+  // prevent unnecessary compositor recycling.
+  const bool unattached = ![GetInProcessNSView() window];
+  browser_compositor_->SetRenderWidgetHostIsHidden(unattached);
 }
 
 void RenderWidgetHostViewMac::SetSize(const gfx::Size& size) {
@@ -1657,8 +1663,10 @@ RenderWidgetHostViewMac::AccessibilityGe
 
 gfx::NativeViewAccessible
 RenderWidgetHostViewMac::AccessibilityGetNativeViewAccessibleForWindow() {
+#if !IS_MAS_BUILD()
   if (remote_window_accessible_)
     return remote_window_accessible_;
+#endif
   return [GetInProcessNSView() window];
 }
 
@@ -1707,9 +1715,11 @@ id RenderWidgetHostViewMac::GetFocusedBr
 }
 
 void RenderWidgetHostViewMac::SetAccessibilityWindow(NSWindow* window) {
+#if !IS_MAS_BUILD()
   // When running in-process, just use the NSView's NSWindow as its own
   // accessibility element.
   remote_window_accessible_ = nil;
+#endif
 }
 
 bool RenderWidgetHostViewMac::SyncIsWidgetForMainFrame(
@@ -2233,20 +2243,26 @@ void RenderWidgetHostViewMac::StopSpeaki
 void RenderWidgetHostViewMac::GetRenderWidgetAccessibilityToken(
     GetRenderWidgetAccessibilityTokenCallback callback) {
   base::ProcessId pid = getpid();
+#if !IS_MAS_BUILD()
   id element_id = GetNativeViewAccessible();
   std::vector<uint8_t> token =
       ui::RemoteAccessibility::GetTokenForLocalElement(element_id);
   std::move(callback).Run(pid, token);
+#else
+  std::move(callback).Run(pid, std::vector<uint8_t>());
+#endif
 }
 
 void RenderWidgetHostViewMac::SetRemoteAccessibilityWindowToken(
     const std::vector<uint8_t>& window_token) {
+#if !IS_MAS_BUILD()
   if (window_token.empty()) {
     remote_window_accessible_ = nil;
   } else {
     remote_window_accessible_ =
         ui::RemoteAccessibility::GetRemoteElementFromToken(window_token);
   }
+#endif
 }
 
 ///////////////////////////////////////////////////////////////////////////////
