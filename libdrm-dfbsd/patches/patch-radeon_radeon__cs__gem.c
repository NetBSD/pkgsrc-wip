$NetBSD: patch-radeon_radeon__cs__gem.c,v 1.1 2014/10/26 10:20:10 wiz Exp $

FreeBSD ports / DragonFly dports does not have this patch.

--- radeon/radeon_cs_gem.c.orig	2017-11-03 16:44:27.000000000 +0000
+++ radeon/radeon_cs_gem.c
@@ -528,9 +528,16 @@ static const struct radeon_cs_funcs rade
 
 static int radeon_get_device_id(int fd, uint32_t *device_id)
 {
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
+    struct drm_radeon_info info;
+#else
     struct drm_radeon_info info = {};
+#endif
     int r;
 
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
+    memset(&info, 0, sizeof info);
+#endif
     *device_id = 0;
     info.request = RADEON_INFO_DEVICE_ID;
     info.value = (uintptr_t)device_id;
