$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/views/tabs/tab_close_button.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_close_button.h
@@ -46,9 +46,6 @@ class TabCloseButton : public views::Lab
   void OnMouseReleased(const ui::MouseEvent& event) override;
   void OnMouseMoved(const ui::MouseEvent& event) override;
   void OnGestureEvent(ui::GestureEvent* event) override;
-  void AddLayerToRegion(ui::Layer* new_layer,
-                        views::LayerRegion region) override;
-  void RemoveLayerFromRegions(ui::Layer* old_layer) override;
 
  protected:
   // Set/reset the image models for the icon with new colors.
