$NetBSD$

Missing ctype(3) casts.

--- cmd/lib/basicutil.c.orig	2016-04-25 00:47:19.000000000 +0000
+++ cmd/lib/basicutil.c
@@ -686,7 +686,7 @@ SECU_SECItemToHex(const SECItem *item, c
 static unsigned char
 nibble(char c)
 {
-    c = PORT_Tolower(c);
+    c = PORT_Tolower((unsigned char)c);
     return (c >= '0' && c <= '9') ? c - '0' :
                                   (c >=
                                        'a' &&
