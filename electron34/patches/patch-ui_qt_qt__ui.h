$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/qt/qt_ui.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/qt/qt_ui.h
@@ -82,7 +82,8 @@ class QtUi : public ui::LinuxUiAndTheme,
   void SetAccentColor(std::optional<SkColor>) override;
   std::unique_ptr<ui::NavButtonProvider> CreateNavButtonProvider() override;
   ui::WindowFrameProvider* GetWindowFrameProvider(bool solid_frame,
-                                                  bool tiled) override;
+                                                  bool tiled,
+                                                  bool maximized) override;
 
   // QtInterface::Delegate:
   void FontChanged() override;
