$NetBSD$

Missing ctype(3) casts.

--- cmd/lib/basicutil.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ cmd/lib/basicutil.c
@@ -676,7 +676,7 @@ SECU_SECItemToHex(const SECItem * item, 
 }
 
 static unsigned char nibble(char c) {
-    c = PORT_Tolower(c);
+    c = PORT_Tolower((unsigned char)c);
     return ( c >= '0' && c <= '9') ? c - '0' :
            ( c >= 'a' && c <= 'f') ? c - 'a' +10 : -1;
 }
