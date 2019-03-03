$NetBSD$

Option to revert:
2019-02-20
radeonsi: use SDMA for uploading data through const_uploader

https://cgit.freedesktop.org/mesa/mesa/commit/?id=edbd2c1ff559cde1d9e22a9fb9059747782a72a7

--- src/gallium/drivers/radeonsi/si_buffer.c.orig	2019-02-21 02:04:29.000000000 +0000
+++ src/gallium/drivers/radeonsi/si_buffer.c
@@ -440,6 +440,9 @@ static void *si_buffer_transfer_map(stru
 		}
 	}
 
+#if defined(REVERT_SDMA_UPLOADER)
+	if ((usage & PIPE_TRANSFER_DISCARD_RANGE) &&
+#else
 	if (usage & PIPE_TRANSFER_FLUSH_EXPLICIT &&
 	    buf->b.b.flags & SI_RESOURCE_FLAG_UPLOAD_FLUSH_EXPLICIT_VIA_SDMA) {
 		usage &= ~(PIPE_TRANSFER_UNSYNCHRONIZED |
@@ -449,6 +452,7 @@ static void *si_buffer_transfer_map(stru
 	}
 
 	if (usage & PIPE_TRANSFER_DISCARD_RANGE &&
+#endif
 	    ((!(usage & (PIPE_TRANSFER_UNSYNCHRONIZED |
 			 PIPE_TRANSFER_PERSISTENT))) ||
 	     (buf->flags & RADEON_FLAG_SPARSE))) {
@@ -461,6 +465,12 @@ static void *si_buffer_transfer_map(stru
 		    si_rings_is_buffer_referenced(sctx, buf->buf, RADEON_USAGE_READWRITE) ||
 		    !sctx->ws->buffer_wait(buf->buf, 0, RADEON_USAGE_READWRITE)) {
 			/* Do a wait-free write-only transfer using a temporary buffer. */
+#if defined(REVERT_SDMA_UPLOADER)
+			unsigned offset;
+			struct si_resource *staging = NULL;
+
+			u_upload_alloc(ctx->stream_uploader, 0,
+#else
 			struct u_upload_mgr *uploader;
 			struct si_resource *staging = NULL;
 			unsigned offset;
@@ -475,6 +485,7 @@ static void *si_buffer_transfer_map(stru
 				uploader = sctx->b.stream_uploader;
 
 			u_upload_alloc(uploader, 0,
+#endif
                                        box->width + (box->x % SI_MAP_BUFFER_ALIGNMENT),
 				       sctx->screen->info.tcc_cache_line_size,
 				       &offset, (struct pipe_resource**)&staging,
@@ -548,6 +559,7 @@ static void si_buffer_do_flush_region(st
 				      transfer->box.x % SI_MAP_BUFFER_ALIGNMENT +
 				      (box->x - transfer->box.x);
 
+#if !defined(REVERT_SDMA_UPLOADER)
 		if (buf->b.b.flags & SI_RESOURCE_FLAG_UPLOAD_FLUSH_EXPLICIT_VIA_SDMA) {
 			/* This should be true for all uploaders. */
 			assert(transfer->box.x == 0);
@@ -587,6 +599,7 @@ static void si_buffer_do_flush_region(st
 			up->size = box->width;
 			return;
 		}
+#endif
 
 		/* Copy the staging buffer into the original one. */
 		si_copy_buffer(sctx, transfer->resource, &stransfer->staging->b.b,
