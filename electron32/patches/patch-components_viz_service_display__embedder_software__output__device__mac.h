$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display_embedder/software_output_device_mac.h.orig	2024-10-18 12:34:11.627829600 +0000
+++ components/viz/service/display_embedder/software_output_device_mac.h
@@ -62,6 +62,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputD
   void UpdateAndCopyBufferDamage(Buffer* previous_paint_buffer,
                                  const SkRegion& new_damage_rect);
 
+  gfx::Rect last_damage;
   gfx::Size pixel_size_;
   float scale_factor_ = 1;
 
