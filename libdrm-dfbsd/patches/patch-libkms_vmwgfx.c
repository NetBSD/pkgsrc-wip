$NetBSD: patch-libkms_vmwgfx.c,v 1.3 2015/05/07 06:31:06 wiz Exp $

Provide compatibility errno number for non-Linux.

From FreeBSD ports for graphics/libdrm version 2.4.84

# the defintion of ERESTART is behind a check for _KERNEL, but
# defining that causes errno to not be defined. fortunately, there's
# an alternative switch. unfortunately, those differ by platform and
# _WANT_KERNEL_ERRNO is too recent to be part of any release, so just
# define ERESTART if we still don't have it after including errno.h

--- libkms/vmwgfx.c.orig	2015-05-06 23:04:31.000000000 +0000
+++ libkms/vmwgfx.c
@@ -26,10 +26,22 @@
  **************************************************************************/
 
 
+#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
+#define _WANT_KERNEL_ERRNO
+#elif defined(__DragonFly__)
+#define _KERNEL_STRUCTURES
+#endif
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
 #include "internal.h"
+#ifndef ERESTART
+#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__) || defined(__DragonFly__)
+#define ERESTART (-1)
+#else
+#define ERESTART 85
+#endif /* __FreeBSD__ || __DragonFly__ */
+#endif
 
 #include "xf86drm.h"
 #include "libdrm_macros.h"
