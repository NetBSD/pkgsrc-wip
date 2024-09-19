$NetBSD$

Don't overwrite _*_SOURCE, it breaks build on NetBSD.

--- src/manage_migrators.c.orig	2015-08-03 05:52:13.000000000 +0000
+++ src/manage_migrators.c
@@ -119,8 +119,10 @@
  *       (name UNIQUE, password);
  */
 
+#if !defined(__NetBSD__)
 /* time.h in glibc2 needs this for strptime. */
 #define _XOPEN_SOURCE
+#endif
 
 #include <time.h>
 #include <stdlib.h>
@@ -132,6 +134,10 @@
 #include <ctype.h>
 #include <dirent.h>
 
+#if defined(__NetBSD__)
+#include <sys/wait.h>
+#endif
+
 #include "manage_sql.h"
 #include "sql.h"
 #include "tracef.h"
