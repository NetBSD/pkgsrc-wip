$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/radeon_dri3.c.orig	2019-02-11 11:12:34.000000000 +0000
+++ src/radeon_dri3.c
@@ -213,6 +213,24 @@ static int radeon_dri3_fd_from_pixmap(Sc
 				      CARD16 *stride,
 				      CARD32 *size)
 {
+#if defined(REVERT_GBM_BO)
+	struct radeon_bo *bo;
+	int fd;
+
+	bo = radeon_get_pixmap_bo(pixmap)->bo.radeon;
+	if (!bo) {
+#ifdef USE_GLAMOR
+		ScrnInfoPtr scrn = xf86ScreenToScrn(screen);
+		RADEONInfoPtr info = RADEONPTR(scrn);
+		if (info->use_glamor)
+			return glamor_fd_from_pixmap(screen, pixmap, stride, size);
+#endif
+		exaMoveInPixmap(pixmap);
+		bo = radeon_get_pixmap_bo(pixmap)->bo.radeon;
+		if (!bo)
+			return -1;
+	}
+#else /* !REVERT_GBM_BO */
 	struct radeon_buffer *bo;
 	int fd;
 #ifdef USE_GLAMOR
@@ -256,15 +274,24 @@ static int radeon_dri3_fd_from_pixmap(Sc
 		if (!bo)
 			return -1;
 	}
+#endif /* REVERT_GBM_BO */
 
 	if (pixmap->devKind > UINT16_MAX)
 		return -1;
 
+#if defined(REVERT_GBM_BO)
+	if (radeon_gem_prime_share_bo(bo, &fd) < 0)
+#else /* !REVERT_GBM_BO */
 	if (radeon_gem_prime_share_bo(bo->bo.radeon, &fd) < 0)
+#endif /* REVERT_GBM_BO */
 		return -1;
 
 	*stride = pixmap->devKind;
+#if defined(REVERT_GBM_BO)
+	*size = bo->size;
+#else /* !REVERT_GBM_BO */
 	*size = bo->bo.radeon->size;
+#endif /* REVERT_GBM_BO */
 	return fd;
 }
 
