$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/views/toolbar/toolbar_button.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/views/toolbar/toolbar_button.cc
@@ -128,6 +128,12 @@ ToolbarButton::ToolbarButton(PressedCall
   if (model_) {
     GetViewAccessibility().SetHasPopup(ax::mojom::HasPopup::kMenu);
   }
+#if BUILDFLAG(IS_WIN)
+  // Paint image(s) to a layer so that the canvas is snapped to pixel
+  // boundaries.
+  image_container_view()->SetPaintToLayer();
+  image_container_view()->layer()->SetFillsBoundsOpaquely(false);
+#endif
 }
 
 ToolbarButton::~ToolbarButton() = default;
@@ -724,6 +730,24 @@ ToolbarButton::GetActionViewInterface() 
   return std::make_unique<ToolbarButtonActionViewInterface>(this);
 }
 
+void ToolbarButton::AddLayerToRegion(ui::Layer* new_layer,
+                                     views::LayerRegion region) {
+#if !BUILDFLAG(IS_WIN)
+  image_container_view()->SetPaintToLayer();
+  image_container_view()->layer()->SetFillsBoundsOpaquely(false);
+#endif
+  ink_drop_container()->SetVisible(true);
+  ink_drop_container()->AddLayerToRegion(new_layer, region);
+}
+
+void ToolbarButton::RemoveLayerFromRegions(ui::Layer* old_layer) {
+  ink_drop_container()->RemoveLayerFromRegions(old_layer);
+  ink_drop_container()->SetVisible(false);
+#if !BUILDFLAG(IS_WIN)
+  image_container_view()->DestroyLayer();
+#endif
+}
+
 ToolbarButtonActionViewInterface::ToolbarButtonActionViewInterface(
     ToolbarButton* action_view)
     : views::LabelButtonActionViewInterface(action_view),
