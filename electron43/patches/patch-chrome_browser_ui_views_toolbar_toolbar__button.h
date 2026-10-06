$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/views/toolbar/toolbar_button.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/views/toolbar/toolbar_button.h
@@ -132,6 +132,9 @@ class ToolbarButton : public views::Labe
   void OnGestureEvent(ui::GestureEvent* event) override;
   std::u16string GetTooltipText(const gfx::Point& p) const override;
   std::unique_ptr<views::ActionViewInterface> GetActionViewInterface() override;
+  void AddLayerToRegion(ui::Layer* new_layer,
+                        views::LayerRegion region) override;
+  void RemoveLayerFromRegions(ui::Layer* old_layer) override;
 
   // views::ContextMenuController:
   void ShowContextMenuForViewImpl(
