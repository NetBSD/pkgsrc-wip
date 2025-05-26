$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display_embedder/software_output_surface.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/viz/service/display_embedder/software_output_surface.cc
@@ -113,7 +113,7 @@ void SoftwareOutputSurface::SwapBuffersC
   base::TimeTicks now = base::TimeTicks::Now();
   base::TimeDelta interval_to_next_refresh =
       now.SnappedToNextTick(refresh_timebase_, refresh_interval_) - now;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (needs_swap_size_notifications_)
     client_->DidSwapWithSize(pixel_size);
 #endif
@@ -140,7 +140,7 @@ gfx::OverlayTransform SoftwareOutputSurf
   return gfx::OVERLAY_TRANSFORM_NONE;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SoftwareOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {
   needs_swap_size_notifications_ = needs_swap_size_notifications;
