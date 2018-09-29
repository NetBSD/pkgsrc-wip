$NetBSD$

Port to mupdf-1.14.0

--- zathura-pdf-mupdf/render.c.orig	2018-03-17 19:47:01.000000000 +0000
+++ zathura-pdf-mupdf/render.c
@@ -18,13 +18,16 @@ pdf_page_render_to_buffer(mupdf_document
     return ZATHURA_ERROR_UNKNOWN;
   }
 
-  fz_display_list* display_list = fz_new_display_list(mupdf_page->ctx, NULL);
+  fz_irect irect = { .x1 = page_width, .y1 = page_height };
+  fz_rect rect = { .x1 = page_width, .y1 = page_height };
+
+  fz_display_list* display_list = fz_new_display_list(mupdf_page->ctx, rect);
   fz_device* device             = fz_new_list_device(mupdf_page->ctx, display_list);
 
   fz_try (mupdf_document->ctx) {
     fz_matrix m;
-    fz_scale(&m, scalex, scaley);
-    fz_run_page(mupdf_document->ctx, mupdf_page->page, device, &m, NULL);
+    m = fz_scale(scalex, scaley);
+    fz_run_page(mupdf_document->ctx, mupdf_page->page, device, m, NULL);
   } fz_catch (mupdf_document->ctx) {
     return ZATHURA_ERROR_UNKNOWN;
   }
@@ -32,16 +35,13 @@ pdf_page_render_to_buffer(mupdf_document
   fz_close_device(mupdf_page->ctx, device);
   fz_drop_device(mupdf_page->ctx, device);
 
-  fz_irect irect = { .x1 = page_width, .y1 = page_height };
-  fz_rect rect = { .x1 = page_width, .y1 = page_height };
-
   fz_colorspace* colorspace = fz_device_bgr(mupdf_document->ctx);
   fz_separations* seps= fz_page_separations(mupdf_page->ctx, mupdf_page->page);
-  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, &irect, seps, 1, image);
+  fz_pixmap* pixmap = fz_new_pixmap_with_bbox_and_data(mupdf_page->ctx, colorspace, irect, seps, 1, image);
   fz_clear_pixmap_with_value(mupdf_page->ctx, pixmap, 0xFF);
 
-  device = fz_new_draw_device(mupdf_page->ctx, NULL, pixmap);
-  fz_run_display_list(mupdf_page->ctx, display_list, device, &fz_identity, &rect, NULL);
+  device = fz_new_draw_device(mupdf_page->ctx, fz_identity, pixmap);
+  fz_run_display_list(mupdf_page->ctx, display_list, device, fz_identity, rect, NULL);
   fz_close_device(mupdf_page->ctx, device);
   fz_drop_device(mupdf_page->ctx, device);
 
