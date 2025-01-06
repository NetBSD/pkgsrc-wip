$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/cocoa/native_widget_mac_ns_window_host.h.orig	2024-10-18 12:35:12.824230400 +0000
+++ ui/views/cocoa/native_widget_mac_ns_window_host.h
@@ -31,7 +31,9 @@
 #include "ui/views/window/dialog_observer.h"
 
 @class NativeWidgetMacNSWindow;
+#if !IS_MAS_BUILD()
 @class NSAccessibilityRemoteUIElement;
+#endif
 @class NSView;
 
 namespace remote_cocoa {
@@ -483,10 +485,12 @@ class VIEWS_EXPORT NativeWidgetMacNSWind
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
