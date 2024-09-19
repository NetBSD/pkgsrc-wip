$NetBSD$

--- src/VBox/GuestHost/OpenGL/util/environment.c.orig	2016-03-04 19:29:23.000000000 +0000
+++ src/VBox/GuestHost/OpenGL/util/environment.c
@@ -12,7 +12,7 @@
 
 void crSetenv( const char *var, const char *value )
 {
-#if defined(LINUX) || defined(FREEBSD) || defined(DARWIN)
+#if defined(LINUX) || defined(FREEBSD) || defined(DARWIN) || defined(__NetBSD__)
 	setenv( var, value, 1 /* replace */ );
 #else
 	unsigned long len;
