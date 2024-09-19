$NetBSD: patch-maint_histinfo.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for exit(3).

--- maint/histinfo.c.orig	1995-01-02 21:48:43.000000000 +0000
+++ maint/histinfo.c
@@ -3,6 +3,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>		/* for modified time (date received) */
 #include <string.h>
