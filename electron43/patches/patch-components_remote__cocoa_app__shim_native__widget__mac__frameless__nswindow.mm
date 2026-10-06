$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/native_widget_mac_frameless_nswindow.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/remote_cocoa/app_shim/native_widget_mac_frameless_nswindow.mm
@@ -4,6 +4,10 @@
 
 #import "components/remote_cocoa/app_shim/native_widget_mac_frameless_nswindow.h"
 
+#include "electron/mas.h"
+
+#if !IS_MAS_BUILD()
+
 @interface NSWindow (PrivateAPI)
 + (Class)frameViewClassForStyleMask:(NSUInteger)windowStyle;
 @end
@@ -18,8 +22,12 @@
 }
 @end
 
+#endif  // MAS_BUILD
+
 @implementation NativeWidgetMacFramelessNSWindow
 
+#if !IS_MAS_BUILD()
+
 + (Class)frameViewClassForStyleMask:(NSUInteger)windowStyle {
   if ([NativeWidgetMacFramelessNSWindowFrame class]) {
     return [NativeWidgetMacFramelessNSWindowFrame class];
@@ -27,4 +35,6 @@
   return [super frameViewClassForStyleMask:windowStyle];
 }
 
+#endif  // MAS_BUILD
+
 @end
