$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/button/label_button.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/button/label_button.cc
@@ -78,13 +78,6 @@ LabelButton::LabelButton(
   SetTextInternal(text);
   SetLayoutManager(std::make_unique<DelegatingLayoutManager>(this));
   GetViewAccessibility().SetIsDefault(is_default_);
-
-#if BUILDFLAG(IS_WIN)
-  // Paint image(s) to a layer so that the canvas is snapped to pixel
-  // boundaries.
-  image_container_view()->SetPaintToLayer();
-  image_container_view()->layer()->SetFillsBoundsOpaquely(false);
-#endif
 }
 
 LabelButton::~LabelButton() {
@@ -508,10 +501,8 @@ void LabelButton::UpdateImage() {
 
 void LabelButton::AddLayerToRegion(ui::Layer* new_layer,
                                    views::LayerRegion region) {
-#if !BUILDFLAG(IS_WIN)
   image_container_view()->SetPaintToLayer();
   image_container_view()->layer()->SetFillsBoundsOpaquely(false);
-#endif
   ink_drop_container()->SetVisible(true);
   ink_drop_container()->AddLayerToRegion(new_layer, region);
 }
@@ -519,9 +510,7 @@ void LabelButton::AddLayerToRegion(ui::L
 void LabelButton::RemoveLayerFromRegions(ui::Layer* old_layer) {
   ink_drop_container()->RemoveLayerFromRegions(old_layer);
   ink_drop_container()->SetVisible(false);
-#if !BUILDFLAG(IS_WIN)
   image_container_view()->DestroyLayer();
-#endif
 }
 
 std::unique_ptr<ActionViewInterface> LabelButton::GetActionViewInterface() {
