$NetBSD: patch-document.c,v 1.1 2015/04/18 17:09:54 leot1990 Exp $

Add mupdf-1.7 support.

--- document.c.orig	2014-10-16 22:21:41.000000000 +0000
+++ document.c
@@ -51,14 +51,14 @@ pdf_document_open(zathura_document_t* do
   }
 
   /* authenticate if password is required and given */
-  if (fz_needs_password(mupdf_document->document) != 0) {
-    if (password == NULL || fz_authenticate_password(mupdf_document->document, (char*) password) == 0) {
+  if (fz_needs_password(mupdf_document->ctx, mupdf_document->document) != 0) {
+    if (password == NULL || fz_authenticate_password(mupdf_document->ctx, mupdf_document->document, (char*) password) == 0) {
       error = ZATHURA_ERROR_INVALID_PASSWORD;
       goto error_free;
     }
   }
 
-  zathura_document_set_number_of_pages(document, fz_count_pages(mupdf_document->document));
+  zathura_document_set_number_of_pages(document, fz_count_pages(mupdf_document->ctx, mupdf_document->document));
   zathura_document_set_data(document, mupdf_document);
 
   return error;
@@ -67,10 +67,10 @@ error_free:
 
   if (mupdf_document != NULL) {
     if (mupdf_document->document != NULL) {
-      fz_close_document(mupdf_document->document);
+      fz_drop_document(mupdf_document->ctx, mupdf_document->document);
     }
     if (mupdf_document->ctx != NULL) {
-      fz_free_context(mupdf_document->ctx);
+      fz_drop_context(mupdf_document->ctx);
     }
 
     free(mupdf_document);
@@ -90,8 +90,8 @@ pdf_document_free(zathura_document_t* do
     return ZATHURA_ERROR_INVALID_ARGUMENTS;
   }
 
-  fz_close_document(mupdf_document->document);
-  fz_free_context(mupdf_document->ctx);
+  fz_drop_document(mupdf_document->ctx, mupdf_document->document);
+  fz_drop_context(mupdf_document->ctx);
   free(mupdf_document);
   zathura_document_set_data(document, NULL);
 
@@ -112,7 +112,7 @@ pdf_document_save_as(zathura_document_t*
      * options. */
 
     fz_write_options opts = { 0 }; /* just use the default options */
-    fz_write_document(mupdf_document->document, (char*) path, &opts);
+    fz_write_document(mupdf_document->ctx, mupdf_document->document, (char*) path, &opts);
   } fz_catch (mupdf_document->ctx) {
     return ZATHURA_ERROR_UNKNOWN;
   }
