$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc
@@ -9,7 +9,7 @@
 #include "partition_alloc/page_allocator.h"
 
 #if PA_BUILDFLAG(HAS_MEMORY_TAGGING) || \
-    (defined(__ARM_FEATURE_BTI_DEFAULT) && (__ARM_FEATURE_BTI_DEFAULT == 1))
+    (defined(__ARM_FEATURE_BTI_DEFAULT) && (__ARM_FEATURE_BTI_DEFAULT == 1) && !PA_BUILDFLAG(IS_BSD))
 struct __ifunc_arg_t;
 
 #include "partition_alloc/aarch64_support.h"
