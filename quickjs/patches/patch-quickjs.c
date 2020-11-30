$NetBSD$

Adapt to NetBSD.

--- quickjs.c.orig	2019-10-27 10:55:35.000000000 +0000
+++ quickjs.c
@@ -111,6 +111,14 @@
 #include <pthread.h>
 #include <stdatomic.h>
 #include <errno.h>
+
+#if defined(__NetBSD__)
+#if ATOMIC_LLONG_LOCK_FREE != 2
+/* The code currently assumes the presence of 64-bit atomics */
+/* ...but the current platform doesn't support it */
+#undef CONFIG_ATOMICS
+#endif
+#endif
 #endif
 
 enum {
@@ -1680,6 +1688,8 @@ static inline size_t js_def_malloc_usabl
     return 0;
 #elif defined(__linux__)
     return malloc_usable_size(ptr);
+#elif defined(__NetBSD__)
+    return 0;
 #else
     /* change this to `return 0;` if compilation fails */
     return malloc_usable_size(ptr);
@@ -1754,6 +1764,8 @@ static const JSMallocFunctions def_mallo
     NULL,
 #elif defined(__linux__)
     (size_t (*)(const void *))malloc_usable_size,
+#elif defined(__NetBSD__)
+    NULL,
 #else
     /* change this to `NULL,` if compilation fails */
     malloc_usable_size,
