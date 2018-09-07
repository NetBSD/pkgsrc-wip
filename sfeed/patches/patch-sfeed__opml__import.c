$NetBSD$

Avoid possible UBs in ctype(3) functions.

--- sfeed_opml_import.c.orig	2018-08-26 13:03:06.000000000 +0000
+++ sfeed_opml_import.c
@@ -18,7 +18,7 @@ static void
 printsafe(const char *s)
 {
 	for (; *s; s++) {
-		if (iscntrl((int)*s))
+		if (iscntrl((unsigned char)*s))
 			continue;
 		else if (*s == '\\')
 			fputs("\\\\", stdout);
