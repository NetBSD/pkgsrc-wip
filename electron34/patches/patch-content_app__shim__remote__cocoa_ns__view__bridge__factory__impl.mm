$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/app_shim_remote_cocoa/ns_view_bridge_factory_impl.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/app_shim_remote_cocoa/ns_view_bridge_factory_impl.mm
@@ -15,6 +15,7 @@
 #include "content/common/web_contents_ns_view_bridge.mojom.h"
 #include "content/public/browser/remote_cocoa.h"
 #include "content/public/browser/render_widget_host_view_mac_delegate.h"
+#include "electron/mas.h"
 #include "mojo/public/cpp/bindings/associated_receiver.h"
 #include "mojo/public/cpp/bindings/associated_remote.h"
 #include "mojo/public/cpp/bindings/pending_associated_receiver.h"
@@ -63,7 +64,9 @@ class RenderWidgetHostNSViewBridgeOwner
       const RenderWidgetHostNSViewBridgeOwner&) = delete;
 
  private:
+#if !IS_MAS_BUILD()
   NSAccessibilityRemoteUIElement* __strong remote_accessibility_element_;
+#endif
   void OnMojoDisconnect() { delete this; }
 
   std::unique_ptr<blink::WebCoalescedInputEvent> TranslateEvent(
@@ -75,6 +78,7 @@ class RenderWidgetHostNSViewBridgeOwner
   }
 
   id GetAccessibilityElement() override {
+#if !IS_MAS_BUILD()
     if (!remote_accessibility_element_) {
       base::ProcessId browser_pid = base::kNullProcessId;
       std::vector<uint8_t> element_token;
@@ -85,6 +89,9 @@ class RenderWidgetHostNSViewBridgeOwner
           ui::RemoteAccessibility::GetRemoteElementFromToken(element_token);
     }
     return remote_accessibility_element_;
+#else
+    return nil;
+#endif
   }
 
   // RenderWidgetHostNSViewHostHelper implementation.
@@ -103,8 +110,10 @@ class RenderWidgetHostNSViewBridgeOwner
     return [bridgedContentView accessibilityFocusedUIElement];
   }
   void SetAccessibilityWindow(NSWindow* window) override {
+#if !IS_MAS_BUILD()
     host_->SetRemoteAccessibilityWindowToken(
         ui::RemoteAccessibility::GetTokenForLocalElement(window));
+#endif
   }
 
   void ForwardKeyboardEvent(const input::NativeWebKeyboardEvent& key_event,
