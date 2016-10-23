$NetBSD$

Add NetBSD support.

--- src/libbu/uce-dirent.h.orig	2016-08-09 06:47:43.000000000 +0000
+++ src/libbu/uce-dirent.h
@@ -123,6 +123,8 @@
 #   define HAVE_DIRENT_H
 # elif defined(__FreeBSD__)                    /* FreeBSD */
 #   define HAVE_DIRENT_H
+# elif defined(__NetBSD__)                     /* NetBSD */
+#   define HAVE_DIRENT_H
 # elif defined(__linux__)                      /* Linux */
 #   define HAVE_DIRENT_H
 # elif defined(__GNUC__)                       /* GNU C/C++ */
