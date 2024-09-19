$NetBSD$

--- sources/lexleximax_combiner.c.orig	2011-06-10 14:50:43.000000000 +0000
+++ sources/lexleximax_combiner.c
@@ -7,7 +7,7 @@
 
 
 #include <stdio.h>
-#include <values.h>
+#include <limits.h>
 #include <lexleximax_combiner.h>
 
 // Compute the number of columns required to handle the combiner
@@ -36,7 +36,7 @@ int lexleximax_combiner::objective_gener
 
   if (n > 0) {
     int ui = ui_n;
-    CUDFcoefficient min_y = MAXLONG, max_y = MINLONG, min_ui, max_ui;
+    CUDFcoefficient min_y = LONG_MAX, max_y = LONG_MIN, min_ui, max_ui;
 
     // Declare criteria values as integer
     CriteriaListIterator crit = criteria->begin();
