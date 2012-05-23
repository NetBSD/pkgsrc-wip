$NetBSD: patch-sysdep.h,v 1.1.1.1 2012/05/23 15:37:12 hfath Exp $

--- sysdep.h.orig	2012-05-23 13:52:36.000000000 +0000
+++ sysdep.h
@@ -233,7 +233,7 @@ struct ether_arp {
 extern void error(int fd, int errorno, const char *fmt, ...);
 #endif
 #ifndef HAVE_GETLINE
-extern int getline(char **line, size_t * length, FILE * stream);
+extern ssize_t getline(char **line, size_t * length, FILE * stream);
 #endif
 #ifndef HAVE_VASPRINTF
 #include <stdarg.h>
