$NetBSD$

From DragonFly dports since otherwise radeonkms.ko not loaded.

--- src/radeon_kms.c.orig	2017-03-16 07:43:58.000000000 +0000
+++ src/radeon_kms.c
@@ -30,6 +30,10 @@
 
 #include <errno.h>
 #include <sys/ioctl.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/param.h>
+#include <sys/linker.h>
+#endif
 /* Driver data structures */
 #include "radeon.h"
 #include "radeon_drm_queue.h"
@@ -824,7 +828,11 @@ static void
 radeon_dirty_update(ScrnInfoPtr scrn)
 {
 	ScreenPtr screen = scrn->pScreen;
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+	PixmapDirtyUpdatePtr ent = NULL;
+#else
 	PixmapDirtyUpdatePtr ent;
+#endif
 	RegionPtr region;
 
 	xorg_list_for_each_entry(ent, &screen->pixmap_dirty_list, ent) {
@@ -1401,7 +1409,11 @@ static int radeon_get_drm_master_fd(Scrn
 #endif
     struct pci_device *dev = info->PciInfo;
     char *busid;
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+    int fd, err;
+#else
     int fd;
+#endif
 
 #ifdef XF86_PDEV_SERVER_FD
     if (pRADEONEnt->platform_dev) {
@@ -1415,6 +1427,17 @@ static int radeon_get_drm_master_fd(Scrn
     XNFasprintf(&busid, "pci:%04x:%02x:%02x.%d",
                 dev->domain, dev->bus, dev->dev, dev->func);
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+    err = kldload("radeonkms");
+    if (err == -1 && errno != EEXIST) {
+       xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+                  "[drm] Failed to load kernel module for %s: %s\n",
+                  busid, strerror(errno));
+       free(busid);
+       return -1;
+    }
+#endif
+
     fd = drmOpen(NULL, busid);
     if (fd == -1)
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
