$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/platform_shared_memory_region.h.orig	2025-03-20 19:11:33.000000000 +0000
+++ base/memory/platform_shared_memory_region.h
@@ -18,7 +18,7 @@
 #include "base/unguessable_token.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace content {
 class SandboxIPCHandler;
 }
@@ -85,7 +85,7 @@ class BASE_EXPORT PlatformSharedMemoryRe
     kMaxValue = GET_SHMEM_TEMP_DIR_FAILURE
   };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Structure to limit access to executable region creation.
   struct ExecutableRegion {
    private:
@@ -217,7 +217,7 @@ class BASE_EXPORT PlatformSharedMemoryRe
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                            ,
                                            bool executable = false
 #endif
