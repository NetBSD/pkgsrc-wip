$NetBSD$

2018-10-16 radeonsi: use compute shaders for clear_buffer & copy_buffer
Commit: 9b331e462e5021d994859756d46cd2519d9c9c6e

https://cgit.freedesktop.org/mesa/mesa/commit/?id=9b331e462e5021d994859756d46cd2519d9c9c6e

--- src/gallium/drivers/radeonsi/si_compute_blit.c.orig	2019-04-23 07:24:08.000000000 +0000
+++ src/gallium/drivers/radeonsi/si_compute_blit.c
@@ -34,10 +34,17 @@ static enum si_cache_policy get_cache_po
 					     enum si_coherency coher,
 					     uint64_t size)
 {
+#if defined(REVERT_COPY_CLEAR)
+	if ((sctx->chip_class >= GFX9 && coher == SI_COHERENCY_CB_META) ||
+	    (sctx->chip_class >= CIK && coher == SI_COHERENCY_SHADER))
+		return L2_LRU;
+		
+#else
 	if ((sctx->chip_class >= GFX9 && (coher == SI_COHERENCY_CB_META ||
 					  coher == SI_COHERENCY_CP)) ||
 	    (sctx->chip_class >= CIK && coher == SI_COHERENCY_SHADER))
 		return size <= 256 * 1024 ? L2_LRU : L2_STREAM;
+#endif
 
 	return L2_BYPASS;
 }
