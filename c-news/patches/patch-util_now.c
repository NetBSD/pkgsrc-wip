$NetBSD: patch-util_now.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for strlen(3), and GC 'register'.

--- util/now.c.orig	1995-04-28 00:51:46.000000000 +0000
+++ util/now.c
@@ -5,6 +5,7 @@
 #include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <time.h>
 #include "libc.h"
 
@@ -15,8 +16,8 @@ main(argc, argv)
 int argc;
 char *argv[];
 {
-	register time_t now;
-	register char c;
+	time_t now;
+	char c;
 
 	now = time((time_t *)NULL);
 	if (argc == 2 && ((c = *argv[1]) == '-' || c == '+') &&
