$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/drmmode_display.c.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/drmmode_display.c
@@ -134,8 +134,14 @@ static PixmapPtr drmmode_create_bo_pixma
 			goto fail;
 	}
 
+#if defined(REVERT_GBM_BO)
+ 	if (!info->use_glamor ||
+	    radeon_glamor_create_textured_pixmap(pixmap,
+						 radeon_get_pixmap_private(pixmap)))
+#else
 	if (!info->use_glamor ||
 	    radeon_glamor_create_textured_pixmap(pixmap, bo))
+#endif
 		return pixmap;
 
 fail:
@@ -426,6 +432,13 @@ destroy_pixmap_for_fbcon(ScrnInfoPtr pSc
 {
 	RADEONInfoPtr info = RADEONPTR(pScrn);
 
+#if defined(REVERT_GBM_BO)
+	/* XXX: The current GPUVM support in the kernel doesn't allow removing
+	 * the virtual address range for this BO, so we need to keep around
+	 * the pixmap to avoid breaking glamor with GPUVM
+	 */
+	if (info->use_glamor && info->ChipFamily >= CHIP_FAMILY_CAYMAN)
+#else
 	/* XXX: The current GPUVM support in the kernel doesn't allow removing
 	 * the virtual address range for this BO, so we need to keep around
 	 * the pixmap to avoid breaking glamor with GPUVM
@@ -437,6 +450,7 @@ destroy_pixmap_for_fbcon(ScrnInfoPtr pSc
 	if (info->use_glamor &&
 	    (info->ChipFamily >= CHIP_FAMILY_CAYMAN ||
 	     xorgGetVersion() >= XORG_VERSION_NUMERIC(1,19,99,1,0)))
+#endif
 		return;
 
 	if (info->fbcon_pixmap)
@@ -2311,6 +2325,23 @@ drmmode_xf86crtc_resize (ScrnInfoPtr scr
 
 	scrn->displayWidth = pitch / cpp;
 
+#if defined(REVERT_GBM_BO)
+#if X_BYTE_ORDER == X_BIG_ENDIAN
+	switch (cpp) {
+	case 4:
+	    tiling_flags |= RADEON_TILING_SWAP_32BIT;
+	    break;
+	case 2:
+	    tiling_flags |= RADEON_TILING_SWAP_16BIT;
+	    break;
+	}
+	if (info->ChipFamily < CHIP_FAMILY_R600 &&
+	    info->r600_shadow_fb && tiling_flags)
+	    tiling_flags |= RADEON_TILING_SURFACE;
+#endif
+	if (tiling_flags)
+	    radeon_bo_set_tiling(info->front_buffer->bo.radeon, tiling_flags, pitch);
+#else
 	if (!info->use_glamor) {
 #if X_BYTE_ORDER == X_BIG_ENDIAN
 		switch (cpp) {
@@ -2328,6 +2359,7 @@ drmmode_xf86crtc_resize (ScrnInfoPtr scr
 		if (tiling_flags)
 			radeon_bo_set_tiling(info->front_buffer->bo.radeon, tiling_flags, pitch);
 	}
+#endif
 
 	if (!info->r600_shadow_fb) {
 		if (info->surf_man && !info->use_glamor)
