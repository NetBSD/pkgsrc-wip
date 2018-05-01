$NetBSD: patch-xf86drmMode.c,v 1.2 2015/04/11 10:02:11 sevan Exp $

Replace patch disabling checking for hw.dri.%d.modesetting on FreeBSD.
This sysctl is only available if a KMS module is loaded.
xf86-video-intel if checking for modesetting fails the first time
tries to load the kernel module and then check again for modesetting.

Use patch from FreeBSD ports / DragonFly dports graphics/libdrm 2.4.84.

Get rid of drmModeSetPlane patch (from NetBSD?)
Android deliberately uses signed crtc_x and crtc_y
"to allow a destination location that is partially off screen."

--- xf86drmMode.c.orig	2017-11-03 16:44:27.000000000 +0000
+++ xf86drmMode.c
@@ -47,6 +47,9 @@
 #include <stdlib.h>
 #include <sys/ioctl.h>
 #ifdef HAVE_SYS_SYSCTL_H
+#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__) || defined(__DragonFly__)
+#include <sys/types.h>
+#endif
 #include <sys/sysctl.h>
 #endif
 #include <stdio.h>
@@ -796,43 +799,75 @@ int drmCheckModesettingSupported(const c
 	closedir(sysdir);
 	if (found)
 		return 0;
-#elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
-	char kbusid[1024], sbusid[1024];
-	char oid[128];
-	int domain, bus, dev, func;
-	int i, modesetting, ret;
-	size_t len;
-
-	ret = sscanf(busid, "pci:%04x:%02x:%02x.%d", &domain, &bus, &dev,
-	    &func);
-	if (ret != 4)
-		return -EINVAL;
-	snprintf(kbusid, sizeof(kbusid), "pci:%04x:%02x:%02x.%d", domain, bus,
-	    dev, func);
+#elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__) || defined(__DragonFly__)
+	#define bus_fmt "pci:%04x:%02x:%02x.%d"
+	#define name_fmt "%*s %*s " bus_fmt
+	unsigned int d1 = 0, b1 = 0, s1 = 0, f1 = 0;
+	if (sscanf(busid, bus_fmt, &d1, &b1, &s1, &f1) != 4)
+                return -EINVAL;
+	/*
+	 * hw.dri.%i.bus is not always present and hw.dri.%i.name does not
+	 * always contain the busid, so try both for best chance of success
+	 */
+	for (int i = 0; i < DRM_MAX_MINOR; ++i) {
+		char name[22], value[256];
+		size_t length = sizeof(value);
+		snprintf(name, sizeof(name), "hw.dri.%d.name", i);
+		if (sysctlbyname(name, value, &length, NULL, 0))
+			continue;
 
-	/* How many GPUs do we expect in the machine ? */
-	for (i = 0; i < 16; i++) {
-		snprintf(oid, sizeof(oid), "hw.dri.%d.busid", i);
-		len = sizeof(sbusid);
-		ret = sysctlbyname(oid, sbusid, &len, NULL, 0);
-		if (ret == -1) {
-			if (errno == ENOENT)
+		value[length] = '\0';
+		unsigned int d2 = 0, b2 = 0, s2 = 0, f2 = 0;
+		switch (sscanf(value, name_fmt, &d2, &b2, &s2, &f2)) {
+		case 0: /* busid not in the name, try busid */
+			length = sizeof(value);
+			snprintf(name, sizeof(name), "hw.dri.%d.busid", i);
+			if (sysctlbyname(name, value, &length, NULL, 0))
 				continue;
-			return -EINVAL;
+
+			value[length] = '\0';
+			if (sscanf(value, bus_fmt, &d2, &b2, &s2, &f2) != 4)
+ 				continue;
+			/* fall through after parsing busid */
+
+		case 4: /* if we jumped here then busid was in the name */ 
+			if ((d1 == d2) && (b1 == b2) && (s1 == s2) && (f1 == f2)) {
+			/*
+			 * Confirm the drm driver for this device supports KMS,
+			 * except on DragonFly where all the drm drivers do so
+			 * but only hw.dri.0.modesetting is present
+			 */ 
+			#ifndef __DragonFly__
+				int modesetting = 0;
+				length = sizeof(modesetting);
+				snprintf(name, sizeof(name), "hw.dri.%i.modesetting", i);
+				if (sysctlbyname(name, &modesetting, &length, NULL, 0)
+				 || length != sizeof(modesetting) || !modesetting)
+					return -ENOSYS;
+				else
+			#endif
+					return 0;
+			}
+		default:
+			break;
 		}
-		if (strcmp(sbusid, kbusid) != 0)
-			continue;
-		snprintf(oid, sizeof(oid), "hw.dri.%d.modesetting", i);
-		len = sizeof(modesetting);
-		ret = sysctlbyname(oid, &modesetting, &len, NULL, 0);
-		if (ret == -1 || len != sizeof(modesetting))
-			return -EINVAL;
-		return (modesetting ? 0 : -ENOSYS);
 	}
-#elif defined(__DragonFly__)
+#elif 0 && defined(__DragonFly__)
 	return 0;
-#endif
-#ifdef __OpenBSD__
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
+#elif defined(__OpenBSD__)
 	int	fd;
 	struct drm_mode_card_res res;
 	drmModeResPtr r = 0;
