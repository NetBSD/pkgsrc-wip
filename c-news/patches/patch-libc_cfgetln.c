$NetBSD: patch-libc_cfgetln.c,v 1.1 2011/08/17 19:56:09 hfath Exp $

Prototype for free()

--- libc/cfgetln.c.orig	1993-09-12 01:52:44.000000000 +0000
+++ libc/cfgetln.c
@@ -5,6 +5,7 @@
  * return value is malloced and must be freed by caller.
  */
 
+#include <stdlib.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <fgetfln.h>
