$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gfx/mojom/ca_layer_params_mojom_traits.cc.orig	2024-10-18 12:35:12.688284600 +0000
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
