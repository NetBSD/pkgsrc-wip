$NetBSD$

Adapt to NetBSD.

--- quickjs.c.orig        2019-07-09 19:49:47.000000000 +0200
+++ quickjs.c    2019-07-12 11:49:56.029913625 +0200
@@ -1277,6 +1277,8 @@
     return 0;
 #elif defined(__linux__)
     return malloc_usable_size(ptr);
+#elif defined(__NetBSD__)
+    return 0;
 #else
     /* change this to `return 0;` if compilation fails */
     return malloc_usable_size(ptr);
@@ -1351,6 +1353,8 @@
     NULL,
 #elif defined(__linux__)
     (size_t (*)(const void *))malloc_usable_size,
+#elif defined(__NetBSD__)
+    NULL,
 #else
     /* change this to `NULL,` if compilation fails */
     malloc_usable_size,
