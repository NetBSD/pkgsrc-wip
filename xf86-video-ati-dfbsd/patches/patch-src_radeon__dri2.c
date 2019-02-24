$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/radeon_dri2.c.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/radeon_dri2.c
@@ -79,12 +79,21 @@ static DevPrivateKeyRec dri2_window_priv
 static Bool
 radeon_get_flink_name(RADEONEntPtr pRADEONEnt, PixmapPtr pixmap, uint32_t *name)
 {
+#if defined(REVERT_GBM_BO)
+    struct radeon_bo *bo = radeon_get_pixmap_bo(pixmap)->bo.radeon;
+#else
     struct radeon_buffer *bo = radeon_get_pixmap_bo(pixmap);
+#endif
     struct drm_gem_flink flink;
 
+#if defined(REVERT_GBM_BO)
+    if (bo)
+	return radeon_gem_get_kernel_name(bo, name) == 0;
+#else
     if (bo && !(bo->flags & RADEON_BO_FLAGS_GBM) &&
 	radeon_gem_get_kernel_name(bo->bo.radeon, name) == 0)
 	return TRUE;
+#endif
 
     if (radeon_get_pixmap_handle(pixmap, &flink.handle)) {
 	if (drmIoctl(pRADEONEnt->fd, DRM_IOCTL_GEM_FLINK, &flink) != 0)
