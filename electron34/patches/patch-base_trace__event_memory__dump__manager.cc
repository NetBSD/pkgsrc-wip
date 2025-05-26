$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/trace_event/memory_dump_manager.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/trace_event/memory_dump_manager.cc
@@ -83,7 +83,7 @@ const char* const MemoryDumpManager::kSy
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
