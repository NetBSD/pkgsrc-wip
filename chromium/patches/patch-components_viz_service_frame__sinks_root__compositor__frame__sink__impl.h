$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -222,7 +222,7 @@ class VIZ_SERVICE_EXPORT RootCompositorF
   base::TimeDelta display_frame_interval_ = BeginFrameArgs::DefaultInterval();
   base::TimeDelta preferred_frame_interval_;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
