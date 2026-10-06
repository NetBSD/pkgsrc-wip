$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/cocoa/native_widget_mac_ns_window_host.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/cocoa/native_widget_mac_ns_window_host.h
@@ -18,6 +18,7 @@
 #include "components/remote_cocoa/browser/scoped_cg_window_id.h"
 #include "components/remote_cocoa/common/native_widget_ns_window.mojom.h"
 #include "components/remote_cocoa/common/native_widget_ns_window_host.mojom.h"
+#include "electron/mas.h"
 #include "mojo/public/cpp/bindings/associated_receiver.h"
 #include "mojo/public/cpp/bindings/associated_remote.h"
 #include "ui/accelerated_widget_mac/accelerated_widget_mac.h"
@@ -32,7 +33,9 @@
 #include "ui/views/window/dialog_observer.h"
 
 @class NativeWidgetMacNSWindow;
+#if !IS_MAS_BUILD()
 @class NSAccessibilityRemoteUIElement;
+#endif
 @class NSView;
 
 namespace remote_cocoa {
@@ -483,10 +486,12 @@ class VIEWS_EXPORT NativeWidgetMacNSWind
   mojo::AssociatedRemote<remote_cocoa::mojom::NativeWidgetNSWindow>
       remote_ns_window_remote_;
 
+#if !IS_MAS_BUILD()
   // Remote accessibility objects corresponding to the NSWindow and its root
   // NSView.
   NSAccessibilityRemoteUIElement* __strong remote_window_accessible_;
   NSAccessibilityRemoteUIElement* __strong remote_view_accessible_;
+#endif
 
   // Used to force the NSApplication's focused accessibility element to be the
   // views::Views accessibility tree when the NSView for this is focused.
