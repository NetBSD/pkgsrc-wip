$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/browser_native_widget_window_mac.mm.orig	2024-10-18 12:34:07.597964800 +0000
+++ components/remote_cocoa/app_shim/browser_native_widget_window_mac.mm
@@ -9,6 +9,7 @@
 #include "components/remote_cocoa/app_shim/native_widget_ns_window_bridge.h"
 #include "components/remote_cocoa/common/native_widget_ns_window_host.mojom.h"
 
+#if !IS_MAS_BUILD()
 @interface NSWindow (PrivateBrowserNativeWidgetAPI)
 + (Class)frameViewClassForStyleMask:(NSUInteger)windowStyle;
 @end
@@ -65,10 +66,13 @@
 
 @end
 
+#endif  // MAS_BUILD
+
 @implementation BrowserNativeWidgetWindow
 
 // NSWindow (PrivateAPI) overrides.
 
+#if !IS_MAS_BUILD()
 + (Class)frameViewClassForStyleMask:(NSUInteger)windowStyle {
   // - NSThemeFrame and its subclasses will be nil if it's missing at runtime.
   if ([BrowserWindowFrame class])
@@ -115,6 +119,8 @@
   return NO;
 }
 
+#endif  // MAS_BUILD
+
 // Handle "Move focus to the window toolbar" configured in System Preferences ->
 // Keyboard -> Shortcuts -> Keyboard. Usually Ctrl+F5. The argument (|unknown|)
 // tends to just be nil.
