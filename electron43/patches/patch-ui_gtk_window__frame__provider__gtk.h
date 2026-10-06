$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gtk/window_frame_provider_gtk.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gtk/window_frame_provider_gtk.h
@@ -20,7 +20,7 @@ namespace gtk {
 
 class WindowFrameProviderGtk : public ui::WindowFrameProvider {
  public:
-  WindowFrameProviderGtk(bool solid_frame, bool tiled);
+  WindowFrameProviderGtk(bool solid_frame, bool tiled, bool maximized);
 
   WindowFrameProviderGtk(const WindowFrameProviderGtk&) = delete;
   WindowFrameProviderGtk& operator=(const WindowFrameProviderGtk&) = delete;
@@ -65,6 +65,8 @@ class WindowFrameProviderGtk : public ui
   // Input parameters used for drawing.
   const bool solid_frame_;
   const bool tiled_;
+  // Whether to draw the window decorations as maximized.
+  const bool maximized_;
 
   // Scale-independent metric calculated based on the bitmaps.
   std::optional<gfx::Insets> frame_thickness_dip_;
