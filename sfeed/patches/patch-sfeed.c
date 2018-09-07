$NetBSD$

Avoid possible UBs in ctype(3) functions.

--- sfeed.c.orig	2018-09-07 13:27:10.299338895 +0000
+++ sfeed.c
@@ -381,11 +381,11 @@ gettzoffset(const char *s)
 	switch (s[0]) {
 	case '-': /* offset */
 	case '+':
-		for (i = 0, p = s + 1; i < 2 && *p && isdigit(*p); i++, p++)
+		for (i = 0, p = s + 1; i < 2 && *p && isdigit((unsigned char)*p); i++, p++)
 			tzhour = (tzhour * 10) + (*p - '0');
-		if (*p && !isdigit(*p))
+		if (*p && !isdigit((unsigned char)*p))
 			p++;
-		for (i = 0; i < 2 && *p && isdigit(*p); i++, p++)
+		for (i = 0; i < 2 && *p && isdigit((unsigned char)*p); i++, p++)
 			tzmin = (tzmin * 10) + (*p - '0');
 		return ((tzhour * 3600) + (tzmin * 60)) * (s[0] == '-' ? -1 : 1);
 	default: /* timezone name */
