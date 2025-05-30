$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -172,7 +172,7 @@ uint64_t GetDefaultMemoryLimit() {
   // Limits the number of FDs used to 32, assuming a 4MB allocation size.
   uint64_t max_default_memory_limit = 128 * kMegabyte;
 #else
-  uint64_t max_default_memory_limit = 512 * kMegabyte;
+  uint64_t max_default_memory_limit = 128 * kMegabyte;
 #endif
 
   // Use 1/8th of discardable memory on low-end devices.
