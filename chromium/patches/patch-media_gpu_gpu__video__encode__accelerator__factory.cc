$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -67,7 +67,7 @@ std::unique_ptr<VideoEncodeAccelerator> 
 }
 #elif BUILDFLAG(USE_VAAPI)
 std::unique_ptr<VideoEncodeAccelerator> CreateVaapiVEA() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     return nullptr;
   }
