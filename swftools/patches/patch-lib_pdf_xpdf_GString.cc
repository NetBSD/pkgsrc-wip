$NetBSD: patch-lib_pdf_xpdf_GString.cc,v 1.1 2015/02/17 10:36:29 fhajny Exp $

Remove ambiguity, fix build on at least SunOS.

--- lib/pdf/xpdf/GString.cc.orig	2012-04-08 17:26:34.000000000 +0000
+++ lib/pdf/xpdf/GString.cc
@@ -528,7 +528,7 @@ void GString::formatDouble(double x, cha
   if ((neg = x < 0)) {
     x = -x;
   }
-  x = floor(x * pow(10, prec) + 0.5);
+  x = floor(x * pow((double)10, prec) + 0.5);
   i = bufSize;
   started = !trim;
   for (j = 0; j < prec && i > 1; ++j) {
