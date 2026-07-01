$NetBSD$

Prevent undefined behaviour of toupper().

--- src/stringlib.c.orig	2025-12-09 03:51:38.000000000 +0000
+++ src/stringlib.c
@@ -232,7 +232,7 @@ void StringUpper(char *s)
 {
 	char *p;
 	for (p = s; *p != '\0'; ++p) {
-		*p = toupper(*p);
+		*p = toupper((unsigned char) *p);
 	}
 }
 
