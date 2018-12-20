$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- rr.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ rr.c
@@ -449,7 +449,7 @@ invalid:
     }
     if (*s++ != '#')
         goto invalid;
-    if (*s && !isspace(*s) && *s != ';' && *s != ')')
+    if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')')
         goto invalid;
     s = skip_white_space(s);
     if (!s) return NULL;
@@ -841,7 +841,7 @@ int extract_algorithm(char **s, char *wh
     int alg;
     char *str_alg;
 
-    if (isdigit(**s)) {
+    if (isdigit((unsigned char)**s)) {
         alg = extract_integer(s, what, NULL);
         if (algorithm_type(alg) == ALG_UNSUPPORTED) {
             bitch("bad or unsupported algorithm %d", alg);
