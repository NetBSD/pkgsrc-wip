$NetBSD$

Portability fixes for BSD systems.

--- xtrlock.c.orig	2021-02-13 15:34:52.000000000 +0000
+++ xtrlock.c
@@ -31,11 +31,16 @@
 #include <grp.h>
 #include <limits.h>
 #include <string.h>
+#include <sys/param.h>
+#ifndef BSD
 #include <crypt.h>
+#endif
 #include <unistd.h>
 #include <math.h>
 #include <ctype.h>
+#ifndef BSD
 #include <values.h>
+#endif
 
 #ifdef SHADOW_PWD
 #include <shadow.h>
