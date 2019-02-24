$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/radeon_dri3.c.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/radeon_dri3.c
@@ -214,6 +214,22 @@ static int radeon_dri3_fd_from_pixmap(Sc
 {
 	struct radeon_bo *bo;
 	int fd;
+
+#if defined(REVERT_GBM_BO)
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
 #ifdef USE_GLAMOR
 	ScrnInfoPtr scrn = xf86ScreenToScrn(screen);
 	RADEONInfoPtr info = RADEONPTR(scrn);
@@ -229,6 +245,7 @@ static int radeon_dri3_fd_from_pixmap(Sc
 		if (!bo)
 			return -1;
 	}
+#endif /* REVERT_GBM_BO */
 
 	if (pixmap->devKind > UINT16_MAX)
 		return -1;
