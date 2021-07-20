$NetBSD$

sysinfo(2) is for Linux only

--- src/gallium/drivers/freedreno/freedreno_screen.c.orig	2021-07-14 20:04:47.137926600 +0000
+++ src/gallium/drivers/freedreno/freedreno_screen.c
@@ -42,7 +42,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include "drm-uapi/drm_fourcc.h"
+#if !defined(__NetBSD__)
 #include <sys/sysinfo.h>
+#endif
 
 #include "freedreno_fence.h"
 #include "freedreno_query.h"
@@ -1010,9 +1012,13 @@ fd_screen_create(struct fd_device *dev, 
 
    screen->has_syncobj = fd_has_syncobj(screen->dev);
 
+#if defined(__NetBSD__)
+   screen->ram_size = 512 * 1024 * 1024; /* XXX should use sysctl hw.physmem64 here */
+#else
    struct sysinfo si;
    sysinfo(&si);
    screen->ram_size = si.totalram;
+#endif
 
    DBG("Pipe Info:");
    DBG(" GPU-id:          %d", screen->gpu_id);
