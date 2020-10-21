$NetBSD$

--- src/utils/prt2pdf.c.orig	2019-08-10 21:30:47.000000000 +0000
+++ src/utils/prt2pdf.c
@@ -83,7 +83,7 @@ o added command line options for
 #include <stdlib.h>
 #include <ctype.h>
 #include <unistd.h>
-char *gets(char *s);
+//char *gets(char *s);
 
 /* ============================================================================================================================== */
 #define MAX(x, y)       ((x) > (y) ? (x) : (y))
