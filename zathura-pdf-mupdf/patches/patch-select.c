$NetBSD$

--- select.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ select.c
@@ -24,9 +24,10 @@ pdf_page_get_text(zathura_page_t* page, 
     mupdf_page_extract_text(mupdf_document, mupdf_page);
   }
 
-  fz_rect rect = { rectangle.x1, rectangle.y1, rectangle.x2, rectangle.y2 };
+  fz_point a = { rectangle.x1, rectangle.y1 };
+  fz_point b = { rectangle.x2, rectangle.y2 };
 
-  return fz_copy_selection(mupdf_page->ctx, mupdf_page->text, rect);
+  return fz_copy_selection(mupdf_page->ctx, mupdf_page->text, a, b, 0);
 
 error_ret:
 
