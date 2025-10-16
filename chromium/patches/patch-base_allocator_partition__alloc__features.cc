$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_alloc_features.cc.orig	2025-09-29 17:05:47.000000000 +0000
+++ base/allocator/partition_alloc_features.cc
@@ -143,7 +143,7 @@ BASE_FEATURE(PartitionAllocEventuallyZer
 // Evaluated and positive stability and peformance-wise on Linux-based systems,
 // disabled elsewhere (for now). Does not apply to Windows.
 BASE_FEATURE(PartitionAllocFewerMemoryRegions,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
