$NetBSD: patch-src_gallium_winsys_svga_drm_vmw__screen__ioctl.c,v 1.1 2015/03/03 16:58:22 tnn2 Exp $

--- src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2015-02-27 23:26:50.000000000 +0000
+++ src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
@@ -48,6 +48,10 @@
 
 #include "os/os_mman.h"
 
+#if defined(__NetBSD__)
+/* XXX: to get ERESTART, although I don't think our drm ioctls use it, check with xsrc */
+#define _KMEMUSER
+#endif
 #include <errno.h>
 #include <unistd.h>
 
