$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/web_contents_observer.h.orig	2024-10-18 12:34:14.438371400 +0000
+++ content/public/browser/web_contents_observer.h
@@ -33,6 +33,7 @@
 #include "third_party/blink/public/mojom/loader/resource_load_info.mojom-forward.h"
 #include "third_party/blink/public/mojom/media/capture_handle_config.mojom-forward.h"
 #include "third_party/skia/include/core/SkColor.h"
+#include "ui/base/cursor/cursor.h"
 #include "ui/base/page_transition_types.h"
 #include "ui/base/window_open_disposition.h"
 
@@ -602,6 +603,9 @@ class CONTENT_EXPORT WebContentsObserver
   // Invoked when the primary main frame changes size.
   virtual void PrimaryMainFrameWasResized(bool width_changed) {}
 
+  // Invoked every time the RenderWidget's cursor changes.
+  virtual void OnCursorChanged(const ui::Cursor& cursor) {}
+
   // Invoked when the given frame changes its window.name property.
   virtual void FrameNameChanged(RenderFrameHost* render_frame_host,
                                 const std::string& name) {}
