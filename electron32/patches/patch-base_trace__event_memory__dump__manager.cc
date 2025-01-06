$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/trace_event/memory_dump_manager.cc.orig	2024-10-18 12:33:59.858222500 +0000
+++ base/trace_event/memory_dump_manager.cc
@@ -87,7 +87,7 @@ const char* const MemoryDumpManager::kSy
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
