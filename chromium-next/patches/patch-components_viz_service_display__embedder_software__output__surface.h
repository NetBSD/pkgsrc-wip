$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/display_embedder/software_output_surface.h.orig	2025-01-27 17:37:37.000000000 +0000
+++ components/viz/service/display_embedder/software_output_surface.h
@@ -42,7 +42,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputS
       UpdateVSyncParametersCallback callback) override;
   void SetDisplayTransformHint(gfx::OverlayTransform transform) override {}
   gfx::OverlayTransform GetDisplayTransform() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
@@ -60,7 +60,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputS
   base::TimeTicks refresh_timebase_;
   base::TimeDelta refresh_interval_ = BeginFrameArgs::DefaultInterval();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool needs_swap_size_notifications_ = false;
 #endif
 
