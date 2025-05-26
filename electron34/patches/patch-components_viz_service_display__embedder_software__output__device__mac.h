$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display_embedder/software_output_device_mac.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/viz/service/display_embedder/software_output_device_mac.h
@@ -62,6 +62,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputD
   void UpdateAndCopyBufferDamage(Buffer* previous_paint_buffer,
                                  const SkRegion& new_damage_rect);
 
+  gfx::Rect last_damage;
   gfx::Size pixel_size_;
   float scale_factor_ = 1;
 
