$NetBSD$

--- plugin.h.orig	2017-01-11 21:21:14.000000000 +0000
+++ plugin.h
@@ -21,7 +21,6 @@ typedef struct mupdf_page_s
 {
   fz_page* page; /**< Reference to the mupdf page */
   fz_context* ctx; /**< Context */
-  fz_stext_sheet* sheet; /**< Text sheet */
   fz_stext_page* text; /**< Page text */
   fz_rect bbox; /**< Bbox */
   bool extracted_text; /**< If text has already been extracted */
