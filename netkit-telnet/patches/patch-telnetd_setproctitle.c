$NetBSD$

--- telnetd/setproctitle.c.orig	1999-12-10 23:06:39.000000000 +0000
+++ telnetd/setproctitle.c
@@ -47,6 +47,11 @@ char setproctitle_rcsid[] =
 #include <stdarg.h>
 #include <stdio.h>
 
+#if defined __APPLE__
+extern char **environ; /* from environ(7) */
+#  define __environ environ
+#endif
+
 #include "setproctitle.h"
 /*
 **  SETPROCTITLE -- set process title for ps
