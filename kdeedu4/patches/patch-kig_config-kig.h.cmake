$NetBSD: patch-kig_config-kig.h.cmake,v 1.1 2011/05/13 23:25:15 mwdavies Exp $

Older NetBSD doesn't have fmin()

--- kig/config-kig.h.cmake.orig	2011-01-19 22:06:41.000000000 +0000
+++ kig/config-kig.h.cmake
@@ -10,3 +10,4 @@
 /* Define to 1 if you have the <ieeefp.h> header file. */
 #cmakedefine HAVE_IEEEFP_H 1
 
+#cmakedefine HAVE_FMIN 1
