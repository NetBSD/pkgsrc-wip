$NetBSD$

Avoid conflict with libc memrchr. Appears to have the same intent,
but this is the path of least resistance.

Authored by dholland@ on 2011/10/03 in patch revision 1.1

diff -r bbd2f93df3a0 -r d8cbf1749395 ptr.h
--- src/ptr.h~	Fri Jun 21 10:19:28 2019 +0000
+++ src/ptr.h	Fri Jun 21 10:22:03 2019 +0000
@@ -69,7 +69,7 @@
 /* TODO: watch memrchr, it is defined differently here than under _GNU_SOURCE,
  * so it could cause bizarre results if a module makes use of a library that
  * uses it */
-char *memrchr(char *p, int lenp, char c);
+char *memrchrx(char *p, int lenp, char c);
 #endif
 
 #endif /* _PTR_H_ */
