$NetBSD: patch-source_mupen64plus-core_src_main_util.c,v 1.1 2012/11/11 02:30:48 othyro Exp $

Fixes "array subscript has type 'char'" warning.

--- source/mupen64plus-core/src/main/util.c.orig	2012-03-10 18:31:29.000000000 +0000
+++ source/mupen64plus-core/src/main/util.c
@@ -45,7 +45,7 @@ char *trim(char *str)
     unsigned int i;
     char *p = str;
 
-    while (isspace(*p))
+    while (isspace((unsigned char)*p))
         p++;
 
     if (str != p)
@@ -57,7 +57,7 @@ char *trim(char *str)
     p = str + strlen(str) - 1;
     if (p > str)
     {
-        while (isspace(*p))
+        while (isspace((unsigned char)*p))
             p--;
         p[1] = '\0';
     }
