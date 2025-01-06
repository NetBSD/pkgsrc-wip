$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/remote_cocoa/app_shim/native_widget_mac_nswindow.mm.orig	2024-10-18 12:34:07.601962600 +0000
+++ components/remote_cocoa/app_shim/native_widget_mac_nswindow.mm
@@ -106,14 +106,18 @@ void OrderChildWindow(NSWindow* child_wi
 
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
@@ -152,6 +156,8 @@ void OrderChildWindow(NSWindow* child_wi
 }
 @end
 
+#if !IS_MAS_BUILD()
+
 @implementation NativeWidgetMacNSWindowTitledFrame
 - (void)mouseDown:(NSEvent*)event {
   if (self.window.isMovable)
@@ -179,6 +185,8 @@ void OrderChildWindow(NSWindow* child_wi
 }
 @end
 
+#endif  // MAS_BUILD
+
 @implementation NativeWidgetMacNSWindow {
  @private
   CommandDispatcher* __strong _commandDispatcher;
@@ -367,6 +375,8 @@ void OrderChildWindow(NSWindow* child_wi
 
 // NSWindow overrides.
 
+#if !IS_MAS_BUILD()
+
 + (Class)frameViewClassForStyleMask:(NSWindowStyleMask)windowStyle {
   if (windowStyle & NSWindowStyleMaskTitled) {
     if (Class customFrame = [NativeWidgetMacNSWindowTitledFrame class])
@@ -378,6 +388,8 @@ void OrderChildWindow(NSWindow* child_wi
   return [super frameViewClassForStyleMask:windowStyle];
 }
 
+#endif
+
 - (BOOL)_isTitleHidden {
   bool shouldShowWindowTitle = YES;
   if (_bridge)
