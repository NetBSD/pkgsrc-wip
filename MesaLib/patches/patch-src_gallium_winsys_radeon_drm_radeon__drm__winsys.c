$NetBSD$

Don't create pipe thread on NetBSD. It triggers some kernel bug.
kern/49838.

--- src/gallium/winsys/radeon/drm/radeon_drm_winsys.c.orig	2016-11-10 22:05:17.000000000 +0000
+++ src/gallium/winsys/radeon/drm/radeon_drm_winsys.c
@@ -819,8 +819,10 @@ radeon_drm_winsys_create(int fd, radeon_
     /* TTM aligns the BO size to the CPU page size */
     ws->info.gart_page_size = sysconf(_SC_PAGESIZE);
 
+#if !defined(__NetBSD__)
     if (ws->num_cpus > 1 && debug_get_option_thread())
         util_queue_init(&ws->cs_queue, "radeon_cs", 8, 1);
+#endif
 
     /* Create the screen at the end. The winsys must be initialized
      * completely.
