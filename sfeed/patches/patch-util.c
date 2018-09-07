$NetBSD$

Avoid possible UBs in ctype(3) functions.

--- util.c.orig	2018-08-26 13:03:06.000000000 +0000
+++ util.c
@@ -31,7 +31,7 @@ parseuri(const char *s, struct uri *u, i
 		p += 2; /* skip "//" */
 	} else {
 		/* protocol part */
-		for (p = s; *p && (isalpha((int)*p) || isdigit((int)*p) ||
+		for (p = s; *p && (isalpha((unsigned char)*p) || isdigit((unsigned char)*p) ||
 			       *p == '+' || *p == '-' || *p == '.'); p++)
 			;
 		if (!strncmp(p, "://", 3)) {
@@ -101,7 +101,7 @@ encodeuri(char *buf, size_t bufsiz, cons
 	for (i = 0, b = 0; s[i]; i++) {
 		if ((int)s[i] == ' ' ||
 		    (unsigned char)s[i] > 127 ||
-		    iscntrl((int)s[i])) {
+		    iscntrl((unsigned char)s[i])) {
 			if (b + 3 >= bufsiz)
 				return -1;
 			buf[b++] = '%';
