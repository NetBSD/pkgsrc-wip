$NetBSD$

--- big.c.orig	2026-09-29 19:07:17.976039282 +0000
+++ big.c
@@ -473,8 +473,8 @@ word bigoscan(char *p,char *q)  /* read 
 }
 
 word digitval(char c)
-{ return isdigit(c)?c-'0':
-         isupper(c)?10+c-'A':
+{ return isdigit((unsigned char)c)?c-'0':
+         isupper((unsigned char)c)?10+c-'A':
          10+c-'a'; }
 
 word strtobig(word z,int base) /* numeral (as Miranda string) to big number */
