$NetBSD: patch-util_newslock.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for exit(3).

--- util/newslock.c.orig	1989-05-22 02:12:16.000000000 +0000
+++ util/newslock.c
@@ -4,6 +4,7 @@
  * (System V has broken ln(1) itself.)
  */
 #include <stdio.h>
+#include <stdlib.h>
 
 main(argc, argv)
 int argc;
