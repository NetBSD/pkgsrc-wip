$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_view_mac.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/render_widget_host_view_mac.h
@@ -23,6 +23,7 @@
 #include "content/browser/renderer_host/text_input_manager.h"
 #include "content/common/content_export.h"
 #include "content/common/render_widget_host_ns_view.mojom.h"
+#include "electron/mas.h"
 #include "mojo/public/cpp/bindings/associated_receiver.h"
 #include "mojo/public/cpp/bindings/associated_remote.h"
 #include "third_party/blink/public/mojom/webshare/webshare.mojom.h"
@@ -53,7 +54,9 @@ class CursorManager;
 
 @protocol RenderWidgetHostViewMacDelegate;
 
+#if !IS_MAS_BUILD()
 @class NSAccessibilityRemoteUIElement;
+#endif
 @class RenderWidgetHostViewCocoa;
 
 namespace content {
@@ -684,9 +687,11 @@ class CONTENT_EXPORT RenderWidgetHostVie
   // EnsureSurfaceSynchronizedForWebTest().
   uint32_t latest_capture_sequence_number_ = 0u;
 
+#if !IS_MAS_BUILD()
   // Remote accessibility objects corresponding to the NSWindow that this is
   // displayed to the user in.
   NSAccessibilityRemoteUIElement* __strong remote_window_accessible_;
+#endif
 
   // Used to force the NSApplication's focused accessibility element to be the
   // content::BrowserAccessibilityCocoa accessibility tree when the NSView for
