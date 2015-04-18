$NetBSD: patch-page.c,v 1.1 2015/04/18 17:09:54 leot1990 Exp $

Add mupdf-1.7 support.

--- page.c.orig	2014-10-16 22:21:41.000000000 +0000
+++ page.c
@@ -29,12 +29,12 @@ pdf_page_init(zathura_page_t* page)
 
   /* load page */
   fz_try (mupdf_page->ctx) {
-    mupdf_page->page = fz_load_page(mupdf_document->document, index);
+    mupdf_page->page = fz_load_page(mupdf_document->ctx, mupdf_document->document, index);
   } fz_catch (mupdf_page->ctx) {
     goto error_free;
   }
 
-  fz_bound_page(mupdf_document->document, (fz_page*) mupdf_page->page, &mupdf_page->bbox);
+  fz_bound_page(mupdf_document->ctx, (fz_page*) mupdf_page->page, &mupdf_page->bbox);
 
   /* get page dimensions */
   zathura_page_set_width(page,  mupdf_page->bbox.x1 - mupdf_page->bbox.x0);
@@ -74,15 +74,15 @@ pdf_page_clear(zathura_page_t* page, mup
 
   if (mupdf_page != NULL) {
     if (mupdf_page->text != NULL) {
-      fz_free_text_page(mupdf_page->ctx, mupdf_page->text);
+      fz_drop_text_page(mupdf_page->ctx, mupdf_page->text);
     }
 
     if (mupdf_page->sheet != NULL) {
-      fz_free_text_sheet(mupdf_page->ctx, mupdf_page->sheet);
+      fz_drop_text_sheet(mupdf_page->ctx, mupdf_page->sheet);
     }
 
     if (mupdf_page->page != NULL) {
-      fz_free_page(mupdf_document->document, mupdf_page->page);
+      fz_drop_page(mupdf_document->ctx, mupdf_page->page);
     }
 
     free(mupdf_page);
