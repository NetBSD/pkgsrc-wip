$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/native_widget_mac_nswindow.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/remote_cocoa/app_shim/native_widget_mac_nswindow.h
@@ -9,6 +9,7 @@
 
 #include "base/apple/foundation_util.h"
 #include "components/remote_cocoa/app_shim/remote_cocoa_app_shim_export.h"
+#include "electron/mas.h"
 #import "ui/base/cocoa/command_dispatcher.h"
 
 namespace remote_cocoa {
@@ -17,6 +18,7 @@ class NativeWidgetNSWindowBridge;
 
 @protocol WindowTouchBarDelegate;
 
+#if !IS_MAS_BUILD()
 // Weak lets Chrome launch even if a future macOS doesn't have the below classes
 WEAK_IMPORT_ATTRIBUTE
 @interface NSNextStepFrame : NSView
@@ -33,6 +35,7 @@ REMOTE_COCOA_APP_SHIM_EXPORT
 REMOTE_COCOA_APP_SHIM_EXPORT
 @interface NativeWidgetMacNSWindowTitledFrame : NSThemeFrame
 @end
+#endif
 
 // The NSWindow used by BridgedNativeWidget. Provides hooks into AppKit that
 // can only be accomplished by overriding methods.
