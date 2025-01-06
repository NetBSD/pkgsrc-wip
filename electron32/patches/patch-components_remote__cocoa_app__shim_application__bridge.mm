$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/application_bridge.mm.orig	2024-10-18 12:34:07.597964800 +0000
+++ components/remote_cocoa/app_shim/application_bridge.mm
@@ -50,6 +50,7 @@ class NativeWidgetBridgeOwner : public N
 
   // NativeWidgetNSWindowHostHelper:
   id GetNativeViewAccessible() override {
+#if !IS_MAS_BUILD()
     if (!remote_accessibility_element_) {
       base::ProcessId browser_pid = base::kNullProcessId;
       std::vector<uint8_t> element_token;
@@ -60,6 +61,9 @@ class NativeWidgetBridgeOwner : public N
           ui::RemoteAccessibility::GetRemoteElementFromToken(element_token);
     }
     return remote_accessibility_element_;
+#else
+    return nil;
+#endif
   }
   void DispatchKeyEvent(ui::KeyEvent* event) override {
     bool event_handled = false;
@@ -98,7 +102,9 @@ class NativeWidgetBridgeOwner : public N
   mojo::AssociatedRemote<mojom::TextInputHost> text_input_host_remote_;
 
   std::unique_ptr<NativeWidgetNSWindowBridge> bridge_;
+#if !IS_MAS_BUILD()
   NSAccessibilityRemoteUIElement* __strong remote_accessibility_element_;
+#endif
 };
 
 }  // namespace
