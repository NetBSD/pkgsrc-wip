$NetBSD$

--- lib/sanitizer_common/sanitizer_allocator.cc.orig	2017-10-17 18:35:46.000000000 +0000
+++ lib/sanitizer_common/sanitizer_allocator.cc
@@ -180,6 +180,25 @@ void InternalFree(void *addr, InternalAl
 // LowLevelAllocator
 static LowLevelAllocateCallback low_level_alloc_callback;
 
+int InternalReallocArr(void *addr, uptr count, uptr size,
+                       InternalAllocatorCache *cache) {
+  void *oaddr;
+  void *naddr = 0;
+
+  internal_memcpy(&oaddr, addr, sizeof(addr));
+  if (!count || !size) {
+    InternalFree(oaddr, cache);
+    internal_memcpy(addr, &naddr, sizeof(addr));
+    return 0;
+  }
+
+  naddr = InternalRealloc(oaddr, count * size, cache);
+  if (!naddr) return -1;
+
+  internal_memcpy(addr, &naddr, sizeof(addr));
+  return 0;
+}
+
 void *LowLevelAllocator::Allocate(uptr size) {
   // Align allocation size.
   size = RoundUpTo(size, 8);
