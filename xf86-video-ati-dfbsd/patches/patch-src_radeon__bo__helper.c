$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/radeon_bo_helper.c.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/radeon_bo_helper.c
@@ -28,7 +28,7 @@
 #include "radeon_glamor.h"
 #include "radeon_bo_gem.h"
 
-
+#if !defined(REVERT_GBM_BO)
 #ifdef USE_GLAMOR
 
 static uint32_t
@@ -57,7 +57,7 @@ radeon_get_gbm_format(int depth, int bit
 }
 
 #endif /* USE_GLAMOR */
-
+#endif /* !REVERT_GBM_BO */
 
 static const unsigned MicroBlockTable[5][3][2] = {
     /*linear  tiled   square-tiled */
@@ -190,6 +190,7 @@ radeon_alloc_pixmap_bo(ScrnInfoPtr pScrn
     struct radeon_buffer *bo;
     int domain = RADEON_GEM_DOMAIN_VRAM;
 
+#if !defined(REVERT_GBM_BO)
 #ifdef USE_GLAMOR
     if (info->use_glamor &&
 	!(usage_hint == CREATE_PIXMAP_USAGE_BACKING_PIXMAP &&
@@ -228,6 +229,7 @@ radeon_alloc_pixmap_bo(ScrnInfoPtr pScrn
 	return bo;
     }
 #endif
+#endif /* !REVERT_GBM_BO */
 
     if (usage_hint) {
 	if (info->allowColorTiling) {
@@ -316,12 +318,14 @@ radeon_alloc_pixmap_bo(ScrnInfoPtr pScrn
 void
 radeon_finish(ScrnInfoPtr scrn, struct radeon_buffer *bo)
 {
+#if !defined(REVERT_GBM_BO)
     RADEONInfoPtr info = RADEONPTR(scrn);
 
     if (info->use_glamor) {
 	radeon_glamor_finish(scrn);
 	return;
     }
+#endif /* !REVERT_GBM_BO */
 
     radeon_cs_flush_indirect(scrn);
     radeon_bo_wait(bo->bo.radeon);
@@ -360,10 +364,17 @@ Bool radeon_get_pixmap_handle(PixmapPtr
     RADEONInfoPtr info = RADEONPTR(scrn);
 #endif
 
+#if defined(REVERT_GBM_BO)
+    if (bo) {
+	*handle = bo->bo.radeon->handle;
+	return TRUE;
+    }
+#else
     if (bo && !(bo->flags & RADEON_BO_FLAGS_GBM)) {
 	*handle = bo->bo.radeon->handle;
 	return TRUE;
     }
+#endif
 
 #ifdef USE_GLAMOR
     if (info->use_glamor) {
@@ -461,6 +472,7 @@ Bool radeon_set_shared_pixmap_backing(Pi
     if (!bo)
 	goto error;
 
+#if !defined(REVERT_GBM_BO)
 #ifdef USE_GLAMOR
     if (info->use_glamor) {
 	struct gbm_import_fd_data data;
@@ -498,6 +510,7 @@ Bool radeon_set_shared_pixmap_backing(Pi
 	return ret;
     }
 #endif
+#endif /* !REVERT_GBM_BO */
 
     bo->bo.radeon = radeon_gem_bo_open_prime(info->bufmgr, ihandle, size);
     if (!bo)
