$NetBSD$

Adapt to NetBSD.

--- qjs.c.orig    2019-07-09 19:49:47.000000000 +0200
+++ qjs.c        2019-07-12 01:26:13.323925295 +0200
@@ -108,6 +108,8 @@
     return 0;
 #elif defined(__linux__)
     return malloc_usable_size(ptr);
+#elif defined(__NetBSD__)
+    return 0;
 #else
     /* change this to `return 0;` if compilation fails */
     return malloc_usable_size(ptr);
@@ -224,6 +226,8 @@
     NULL,
 #elif defined(__linux__)
     (size_t (*)(const void *))malloc_usable_size,
+#elif defined(__NetBSD__)
+    NULL,
 #else
     /* change this to `NULL,` if compilation fails */
     malloc_usable_size,
