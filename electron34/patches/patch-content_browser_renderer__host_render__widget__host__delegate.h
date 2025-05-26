$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_delegate.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/render_widget_host_delegate.h
@@ -27,6 +27,7 @@
 #include "ui/base/mojom/window_show_state.mojom-forward.h"
 #include "ui/base/ui_base_types.h"
 #include "ui/gfx/mojom/delegated_ink_point_renderer.mojom.h"
+#include "ui/base/cursor/cursor.h"
 #include "ui/gfx/native_widget_types.h"
 
 namespace blink {
@@ -293,6 +294,9 @@ class CONTENT_EXPORT RenderWidgetHostDel
   // Returns the associated RenderViewHostDelegateView*, if possible.
   virtual RenderViewHostDelegateView* GetDelegateView();
 
+  // Notify the delegate of the RenderWidget's changing cursor.
+  virtual void OnCursorChanged(const ui::Cursor& cursor) {}
+
   // Returns true if the provided RenderWidgetHostImpl matches the current
   // RenderWidgetHost on the primary main frame, and false otherwise.
   virtual bool IsWidgetForPrimaryMainFrame(RenderWidgetHostImpl*);
