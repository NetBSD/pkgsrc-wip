$NetBSD$

Missing ctype(3) casts.

--- lib/certhigh/ocsp.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/certhigh/ocsp.c
@@ -3569,7 +3569,7 @@ ocsp_UrlEncodeBase64Buf(const char *base
 
     for (walkInput = base64Buf; *walkInput; ++walkInput) {
         char c = *walkInput;
-        if (isspace(c))
+        if (isspace((unsigned char)c))
             continue;
         switch (c) {
             case '+':
