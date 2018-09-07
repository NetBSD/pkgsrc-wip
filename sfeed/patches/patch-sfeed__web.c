$NetBSD$

Avoid possible UBs in ctype(3) functions.

--- sfeed_web.c.orig	2018-08-26 13:03:06.000000000 +0000
+++ sfeed_web.c
@@ -22,7 +22,7 @@ static void
 printfeedtype(const char *s, FILE *fp)
 {
 	for (; *s; s++)
-		if (!isspace((int)*s))
+		if (!isspace((unsigned char)*s))
 			fputc(*s, fp);
 }
 
