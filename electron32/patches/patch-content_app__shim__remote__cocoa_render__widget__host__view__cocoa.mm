$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/app_shim_remote_cocoa/render_widget_host_view_cocoa.mm.orig	2024-10-18 12:34:11.947662000 +0000
+++ content/app_shim_remote_cocoa/render_widget_host_view_cocoa.mm
@@ -169,6 +169,15 @@ void ExtractUnderlines(NSAttributedStrin
 
 }  // namespace
 
+@interface NSWindow (AtomCustomMethods)
+- (BOOL)acceptsFirstMouse;
+- (BOOL)disableAutoHideCursor;
+@end
+
+@interface NSView (ElectronCustomMethods)
+- (BOOL)shouldIgnoreMouseEvent;
+@end
+
 // RenderWidgetHostViewCocoa ---------------------------------------------------
 
 // Private methods:
@@ -767,6 +776,9 @@ void ExtractUnderlines(NSAttributedStrin
 }
 
 - (BOOL)acceptsFirstMouse:(NSEvent*)theEvent {
+  if ([self.window respondsToSelector:@selector(acceptsFirstMouse)] &&
+      [self.window acceptsFirstMouse])
+    return YES;
   // Enable "click-through" if mouse clicks are accepted in inactive windows
   return [self acceptsMouseEventsOption] > kAcceptMouseEventsInActiveWindow;
 }
@@ -861,6 +873,10 @@ void ExtractUnderlines(NSAttributedStrin
   // its parent view.
   BOOL hitSelf = NO;
   while (view) {
+    if ([view respondsToSelector:@selector(shouldIgnoreMouseEvent)] && ![view shouldIgnoreMouseEvent]) {
+      return NO;
+    }
+
     if (view == self)
       hitSelf = YES;
     if ([view isKindOfClass:[self class]] && ![view isEqual:self] &&
@@ -1183,6 +1199,10 @@ void ExtractUnderlines(NSAttributedStrin
                               eventType == NSEventTypeKeyDown &&
                               !(modifierFlags & NSEventModifierFlagCommand);
 
+  if ([theEvent.window respondsToSelector:@selector(disableAutoHideCursor)] &&
+      [theEvent.window disableAutoHideCursor])
+    shouldAutohideCursor = NO;
+
   // We only handle key down events and just simply forward other events.
   if (eventType != NSEventTypeKeyDown) {
     _hostHelper->ForwardKeyboardEvent(event, latencyInfo);
@@ -2042,15 +2062,21 @@ void ExtractUnderlines(NSAttributedStrin
 // Since this implementation doesn't have to wait any IPC calls, this doesn't
 // make any key-typing jank. --hbono 7/23/09
 //
+#if !IS_MAS_BUILD()
 extern "C" {
 extern NSString* NSTextInputReplacementRangeAttributeName;
 }
+#endif
 
 - (NSArray*)validAttributesForMarkedText {
   // This code is just copied from WebKit except renaming variables.
   static NSArray* const kAttributes = @[
     NSUnderlineStyleAttributeName, NSUnderlineColorAttributeName,
+#if !IS_MAS_BUILD()
     NSMarkedClauseSegmentAttributeName, NSTextInputReplacementRangeAttributeName
+#else
+    NSMarkedClauseSegmentAttributeName
+#endif
   ];
   return kAttributes;
 }
