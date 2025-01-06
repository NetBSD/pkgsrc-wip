$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gtk/gtk_ui.h.orig	2024-10-18 12:35:12.728268900 +0000
+++ ui/gtk/gtk_ui.h
@@ -110,7 +110,8 @@ class GtkUi : public ui::LinuxUiAndTheme
   void SetAccentColor(std::optional<SkColor> accent_color) override;
   std::unique_ptr<ui::NavButtonProvider> CreateNavButtonProvider() override;
   ui::WindowFrameProvider* GetWindowFrameProvider(bool solid_frame,
-                                                  bool tiled) override;
+                                                  bool tiled,
+                                                  bool maximized) override;
 
  private:
   using TintMap = std::map<int, color_utils::HSL>;
@@ -199,7 +200,7 @@ class GtkUi : public ui::LinuxUiAndTheme
   // while Chrome is running.  This 2D array is indexed first by whether the
   // frame is translucent (0) or solid(1), then by whether the frame is normal
   // (0) or tiled (1).
-  std::unique_ptr<ui::WindowFrameProvider> frame_providers_[2][2];
+  std::unique_ptr<ui::WindowFrameProvider> frame_providers_[2][2][2];
 
   // Objects to notify when the window frame button order changes.
   base::ObserverList<ui::WindowButtonOrderObserver>::Unchecked
