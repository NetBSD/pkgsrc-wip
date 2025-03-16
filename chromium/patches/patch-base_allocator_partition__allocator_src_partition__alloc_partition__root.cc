$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__root.cc,v 1.1 2025/02/06 09:57:39 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_root.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_root.cc
@@ -44,7 +44,7 @@
 #include "wow64apiset.h"
 #endif
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #if PA_CONFIG(ENABLE_SHADOW_METADATA)
 #include <sys/mman.h>
@@ -293,7 +293,7 @@ void PartitionAllocMallocInitOnce() {
     return;
   }
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
   // When fork() is called, only the current thread continues to execute in the
   // child process. If the lock is held, but *not* by this thread when fork() is
   // called, we have a deadlock.
@@ -1113,7 +1113,7 @@ void PartitionRoot::Init(PartitionOption
     // apple OSes.
     PA_CHECK((internal::SystemPageSize() == (size_t{1} << 12)) ||
              (internal::SystemPageSize() == (size_t{1} << 14)));
-#elif PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
+#elif (PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
     // Check runtime pagesize. Though the code is currently the same, it is
     // not merged with the IS_APPLE case above as a 1 << 16 case is only
     // supported on Linux on AArch64.
