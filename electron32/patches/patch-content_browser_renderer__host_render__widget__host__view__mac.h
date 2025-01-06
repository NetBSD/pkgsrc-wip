$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_view_mac.h.orig	2024-10-18 12:34:13.646779500 +0000
+++ content/browser/renderer_host/render_widget_host_view_mac.h
@@ -53,7 +53,9 @@ class CursorManager;
 
 @protocol RenderWidgetHostViewMacDelegate;
 
+#if !IS_MAS_BUILD()
 @class NSAccessibilityRemoteUIElement;
+#endif
 @class RenderWidgetHostViewCocoa;
 @class CursorAccessibilityScaleFactorObserver;
 
@@ -686,9 +688,11 @@ class CONTENT_EXPORT RenderWidgetHostVie
   // EnsureSurfaceSynchronizedForWebTest().
   uint32_t latest_capture_sequence_number_ = 0u;
 
+#if !IS_MAS_BUILD()
   // Remote accessibility objects corresponding to the NSWindow that this is
   // displayed to the user in.
   NSAccessibilityRemoteUIElement* __strong remote_window_accessible_;
+#endif
 
   // Used to force the NSApplication's focused accessibility element to be the
   // content::BrowserAccessibilityCocoa accessibility tree when the NSView for
