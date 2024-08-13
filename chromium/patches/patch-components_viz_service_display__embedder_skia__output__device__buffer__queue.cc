$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/display_embedder/skia_output_device_buffer_queue.cc.orig	2024-08-06 19:52:24.849931700 +0000
+++ components/viz/service/display_embedder/skia_output_device_buffer_queue.cc
@@ -174,7 +174,7 @@ SkiaOutputDeviceBufferQueue::SkiaOutputD
   capabilities_.only_invalidates_damage_rect = false;
   capabilities_.number_of_buffers = 3;
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   capabilities_.renderer_allocates_images =
       ::features::ShouldRendererAllocateImages();
 #else
