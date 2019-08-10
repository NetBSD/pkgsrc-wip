$NetBSD$

Exclude sysmacros.h except on linux.
Exclude code to decipher driver from fd on netbsd - TODO?

--- drm.c.orig	2019-07-11 05:37:37.000000000 +0000
+++ drm.c
@@ -24,7 +24,10 @@
 #include "drm.h"
 #include "drm-private.h"
 
+#ifdef __linux__
 #include <sys/sysmacros.h>
+#endif
+#include <sys/types.h>
 
 const static struct drm_driver *drivers[] = {
 #if WITH_DRM_INTEL
@@ -39,6 +42,7 @@ const static struct drm_driver *drivers[
 static const struct drm_driver *
 find_driver(int fd)
 {
+#ifndef __NetBSD__ /* XXX */
 	char path[64], id[32];
 	uint32_t vendor_id, device_id;
 	char *path_part;
@@ -85,6 +89,7 @@ find_driver(int fd)
 	return NULL;
 
 dumb:
+#endif
 	return &dumb_drm_driver;
 }
 
