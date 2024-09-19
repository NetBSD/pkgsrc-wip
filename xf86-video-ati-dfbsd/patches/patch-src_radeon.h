$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/radeon.h.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/radeon.h
@@ -606,8 +606,10 @@ typedef struct {
     unsigned hwcursor_disabled;
 
 #ifdef USE_GLAMOR
+#if !defined(REVERT_GBM_BO)
     struct gbm_device *gbm;
 
+#endif
     struct {
 	CreateGCProcPtr SavedCreateGC;
 	RegionPtr (*SavedCopyArea)(DrawablePtr, DrawablePtr, GCPtr, int, int,
@@ -747,6 +749,10 @@ static inline Bool radeon_set_pixmap_bo(
 	}
 
 	if (bo) {
+#if defined(REVERT_GBM_BO)
+	    uint32_t pitch;
+
+#endif
 	    if (!priv) {
 		priv = calloc(1, sizeof (struct radeon_pixmap));
 		if (!priv)
@@ -755,10 +761,16 @@ static inline Bool radeon_set_pixmap_bo(
 
 	    radeon_buffer_ref(bo);
 	    priv->bo = bo;
+#if defined(REVERT_GBM_BO)
+
+	radeon_bo_get_tiling(bo->bo.radeon, &priv->tiling_flags, &pitch);
+#endif
 	}
 
 	radeon_set_pixmap_private(pPix, priv);
+#if !defined(REVERT_GBM_BO)
 	radeon_get_pixmap_tiling_flags(pPix);
+#endif
 	return TRUE;
     } else
 #endif /* USE_GLAMOR */
