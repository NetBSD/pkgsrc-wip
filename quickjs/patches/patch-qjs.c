$NetBSD$

Adapt to NetBSD.

--- qjs.c.orig	2019-07-09 17:49:47.000000000 +0000
+++ qjs.c
@@ -150,6 +150,8 @@ static inline size_t js_trace_malloc_usa
     return 0;
 #elif defined(__linux__)
     return malloc_usable_size(ptr);
+#elif defined(__NetBSD__)
+    return 0;
 #else
     /* change this to `return 0;` if compilation fails */
     return malloc_usable_size(ptr);
@@ -266,6 +268,8 @@ static const JSMallocFunctions trace_mf 
     NULL,
 #elif defined(__linux__)
     (size_t (*)(const void *))malloc_usable_size,
+#elif defined(__NetBSD__)
+    NULL,
 #else
     /* change this to `NULL,` if compilation fails */
     malloc_usable_size,
