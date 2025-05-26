$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/application_bridge.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/remote_cocoa/app_shim/application_bridge.mm
@@ -12,6 +12,7 @@
 #include "components/remote_cocoa/app_shim/native_widget_ns_window_bridge.h"
 #include "components/remote_cocoa/app_shim/native_widget_ns_window_host_helper.h"
 #include "components/system_media_controls/mac/remote_cocoa/system_media_controls_bridge.h"
+#include "electron/mas.h"
 #include "mojo/public/cpp/bindings/associated_remote.h"
 #include "mojo/public/cpp/bindings/self_owned_receiver.h"
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
@@ -51,6 +52,7 @@ class NativeWidgetBridgeOwner : public N
 
   // NativeWidgetNSWindowHostHelper:
   id GetNativeViewAccessible() override {
+#if !IS_MAS_BUILD()
     if (!remote_accessibility_element_) {
       base::ProcessId browser_pid = base::kNullProcessId;
       std::vector<uint8_t> element_token;
@@ -61,6 +63,9 @@ class NativeWidgetBridgeOwner : public N
           ui::RemoteAccessibility::GetRemoteElementFromToken(element_token);
     }
     return remote_accessibility_element_;
+#else
+    return nil;
+#endif
   }
   void DispatchKeyEvent(ui::KeyEvent* event) override {
     bool event_handled = false;
@@ -99,7 +104,9 @@ class NativeWidgetBridgeOwner : public N
   mojo::AssociatedRemote<mojom::TextInputHost> text_input_host_remote_;
 
   std::unique_ptr<NativeWidgetNSWindowBridge> bridge_;
+#if !IS_MAS_BUILD()
   NSAccessibilityRemoteUIElement* __strong remote_accessibility_element_;
+#endif
 };
 
 }  // namespace
