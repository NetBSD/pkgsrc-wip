$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc.orig	2024-12-03 23:30:04.093346000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc
@@ -38,7 +38,7 @@ uint32_t SecTaskGetCodeSignStatus(SecTas
 #endif  // PA_BUILDFLAG(IS_MAC)
 
 #if PA_BUILDFLAG(HAS_MEMORY_TAGGING) || \
-    (defined(__ARM_FEATURE_BTI_DEFAULT) && (__ARM_FEATURE_BTI_DEFAULT == 1))
+    (defined(__ARM_FEATURE_BTI_DEFAULT) && (__ARM_FEATURE_BTI_DEFAULT == 1) && !PA_BUILDFLAG(IS_BSD))
 struct __ifunc_arg_t;
 
 #include "partition_alloc/aarch64_support.h"
