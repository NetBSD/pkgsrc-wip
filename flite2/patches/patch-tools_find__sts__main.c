$NetBSD$

--- tools/find_sts_main.c.orig	2011-12-07 21:48:06.000000000 +0000
+++ tools/find_sts_main.c
@@ -40,7 +40,8 @@
 #include <stdio.h>
 #include <math.h>
 #include <string.h>
-
+#include <stdlib.h>
+#include <unistd.h>
 /* To allow some normally const fields to manipulated during building */
 #define const
 
