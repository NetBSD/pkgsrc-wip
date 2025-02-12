$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/config/gpu_finch_features.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/gpu/config/gpu_finch_features.cc
@@ -61,7 +61,7 @@ bool IsDeviceBlocked(const char* field, 
 
 // Used to limit GL version to 2.0 for skia raster and compositing.
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUseGles2ForOopR,
              "UseGles2ForOopR",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -142,7 +142,8 @@ BASE_FEATURE(kAggressiveSkiaGpuResourceP
 // DefaultEnableGpuRasterization has launched on Mac, Windows, ChromeOS,
 // Android and Linux.
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDefaultEnableGpuRasterization,
              "DefaultEnableGpuRasterization",
              base::FEATURE_ENABLED_BY_DEFAULT);