@@ -189,6 +196,52 @@ void si_clear_buffer(struct si_context *
 		     uint32_t clear_value_size, enum si_coherency coher,
 		     bool force_cpdma)
 {
+#if defined(REVERT_COPY_CLEAR)
+
+/* Recommended maximum sizes for optimal performance.
+ * Fall back to compute or SDMA if the size is greater.
+ */
+#define CP_DMA_COPY_PERF_THRESHOLD	(64 * 1024) /* copied from Vulkan */
+#define CP_DMA_CLEAR_PERF_THRESHOLD	(32 * 1024) /* guess (clear is much slower) */
+
+	struct radeon_winsys *ws = sctx->ws;
+	struct si_resource *rdst = si_resource(dst);
+	enum si_cache_policy cache_policy = get_cache_policy(sctx, coher, size);
+
+	if (!size)
+		return;
+
+	uint64_t aligned_size = size & ~3ull;
+
+	/* dma_clear_buffer can use clear_buffer on failure. Make sure that
+	 * doesn't happen. We don't want an infinite recursion: */
+	if (sctx->dma_cs &&
+	    !(dst->flags & PIPE_RESOURCE_FLAG_SPARSE) &&
+	    (offset % 4 == 0) &&
+	    /* CP DMA is very slow. Always use SDMA for big clears. This
+	     * alone improves DeusEx:MD performance by 70%. */
+	    (size > CP_DMA_CLEAR_PERF_THRESHOLD ||
+	     /* Buffers not used by the GFX IB yet will be cleared by SDMA.
+	      * This happens to move most buffer clears to SDMA, including
+	      * DCC and CMASK clears, because pipe->clear clears them before
+	      * si_emit_framebuffer_state (in a draw call) adds them.
+	      * For example, DeusEx:MD has 21 buffer clears per frame and all
+	      * of them are moved to SDMA thanks to this. */
+	     !ws->cs_is_buffer_referenced(sctx->gfx_cs, rdst->buf,
+				          RADEON_USAGE_READWRITE))) {
+		si_sdma_clear_buffer(sctx, dst, offset, aligned_size, *clear_value);
+
+		offset += aligned_size;
+		size -= aligned_size;
+	} else if (aligned_size >= 4) {
+		si_cp_dma_clear_buffer(sctx, sctx->gfx_cs, dst, offset,
+				       aligned_size, *clear_value, 0, coher,
+				       get_cache_policy(sctx, coher, size));
+
+		offset += aligned_size;
+		size -= aligned_size;
+	}
+#else
 	if (!size)
 		return;
 
@@ -268,6 +321,7 @@ void si_clear_buffer(struct si_context *
 		offset += aligned_size;
 		size -= aligned_size;
 	}
+#endif
 
 	/* Handle non-dword alignment. */
 	if (size) {
@@ -285,8 +339,61 @@ static void si_pipe_clear_buffer(struct 
 				 const void *clear_value,
 				 int clear_value_size)
 {
+#if defined(REVERT_COPY_CLEAR)
+	struct si_context *sctx = (struct si_context*)ctx;
+	uint32_t dword_value;
+
+	assert(offset % clear_value_size == 0);
+	assert(size % clear_value_size == 0);
+
+	if (clear_value_size > 4) {
+		bool clear_dword_duplicated = true;
+
+		/* See if we can lower large fills to dword fills. */
+		for (unsigned i = 1; i < clear_value_size / 4; i++)
+			if (((uint32_t *)clear_value)[0] != ((uint32_t*)clear_value)[i]) {
+				clear_dword_duplicated = false;
+				break;
+			}
+
+		if (!clear_dword_duplicated) {
+			/* Use transform feedback for 64-bit, 96-bit, and
+			 * 128-bit fills.
+			 */
+			union pipe_color_union streamout_clear_value;
+
+			memcpy(&streamout_clear_value, clear_value, clear_value_size);
+			si_blitter_begin(sctx, SI_DISABLE_RENDER_COND);
+			util_blitter_clear_buffer(sctx->blitter, dst, offset,
+						  size, clear_value_size / 4,
+						  &streamout_clear_value);
+			si_blitter_end(sctx);
+			return;
+		}
+	}
+
+	/* Expand the clear value to a dword. */
+	switch (clear_value_size) {
+	case 1:
+		dword_value = *(uint8_t*)clear_value;
+		dword_value |= (dword_value << 8) |
+			       (dword_value << 16) |
+			       (dword_value << 24);
+		break;
+	case 2:
+		dword_value = *(uint16_t*)clear_value;
+		dword_value |= dword_value << 16;
+		break;
+	default:
+		dword_value = *(uint32_t*)clear_value;
+	}
+
+	si_clear_buffer(sctx, dst, offset, size, &dword_value,
+			clear_value_size, SI_COHERENCY_SHADER, false);
+#else
 	si_clear_buffer((struct si_context*)ctx, dst, offset, size, (uint32_t*)clear_value,
 			clear_value_size, SI_COHERENCY_SHADER, false);
+#endif
 }
 
 void si_copy_buffer(struct si_context *sctx,
@@ -299,6 +406,17 @@ void si_copy_buffer(struct si_context *s
 	enum si_coherency coher = SI_COHERENCY_SHADER;
 	enum si_cache_policy cache_policy = get_cache_policy(sctx, coher, size);
 
+#if defined(REVERT_COPY_CLEAR)
+	si_cp_dma_copy_buffer(sctx, dst, src, dst_offset, src_offset, size,
+			      0, coher, cache_policy);
+ 
+	if (cache_policy != L2_BYPASS)
+ 		si_resource(dst)->TC_L2_dirty = true;
+ 
+	/* If it's not a prefetch... */
+	if (dst_offset != src_offset)
+		sctx->num_cp_dma_calls++;
+#else
 	/* Only use compute for VRAM copies on dGPUs. */
 	if (sctx->screen->info.has_dedicated_vram &&
 	    si_resource(dst)->domains & RADEON_DOMAIN_VRAM &&
@@ -311,6 +429,7 @@ void si_copy_buffer(struct si_context *s
 		si_cp_dma_copy_buffer(sctx, dst, src, dst_offset, src_offset, size,
 				      0, coher, cache_policy);
 	}
+#endif
 }
 
 void si_compute_copy_image(struct si_context *sctx,
