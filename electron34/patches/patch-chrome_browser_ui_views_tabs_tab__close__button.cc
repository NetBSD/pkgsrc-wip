$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/views/tabs/tab_close_button.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_close_button.cc
@@ -18,7 +18,6 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/metadata/metadata_impl_macros.h"
 #include "ui/base/pointer/touch_ui_controller.h"
-#include "ui/compositor/layer.h"
 #include "ui/gfx/canvas.h"
 #include "ui/gfx/color_utils.h"
 #include "ui/gfx/geometry/insets.h"
@@ -63,8 +62,6 @@ TabCloseButton::TabCloseButton(PressedCa
   views::InkDrop::Get(this)->GetInkDrop()->SetHoverHighlightFadeDuration(
       base::TimeDelta());
 
-  image_container_view()->DestroyLayer();
-
   // The ink drop highlight path is the same as the focus ring highlight path,
   // but needs to be explicitly mirrored for RTL.
   // TODO(http://crbug.com/1056490): Make ink drops in RTL work the same way as
@@ -145,20 +142,6 @@ void TabCloseButton::OnGestureEvent(ui::
   event->SetHandled();
 }
 
-void TabCloseButton::AddLayerToRegion(ui::Layer* new_layer,
-                                      views::LayerRegion region) {
-  image_container_view()->SetPaintToLayer();
-  image_container_view()->layer()->SetFillsBoundsOpaquely(false);
-  ink_drop_container()->SetVisible(true);
-  ink_drop_container()->AddLayerToRegion(new_layer, region);
-}
-
-void TabCloseButton::RemoveLayerFromRegions(ui::Layer* old_layer) {
-  ink_drop_container()->RemoveLayerFromRegions(old_layer);
-  ink_drop_container()->SetVisible(false);
-  image_container_view()->DestroyLayer();
-}
-
 gfx::Size TabCloseButton::CalculatePreferredSize(
     const views::SizeBounds& available_size) const {
   return kButtonSize;
