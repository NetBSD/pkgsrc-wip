$NetBSD: patch-utils.c,v 1.1 2015/04/18 17:09:54 leot1990 Exp $

Add mupdf-1.7 support.

--- utils.c.orig	2014-10-16 22:21:41.000000000 +0000
+++ utils.c
@@ -17,9 +17,9 @@ mupdf_page_extract_text(mupdf_document_t
     text_device = fz_new_text_device(mupdf_page->ctx, mupdf_page->sheet, mupdf_page->text);
     fz_matrix ctm;
     fz_scale(&ctm, 1.0, 1.0);
-    fz_run_page(mupdf_document->document, mupdf_page->page, text_device, &ctm, NULL);
+    fz_run_page(mupdf_page->ctx, mupdf_page->page, text_device, &ctm, NULL);
   } fz_always (mupdf_document->ctx) {
-    fz_free_device(text_device);
+    fz_drop_device(mupdf_page->ctx, text_device);
   } fz_catch(mupdf_document->ctx) {
   }
 
