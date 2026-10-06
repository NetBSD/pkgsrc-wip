$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gfx/mojom/ca_layer_params_mojom_traits.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gfx/mojom/ca_layer_params_mojom_traits.cc
@@ -52,6 +52,9 @@ bool StructTraits<gfx::mojom::CALayerPar
   if (!data.ReadPixelSize(&out->pixel_size))
     return false;
 
+  if (!data.ReadDamage(&out->damage))
+    return false;
+
   out->scale_factor = data.scale_factor();
   return true;
 }
