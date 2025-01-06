$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/native_widget_mac_nswindow.h.orig	2024-10-18 12:34:07.597964800 +0000
+++ components/remote_cocoa/app_shim/native_widget_mac_nswindow.h
@@ -17,6 +17,7 @@ class NativeWidgetNSWindowBridge;
 
 @protocol WindowTouchBarDelegate;
 
+#if !IS_MAS_BUILD()
 // Weak lets Chrome launch even if a future macOS doesn't have the below classes
 WEAK_IMPORT_ATTRIBUTE
 @interface NSNextStepFrame : NSView
@@ -33,6 +34,7 @@ REMOTE_COCOA_APP_SHIM_EXPORT
 REMOTE_COCOA_APP_SHIM_EXPORT
 @interface NativeWidgetMacNSWindowTitledFrame : NSThemeFrame
 @end
+#endif
 
 // The NSWindow used by BridgedNativeWidget. Provides hooks into AppKit that
 // can only be accomplished by overriding methods.
