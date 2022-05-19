$NetBSD$

Avoid conflict with libc memrchr. Appears to have the same intent,
but this is the path of least resistance.

Authored by dholland@ in revision 1.1 2011/10/03

diff -r d8cbf1749395 -r c8b10f57c096 ptr.c
--- src/ptr.c~	Fri Jun 21 10:22:03 2019 +0000
+++ src/ptr.c	Fri Jun 21 10:26:10 2019 +0000
@@ -419,7 +419,7 @@
  * find last occurrence of c in p
  * return NULL if none found.
  */
-char *memrchr(char *p, int lenp, char c)
+char *memrchrx(char *p, int lenp, char c)
 {
     char *v, *s = p;
 
