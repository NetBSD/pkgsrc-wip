$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/web_contents_observer.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/web_contents_observer.h
@@ -37,6 +37,7 @@
 #include "third_party/blink/public/mojom/media/capture_handle_config.mojom-forward.h"
 #include "third_party/skia/include/core/SkColor.h"
 #include "ui/accessibility/ax_location_and_scroll_updates.h"
+#include "ui/base/cursor/cursor.h"
 #include "ui/base/page_transition_types.h"
 #include "ui/base/window_open_disposition.h"
 
@@ -617,6 +618,9 @@ class CONTENT_EXPORT WebContentsObserver
   // Invoked when the primary main frame changes size.
   virtual void PrimaryMainFrameWasResized(bool width_changed) {}
 
+  // Invoked every time the RenderWidget's cursor changes.
+  virtual void OnCursorChanged(const ui::Cursor& cursor) {}
+
   // Invoked when the given frame changes its window.name property.
   virtual void FrameNameChanged(RenderFrameHost* render_frame_host,
                                 const std::string& name) {}
