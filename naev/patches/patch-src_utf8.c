$NetBSD$

alloca(3) is in stdlib.h on NetBSD (others?)

--- src/utf8.c.orig	2020-12-17 02:23:41.000000000 +0000
+++ src/utf8.c
@@ -23,7 +23,11 @@
 #if HAS_WIN32
 #include <malloc.h>
 #else /* HAS_WIN32 */
+#ifdef __linux__
 #include <alloca.h> /* Not available in windows, necessary for linux. */
+#else
+#include <stdlib.h>
+#endif /* __linux__ */
 #endif /* HAS_WIN32 */
 #include <assert.h>
 
