$NetBSD$

Function new_from_template() is defined with return value of type int.
This patch returns -1 to indicate an error.

--- bystand.c.orig	2019-11-25 12:10:21.000000000 +0000
+++ bystand.c
@@ -483,7 +483,7 @@ static int new_from_template(const char*
     printf("%m\n");
   }
   sqlite3_free(filename);
-  if(!fp) return;
+  if(!fp) return -1;
   filename=sqlite3_mprintf("%s/article",home);
   if(!filename) errx(1,"Allocation failed");
   outfp=fopen(filename,"w");
