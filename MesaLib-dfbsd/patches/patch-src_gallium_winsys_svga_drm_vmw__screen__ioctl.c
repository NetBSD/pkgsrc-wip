$NetBSD: patch-src_gallium_winsys_svga_drm_vmw__screen__ioctl.c,v 1.3 2015/05/15 14:27:42 nros Exp $

Make sure ERESTART gets defined.

--- src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2017-05-25 07:13:13.000000000 +0000
+++ src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
@@ -48,9 +48,25 @@
 
 #include "os/os_mman.h"
 
+#if defined(__NetBSD__)
+#define _KMEMUSER
+#endif
+
 #include <errno.h>
 #include <unistd.h>
 
+#if defined(__NetBSD__)
+#if !defined(ERESTART)
+#define ERESTART (-3)
+#endif
+#endif
+
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#if !defined(ERESTART)
+#define ERESTART (-1)
+#endif
+#endif
+
 #define VMW_MAX_DEFAULT_TEXTURE_SIZE   (128 * 1024 * 1024)
 #define VMW_FENCE_TIMEOUT_SECONDS 60
 
