$NetBSD: patch-config.h.cmake,v 1.1 2013/05/09 12:33:52 fhajny Exp $

sys/wait.h is needed on SunOS and missed by cmake.
--- config.h.cmake.orig	2012-08-06 11:42:12.000000000 +0000
+++ config.h.cmake
@@ -22,6 +22,7 @@
 #cmakedefine HAVE_SYS_TYPES_H
 #cmakedefine HAVE_SYS_UIO_H
 #cmakedefine HAVE_SYS_UN_H
+#cmakedefine HAVE_SYS_WAIT_H
 #cmakedefine HAVE_TIME_H
 #cmakedefine HAVE_UNISTD_H
 #cmakedefine HAVE_SYSLOG_H
