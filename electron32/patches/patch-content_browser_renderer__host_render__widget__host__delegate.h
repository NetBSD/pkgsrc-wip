$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_delegate.h.orig	2024-10-18 12:34:13.594806400 +0000
+++ content/browser/renderer_host/render_widget_host_delegate.h
@@ -26,6 +26,7 @@
 #include "third_party/blink/public/mojom/manifest/display_mode.mojom.h"
 #include "ui/base/ui_base_types.h"
 #include "ui/gfx/mojom/delegated_ink_point_renderer.mojom.h"
+#include "ui/base/cursor/cursor.h"
 #include "ui/gfx/native_widget_types.h"
 
 namespace blink {
@@ -285,6 +286,9 @@ class CONTENT_EXPORT RenderWidgetHostDel
   // Returns the associated RenderViewHostDelegateView*, if possible.
   virtual RenderViewHostDelegateView* GetDelegateView();
 
+  // Notify the delegate of the RenderWidget's changing cursor.
+  virtual void OnCursorChanged(const ui::Cursor& cursor) {}
+
   // Returns true if the provided RenderWidgetHostImpl matches the current
   // RenderWidgetHost on the primary main frame, and false otherwise.
   virtual bool IsWidgetForPrimaryMainFrame(RenderWidgetHostImpl*);
