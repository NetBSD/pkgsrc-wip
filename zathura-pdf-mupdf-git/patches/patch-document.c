$NetBSD: patch-document.c,v 1.4 2017/01/31 10:12:02 leot Exp $

- Correct the glib-2.0 include header file path.
- Port to mupdf-1.14.0

--- zathura-pdf-mupdf/document.c.orig	2018-03-17 19:47:01.000000000 +0000
+++ zathura-pdf-mupdf/document.c
@@ -3,7 +3,7 @@
 #include <mupdf/fitz.h>
 #include <mupdf/pdf.h>
 
-#include <glib-2.0/glib.h>
+#include <glib.h>
 
 #include "plugin.h"
 
@@ -138,7 +138,7 @@ pdf_document_get_information(zathura_doc
 
   fz_try (mupdf_document->ctx) {
     pdf_obj* trailer = pdf_trailer(mupdf_document->ctx, (pdf_document*) mupdf_document->document);
-    pdf_obj* info_dict = pdf_dict_get(mupdf_document->ctx, trailer, PDF_NAME_Info);
+    pdf_obj* info_dict = pdf_dict_get(mupdf_document->ctx, trailer, PDF_NAME(Info));
 
     /* get string values */
     typedef struct info_value_s {
