$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/platform_shared_memory_region.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ base/memory/platform_shared_memory_region.h
@@ -19,7 +19,7 @@
 #include "base/unguessable_token.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace content {
 class SandboxIPCHandler;
 }
@@ -86,7 +86,7 @@ class BASE_EXPORT PlatformSharedMemoryRe
     kMaxValue = GET_SHMEM_TEMP_DIR_FAILURE
   };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Structure to limit access to executable region creation.
   struct ExecutableRegion {
    private:
@@ -125,7 +125,7 @@ class BASE_EXPORT PlatformSharedMemoryRe
 #if BUILDFLAG(IS_FUCHSIA)
     kNotVmo,
 #endif
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFcntlFailed,
     kReadOnlyFdNotReadOnly,
     kUnexpectedReadOnlyFd,
@@ -256,7 +256,7 @@ class BASE_EXPORT PlatformSharedMemoryRe
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                            ,
                                            bool executable = false
 #endif
