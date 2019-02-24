$NetBSD$

Option to revert:

2017-05-15 radeonsi: enable threaded_context
Commit:	1c8f7d3be6ffb3567041f1e11a037fa7e75e4c28

https://cgit.freedesktop.org/mesa/mesa/commit/?id=1c8f7d3be6ffb3567041f1e11a037fa7e75e4c28

2018-10-16 radeonsi: use compute shaders for clear_buffer & copy_buffer
Commit: 9b331e462e5021d994859756d46cd2519d9c9c6e

https://cgit.freedesktop.org/mesa/mesa/commit/?id=9b331e462e5021d994859756d46cd2519d9c9c6e

--- src/gallium/drivers/radeonsi/si_pipe.c.orig	2019-02-02 23:08:03.000000000 +0000
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
@@ -373,7 +375,11 @@ static void si_set_context_param(struct 
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
@@ -388,7 +394,11 @@ static struct pipe_context *si_create_co
 		sscreen->record_llvm_ir = true; /* racy but not critical */
 
 	sctx->b.screen = screen; /* this must be set first */
+#if defined(REVERT_THREADED_CONTEXT)
+	sctx->b.priv = priv;
+#else
 	sctx->b.priv = NULL;
+#endif
 	sctx->b.destroy = si_destroy_context;
 	sctx->b.emit_string_marker = si_emit_string_marker;
 	sctx->b.set_debug_callback = si_set_debug_callback;
@@ -622,6 +632,7 @@ fail:
 	return NULL;
 }
 
+#if !defined(REVERT_THREADED_CONTEXT)
 static struct pipe_context *si_pipe_create_context(struct pipe_screen *screen,
 						   void *priv, unsigned flags)
 {
@@ -652,6 +663,7 @@ static struct pipe_context *si_pipe_crea
 				       sscreen->info.drm_major >= 3 ? si_create_fence : NULL,
 				       &((struct si_context*)ctx)->tc);
 }
+#endif
 
 /*
  * pipe_screen
@@ -847,7 +859,11 @@ struct pipe_screen *radeonsi_screen_crea
 							debug_options, 0);
 
 	/* Set functions first. */
+#if defined(REVERT_THREADED_CONTEXT)
+	sscreen->b.context_create = si_create_context;
+#else
 	sscreen->b.context_create = si_pipe_create_context;
+#endif
 	sscreen->b.destroy = si_destroy_screen;
 
 	si_init_screen_get_functions(sscreen);
@@ -1116,7 +1132,11 @@ struct pipe_screen *radeonsi_screen_crea
 		si_init_compiler(sscreen, &sscreen->compiler_lowp[i]);
 
 	/* Create the auxiliary context. This must be done last. */
+#if defined(REVERT_THREADED_CONTEXT)
+	sscreen->aux_context = sscreen->b.context_create(&sscreen->b, NULL, 0);
+#else
 	sscreen->aux_context = si_create_context(&sscreen->b, 0);
+#endif
 
 	if (sscreen->debug_flags & DBG(TEST_DMA))
 		si_test_dma(sscreen);
