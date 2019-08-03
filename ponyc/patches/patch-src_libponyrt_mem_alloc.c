$NetBSD$

Provide fallback to MAP_ALIGNED_SUPER for NetBSD.

--- src/libponyrt/mem/alloc.c.orig	2019-07-27 10:37:45.000000000 +0000
+++ src/libponyrt/mem/alloc.c
@@ -36,6 +36,9 @@ void* ponyint_virt_alloc(size_t bytes)
   p = mmap(0, bytes, PROT_READ | PROT_WRITE,
     MAP_PRIVATE | MAP_ANON, -1, 0);
 #elif defined(PLATFORM_IS_BSD)
+#ifndef MAP_ALIGNED_SUPER
+#define MAP_ALIGNED_SUPER 0
+#endif
   p = mmap(0, bytes, PROT_READ | PROT_WRITE,
     MAP_PRIVATE | MAP_ANON | MAP_ALIGNED_SUPER, -1, 0);
 #endif
