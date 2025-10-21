$NetBSD$

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_page_constants.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_page_constants.h
@@ -17,7 +17,7 @@ namespace partition_alloc::internal {
 // PartitionPageSize() is 4 times the OS page size.
 static constexpr size_t kMaxSlotsPerSlotSpan = 4 * (1 << 14) / kSmallestBucket;
 #elif defined(PARTITION_ALLOCATOR_CONSTANTS_POSIX_NONCONST_PAGE_SIZE) && \
-    PA_BUILDFLAG(IS_LINUX) && \
+    (PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && \
     (PA_BUILDFLAG(PA_ARCH_CPU_ARM64) || PA_BUILDFLAG(PA_ARCH_CPU_PPC64))
 // System page size can be 4, 16, or 64 kiB on Linux on AArch64.
 // System page size can be 4 or 64 kiB on Linux on ppc64.
