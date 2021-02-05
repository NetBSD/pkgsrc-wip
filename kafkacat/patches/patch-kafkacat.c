$NetBSD$

Avoid possible undefined behaviour when using ctype(3) functions.

--- kafkacat.c.orig	2020-07-21 07:09:21.000000000 +0000
+++ kafkacat.c
@@ -1540,12 +1540,12 @@ static int read_conf_file (const char *p
                 line++;
 
                 /* Left-trim */
-                while (isspace(*s))
+                while (isspace((unsigned char)*s))
                         s++;
 
                 /* Right-trim and remove newline */
                 t = s + strlen(s) - 1;
-                while (t > s && isspace(*t)) {
+                while (t > s && isspace((unsigned char)*t)) {
                         *t = 0;
                         t--;
                 }
