$NetBSD$

Fix Linuxisms.

--- tests/exynos/exynos_fimg2d_test.c.orig	2021-07-02 12:49:05.452438600 +0000
+++ tests/exynos/exynos_fimg2d_test.c
@@ -31,7 +31,10 @@
 #include <unistd.h>
 
 #include <sys/mman.h>
+#ifdef __linux__
 #include <linux/stddef.h>
+#else
+#endif
 
 #include <xf86drm.h>
 #include <xf86drmMode.h>
