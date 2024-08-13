$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/gpu_process_host.cc.orig	2024-08-06 19:52:25.161958200 +0000
+++ content/browser/gpu/gpu_process_host.cc
@@ -273,6 +273,7 @@ static const char* const kSwitchNames[] 
     switches::kEnableLowEndDeviceMode,
     switches::kDisableSkiaGraphite,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -300,7 +301,7 @@ static const char* const kSwitchNames[] 
     switches::kOzoneDumpFile,
     switches::kEnableNativeGpuMemoryBuffers,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
