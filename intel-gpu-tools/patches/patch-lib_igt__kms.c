$NetBSD$

--- lib/igt_kms.c.orig	2015-09-11 14:42:51.000000000 +0000
+++ lib/igt_kms.c
@@ -40,6 +40,9 @@
 #endif
 #include <errno.h>
 #include <time.h>
+#ifdef __NetBSD__
+#include <dev/wscons/wsdisplay_usl_io.h>
+#endif
 
 #include <i915_drm.h>
 
@@ -311,8 +314,10 @@ static signed long set_vt_mode(unsigned 
 		return -errno;
 
 	prev_mode = 0;
+#ifndef __NetBSD__
 	if (drmIoctl(fd, KDGETMODE, &prev_mode))
 		goto err;
+#endif
 	if (drmIoctl(fd, KDSETMODE, (void *)mode))
 		goto err;
 
