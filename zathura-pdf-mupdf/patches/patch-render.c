$NetBSD$

--- render.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ render.c
@@ -37,7 +37,7 @@ pdf_page_render_to_buffer(mupdf_document
   fz_rect rect = { .x1 = page_width, .y1 = page_height };
 
   fz_colorspace* colorspace = fz_device_bgr(mupdf_document->ctx);
-  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, &irect, 1, image);
+  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, &irect, NULL, 1, image);
   fz_clear_pixmap_with_value(mupdf_page->ctx, pixmap, 0xFF);
 
   device = fz_new_draw_device(mupdf_page->ctx, NULL, pixmap);
