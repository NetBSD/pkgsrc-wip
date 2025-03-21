$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -118,7 +118,7 @@ std::vector<VEAFactoryFunction> GetVEAFa
     return vea_factory_functions;
 
 #if BUILDFLAG(USE_VAAPI)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     vea_factory_functions.push_back(base::BindRepeating(&CreateVaapiVEA));
   }
@@ -126,7 +126,7 @@ std::vector<VEAFactoryFunction> GetVEAFa
   vea_factory_functions.push_back(base::BindRepeating(&CreateVaapiVEA));
 #endif
 #elif BUILDFLAG(USE_V4L2_CODEC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     vea_factory_functions.push_back(base::BindRepeating(&CreateV4L2VEA));
   }
