$NetBSD: patch-index.c,v 1.1 2015/04/18 17:09:54 leot1990 Exp $

Add mupdf-1.7 support.

--- index.c.orig	2014-10-16 22:21:41.000000000 +0000
+++ index.c
@@ -19,7 +19,7 @@ pdf_document_index_generate(zathura_docu
   }
 
   /* get outline */
-  fz_outline* outline = fz_load_outline(mupdf_document->document);
+  fz_outline* outline = fz_load_outline(mupdf_document->ctx, mupdf_document->document);
   if (outline == NULL) {
     if (error != NULL) {
       *error = ZATHURA_ERROR_UNKNOWN;
@@ -32,7 +32,7 @@ pdf_document_index_generate(zathura_docu
   build_index(outline, root);
 
   /* free outline */
-  fz_free_outline(mupdf_document->ctx, outline);
+  fz_drop_outline(mupdf_document->ctx, outline);
 
   return root;
 }
