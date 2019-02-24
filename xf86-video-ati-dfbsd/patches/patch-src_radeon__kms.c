$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/radeon_kms.c.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/radeon_kms.c
@@ -212,10 +212,12 @@ static void RADEONFreeRec(ScrnInfoPtr pS
 	    info->accel_state = NULL;
 	}
 
+#if !defined(REVERT_GBM_BO)
 #ifdef USE_GLAMOR
 	if (info->gbm)
 	    gbm_device_destroy(info->gbm);
 #endif
+#endif /* !REVERT_GBM_BO */
 
 	pEnt = info->pEnt;
 	free(pScrn->driverPrivate);
@@ -2269,10 +2271,14 @@ Bool RADEONScreenInit_KMS(ScreenPtr pScr
 	return FALSE;
     }
 
+#if defined(REVERT_GBM_BO)
+    front_ptr = info->front_buffer->bo.radeon->ptr;
+#else /* !REVERT_GBM_BO */
     if (!(info->front_buffer->flags & RADEON_BO_FLAGS_GBM))
 	front_ptr = info->front_buffer->bo.radeon->ptr;
     else
 	front_ptr = NULL;
+#endif /* REVERT_GBM_BO */
 
     if (info->r600_shadow_fb) {
 	info->fb_shadow = calloc(1,
@@ -2743,6 +2749,23 @@ static Bool radeon_setup_kernel_mem(Scre
             }
         }
 
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
+            radeon_bo_set_tiling(info->front_buffer->bo.radeon, tiling_flags, pitch);
+#else /* !REVERT_GBM_BO */
 	if (!info->use_glamor) {
 #if X_BYTE_ORDER == X_BIG_ENDIAN
 	    switch (cpp) {
@@ -2760,6 +2783,7 @@ static Bool radeon_setup_kernel_mem(Scre
 	    if (tiling_flags)
 		radeon_bo_set_tiling(info->front_buffer->bo.radeon, tiling_flags, pitch);
 	}
+#endif /* REVERT_GBM_BO */
 
 	pScrn->displayWidth = pitch / cpp;
     }
