$NetBSD$

Missing ctype(3) casts.

--- lib/util/oidstring.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/util/oidstring.c
@@ -50,7 +50,7 @@ bad_data:
     }
     do {
 	PRUint32 decimal = 0;
-        while (len > 0 && isdigit(*from)) {
+        while (len > 0 && isdigit((unsigned char)*from)) {
 	    PRUint32 addend = (*from++ - '0');
 	    --len;
 	    if (decimal > max_decimal)  /* overflow */
