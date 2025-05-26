$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/linux/fallback_linux_ui.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/linux/fallback_linux_ui.h
@@ -67,7 +67,8 @@ class FallbackLinuxUi : public LinuxUiAn
   void SetAccentColor(std::optional<SkColor> accent_color) override;
   std::unique_ptr<ui::NavButtonProvider> CreateNavButtonProvider() override;
   ui::WindowFrameProvider* GetWindowFrameProvider(bool solid_frame,
-                                                  bool tiled) override;
+                                                  bool tiled,
+                                                  bool maximized) override;
 
  private:
   std::optional<gfx::FontRenderParams> default_font_render_params_;
