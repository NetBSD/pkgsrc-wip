$NetBSD: patch-libc_stdfdopen.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for exit(3).

--- libc/stdfdopen.c.orig	1990-10-28 07:20:54.000000000 +0000
+++ libc/stdfdopen.c
@@ -4,6 +4,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <errno.h>
 #ifndef __STDC__
 extern int errno;
