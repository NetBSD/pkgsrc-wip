$NetBSD$

Option to revert:
2019-02-20
radeonsi: use SDMA for uploading data through const_uploader

https://cgit.freedesktop.org/mesa/mesa/commit/?id=edbd2c1ff559cde1d9e22a9fb9059747782a72a7

--- src/gallium/drivers/radeonsi/si_dma_cs.c.orig	2019-02-21 02:04:29.000000000 +0000
+++ src/gallium/drivers/radeonsi/si_dma_cs.c
@@ -182,7 +182,11 @@ void si_need_dma_space(struct si_context
 					 RADEON_USAGE_WRITE)))
 		si_dma_emit_wait_idle(ctx);
 
+#if defined(REVERT_SDMA_UPLOADER)
+	unsigned sync = 0;
+#else
 	unsigned sync = ctx->sdma_uploads_in_progress ? 0 : RADEON_USAGE_SYNCHRONIZED;
+#endif
 	if (dst) {
 		ws->cs_add_buffer(ctx->dma_cs, dst->buf, RADEON_USAGE_WRITE | sync,
 				  dst->domains, 0);
