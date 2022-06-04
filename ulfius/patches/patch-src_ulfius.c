$NetBSD$

Reported to upstream.

--- src/ulfius.c.orig	2022-05-28 16:10:35.000000000 +0000
+++ src/ulfius.c
@@ -1860,7 +1860,7 @@ char * ulfius_url_encode(const char * st
       pbuf = buf;
       while (* pstr) {
         // "$-_.+!*'(),"
-        if (isalnum(* pstr) || * pstr == '$' || * pstr == '-' || * pstr == '_' ||
+        if (isalnum((int)* pstr) || * pstr == '$' || * pstr == '-' || * pstr == '_' ||
             * pstr == '.' || * pstr == '!' || * pstr == '*' ||
             * pstr == '\'' || * pstr == '(' || * pstr == ')' || * pstr == ',')
           * pbuf++ = * pstr;
