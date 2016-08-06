$NetBSD$

--- base/trace_event/malloc_dump_provider.cc.orig	2016-08-05 17:13:37.000000000 +0000
+++ base/trace_event/malloc_dump_provider.cc
@@ -19,6 +19,8 @@
 
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
+#elif defined(OS_NETBSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -26,7 +28,7 @@
 namespace base {
 namespace trace_event {
 
-#if BUILDFLAG(USE_EXPERIMENTAL_ALLOCATOR_SHIM)
+#if 0 // BUILDFLAG(USE_EXPERIMENTAL_ALLOCATOR_SHIM)
 namespace {
 
 using allocator::AllocatorDispatch;
@@ -103,6 +105,8 @@ MallocDumpProvider::~MallocDumpProvider(
 // the current process.
 bool MallocDumpProvider::OnMemoryDump(const MemoryDumpArgs& args,
                                       ProcessMemoryDump* pmd) {
+  return 0;
+#if 0
   size_t total_virtual_size = 0;
   size_t resident_size = 0;
   size_t allocated_objects_size = 0;
@@ -197,10 +201,11 @@ bool MallocDumpProvider::OnMemoryDump(co
   tid_dumping_heap_ = kInvalidThreadId;
 
   return true;
+#endif
 }
 
 void MallocDumpProvider::OnHeapProfilingEnabled(bool enabled) {
-#if BUILDFLAG(USE_EXPERIMENTAL_ALLOCATOR_SHIM)
+#if 0 // BUILDFLAG(USE_EXPERIMENTAL_ALLOCATOR_SHIM)
   if (enabled) {
     {
       AutoLock lock(allocation_register_lock_);
