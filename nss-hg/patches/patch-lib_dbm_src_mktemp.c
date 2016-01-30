$NetBSD$

Missing ctype(3) casts.

--- lib/dbm/src/mktemp.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/dbm/src/mktemp.c
@@ -137,7 +137,7 @@ _gettemp(char *path, register int *doope
 			if (*trv == 'z')
 				*trv++ = 'a';
 			else {
-				if (isdigit(*trv))
+				if (isdigit((unsigned char)*trv))
 					*trv = 'a';
 				else
 					++*trv;
