$NetBSD$

--- lib/sanitizer_common/sanitizer_allocator_internal.h.orig	2017-10-17 18:35:46.000000000 +0000
+++ lib/sanitizer_common/sanitizer_allocator_internal.h
@@ -57,6 +57,8 @@ void *InternalRealloc(void *p, uptr size
 void *InternalCalloc(uptr countr, uptr size,
                      InternalAllocatorCache *cache = nullptr);
 void InternalFree(void *p, InternalAllocatorCache *cache = nullptr);
+int InternalReallocArr(void *p, uptr count, uptr size,
+                       InternalAllocatorCache *cache = nullptr);
 InternalAllocator *internal_allocator();
 
 enum InternalAllocEnum {
