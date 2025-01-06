$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gfx/ca_layer_params.h.orig	2024-10-18 12:35:12.660296000 +0000
+++ ui/gfx/ca_layer_params.h
@@ -6,6 +6,7 @@
 #define UI_GFX_CA_LAYER_PARAMS_H_
 
 #include "build/build_config.h"
+#include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gfx_export.h"
 
@@ -51,6 +52,8 @@ struct GFX_EXPORT CALayerParams {
   gfx::ScopedRefCountedIOSurfaceMachPort io_surface_mach_port;
 #endif
 
+  gfx::Rect damage;
+
   // The geometry of the frame.
   gfx::Size pixel_size;
   float scale_factor = 1.f;
