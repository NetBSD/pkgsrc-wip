$NetBSD$

--- output.c.orig	2016-07-27 09:17:40.617570040 +0000
+++ output.c
@@ -24,6 +24,7 @@ char output_RCSid[] = "Revision: 1.5 $";
 
 #include "agm.h"
 
+void
 print_prevs (percent)
      int percent;
 {
