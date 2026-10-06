$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/native_widget_mac_nswindow.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/remote_cocoa/app_shim/native_widget_mac_nswindow.mm
@@ -26,6 +26,7 @@
 #import "components/remote_cocoa/app_shim/views_nswindow_delegate.h"
 #import "components/remote_cocoa/app_shim/window_touch_bar_delegate.h"
 #include "components/remote_cocoa/common/native_widget_ns_window_host.mojom.h"
+#include "electron/mas.h"
 #import "ui/base/cocoa/user_interface_item_command_handler.h"
 #import "ui/base/cocoa/window_size_constants.h"
 
@@ -111,14 +112,18 @@ void OrderChildWindow(NSWindow* child_wi
 
 }  // namespace
 
+#if !IS_MAS_BUILD()
 @interface NSNextStepFrame (Private)
 - (instancetype)initWithFrame:(NSRect)frame
                     styleMask:(NSUInteger)styleMask
                         owner:(id)owner;
 @end
+#endif
 
 @interface NSWindow (Private)
+#if !IS_MAS_BUILD()
 + (Class)frameViewClassForStyleMask:(NSWindowStyleMask)windowStyle;
+#endif
 - (BOOL)hasKeyAppearance;
 - (long long)_resizeDirectionForMouseLocation:(CGPoint)location;
 - (BOOL)_isConsideredOpenForPersistentState;
@@ -157,6 +162,8 @@ void OrderChildWindow(NSWindow* child_wi
 }
 @end
 
+#if !IS_MAS_BUILD()
+
 @implementation NativeWidgetMacNSWindowTitledFrame
 - (void)mouseDown:(NSEvent*)event {
   if (self.window.isMovable)
@@ -184,6 +191,8 @@ void OrderChildWindow(NSWindow* child_wi
 }
 @end
 
+#endif  // MAS_BUILD
+
 @implementation NativeWidgetMacNSWindow {
  @private
   CommandDispatcher* __strong _commandDispatcher;
@@ -380,6 +389,8 @@ void OrderChildWindow(NSWindow* child_wi
 
 // NSWindow overrides.
 
+#if !IS_MAS_BUILD()
+
 + (Class)frameViewClassForStyleMask:(NSWindowStyleMask)windowStyle {
   if (windowStyle & NSWindowStyleMaskTitled) {
     if (Class customFrame = [NativeWidgetMacNSWindowTitledFrame class])
@@ -391,6 +402,8 @@ void OrderChildWindow(NSWindow* child_wi
   return [super frameViewClassForStyleMask:windowStyle];
 }
 
+#endif
+
 - (BOOL)_isTitleHidden {
   bool shouldShowWindowTitle = YES;
   if (_bridge)
