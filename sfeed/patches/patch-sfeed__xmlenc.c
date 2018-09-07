$NetBSD$

Avoid possible UBs in ctype(3) functions.

--- sfeed_xmlenc.c.orig	2018-08-26 13:03:06.000000000 +0000
+++ sfeed_xmlenc.c
@@ -37,7 +37,7 @@ xmlattr(XMLParser *p, const char *tag, s
 		if (*value) {
 			/* output lowercase */
 			for (; *value; value++)
-				putc(tolower((int)*value), stdout);
+				putc(tolower((unsigned char)*value), stdout);
 			putchar('\n');
 		}
 		exit(0);
