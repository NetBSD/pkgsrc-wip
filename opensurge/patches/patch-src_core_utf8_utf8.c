$NetBSD$

Much more than FreeBSD doesn't have <alloca.h>.

--- src/core/utf8/utf8.c.orig	2021-01-25 19:29:44.000000000 +0000
+++ src/core/utf8/utf8.c
@@ -24,9 +24,9 @@
 #include <malloc.h>
 #define snprintf _snprintf
 #else
-#ifndef __FreeBSD__
+#if defined(__linux__) || defined(__sun)
 #include <alloca.h>
-#endif /* __FreeBSD__ */
+#endif /* defined(__linux__) || defined(__sun) */
 #endif
 #include <assert.h>
 
