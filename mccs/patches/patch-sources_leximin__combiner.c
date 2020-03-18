$NetBSD$

--- sources/leximin_combiner.c.orig	2011-06-10 14:50:43.000000000 +0000
+++ sources/leximin_combiner.c
@@ -7,7 +7,7 @@
 
 
 #include <stdio.h>
-#include <values.h>
+#include <limits.h>
 #include <leximin_combiner.h>
 
 // Compute the number of columns required to handle the combiner
@@ -34,7 +34,7 @@ int leximin_combiner::column_allocation(
 // Generate the objective function
 int leximin_combiner::objective_generation() {
   int ui;
-  CUDFcoefficient min_y = MAXLONG, max_y = MINLONG, min_ui, max_ui;
+  CUDFcoefficient min_y = LONG_MAX, max_y = LONG_MIN, min_ui, max_ui;
 
   // Declare criteria values as integer
   ui = ui_n;
@@ -117,7 +117,7 @@ int leximin_combiner::set_variable_range
 // Initialize integer variables
 void leximin_combiner::initialize_intvars() {
   int ui;
-  CUDFcoefficient min_y = MAXLONG, max_y = MINLONG, min_ui, max_ui;
+  CUDFcoefficient min_y = LONG_MAX, max_y = LONG_MIN, min_ui, max_ui;
 
   // Declare criteria values as integer
   ui = ui_n;
