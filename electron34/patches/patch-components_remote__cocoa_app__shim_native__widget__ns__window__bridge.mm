$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/native_widget_ns_window_bridge.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/remote_cocoa/app_shim/native_widget_ns_window_bridge.mm
@@ -41,6 +41,7 @@
 #import "components/remote_cocoa/app_shim/views_nswindow_delegate.h"
 #import "components/remote_cocoa/app_shim/window_move_loop.h"
 #include "components/remote_cocoa/common/native_widget_ns_window_host.mojom.h"
+#include "electron/mas.h"
 #include "mojo/public/cpp/bindings/self_owned_receiver.h"
 #include "net/cert/x509_util_apple.h"
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
@@ -654,10 +655,12 @@ void NativeWidgetNSWindowBridge::CreateC
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
