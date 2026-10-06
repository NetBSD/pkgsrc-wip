$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display_embedder/software_output_device_win.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/viz/service/display_embedder/software_output_device_win.cc
@@ -193,7 +193,7 @@ void SoftwareOutputDeviceWinProxy::EndPa
   if (!canvas_)
     return;
 
-  layered_window_updater_->Draw(base::BindOnce(
+  layered_window_updater_->Draw(damage_rect, base::BindOnce(
       &SoftwareOutputDeviceWinProxy::DrawAck, base::Unretained(this)));
   waiting_on_draw_ack_ = true;
 
