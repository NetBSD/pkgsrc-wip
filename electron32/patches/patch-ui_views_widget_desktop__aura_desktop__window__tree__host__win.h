$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/widget/desktop_aura/desktop_window_tree_host_win.h.orig	2024-10-18 12:35:12.872211500 +0000
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_win.h
@@ -263,6 +263,7 @@ class VIEWS_EXPORT DesktopWindowTreeHost
   void HandleWindowSizeUnchanged() override;
   void HandleWindowScaleFactorChanged(float window_scale_factor) override;
   void HandleHeadlessWindowBoundsChanged(const gfx::Rect& bounds) override;
+  bool HandleMouseEventForCaption(UINT message) const override;
 
   Widget* GetWidget();
   const Widget* GetWidget() const;
