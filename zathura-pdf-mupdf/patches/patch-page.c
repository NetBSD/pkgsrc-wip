$NetBSD$

--- page.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ page.c
@@ -2,6 +2,8 @@
 
 #define _POSIX_C_SOURCE 1
 
+#include <stdlib.h>
+
 #include "plugin.h"
 
 zathura_error_t
@@ -50,11 +52,6 @@ pdf_page_init(zathura_page_t* page)
     goto error_free;
   }
 
-  mupdf_page->sheet = fz_new_stext_sheet(mupdf_page->ctx);
-  if (mupdf_page->sheet == NULL) {
-    goto error_free;
-  }
-
   return ZATHURA_ERROR_OK;
 
 error_free:
@@ -79,10 +76,6 @@ pdf_page_clear(zathura_page_t* page, mup
       fz_drop_stext_page(mupdf_page->ctx, mupdf_page->text);
     }
 
-    if (mupdf_page->sheet != NULL) {
-      fz_drop_stext_sheet(mupdf_page->ctx, mupdf_page->sheet);
-    }
-
     if (mupdf_page->page != NULL) {
       fz_drop_page(mupdf_document->ctx, mupdf_page->page);
     }
