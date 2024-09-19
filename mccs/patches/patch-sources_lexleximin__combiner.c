$NetBSD$

--- sources/lexleximin_combiner.c.orig	2011-06-10 14:50:43.000000000 +0000
+++ sources/lexleximin_combiner.c
@@ -7,7 +7,7 @@
 
 
 #include <stdio.h>
-#include <values.h>
+#include <limits.h>
 #include <lexleximin_combiner.h>
 
 // Compute the number of columns required to handle the combiner
@@ -34,7 +34,7 @@ int lexleximin_combiner::column_allocati
 // Generate the objective function
 int lexleximin_combiner::objective_generation() {
   int ui;
-  CUDFcoefficient min_y = MAXLONG, max_y = MINLONG, min_ui, max_ui;
+  CUDFcoefficient min_y = LONG_MAX, max_y = LONG_MIN, min_ui, max_ui;
 
   // Declare criteria values as integer
   ui = ui_n;
