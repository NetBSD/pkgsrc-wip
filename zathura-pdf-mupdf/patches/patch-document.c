$NetBSD: patch-document.c,v 1.4 2017/01/31 10:12:02 leot Exp $

Correct the glib-2.0 include header file path.

--- document.c.orig	2017-01-11 21:21:14.000000000 +0000
+++ document.c
@@ -2,10 +2,13 @@
 
 #define _POSIX_C_SOURCE 1
 
+#include <stdlib.h>
+#include <string.h>
+
 #include <mupdf/fitz.h>
 #include <mupdf/pdf.h>
 
-#include <glib-2.0/glib.h>
+#include <glib.h>
 
 #include "plugin.h"
 
