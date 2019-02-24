$NetBSD: patch-src_gallium_winsys_radeon_drm_radeon__drm__winsys.c,v 1.1 2015/04/25 11:19:18 tnn Exp $

Don't create pipe thread on NetBSD. It triggers some kernel bug.
kern/49838.

--- src/gallium/winsys/radeon/drm/radeon_drm_winsys.c.orig	2018-07-06 23:20:10.000000000 +0000
+++ src/gallium/winsys/radeon/drm/radeon_drm_winsys.c
@@ -906,8 +906,10 @@ radeon_drm_winsys_create(int fd, const s
     /* TTM aligns the BO size to the CPU page size */
     ws->info.gart_page_size = sysconf(_SC_PAGESIZE);
 
+#if !defined(NO_CS_QUEUE)
     if (ws->num_cpus > 1 && debug_get_option_thread())
         util_queue_init(&ws->cs_queue, "rcs", 8, 1, 0);
+#endif
 
     /* Create the screen at the end. The winsys must be initialized
      * completely.
