$NetBSD$

Ignore separations to fix issue #1 and issue #2.

XXX: Why this happens and why this solve the problem?

--- zathura-pdf-mupdf/render.c.orig	2018-10-04 00:21:14.161825172 +0000
+++ zathura-pdf-mupdf/render.c
@@ -36,8 +36,7 @@ pdf_page_render_to_buffer(mupdf_document
   fz_drop_device(mupdf_page->ctx, device);
 
   fz_colorspace* colorspace = fz_device_bgr(mupdf_document->ctx);
-  fz_separations* seps= fz_page_separations(mupdf_page->ctx, mupdf_page->page);
-  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, irect, seps, 1, image);
+  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, irect, NULL, 1, image);
   fz_clear_pixmap_with_value(mupdf_page->ctx, pixmap, 0xFF);
 
   device = fz_new_draw_device(mupdf_page->ctx, fz_identity, pixmap);
@@ -47,7 +46,6 @@ pdf_page_render_to_buffer(mupdf_document
 
   fz_drop_pixmap(mupdf_page->ctx, pixmap);
   fz_drop_display_list(mupdf_page->ctx, display_list);
-  fz_drop_separations(mupdf_page->ctx, seps);
 
   return ZATHURA_ERROR_OK;
 }
