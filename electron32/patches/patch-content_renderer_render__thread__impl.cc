$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/render_thread_impl.cc.orig	2024-10-18 12:34:14.622276800 +0000
+++ content/renderer/render_thread_impl.cc
@@ -214,6 +214,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif BUILDFLAG(IS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -1017,7 +1019,7 @@ media::GpuVideoAcceleratorFactories* Ren
                              kGpuStreamIdMedia, kGpuStreamPriorityMedia);
 
   const bool enable_video_decode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) &&
 #endif  // BUILDFLAG(IS_LINUX)
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode) &&
@@ -1026,7 +1028,7 @@ media::GpuVideoAcceleratorFactories* Ren
        gpu::kGpuFeatureStatusEnabled);
 
   const bool enable_video_encode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoEncodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoEncode) &&
@@ -1276,7 +1278,7 @@ bool RenderThreadImpl::IsLcdTextEnabled(
 }
 
 bool RenderThreadImpl::IsElasticOverscrollEnabled() {
-  return is_elastic_overscroll_enabled_;
+  return base::CommandLine::ForCurrentProcess()->HasSwitch("scroll-bounce");
 }
 
 gpu::GpuMemoryBufferManager* RenderThreadImpl::GetGpuMemoryBufferManager() {
@@ -1801,7 +1803,7 @@ std::unique_ptr<CodecFactory> RenderThre
     bool enable_video_encode_accelerator) {
   mojo::PendingRemote<media::mojom::VideoEncodeAcceleratorProvider>
       vea_provider;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseOutOfProcessVideoEncoding)) {
     BindHostReceiver(vea_provider.InitWithNewPipeAndPassReceiver());
   } else {
