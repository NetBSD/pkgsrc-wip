$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gfx/ca_layer_params.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gfx/ca_layer_params.h
@@ -7,6 +7,7 @@
 
 #include "base/component_export.h"
 #include "build/build_config.h"
+#include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/geometry/size.h"
 
 #if BUILDFLAG(IS_APPLE)
@@ -51,6 +52,8 @@ struct COMPONENT_EXPORT(GFX) CALayerPara
   gfx::ScopedRefCountedIOSurfaceMachPort io_surface_mach_port;
 #endif
 
+  gfx::Rect damage;
+
   // The geometry of the frame.
   gfx::Size pixel_size;
   float scale_factor = 1.f;
