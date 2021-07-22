$NetBSD$

Fix Linuxisms.

--- exynos/exynos_fimg2d.c.orig	2021-07-02 12:49:05.429105000 +0000
+++ exynos/exynos_fimg2d.c
@@ -30,7 +30,11 @@
 #include <assert.h>
 
 #include <sys/mman.h>
+#ifdef __linux__
 #include <linux/stddef.h>
+#else
+#endif
+
 
 #include <xf86drm.h>
 
