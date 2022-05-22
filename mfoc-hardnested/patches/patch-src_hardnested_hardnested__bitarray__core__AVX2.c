$NetBSD$

Fix unportable *memalign() call.

--- src/hardnested/hardnested_bitarray_core_AVX2.c.orig	2021-08-13 21:44:15.000000000 +0000
+++ src/hardnested/hardnested_bitarray_core_AVX2.c
@@ -18,14 +18,14 @@
 
 #include <stdint.h>
 #include <stdlib.h>
-#if !defined _MSC_VER && !defined __APPLE__
+#if !defined _MSC_VER && !defined __APPLE__ && !defined __NetBSD__ && !defined __FreeBSD__ && !defined __dietlibc__ && !defined _AIX && !defined __OpenBSD__ && !defined __DragonFly__
 #include <malloc.h>
 #endif
 
 uint32_t* malloc_bitarray_AVX2(uint32_t x) {
 #if defined (_WIN32)
     return __builtin_assume_aligned(_aligned_malloc((x), 16), 16);
-#elif defined (__APPLE__)
+#elif defined (__APPLE__) || defined (__NetBSD__) || defined (__FreeBSD__) || defined (__dietlibc__) || defined (_AIX) || defined (__OpenBSD__) || defined (__DragonFly__)
     uint32_t *allocated_memory;
     if (posix_memalign((void**) &allocated_memory, 16, x)) {
         return NULL;
