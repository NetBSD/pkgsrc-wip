$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- base64.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ base64.c
@@ -39,7 +39,7 @@ decode_base64(void *dest, char *src, siz
             v = 62;
         else if (*src == '/')
             v = 63;
-        else if (isspace(*src) || *src == '=') {
+        else if (isspace((unsigned char)*src) || *src == '=') {
             src++;
             continue;
         } else {
