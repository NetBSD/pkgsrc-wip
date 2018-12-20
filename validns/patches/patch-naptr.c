$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- naptr.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ naptr.c
@@ -42,7 +42,7 @@ static struct rr *naptr_parse(char *name
     if (text.length < 0)
         return NULL;
     for (i = 0; i < text.length; i++) {
-        if (!isalnum(text.data[i])) {
+        if (!isalnum((unsigned char)text.data[i])) {
             return bitch("flags contains illegal characters");
         }
     }
