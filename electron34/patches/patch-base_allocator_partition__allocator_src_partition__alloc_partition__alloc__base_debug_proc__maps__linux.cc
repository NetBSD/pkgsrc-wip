$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc
@@ -19,7 +19,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || \
-    PA_BUILDFLAG(IS_ANDROID)
+    PA_BUILDFLAG(IS_ANDROID) || PA_BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
