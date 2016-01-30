$NetBSD$

Missing ctype(3) casts.

--- lib/certdb/certdb.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/certdb/certdb.c
@@ -1288,7 +1288,7 @@ sec_lower_string(char *s)
     }
 
     while (*s) {
-        *s = PORT_Tolower(*s);
+        *s = PORT_Tolower((unsigned char)*s);
         s++;
     }
 
@@ -2301,7 +2301,7 @@ CERT_FixupEmailAddr(const char *emailAdd
 
     /* make it lower case */
     while (*str) {
-        *str = tolower(*str);
+        *str = tolower((unsigned char)*str);
         str++;
     }
 
