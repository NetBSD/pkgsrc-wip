$NetBSD: patch-xf86drmMode.c,v 1.2 2015/04/11 10:02:11 sevan Exp $

Get rid of patch disabling checking for hw.dri.%d.modesetting on FreeBSD.
This sysctl is only available if a KMS module is loaded.
xf86-video-intel if checking for modesetting fails the first time
tries to load the kernel module and then check again for modesetting. 

Get rid of drmModeSetPlane patch (from NetBSD?)
Android deliberately uses signed crtc_x and crtc_y
"to allow a destination location that is partially off screen."

--- xf86drmMode.c.orig	2017-01-28 01:15:16.000000000 +0000
+++ xf86drmMode.c
@@ -829,6 +829,19 @@ int drmCheckModesettingSupported(const c
 			return -EINVAL;
 		return (modesetting ? 0 : -ENOSYS);
 	}
+#elif defined(__NetBSD__)
+	int fd;
+	static const struct drm_mode_card_res zero_res;
+	struct drm_mode_card_res res = zero_res;
+	int ret;
+ 
+	fd = drmOpen(NULL, busid);
+	if (fd == -1)
+		return -EINVAL;
+	ret = drmIoctl(fd, DRM_IOCTL_MODE_GETRESOURCES, &res);
+	drmClose(fd);
+	if (ret == 0)
+		return 0;
 #elif defined(__DragonFly__)
 	return 0;
 #endif
