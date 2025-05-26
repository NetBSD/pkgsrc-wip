$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/browser_native_widget_window_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/remote_cocoa/app_shim/browser_native_widget_window_mac.mm
@@ -8,7 +8,9 @@
 
 #include "components/remote_cocoa/app_shim/native_widget_ns_window_bridge.h"
 #include "components/remote_cocoa/common/native_widget_ns_window_host.mojom.h"
+#include "electron/mas.h"
 
+#if !IS_MAS_BUILD()
 @interface NSWindow (PrivateBrowserNativeWidgetAPI)
 + (Class)frameViewClassForStyleMask:(NSUInteger)windowStyle;
 @end
@@ -95,10 +97,13 @@
 
 @end
 
+#endif  // MAS_BUILD
+
 @implementation BrowserNativeWidgetWindow
 
 // NSWindow (PrivateAPI) overrides.
 
+#if !IS_MAS_BUILD()
 + (Class)frameViewClassForStyleMask:(NSUInteger)windowStyle {
   // - NSThemeFrame and its subclasses will be nil if it's missing at runtime.
   if ([BrowserWindowFrame class])
@@ -145,6 +150,8 @@
   return NO;
 }
 
+#endif  // MAS_BUILD
+
 // Handle "Move focus to the window toolbar" configured in System Preferences ->
 // Keyboard -> Shortcuts -> Keyboard. Usually Ctrl+F5. The argument (|unknown|)
 // tends to just be nil.
@@ -155,8 +162,8 @@
 }
 
 - (void)setAlwaysShowTrafficLights:(BOOL)alwaysShow {
-  [base::apple::ObjCCastStrict<BrowserWindowFrame>(self.contentView.superview)
-      setAlwaysShowTrafficLights:alwaysShow];
+  // [base::apple::ObjCCastStrict<BrowserWindowFrame>(self.contentView.superview)
+  //    setAlwaysShowTrafficLights:alwaysShow];
 }
 
 @end
