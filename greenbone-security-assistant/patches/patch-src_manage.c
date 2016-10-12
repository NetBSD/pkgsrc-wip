$NetBSD$

Don't overwrite _*_SOURCE, it breaks build on NetBSD.

--- src/manage.c.orig	2016-08-25 12:15:47.000000000 +0000
+++ src/manage.c
@@ -37,10 +37,12 @@
  * running the tasks.
  */
 
+#if !defined(__NetBSD__)
 /* time.h in glibc2 needs this for strptime. */
 #define _XOPEN_SOURCE
 /* pthread_sigmask () needs this with glibc < 2.19 */
 #define _GNU_SOURCE
+#endif
 
 #include "manage.h"
 #include "scanner.h"
