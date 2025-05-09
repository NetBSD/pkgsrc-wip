$NetBSD: patch-src_gallium_auxiliary_pipe-loader_pipe__loader__drm.c,v 1.1 2019/08/21 13:35:28 nia Exp $

* From FreeBSD ports / DragonFly dports graphics/mesa-dri

Revert the following commit.

FreeBSD and DragonFly don't have the required render nodes.

-------

From 69a1b9959e59653da262185c4e2cf57d24939b19 Mon Sep 17 00:00:00 2001
Date: Mon, 29 Jun 2015 12:36:45 +0100
Subject: pipe-loader: drop support for non-render node devices

Render nodes have been around for quite some time. Removing support via
the master/primary node allows us to clean up the conditional
compilation and simplify the build greatly.

For example currently we the pipe-loader, which explicitly links against
xcb and friends (for X auth) if found at compile-time. That
would cause problems as one will be forced to use X/xcb, even if it's a
headless system that is used for opencl.

v2: Clarify the linking topic in the commit message.

* Extended for NetBSD.

--- src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c.orig	2025-01-22 18:12:23.000000000 +0000
+++ src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c
@@ -239,6 +239,16 @@ pipe_loader_drm_probe_fd(struct pipe_loa
    return ret;
 }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
+static int
+open_drm_minor(int minor)
+{
+   char path[PATH_MAX];
+   snprintf(path, sizeof(path), DRM_DEV_NAME, DRM_DIR_NAME, minor);
+   return open(path, O_RDWR, 0);
+}
+#endif
+
 static int
 open_drm_render_node_minor(int minor)
 {
@@ -251,7 +261,19 @@ open_drm_render_node_minor(int minor)
 static int
 pipe_loader_drm_probe_internal(struct pipe_loader_device **devs, int ndev, bool zink)
 {
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
+   int i, k, fd, num_render_node_devs;
+   int j = 0;
+
+   struct {
+      unsigned vendor_id;
+      unsigned chip_id;
+   } render_node_devs[DRM_RENDER_NODE_MAX_NODES];
+
+   /* Look for render nodes first */
+#else
    int i, j, fd;
+#endif
 
    for (i = DRM_RENDER_NODE_MIN_MINOR, j = 0;
         i <= DRM_RENDER_NODE_MAX_MINOR; i++) {
@@ -266,6 +288,11 @@ pipe_loader_drm_probe_internal(struct pi
          continue;
       }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
+      render_node_devs[j].vendor_id = dev->u.pci.vendor_id;
+      render_node_devs[j].chip_id = dev->u.pci.chip_id;
+
+#endif
       if (j < ndev) {
          devs[j] = dev;
       } else {
@@ -275,6 +302,48 @@ pipe_loader_drm_probe_internal(struct pi
       j++;
    }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
+   num_render_node_devs = j;
+
+   /* Next look for drm devices. */
+   for (i = 0; i < DRM_MAX_MINOR; i++) {
+      struct pipe_loader_device *dev;
+      bool duplicate = false;
+      fd = open_drm_minor(i);
+      if (fd < 0)
+         continue;
+
+      if (!pipe_loader_drm_probe_fd(&dev, fd, zink)) {
+         close(fd);
+         continue;
+      }
+
+      /* Check to make sure we aren't already accessing this device via
+       * render nodes.
+       */
+      for (k = 0; k < num_render_node_devs; k++) {
+         if (dev->u.pci.vendor_id == render_node_devs[k].vendor_id &&
+             dev->u.pci.chip_id == render_node_devs[k].chip_id) {
+            close(fd);
+            dev->ops->release(&dev);
+            duplicate = true;
+            break;
+         }
+      }
+
+      if (duplicate)
+         continue;
+
+      if (j < ndev) {
+         devs[j] = dev;
+      } else {
+         dev->ops->release(&dev);
+      }
+
+      j++;
+   }
+
+#endif
    return j;
 }
 
