$NetBSD$

Option to revert:
2019-02-20
radeonsi: use SDMA for uploading data through const_uploader

https://cgit.freedesktop.org/mesa/mesa/commit/?id=edbd2c1ff559cde1d9e22a9fb9059747782a72a7

--- src/gallium/drivers/radeonsi/si_gfx_cs.c.orig	2019-02-28 21:26:15.000000000 +0000
+++ src/gallium/drivers/radeonsi/si_gfx_cs.c
@@ -108,6 +108,19 @@ void si_flush_gfx_cs(struct si_context *
 	if (ctx->screen->debug_flags & DBG(CHECK_VM))
 		flags &= ~PIPE_FLUSH_ASYNC;
 
+#if defined(REVERT_SDMA_UPLOADER)
+	/* If the state tracker is flushing the GFX IB, si_flush_from_st is
+	 * responsible for flushing the DMA IB and merging the fences from both.
+	 * This code is only needed when the driver flushes the GFX IB
+	 * internally, and it never asks for a fence handle.
+	 */
+	if (radeon_emitted(ctx->dma_cs, 0)) {
+		assert(fence == NULL); /* internal flushes only */
+		si_flush_dma_cs(ctx, flags, NULL);
+	}
+
+	ctx->gfx_flush_in_progress = true;
+#else
 	ctx->gfx_flush_in_progress = true;
 
 	/* If the state tracker is flushing the GFX IB, si_flush_from_st is
@@ -139,6 +152,7 @@ void si_flush_gfx_cs(struct si_context *
 	/* Flush SDMA (preamble IB). */
 	if (radeon_emitted(ctx->dma_cs, 0))
 		si_flush_dma_cs(ctx, flags, NULL);
+#endif
 
 	if (ctx->has_graphics) {
 		if (!LIST_IS_EMPTY(&ctx->active_queries))
