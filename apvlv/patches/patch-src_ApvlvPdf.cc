$NetBSD$

goo/gtypes.h is not exported and seems not strictly needed by ApvlvPdf.cc.

--- src/ApvlvPdf.cc.orig	2015-01-10 14:04:24.000000000 +0000
+++ src/ApvlvPdf.cc
@@ -29,7 +29,6 @@
 #include "ApvlvPdf.h"
 
 #ifndef POPPLER_WITH_GDK
-#include <goo/gtypes.h>
 
 static void
 copy_cairo_surface_to_pixbuf (cairo_surface_t *surface,
