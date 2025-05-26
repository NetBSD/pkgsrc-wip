$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gfx/mojom/ca_layer_params_mojom_traits.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gfx/mojom/ca_layer_params_mojom_traits.h
@@ -20,6 +20,10 @@ struct StructTraits<gfx::mojom::CALayerP
     return ca_layer_params.pixel_size;
   }
 
+  static gfx::Rect damage(const gfx::CALayerParams& ca_layer_params) {
+    return ca_layer_params.damage;
+  }
+
   static float scale_factor(const gfx::CALayerParams& ca_layer_params) {
     return ca_layer_params.scale_factor;
   }
