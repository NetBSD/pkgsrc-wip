$NetBSD$

Fix double free in pdf_page_init()

In case of failure in 'pdf_page_init', the mupdf_page is being cleared
and freed but the zathura_page still holds a pointer to it, resulting
in a double free when 'pdf_page_clear' is later called.

The execution flow resulting in a double free is the following:
  zathura_page_new()
    pdf_page_init()
      zathura_page_set_data()
      failure of fz_load_page(),fz_bound_page() or fz_new_stext_sheet()
      pdf_page_clear()
    zathura_page_free()
      pdf_page_clear() // double free

Make sure 'zathura_page_set_data' is called only if no errors occurred
so that page->data never points to freed memory.

Backported from upstream, commit 83b3f9e77bb6aedfa6b4fffc1088c25ae209fd81.

--- page.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ page.c
@@ -20,8 +20,6 @@ pdf_page_init(zathura_page_t* page)
     return  ZATHURA_ERROR_OUT_OF_MEMORY;
   }
 
-  zathura_page_set_data(page, mupdf_page);
-
   mupdf_page->ctx = mupdf_document->ctx;
   if (mupdf_page->ctx == NULL) {
     goto error_free;
@@ -36,10 +34,6 @@ pdf_page_init(zathura_page_t* page)
 
   fz_bound_page(mupdf_document->ctx, (fz_page*) mupdf_page->page, &mupdf_page->bbox);
 
-  /* get page dimensions */
-  zathura_page_set_width(page,  mupdf_page->bbox.x1 - mupdf_page->bbox.x0);
-  zathura_page_set_height(page, mupdf_page->bbox.y1 - mupdf_page->bbox.y0);
-
   /* setup text */
   mupdf_page->extracted_text = false;
 
@@ -55,6 +49,12 @@ pdf_page_init(zathura_page_t* page)
     goto error_free;
   }
 
+  zathura_page_set_data(page, mupdf_page);
+
+  /* get page dimensions */
+  zathura_page_set_width(page,  mupdf_page->bbox.x1 - mupdf_page->bbox.x0);
+  zathura_page_set_height(page, mupdf_page->bbox.y1 - mupdf_page->bbox.y0);
+
   return ZATHURA_ERROR_OK;
 
 error_free:
