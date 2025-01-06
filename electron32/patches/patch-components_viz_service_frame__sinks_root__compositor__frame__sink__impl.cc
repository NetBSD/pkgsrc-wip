$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc.orig	2024-10-18 12:34:11.647819300 +0000
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc
@@ -100,7 +100,8 @@ RootCompositorFrameSinkImpl::Create(
       params->gpu_compositing, params->widget);
   auto output_surface = output_surface_provider->CreateOutputSurface(
       params->widget, params->gpu_compositing, display_client.get(),
-      display_controller.get(), params->renderer_settings, debug_settings);
+      display_controller.get(), params->renderer_settings, debug_settings,
+      params->offscreen);
 
   // Creating output surface failed. The host can send a new request, possibly
   // with a different compositing mode.
@@ -111,7 +112,7 @@ RootCompositorFrameSinkImpl::Create(
   output_surface->SetNeedsSwapSizeNotifications(
       params->send_swap_size_notifications);
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   // For X11, we need notify client about swap completion after resizing, so the
   // client can use it for synchronize with X11 WM.
   output_surface->SetNeedsSwapSizeNotifications(true);
@@ -673,7 +674,7 @@ void RootCompositorFrameSinkImpl::Displa
   if (display_client_ && enable_swap_completion_callback_) {
     display_client_->DidCompleteSwapWithSize(pixel_size);
   }
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   if (display_client_ && pixel_size != last_swap_pixel_size_) {
     last_swap_pixel_size_ = pixel_size;
     display_client_->DidCompleteSwapWithNewSize(last_swap_pixel_size_);
