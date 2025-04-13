$NetBSD$

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_page_constants.h.orig	2025-01-24 10:49:20.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_page_constants.h
@@ -16,7 +16,7 @@ namespace partition_alloc::internal {
 // (1 << 12 or 1 << 14), as checked in PartitionRoot::Init(). And
 // PartitionPageSize() is 4 times the OS page size.
 static constexpr size_t kMaxSlotsPerSlotSpan = 4 * (1 << 14) / kSmallestBucket;
-#elif (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 // System page size can be 4, 16, or 64 kiB on Linux on arm64. 64 kiB is
 // currently (kMaxSlotsPerSlotSpanBits == 13) not supported by the code,
 // so we use the 16 kiB maximum (64 kiB will crash).
