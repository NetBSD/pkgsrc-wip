$NetBSD$

Disable Linux-only functions

--- cogl/cogl/cogl-dma-buf-handle.h.orig	2020-10-05 18:05:31.474278000 +0000
+++ cogl/cogl/cogl-dma-buf-handle.h
@@ -63,6 +63,7 @@ cogl_dma_buf_handle_new (CoglFramebuffer
 COGL_EXPORT void
 cogl_dma_buf_handle_free (CoglDmaBufHandle *dmabuf_handle);
 
+# ifndef __NetBSD__
 COGL_EXPORT gboolean
 cogl_dma_buf_handle_sync_read_start (CoglDmaBufHandle  *dmabuf_handle,
                                      GError           **error);
@@ -70,7 +71,7 @@ cogl_dma_buf_handle_sync_read_start (Cog
 COGL_EXPORT gboolean
 cogl_dma_buf_handle_sync_read_end (CoglDmaBufHandle  *dmabuf_handle,
                                    GError           **error);
-
+# endif
 COGL_EXPORT gpointer
 cogl_dma_buf_handle_mmap (CoglDmaBufHandle  *dmabuf_handle,
                           GError           **error);
