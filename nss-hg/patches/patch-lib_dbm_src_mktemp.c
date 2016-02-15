$NetBSD$

Missing ctype(3) casts.

--- lib/dbm/src/mktemp.c.orig	2016-02-15 10:09:28.000000000 +0000
+++ lib/dbm/src/mktemp.c
@@ -138,7 +138,7 @@ _gettemp(char *path, register int *doope
             if (*trv == 'z')
                 *trv++ = 'a';
             else {
-                if (isdigit(*trv))
+                if (isdigit((unsigned char)*trv))
                     *trv = 'a';
                 else
                     ++*trv;
