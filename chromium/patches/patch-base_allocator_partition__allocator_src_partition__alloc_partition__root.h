$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_root.h.orig	2025-09-29 17:05:47.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_root.h
@@ -202,7 +202,7 @@ struct PartitionOptions {
   // system to configure PartitionAlloc.
   EnableToggle fewer_memory_regions =
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_ANDROID) || \
-    PA_BUILDFLAG(IS_CHROMEOS)
+    PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
       kEnabled;
 #else
       kDisabled;
