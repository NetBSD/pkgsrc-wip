$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- nsec3.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ nsec3.c
@@ -65,7 +65,7 @@ static struct rr* nsec3_parse(char *name
         rr->salt.length = 0;
         rr->salt.data = NULL;
         s++;
-        if (*s && !isspace(*s) && *s != ';' && *s != ')')
+        if (*s && !isspace((unsigned char)*s) && *s != ';' && *s != ')')
             return bitch("salt is not valid");
         s = skip_white_space(s);
     } else {
