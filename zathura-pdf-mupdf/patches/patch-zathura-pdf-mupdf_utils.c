$NetBSD$

Port to mupdf-1.14.0

--- zathura-pdf-mupdf/utils.c.orig	2018-03-17 19:47:01.000000000 +0000
+++ zathura-pdf-mupdf/utils.c
@@ -18,8 +18,8 @@ mupdf_page_extract_text(mupdf_document_t
     fz_disable_device_hints(mupdf_page->ctx, text_device, FZ_DONT_INTERPOLATE_IMAGES);
 
     fz_matrix ctm;
-    fz_scale(&ctm, 1.0, 1.0);
-    fz_run_page(mupdf_page->ctx, mupdf_page->page, text_device, &ctm, NULL);
+    ctm = fz_scale(1.0, 1.0);
+    fz_run_page(mupdf_page->ctx, mupdf_page->page, text_device, ctm, NULL);
   } fz_always (mupdf_document->ctx) {
     fz_close_device(mupdf_page->ctx, text_device);
     fz_drop_device(mupdf_page->ctx, text_device);
