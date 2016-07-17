$NetBSD$

--- base/process/memory_stubs.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/process/memory_stubs.cc
@@ -27,6 +27,8 @@ bool AdjustOOMScore(ProcessId process, i
 // their respective stdlib function since those functions will return null on a
 // failure to allocate.
 
+#if !defined(OS_FREEBSD)
+// FreeBSD brings it's own implementation in memory.cc -- cmt
 bool UncheckedMalloc(size_t size, void** result) {
   *result = malloc(size);
   return *result != nullptr;
@@ -36,5 +38,6 @@ bool UncheckedCalloc(size_t num_items, s
   *result = calloc(num_items, size);
   return *result != nullptr;
 }
+#endif
 
 }  // namespace base
