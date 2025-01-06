$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/native_widget_ns_window_bridge.mm.orig	2024-10-18 12:34:07.601962600 +0000
+++ components/remote_cocoa/app_shim/native_widget_ns_window_bridge.mm
@@ -635,10 +635,12 @@ void NativeWidgetNSWindowBridge::CreateC
   // this should be treated as an error and caught early.
   CHECK(bridged_view_);
 
+#if !IS_MAS_BUILD()
   // Send the accessibility tokens for the NSView now that it exists.
   host_->SetRemoteAccessibilityTokens(
       ui::RemoteAccessibility::GetTokenForLocalElement(window_),
       ui::RemoteAccessibility::GetTokenForLocalElement(bridged_view_));
+#endif
 
   // Beware: This view was briefly removed (in favor of a bare CALayer) in
   // https://crrev.com/c/1236675. The ordering of unassociated layers relative
