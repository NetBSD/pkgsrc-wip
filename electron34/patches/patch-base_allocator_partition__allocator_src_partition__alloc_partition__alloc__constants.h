$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h
@@ -329,7 +329,7 @@ PA_DEFINE_OPERATORS_FOR_FLAGS(PoolHandle
 // 8GB for each of the glued pools).
 #if PA_BUILDFLAG(HAS_64_BIT_POINTERS)
 #if PA_BUILDFLAG(IS_ANDROID) || PA_BUILDFLAG(IS_IOS) || \
-    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION)
+    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION) || PA_BUILDFLAG(IS_BSD)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
 constexpr size_t kPoolMaxSize = 16 * kGiB;
@@ -446,7 +446,7 @@ PA_ALWAYS_INLINE constexpr size_t MaxDir
 // TODO(casey.smalley@arm.com): under 64k pages we can end up in a situation
 // where a normal slot span will be large enough to contain multiple items,
 // but the address will go over the final partition page after being aligned.
-#if PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
+#if (PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
 constexpr size_t kMaxSupportedAlignment = kSuperPageSize / 4;
 #else
 constexpr size_t kMaxSupportedAlignment = kSuperPageSize / 2;
