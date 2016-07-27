$NetBSD$

--- gobble.c.orig	2016-07-27 09:01:17.572044212 +0000
+++ gobble.c
@@ -22,6 +22,10 @@ char gobble_RCSid[] = "Revision: 1.4 $";
 
 #include "agm.h"
 
+#include <stdlib.h>
+#include <unistd.h>
+
+void
 gobble_file (filename, command)
     char *filename, *command;
 {
@@ -81,4 +85,3 @@ gobble_file (filename, command)
   }
   if (notquiet) printf (" %d words\n", wordcount - before_count);
 }
-
