$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/gpu/gpu_memory_buffer_manager_singleton.cc.orig	2024-10-18 12:34:12.471389300 +0000
+++ content/browser/gpu/gpu_memory_buffer_manager_singleton.cc
@@ -54,7 +54,7 @@ scoped_refptr<base::SingleThreadTaskRunn
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsGpuMemoryBufferNV12Supported() {
   static bool is_computed = false;
   static bool supported = false;
@@ -117,7 +117,7 @@ void GpuMemoryBufferManagerSingleton::On
     SetNativeConfigurations(std::move(configs));
   }
 #endif  // BUILDFLAG(IS_OZONE_X11)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Dynamic check whether the NV12 format is supported as it may be
   // inconsistent between the system GBM (Generic Buffer Management) and
   // chromium miniGBM.
