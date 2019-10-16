$NetBSD$

Add DragonFly to conditions list.

--- fltk/x11.h.orig	2012-03-23 05:49:17.000000000 +0000
+++ fltk/x11.h
@@ -69,7 +69,7 @@ header files directly.
 
 #   undef Window
 
-#   if defined(__FreeBSD__) || defined(__APPLE__) || defined(__CYGWIN__)
+#   if defined(__FreeBSD__) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__DragonFly__)
      typedef unsigned long	ulong;
      typedef unsigned int      	uint;
      typedef unsigned char	uchar;
