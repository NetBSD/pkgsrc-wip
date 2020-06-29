$NetBSD$

unistd is also needed on NetBSD.

--- lib-src/libnyquist/nyquist/xlisp/security.c.orig	2020-06-19 15:16:47.000000000 +0000
+++ lib-src/libnyquist/nyquist/xlisp/security.c
@@ -4,7 +4,7 @@
  */
 
 #include <stdlib.h>
-#if defined(UNIX) || defined(__APPLE__) || defined(__CYGWIN__)
+#if defined(UNIX) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__NetBSD__)
 #include <unistd.h>
 #endif
 #ifdef WIN32
