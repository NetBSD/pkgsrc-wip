$NetBSD$

--- src/pipewire/conf.c.orig	2024-10-21 15:45:51.137278772 +0000
+++ src/pipewire/conf.c
@@ -18,7 +18,7 @@
 #ifdef HAVE_PWD_H
 #include <pwd.h>
 #endif
-#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__) || defined(__NetBSD__)
 #ifndef O_PATH
 #define O_PATH 0
 #endif
