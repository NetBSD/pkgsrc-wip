$NetBSD$

Option to revert:

2017-05-15 radeonsi: enable threaded_context
Commit:	1c8f7d3be6ffb3567041f1e11a037fa7e75e4c28

https://cgit.freedesktop.org/mesa/mesa/commit/?id=1c8f7d3be6ffb3567041f1e11a037fa7e75e4c28

2018-10-16 radeonsi: use compute shaders for clear_buffer & copy_buffer
Commit: 9b331e462e5021d994859756d46cd2519d9c9c6e

https://cgit.freedesktop.org/mesa/mesa/commit/?id=9b331e462e5021d994859756d46cd2519d9c9c6e

Option to revert:
2019-02-20
radeonsi: use SDMA for uploading data through const_uploader

https://cgit.freedesktop.org/mesa/mesa/commit/?id=edbd2c1ff559cde1d9e22a9fb9059747782a72a7

--- src/gallium/drivers/radeonsi/si_pipe.c.orig	2019-02-28 21:26:15.000000000 +0000
+++ src/gallium/drivers/radeonsi/si_pipe.c
@@ -197,10 +197,12 @@ static void si_destroy_context(struct pi
 		sctx->b.delete_vs_state(&sctx->b, sctx->vs_blit_color_layered);
 	if (sctx->vs_blit_texcoord)
 		sctx->b.delete_vs_state(&sctx->b, sctx->vs_blit_texcoord);
+#if !defined(REVERT_COPY_CLEAR)
 	if (sctx->cs_clear_buffer)
 		sctx->b.delete_compute_state(&sctx->b, sctx->cs_clear_buffer);
 	if (sctx->cs_copy_buffer)
 		sctx->b.delete_compute_state(&sctx->b, sctx->cs_copy_buffer);
+#endif
 	if (sctx->cs_copy_image)
 		sctx->b.delete_compute_state(&sctx->b, sctx->cs_copy_image);
 	if (sctx->cs_copy_image_1d_array)
@@ -378,7 +380,11 @@ static void si_set_context_param(struct
 }
 
 static struct pipe_context *si_create_context(struct pipe_screen *screen,
+#if defined(REVERT_THREADED_CONTEXT)
+                                              void *priv, unsigned flags)
+#else
                                               unsigned flags)
+#endif
 {
 	struct si_context *sctx = CALLOC_STRUCT(si_context);
 	struct si_screen* sscreen = (struct si_screen *)screen;
@@ -396,7 +402,11 @@ static struct pipe_context *si_create_co
 		sscreen->record_llvm_ir = true; /* racy but not critical */
 
 	sctx->b.screen = screen; /* this must be set first */
+#if defined(REVERT_THREADED_CONTEXT)
+	sctx->b.priv = priv;
+#else
 	sctx->b.priv = NULL;
+#endif
 	sctx->b.destroy = si_destroy_context;
 	sctx->screen = sscreen; /* Easy accessing of screen/winsys. */
 	sctx->is_debug = (flags & PIPE_CONTEXT_DEBUG) != 0;
@@ -454,8 +464,13 @@ static struct pipe_context *si_create_co
 						   sctx, stop_exec_on_failure);
 	}
 
+#if defined(REVERT_SDMA_UPLOADER)
+	bool use_sdma_upload = false;
+	sctx->b.const_uploader = u_upload_create(&sctx->b, 128 * 1024,
+#else
 	bool use_sdma_upload = sscreen->info.has_dedicated_vram && sctx->dma_cs;
 	sctx->b.const_uploader = u_upload_create(&sctx->b, 256 * 1024,
+#endif
 						 0, PIPE_USAGE_DEFAULT,
 						 SI_RESOURCE_FLAG_32BIT |
 						 (use_sdma_upload ?
@@ -647,6 +662,7 @@ fail:
 	return NULL;
 }
 
+#if !defined(REVERT_THREADED_CONTEXT)
 static struct pipe_context *si_pipe_create_context(struct pipe_screen *screen,
 						   void *priv, unsigned flags)
 {
@@ -677,6 +693,7 @@ static struct pipe_context *si_pipe_crea
 				       sscreen->info.drm_major >= 3 ? si_create_fence : NULL,
 				       &((struct si_context*)ctx)->tc);
 }
+#endif
 
 /*
  * pipe_screen
@@ -874,7 +891,11 @@ struct pipe_screen *radeonsi_screen_crea
 						       debug_options, 0);
 
 	/* Set functions first. */
+#if defined(REVERT_THREADED_CONTEXT)
+	sscreen->b.context_create = si_create_context;
+#else
 	sscreen->b.context_create = si_pipe_create_context;
+#endif
 	sscreen->b.destroy = si_destroy_screen;
 
 	si_init_screen_get_functions(sscreen);
@@ -1144,7 +1165,11 @@ struct pipe_screen *radeonsi_screen_crea
 		si_init_compiler(sscreen, &sscreen->compiler_lowp[i]);
 
 	/* Create the auxiliary context. This must be done last. */
+#if defined(REVERT_THREADED_CONTEXT)
+	sscreen->aux_context = sscreen->b.context_create(&sscreen->b, NULL, 0);
+#else
 	sscreen->aux_context = si_create_context(&sscreen->b, 0);
+#endif
 
 	if (sscreen->debug_flags & DBG(TEST_DMA))
 		si_test_dma(sscreen);
