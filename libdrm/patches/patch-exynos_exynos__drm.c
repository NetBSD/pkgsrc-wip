$NetBSD$

Fix Linuxisms.

--- exynos/exynos_drm.c.orig	2021-07-02 12:49:05.425771700 +0000
+++ exynos/exynos_drm.c
@@ -31,7 +31,10 @@
 #include <unistd.h>
 
 #include <sys/mman.h>
+#ifdef __linux__
 #include <linux/stddef.h>
+#else
+#endif
 
 #include <xf86drm.h>
 
