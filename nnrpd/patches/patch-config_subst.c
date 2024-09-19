$NetBSD: patch-config_subst.c,v 1.1 2011/09/21 20:10:17 hfath Exp $

Take care of outdated extern declarations, #including the missing
header files

--- config/subst.c.orig	1997-12-08 23:48:50.000000000 +0000
+++ config/subst.c
@@ -2,8 +2,10 @@
 **
 **  A C version of Henry Spencer's "subst" script.
 */
+#include <stdlib.h>
 #include <stdio.h>
 #include <errno.h>
+#include <string.h>
 #include <signal.h>
 
 #define LINESIZE		1024
@@ -33,10 +35,6 @@ static char	*argv0;
 extern char	*optarg;
 extern int	optind;
 
-extern void	exit();
-extern char	*malloc();
-extern char	*strcpy();
-
 
 
 /*
@@ -49,11 +47,11 @@ extern char	*strcpy();
 static char *
 xstrerror()
 {
-    extern int	sys_nerr;
 #if !defined(__FreeBSD__) && !defined(__NetBSD__)
+    extern int	sys_nerr;
     extern char	*sys_errlist[];
-#endif
     extern int	errno;
+#endif
     static char	buff[30];
 
     if (errno >= 0 && errno < sys_nerr)
