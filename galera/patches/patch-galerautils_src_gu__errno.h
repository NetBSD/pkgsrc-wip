$NetBSD$

NetBSD support.

--- galerautils/src/gu_errno.h.orig	2022-11-02 06:09:14.000000000 +0000
+++ galerautils/src/gu_errno.h
@@ -7,7 +7,7 @@
 
 #include <errno.h>
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #  define GU_ELAST ELAST
 #else
 /* must be high enough to not collide with system errnos but lower than 256 */
