$NetBSD$

Portability fixes for BSD systems.

--- xtrlock.c.orig	2021-02-13 15:34:52.000000000 +0000
+++ xtrlock.c
@@ -31,11 +31,15 @@
 #include <grp.h>
 #include <limits.h>
 #include <string.h>
+#if !(defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__APPLE__))
 #include <crypt.h>
+#endif
 #include <unistd.h>
 #include <math.h>
 #include <ctype.h>
+#if !(defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__APPLE__))
 #include <values.h>
+#endif

 #ifdef SHADOW_PWD
 #include <shadow.h>
