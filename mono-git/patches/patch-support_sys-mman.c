$NetBSD$

--- support/sys-mman.c.orig	2016-08-08 17:23:32.000000000 +0000
+++ support/sys-mman.c
@@ -22,6 +22,11 @@
 #define __BSD_VISIBLE 1
 #endif
 
+#ifdef __NetBSD__
+/* For mincore () */
+#define _NETBSD_SOURCE
+#endif
+
 #include <sys/types.h>
 #include <sys/mman.h>
 #include <errno.h>
