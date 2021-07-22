$NetBSD$

Fix Linuxisms.

--- omap/omap_drm.c.orig	2021-07-02 12:49:05.445771700 +0000
+++ omap/omap_drm.c
@@ -27,8 +27,11 @@
  */
 
 #include <stdlib.h>
+#ifdef __linux__
 #include <linux/stddef.h>
 #include <linux/types.h>
+#else
+#endif
 #include <errno.h>
 #include <sys/mman.h>
 #include <fcntl.h>
