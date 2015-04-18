$NetBSD: patch-render.c,v 1.1 2015/04/18 17:09:54 leot1990 Exp $

Add mupdf-1.7 support.

--- render.c.orig	2014-10-16 22:21:41.000000000 +0000
+++ render.c
@@ -26,12 +26,12 @@ pdf_page_render_to_buffer(mupdf_document
   fz_try (mupdf_document->ctx) {
     fz_matrix m;
     fz_scale(&m, scalex, scaley);
-    fz_run_page(mupdf_document->document, mupdf_page->page, device, &m, NULL);
+    fz_run_page(mupdf_document->ctx, mupdf_page->page, device, &m, NULL);
   } fz_catch (mupdf_document->ctx) {
     return ZATHURA_ERROR_UNKNOWN;
   }
 
-  fz_free_device(device);
+  fz_drop_device(mupdf_page->ctx, device);
 
   fz_irect irect = { .x1 = page_width, .y1 = page_height };
   fz_rect rect = { .x1 = page_width, .y1 = page_height };
@@ -41,8 +41,8 @@ pdf_page_render_to_buffer(mupdf_document
   fz_clear_pixmap_with_value(mupdf_page->ctx, pixmap, 0xFF);
 
   device = fz_new_draw_device(mupdf_page->ctx, pixmap);
-  fz_run_display_list(display_list, device, &fz_identity, &rect, NULL);
-  fz_free_device(device);
+  fz_run_display_list(mupdf_page->ctx, display_list, device, &fz_identity, &rect, NULL);
+  fz_drop_device(mupdf_page->ctx, device);
 
   unsigned char* s = fz_pixmap_samples(mupdf_page->ctx, pixmap);
   unsigned int n   = fz_pixmap_components(mupdf_page->ctx, pixmap);
