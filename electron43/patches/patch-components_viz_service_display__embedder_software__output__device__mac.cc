$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display_embedder/software_output_device_mac.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/viz/service/display_embedder/software_output_device_mac.cc
@@ -111,6 +111,8 @@ void SoftwareOutputDeviceMac::UpdateAndC
 
 SkCanvas* SoftwareOutputDeviceMac::BeginPaint(
     const gfx::Rect& new_damage_rect) {
+  last_damage = new_damage_rect;
+
   // Record the previous paint buffer.
   Buffer* previous_paint_buffer =
       buffer_queue_.empty() ? nullptr : buffer_queue_.back().get();
@@ -199,6 +201,7 @@ void SoftwareOutputDeviceMac::EndPaint()
     ca_layer_params.is_empty = false;
     ca_layer_params.scale_factor = scale_factor_;
     ca_layer_params.pixel_size = pixel_size_;
+    ca_layer_params.damage = last_damage;
     ca_layer_params.io_surface_mach_port.reset(
         IOSurfaceCreateMachPort(current_paint_buffer_->io_surface.get()));
     client_->SoftwareDeviceUpdatedCALayerParams(ca_layer_params);
