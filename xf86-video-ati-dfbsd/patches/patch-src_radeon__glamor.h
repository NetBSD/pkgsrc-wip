$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/radeon_glamor.h.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/radeon_glamor.h
@@ -33,12 +33,14 @@ struct radeon_pixmap;
 
 #ifdef USE_GLAMOR
 
+#if !defined(REVERT_GBM_BO)
 #ifndef HAVE_GLAMOR_FINISH
 #include <GL/gl.h>
 #endif
 
 #include <gbm.h>
 
+#endif /* !REVERT_GBM_BO */
 #define GLAMOR_FOR_XORG  1
 #include <glamor.h>
 
@@ -71,12 +73,17 @@ void radeon_glamor_screen_init(ScreenPtr
 Bool radeon_glamor_create_screen_resources(ScreenPtr screen);
 void radeon_glamor_free_screen(int scrnIndex, int flags);
 
+#if defined(REVERT_GBM_BO)
+Bool radeon_glamor_create_textured_pixmap(PixmapPtr pixmap, struct radeon_pixmap *priv);
+#else
 Bool radeon_glamor_create_textured_pixmap(PixmapPtr pixmap, struct radeon_buffer *bo);
+#endif
 void radeon_glamor_exchange_buffers(PixmapPtr src, PixmapPtr dst);
 PixmapPtr radeon_glamor_set_pixmap_bo(DrawablePtr drawable, PixmapPtr pixmap);
 
 XF86VideoAdaptorPtr radeon_glamor_xv_init(ScreenPtr pScreen, int num_adapt);
 
+#if !defined(REVERT_GBM_BO)
 static inline void
 radeon_glamor_finish(ScrnInfoPtr scrn)
 {
@@ -91,6 +98,7 @@ radeon_glamor_finish(ScrnInfoPtr scrn)
 
 	info->gpu_flushed++;
 }
+#endif /* !REVERT_GBM_BO */
 
 #else
 
@@ -100,7 +108,11 @@ static inline void radeon_glamor_fini(Sc
 static inline Bool radeon_glamor_create_screen_resources(ScreenPtr screen) { return FALSE; }
 static inline void radeon_glamor_free_screen(int scrnIndex, int flags) { }
 
+#if defined(REVERT_GBM_BO)
+static inline Bool radeon_glamor_create_textured_pixmap(PixmapPtr pixmap, struct radeon_pixmap *priv) { return TRUE; }
+#else
 static inline Bool radeon_glamor_create_textured_pixmap(PixmapPtr pixmap, struct radeon_buffer *bo) { return TRUE; }
+#endif
 
 static inline void radeon_glamor_exchange_buffers(PixmapPtr src, PixmapPtr dst) {}
 static inline PixmapPtr radeon_glamor_set_pixmap_bo(DrawablePtr drawable, PixmapPtr pixmap) { return pixmap; }
@@ -109,7 +121,9 @@ static inline struct radeon_pixmap *rade
 
 static inline XF86VideoAdaptorPtr radeon_glamor_xv_init(ScreenPtr pScreen, int num_adapt) { return NULL; }
 
+#if !defined(REVERT_GBM_BO)
 static inline void radeon_glamor_finish(ScrnInfoPtr pScrn) { }
+#endif /* !REVERT_GBM_BO */
 
 #endif
 
