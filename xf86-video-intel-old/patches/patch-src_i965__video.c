$NetBSD: patch-src_i965__video.c,v 1.1 2013/05/29 03:38:09 makoto Exp $

git clone git://cgit.freedesktop.org/xorg/driver/xf86-video-intel/
git checkout e4cd9de2933ada3e2a4b43552729ae3a370128bf
and make diff

--- src/i965_video.c.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i965_video.c
@@ -795,6 +795,7 @@ i965_emit_video_setup(ScrnInfoPtr pScrn,
     OUT_BATCH(0); /* sf */
     /* Only the PS uses the binding table */
     OUT_RELOC(bind_bo, I915_GEM_DOMAIN_INSTRUCTION, 0, 0);
+    drm_intel_bo_unreference(bind_bo);
 
     /* Blend constant color (magenta is fun) */
     OUT_BATCH(BRW_3DSTATE_CONSTANT_COLOR | 3);
@@ -1130,16 +1131,15 @@ I965DisplayVideoTextured(ScrnInfoPtr pSc
 
 	i965_emit_video_setup(pScrn, bind_bo, n_src_surf);
 
-	BEGIN_BATCH(12);
+	BEGIN_BATCH(10);
 	/* Set up the pointer to our vertex buffer */
-	OUT_BATCH(BRW_3DSTATE_VERTEX_BUFFERS | 3);
+	OUT_BATCH(BRW_3DSTATE_VERTEX_BUFFERS | 2);
 	/* four 32-bit floats per vertex */
 	OUT_BATCH((0 << VB0_BUFFER_INDEX_SHIFT) |
 		  VB0_VERTEXDATA |
 		  ((4 * 4) << VB0_BUFFER_PITCH_SHIFT));
 	OUT_RELOC(vb_bo, I915_GEM_DOMAIN_VERTEX, 0, 0);
 	OUT_BATCH(3); /* four corners to our rectangle */
-	OUT_BATCH(0); /* reserved */
 
 	OUT_BATCH(BRW_3DPRIMITIVE |
 		  BRW_3DPRIMITIVE_VERTEX_SEQUENTIAL |
@@ -1151,7 +1151,6 @@ I965DisplayVideoTextured(ScrnInfoPtr pSc
 	OUT_BATCH(1); /* single instance */
 	OUT_BATCH(0); /* start instance location */
 	OUT_BATCH(0); /* index buffer offset, ignored */
-	OUT_BATCH(MI_NOOP);
 	ADVANCE_BATCH();
 
 	intel_batch_end_atomic(pScrn);
@@ -1162,10 +1161,6 @@ I965DisplayVideoTextured(ScrnInfoPtr pSc
     }
 
     i830MarkSync(pScrn);
-
-    /* release reference once we're finished */
-    drm_intel_bo_unreference(bind_bo);
-
 #if WATCH_STATS
     i830_dump_error_state(pScrn);
 #endif
