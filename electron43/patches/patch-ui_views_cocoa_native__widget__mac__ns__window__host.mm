$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/cocoa/native_widget_mac_ns_window_host.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/cocoa/native_widget_mac_ns_window_host.mm
@@ -21,6 +21,7 @@
 #include "components/remote_cocoa/app_shim/native_widget_ns_window_bridge.h"
 #include "components/remote_cocoa/browser/ns_view_ids.h"
 #include "components/remote_cocoa/browser/window.h"
+#include "electron/mas.h"
 #include "mojo/public/cpp/bindings/self_owned_associated_receiver.h"
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
 #include "ui/accessibility/accessibility_features.h"
@@ -349,7 +350,11 @@ gfx::NativeViewAccessible
 NativeWidgetMacNSWindowHost::GetNativeViewAccessibleForNSView() const {
   if (in_process_ns_window_bridge_)
     return in_process_ns_window_bridge_->ns_view();
+#if !IS_MAS_BUILD()
   return remote_view_accessible_;
+#else
+  return nullptr;
+#endif
 }
 
 gfx::NativeViewAccessible
@@ -364,7 +369,11 @@ NativeWidgetMacNSWindowHost::GetNativeVi
     return [in_process_ns_window_bridge_->ns_view() window];
   }
 
+#if !IS_MAS_BUILD()
   return remote_window_accessible_;
+#else
+  return nullptr;
+#endif
 }
 
 remote_cocoa::mojom::NativeWidgetNSWindow*
@@ -1333,9 +1342,11 @@ void NativeWidgetMacNSWindowHost::OnWind
   // for PWAs. However this breaks accessibility on in-process windows,
   // so set it back to NO when a local window gains focus. See
   // https://crbug.com/41485830.
+#if !IS_MAS_BUILD()
   if (is_key && features::IsAccessibilityRemoteUIAppEnabled()) {
     [NSAccessibilityRemoteUIElement setRemoteUIApp:!!application_host_];
   }
+#endif
   // Explicitly set the keyboard accessibility state on regaining key
   // window status.
   if (is_key && is_content_first_responder)
@@ -1474,17 +1485,20 @@ void NativeWidgetMacNSWindowHost::OnFocu
 void NativeWidgetMacNSWindowHost::SetRemoteAccessibilityTokens(
     const std::vector<uint8_t>& window_token,
     const std::vector<uint8_t>& view_token) {
+#if !IS_MAS_BUILD()
   remote_window_accessible_ =
       ui::RemoteAccessibility::GetRemoteElementFromToken(window_token);
   remote_view_accessible_ =
       ui::RemoteAccessibility::GetRemoteElementFromToken(view_token);
   [remote_view_accessible_ setWindowUIElement:remote_window_accessible_];
   [remote_view_accessible_ setTopLevelUIElement:remote_window_accessible_];
+#endif
 }
 
 bool NativeWidgetMacNSWindowHost::GetRootViewAccessibilityToken(
     base::ProcessId* pid,
     std::vector<uint8_t>* token) {
+#if !IS_MAS_BUILD()
   *pid = getpid();
   id element_id = GetNativeViewAccessible();
 
@@ -1497,6 +1511,7 @@ bool NativeWidgetMacNSWindowHost::GetRoo
   }
 
   *token = ui::RemoteAccessibility::GetTokenForLocalElement(element_id);
+#endif
   return true;
 }
 
