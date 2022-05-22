$NetBSD$

Fix unportable *memalign() call.

--- src/hardnested/hardnested_bf_core_AVX.c.orig	2021-08-13 21:44:15.000000000 +0000
+++ src/hardnested/hardnested_bf_core_AVX.c
@@ -49,7 +49,7 @@ THE SOFTWARE.
 
 #include "hardnested_bruteforce.h"
 #include <stdlib.h>
-#if !defined _MSC_VER && !defined __APPLE__
+#if !defined _MSC_VER && !defined __APPLE__ && !defined __NetBSD__ && !defined __FreeBSD__ && !defined __dietlibc__ && !defined _AIX && !defined __OpenBSD__ && !defined __DragonFly__
 #include <malloc.h>
 #endif
 #include "../crapto1.h"
@@ -87,7 +87,7 @@ typedef union {
 #if defined (_WIN32)
 #define malloc_bitslice(x) __builtin_assume_aligned(_aligned_malloc((x), MAX_BITSLICES/8), MAX_BITSLICES/8)
 #define free_bitslice(x) _aligned_free(x)
-#elif defined (__APPLE__)
+#elif defined (__APPLE__) || defined (__NetBSD__) || defined (__FreeBSD__) || defined (__dietlibc__) || defined (_AIX) || defined (__OpenBSD__) || defined (__DragonFly__)
 
 static void *malloc_bitslice(size_t x) {
     char *allocated_memory;
