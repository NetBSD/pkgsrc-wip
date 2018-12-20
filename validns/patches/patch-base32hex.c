$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- base32hex.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ base32hex.c
@@ -48,7 +48,7 @@ decode_base32hex(void *dest, char *src, 
             v = *src - 'a' + 10;
         else if (*src >= '0' && *src <= '9')
             v = *src - '0';
-        else if (isspace(*src) || *src == '=') {
+        else if (isspace((unsigned char)*src) || *src == '=') {
             src++;
             continue;
         } else {
