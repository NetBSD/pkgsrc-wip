$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/video_capture/video_capture_service_impl.cc.orig	2024-10-18 12:34:32.201669500 +0000
+++ services/video_capture/video_capture_service_impl.cc
@@ -42,7 +42,7 @@
 #include "services/video_capture/lacros/device_factory_adapter_lacros.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "media/capture/capture_switches.h"
 #include "media/capture/video/video_capture_gpu_channel_host.h"
 #include "services/viz/public/cpp/gpu/context_provider_command_buffer.h"
@@ -110,7 +110,7 @@ class VideoCaptureServiceImpl::GpuDepend
       this};
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 // Intended usage of this class is to create viz::Gpu in utility process and
 // connect to viz::GpuClient of browser process, which will call to Gpu service.
 // Also, this class holds the viz::ContextProvider to listen and monitor Gpu
@@ -331,7 +331,7 @@ void VideoCaptureServiceImpl::LazyInitia
     gpu_dependencies_context_ = std::make_unique<GpuDependenciesContext>();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   {
 #else
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled()) {
@@ -463,7 +463,7 @@ void VideoCaptureServiceImpl::OnGpuInfoU
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 void VideoCaptureServiceImpl::SetVizGpu(std::unique_ptr<viz::Gpu> viz_gpu) {
   viz_gpu_ = std::move(viz_gpu);
 }
