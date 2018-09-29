$NetBSD$

Port to mupdf-1.14.0

--- zathura-pdf-mupdf/search.c.orig	2018-03-17 19:47:01.000000000 +0000
+++ zathura-pdf-mupdf/search.c
@@ -39,17 +39,19 @@ pdf_page_search_text(zathura_page_t* pag
     mupdf_page_extract_text(mupdf_document, mupdf_page);
   }
 
-  fz_rect* hit_bbox = fz_malloc_array(mupdf_page->ctx, N_SEARCH_RESULTS, sizeof(fz_rect));
+  fz_quad* hit_bbox = fz_malloc_array(mupdf_page->ctx, N_SEARCH_RESULTS, sizeof(fz_quad));
   int num_results = fz_search_stext_page(mupdf_page->ctx, mupdf_page->text,
       text, hit_bbox, N_SEARCH_RESULTS);
 
+  fz_rect r;
   for (int i = 0; i < num_results; i++) {
     zathura_rectangle_t* rectangle = g_malloc0(sizeof(zathura_rectangle_t));
 
-    rectangle->x1 = hit_bbox[i].x0;
-    rectangle->x2 = hit_bbox[i].x1;
-    rectangle->y1 = hit_bbox[i].y0;
-    rectangle->y2 = hit_bbox[i].y1;
+    r = fz_rect_from_quad(hit_bbox[i]);
+    rectangle->x1 = r.x0;
+    rectangle->x2 = r.x1;
+    rectangle->y1 = r.y0;
+    rectangle->y2 = r.y1;
 
     girara_list_append(list, rectangle);
   }
