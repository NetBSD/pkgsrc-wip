$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/gpu_video_decode_accelerator_factory.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ media/gpu/gpu_video_decode_accelerator_factory.cc
@@ -13,7 +13,7 @@
 #include "media/gpu/media_gpu_export.h"
 #include "media/media_buildflags.h"
 
-#if BUILDFLAG(USE_V4L2_CODEC) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(USE_V4L2_CODEC) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #include "media/gpu/v4l2/legacy/v4l2_video_decode_accelerator.h"
 #include "media/gpu/v4l2/v4l2_device.h"
 #endif
@@ -29,7 +29,7 @@ GpuVideoDecodeAcceleratorFactory::Create
   if (gpu_preferences.disable_accelerated_video_decode)
     return nullptr;
 
-#if BUILDFLAG(USE_V4L2_CODEC) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(USE_V4L2_CODEC) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 
   std::unique_ptr<VideoDecodeAccelerator> vda;
   vda.reset(new V4L2VideoDecodeAccelerator(base::MakeRefCounted<V4L2Device>()));
