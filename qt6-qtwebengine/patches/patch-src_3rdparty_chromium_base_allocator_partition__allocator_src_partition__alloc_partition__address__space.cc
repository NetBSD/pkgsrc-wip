$NetBSD$

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_address_space.cc.orig	2025-01-24 10:49:20.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_address_space.cc
@@ -421,7 +421,7 @@ void PartitionAddressSpace::UninitThread
 }
 #endif
 
-#if (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
