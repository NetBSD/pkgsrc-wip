$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/widget/desktop_aura/desktop_window_tree_host_win.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_win.h
@@ -266,6 +266,7 @@ class VIEWS_EXPORT DesktopWindowTreeHost
   void HandleWindowSizeUnchanged() override;
   void HandleWindowScaleFactorChanged(float window_scale_factor) override;
   void HandleHeadlessWindowBoundsChanged(const gfx::Rect& bounds) override;
+  bool HandleMouseEventForCaption(UINT message) const override;
 
   Widget* GetWidget();
   const Widget* GetWidget() const;
