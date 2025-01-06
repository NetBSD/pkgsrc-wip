$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/app_shim_remote_cocoa/ns_view_bridge_factory_impl.mm.orig	2024-10-18 12:34:11.939666300 +0000
+++ content/app_shim_remote_cocoa/ns_view_bridge_factory_impl.mm
@@ -63,7 +63,9 @@ class RenderWidgetHostNSViewBridgeOwner
       const RenderWidgetHostNSViewBridgeOwner&) = delete;
 
  private:
+#if !IS_MAS_BUILD()
   NSAccessibilityRemoteUIElement* __strong remote_accessibility_element_;
+#endif
   void OnMojoDisconnect() { delete this; }
 
   std::unique_ptr<blink::WebCoalescedInputEvent> TranslateEvent(
@@ -75,6 +77,7 @@ class RenderWidgetHostNSViewBridgeOwner
   }
 
   id GetAccessibilityElement() override {
+#if !IS_MAS_BUILD()
     if (!remote_accessibility_element_) {
       base::ProcessId browser_pid = base::kNullProcessId;
       std::vector<uint8_t> element_token;
@@ -85,6 +88,9 @@ class RenderWidgetHostNSViewBridgeOwner
           ui::RemoteAccessibility::GetRemoteElementFromToken(element_token);
     }
     return remote_accessibility_element_;
+#else
+    return nil;
+#endif
   }
 
   // RenderWidgetHostNSViewHostHelper implementation.
@@ -103,8 +109,10 @@ class RenderWidgetHostNSViewBridgeOwner
     return [bridgedContentView accessibilityFocusedUIElement];
   }
   void SetAccessibilityWindow(NSWindow* window) override {
+#if !IS_MAS_BUILD()
     host_->SetRemoteAccessibilityWindowToken(
         ui::RemoteAccessibility::GetTokenForLocalElement(window));
+#endif
   }
 
   void ForwardKeyboardEvent(const input::NativeWebKeyboardEvent& key_event,
