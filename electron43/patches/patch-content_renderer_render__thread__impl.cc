$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/render_thread_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/renderer/render_thread_impl.cc
@@ -212,6 +212,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif BUILDFLAG(IS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -1046,7 +1048,7 @@ media::GpuVideoAcceleratorFactories* Ren
                              kGpuStreamIdMedia, kGpuStreamPriorityMedia);
 
   const bool enable_video_decode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kAcceleratedVideoDecodeLinux) &&
 #endif  // BUILDFLAG(IS_LINUX)
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode) &&
@@ -1055,7 +1057,7 @@ media::GpuVideoAcceleratorFactories* Ren
        gpu::kGpuFeatureStatusEnabled);
 
   const bool enable_video_encode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kAcceleratedVideoEncodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoEncode) &&
@@ -1306,7 +1308,7 @@ bool RenderThreadImpl::IsLcdTextEnabled(
 }
 
 bool RenderThreadImpl::IsElasticOverscrollEnabled() {
-  return is_elastic_overscroll_enabled_;
+  return base::CommandLine::ForCurrentProcess()->HasSwitch("scroll-bounce");
 }
 
 gpu::GpuMemoryBufferManager* RenderThreadImpl::GetGpuMemoryBufferManager() {
@@ -1850,7 +1852,7 @@ std::unique_ptr<CodecFactory> RenderThre
     bool enable_video_encode_accelerator) {
   mojo::PendingRemote<media::mojom::VideoEncodeAcceleratorProvider>
       vea_provider;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseOutOfProcessVideoEncoding)) {
     BindHostReceiver(vea_provider.InitWithNewPipeAndPassReceiver());
   } else {
