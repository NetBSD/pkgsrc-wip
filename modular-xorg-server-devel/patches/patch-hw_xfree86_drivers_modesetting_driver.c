$NetBSD$

Revert "modesetting: Remove #ifdefs XF86_PDEV_SERVER_FD"
https://patchwork.freedesktop.org/patch/207937/

--- hw/xfree86/drivers/modesetting/driver.c.orig	2018-02-28 18:22:20.000000000 +0000
+++ hw/xfree86/drivers/modesetting/driver.c
@@ -244,12 +244,14 @@ probe_hw(const char *dev, struct xf86_pl
 {
     int fd;
 
+#ifdef XF86_PDEV_SERVER_FD
     if (platform_dev && (platform_dev->flags & XF86_PDEV_SERVER_FD)) {
         fd = xf86_platform_device_odev_attributes(platform_dev)->fd;
         if (fd == -1)
             return FALSE;
         return check_outputs(fd, NULL);
     }
+#endif
 
     fd = open_hw(dev);
     if (fd != -1) {
@@ -710,8 +712,10 @@ FreeRec(ScrnInfoPtr pScrn)
             if (ms->pEnt->location.type == BUS_PCI)
                 ret = drmClose(ms->fd);
             else
+#ifdef XF86_PDEV_SERVER_FD
                 if (!(ms->pEnt->location.type == BUS_PLATFORM &&
                       (ms->pEnt->location.id.plat->flags & XF86_PDEV_SERVER_FD)))
+#endif
                     ret = close(ms->fd);
             (void) ret;
             ms_ent->fd = 0;
@@ -824,11 +828,13 @@ ms_get_drm_master_fd(ScrnInfoPtr pScrn)
 
 #ifdef XSERVER_PLATFORM_BUS
     if (pEnt->location.type == BUS_PLATFORM) {
+#ifdef XF86_PDEV_SERVER_FD
         if (pEnt->location.id.plat->flags & XF86_PDEV_SERVER_FD)
             ms->fd =
                 xf86_platform_device_odev_attributes(pEnt->location.id.plat)->
                 fd;
         else
+#endif
         {
             char *path =
                 xf86_platform_device_odev_attributes(pEnt->location.id.plat)->
@@ -1491,9 +1497,11 @@ SetMaster(ScrnInfoPtr pScrn)
     modesettingPtr ms = modesettingPTR(pScrn);
     int ret;
 
+#ifdef XF86_PDEV_SERVER_FD
     if (ms->pEnt->location.type == BUS_PLATFORM &&
         (ms->pEnt->location.id.plat->flags & XF86_PDEV_SERVER_FD))
         return TRUE;
+#endif
 
     ret = drmSetMaster(ms->fd);
     if (ret)
@@ -1742,9 +1750,11 @@ LeaveVT(ScrnInfoPtr pScrn)
 
     pScrn->vtSema = FALSE;
 
+#ifdef XF86_PDEV_SERVER_FD
     if (ms->pEnt->location.type == BUS_PLATFORM &&
         (ms->pEnt->location.id.plat->flags & XF86_PDEV_SERVER_FD))
         return;
+#endif
 
     drmDropMaster(ms->fd);
 }
