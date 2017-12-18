$NetBSD$

--- utils.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ utils.c
@@ -7,17 +7,14 @@
 void
 mupdf_page_extract_text(mupdf_document_t* mupdf_document, mupdf_page_t* mupdf_page) {
   if (mupdf_document == NULL || mupdf_document->ctx == NULL || mupdf_page == NULL ||
-      mupdf_page->sheet == NULL || mupdf_page->text == NULL) {
+      mupdf_page->text == NULL) {
     return;
   }
 
   fz_device* text_device = NULL;
 
   fz_try (mupdf_page->ctx) {
-    text_device = fz_new_stext_device(mupdf_page->ctx, mupdf_page->sheet, mupdf_page->text, NULL);
-
-    /* Disable FZ_IGNORE_IMAGE to collect image blocks */
-    fz_disable_device_hints(mupdf_page->ctx, text_device, FZ_IGNORE_IMAGE);
+    text_device = fz_new_stext_device(mupdf_page->ctx, mupdf_page->text, NULL);
 
     fz_matrix ctm;
     fz_scale(&ctm, 1.0, 1.0);
