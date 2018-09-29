$NetBSD$

Port to mupdf-1.14.0

--- zathura-pdf-mupdf/page.c.orig	2018-03-17 19:47:01.000000000 +0000
+++ zathura-pdf-mupdf/page.c
@@ -30,14 +30,12 @@ pdf_page_init(zathura_page_t* page)
     goto error_free;
   }
 
-  fz_bound_page(mupdf_document->ctx, (fz_page*) mupdf_page->page, &mupdf_page->bbox);
+  mupdf_page->bbox = fz_bound_page(mupdf_document->ctx, (fz_page*) mupdf_page->page);
 
   /* setup text */
   mupdf_page->extracted_text = false;
 
-  fz_rect mediabox;
-  mupdf_page->text = fz_new_stext_page(mupdf_page->ctx,
-      fz_bound_page(mupdf_page->ctx, mupdf_page->page, &mediabox));
+  mupdf_page->text = fz_new_stext_page(mupdf_page->ctx, mupdf_page->bbox);
   if (mupdf_page->text == NULL) {
     goto error_free;
   }
