$NetBSD$

Depend on errno.h to provide errno.

--- sh.h.orig	2015-06-07 19:11:23.000000000 +0000
+++ sh.h
@@ -68,7 +68,6 @@
 #define SH_VA_START(va, argn) va_start(va, argn)
 
 #include <errno.h>
-extern int errno;
 
 #ifdef HAVE_FCNTL_H
 # include <fcntl.h>
