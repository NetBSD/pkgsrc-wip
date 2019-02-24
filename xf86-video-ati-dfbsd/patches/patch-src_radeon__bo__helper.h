$NetBSD$

Revert:
glamor: Use GBM for BO allocation when possible
commit	3c4c0213c11d623cba7adbc28dde652694f2f758

https://cgit.freedesktop.org/xorg/driver/xf86-video-ati

--- src/radeon_bo_helper.h.orig	2018-09-14 15:56:09.000000000 +0000
+++ src/radeon_bo_helper.h
@@ -23,21 +23,27 @@
 #ifndef RADEON_BO_HELPER_H
 #define RADEON_BO_HELPER_H 1
 
+#if !defined(REVERT_GBM_BO)
 #ifdef USE_GLAMOR
 #include <gbm.h>
 #endif
+#endif /* !REVERT_GBM_BO */
 
 #define RADEON_BO_FLAGS_GBM	0x1
 
 struct radeon_buffer {
 	union {
+#if !defined(REVERT_GBM_BO)
 #ifdef USE_GLAMOR
 		struct gbm_bo *gbm;
 #endif
+#endif /* !REVERT_GBM_BO */
 		struct radeon_bo *radeon;
 	} bo;
 	uint32_t ref_count;
+#if !defined(REVERT_GBM_BO)
     uint32_t flags;
+#endif /* !REVERT_GBM_BO */
 };
 
 extern struct radeon_buffer *
@@ -96,6 +102,10 @@ radeon_buffer_unref(struct radeon_buffer
 	return;
     }
 
+#if defined(REVERT_GBM_BO)
+    radeon_bo_unmap(buf->bo.radeon);
+    radeon_bo_unref(buf->bo.radeon);
+#else /* !REVERT_GBM_BO */
 #ifdef USE_GLAMOR
     if (buf->flags & RADEON_BO_FLAGS_GBM) {
 	gbm_bo_destroy(buf->bo.gbm);
@@ -105,6 +115,7 @@ radeon_buffer_unref(struct radeon_buffer
 	radeon_bo_unmap(buf->bo.radeon);
 	radeon_bo_unref(buf->bo.radeon);
     }
+#endif /* REVERT_GBM_BO */
 
     free(buf);
     *buffer = NULL;
