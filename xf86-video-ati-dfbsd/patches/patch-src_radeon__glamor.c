$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/radeon_glamor.c.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/radeon_glamor.c
@@ -50,6 +50,29 @@ radeon_glamor_exchange_buffers(PixmapPtr
 Bool
 radeon_glamor_create_screen_resources(ScreenPtr screen)
 {
+#if defined(REVERT_GBM_BO)
+
+	ScrnInfoPtr scrn = xf86ScreenToScrn(screen);
+	RADEONInfoPtr info = RADEONPTR(scrn);
+
+	if (!info->use_glamor)
+		return TRUE;
+
+#ifdef HAVE_GLAMOR_GLYPHS_INIT
+	if (!glamor_glyphs_init(screen))
+		return FALSE;
+#endif
+
+	if (!glamor_egl_create_textured_screen(screen,
+					       info->front_buffer->bo.radeon->handle,
+					       scrn->displayWidth *
+					       info->pixel_bytes))
+		return FALSE;
+
+	return TRUE;
+
+#else /* !REVERT_GBM_BO */
+
 	PixmapPtr screen_pixmap = screen->GetScreenPixmap(screen);
 	ScrnInfoPtr scrn = xf86ScreenToScrn(screen);
 	RADEONInfoPtr info = RADEONPTR(scrn);
@@ -64,6 +87,7 @@ radeon_glamor_create_screen_resources(Sc
 
 	return radeon_glamor_create_textured_pixmap(screen_pixmap,
 						    info->front_buffer);
+#endif /* REVERT_GBM_BO */
 }
 
 
@@ -132,12 +156,14 @@ radeon_glamor_pre_init(ScrnInfoPtr scrn)
 	}
 #endif
 
+#if !defined(REVERT_GBM_BO)
 	info->gbm = gbm_create_device(pRADEONEnt->fd);
 	if (!info->gbm) {
 		xf86DrvMsg(scrn->scrnIndex, X_ERROR,
 			   "gbm_create_device returned NULL\n");
 		return FALSE;
 	}
+#endif
 
 	/* Load glamor module */
 	if ((glamor_module = xf86LoadSubModule(scrn, GLAMOR_EGL_MODULE_NAME))) {
@@ -166,6 +192,13 @@ radeon_glamor_pre_init(ScrnInfoPtr scrn)
 	return TRUE;
 }
 
+#if defined(REVERT_GBM_BO)
+radeon_glamor_create_textured_pixmap(PixmapPtr pixmap, struct radeon_pixmap *priv)
+{
+	return glamor_egl_create_textured_pixmap(pixmap, priv->bo->bo.radeon->handle,
+						 pixmap->devKind);
+}
+#else /* !REVERT_GBM_BO */
 Bool
 radeon_glamor_create_textured_pixmap(PixmapPtr pixmap, struct radeon_buffer *bo)
 {
@@ -188,6 +221,7 @@ radeon_glamor_create_textured_pixmap(Pix
 							 pixmap->devKind);
 	}
 }
+#endif /* REVERT_GBM_BO */
 
 static Bool radeon_glamor_destroy_pixmap(PixmapPtr pixmap)
 {
@@ -198,6 +232,15 @@ static Bool radeon_glamor_destroy_pixmap
 #endif
 
 	if (pixmap->refcnt == 1) {
+#if defined(REVERT_GBM_BO)
+		if (pixmap->devPrivate.ptr) {
+			struct radeon_buffer *bo = radeon_get_pixmap_bo(pixmap);
+
+			if (bo)
+				radeon_bo_unmap(bo->bo.radeon);
+		}
+#endif /* REVERT_GBM_BO */
+
 #ifdef HAVE_GLAMOR_EGL_DESTROY_TEXTURED_PIXMAP
 		glamor_egl_destroy_textured_pixmap(pixmap);
 #endif
@@ -271,7 +314,11 @@ radeon_glamor_create_pixmap(ScreenPtr sc
 
 		screen->ModifyPixmapHeader(pixmap, w, h, 0, 0, stride, NULL);
 
+#if defined(REVERT_GBM_BO)
+		if (!radeon_glamor_create_textured_pixmap(pixmap, priv))
+#else
 		if (!radeon_glamor_create_textured_pixmap(pixmap, priv->bo))
+#endif
 			goto fallback_glamor;
 
 		pixmap->devPrivate.ptr = NULL;
@@ -402,11 +449,23 @@ radeon_glamor_set_shared_pixmap_backing(
 {
 	ScreenPtr screen = pixmap->drawable.pScreen;
 	ScrnInfoPtr scrn = xf86ScreenToScrn(screen);
+#if defined(REVERT_GBM_BO)
+	struct radeon_pixmap *priv;
+#else /* !REVERT_GBM_BO */
 	int ihandle = (int)(long)handle;
+#endif /* REVERT_GBM_BO */
 
 	if (!radeon_set_shared_pixmap_backing(pixmap, handle, NULL))
 		return FALSE;
 
+#if defined(REVERT_GBM_BO)
+	priv = radeon_get_pixmap_private(pixmap);
+	if (!radeon_glamor_create_textured_pixmap(pixmap, priv)) {
+		xf86DrvMsg(scrn->scrnIndex, X_ERROR,
+			   "Failed to get PRIME drawable for glamor pixmap.\n");
+		return FALSE;
+	}
+#else /* !REVERT_GBM_BO */
 	if (ihandle != -1 &&
 	    !radeon_glamor_create_textured_pixmap(pixmap,
 						  radeon_get_pixmap_bo(pixmap))) {
@@ -414,6 +473,7 @@ radeon_glamor_set_shared_pixmap_backing(
 			   "Failed to get PRIME drawable for glamor pixmap.\n");
 		return FALSE;
 	}
+#endif /* REVERT_GBM_BO */
 
 	screen->ModifyPixmapHeader(pixmap,
 				   pixmap->drawable.width,
