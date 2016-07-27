$NetBSD$

--- sort.c.orig	2016-07-27 09:17:40.627432117 +0000
+++ sort.c
@@ -14,6 +14,7 @@ char sort_RCSid[] = "Revision: 1.2 $";
 
 #include "agm.h"
 
+void
 merge_sort (start, length)
     struct wnode **start;
     int length;
