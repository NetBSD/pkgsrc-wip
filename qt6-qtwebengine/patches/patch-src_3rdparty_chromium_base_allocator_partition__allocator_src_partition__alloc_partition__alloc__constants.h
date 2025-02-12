$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h
@@ -316,7 +316,7 @@ constexpr size_t kNumPools = kMaxPoolHan
 #if BUILDFLAG(IS_IOS)
 constexpr size_t kPoolMaxSize = 1 * kGiB;
 #elif BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(ENABLE_POINTER_COMPRESSION)
+    BUILDFLAG(ENABLE_POINTER_COMPRESSION) || BUILDFLAG(IS_BSD)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
 constexpr size_t kPoolMaxSize = 16 * kGiB;
