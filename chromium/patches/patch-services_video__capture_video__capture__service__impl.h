$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/video_capture/video_capture_service_impl.h.orig	2024-10-26 07:00:30.559268200 +0000
+++ services/video_capture/video_capture_service_impl.h
@@ -27,7 +27,7 @@
 #include "services/video_capture/ash/video_capture_device_factory_ash.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "services/viz/public/cpp/gpu/gpu.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_ASH)
@@ -75,7 +75,7 @@ class VideoCaptureServiceImpl : public m
 #if BUILDFLAG(IS_WIN)
   void OnGpuInfoUpdate(const CHROME_LUID& luid) override;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   void SetVizGpu(std::unique_ptr<viz::Gpu> viz_gpu);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_ASH)
@@ -120,7 +120,7 @@ class VideoCaptureServiceImpl : public m
       factory_receivers_ash_;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   class VizGpuContextProvider;
   std::unique_ptr<VizGpuContextProvider> viz_gpu_context_provider_;
   std::unique_ptr<viz::Gpu> viz_gpu_;
