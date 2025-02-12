$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/gpu/compositor_util.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/content/browser/gpu/compositor_util.cc
@@ -149,7 +149,7 @@ const GpuFeatureData GetGpuFeatureData(
       {"video_decode",
        SafeGetFeatureStatus(gpu_feature_info,
                             gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE),
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
        !base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) ||
 #endif  // BUILDFLAG(IS_LINUX)
            command_line.HasSwitch(switches::kDisableAcceleratedVideoDecode),
@@ -160,7 +160,7 @@ const GpuFeatureData GetGpuFeatureData(
       {"video_encode",
        SafeGetFeatureStatus(gpu_feature_info,
                             gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_ENCODE),
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
        !base::FeatureList::IsEnabled(media::kVaapiVideoEncodeLinux),
 #else
        command_line.HasSwitch(switches::kDisableAcceleratedVideoEncode),
