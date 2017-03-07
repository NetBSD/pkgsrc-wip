$NetBSD$

Why shouldn't FreeBSD define USE_BACKTRACE as well.

--- src/mapi/glapi/glapi_gentable.c.orig	2017-02-13 11:56:32.000000000 +0000
+++ src/mapi/glapi/glapi_gentable.c
@@ -36,7 +36,7 @@
 #endif
 
 #if (defined(GLXEXT) && defined(HAVE_BACKTRACE)) \
-	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__))
+	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__))
 #define USE_BACKTRACE
 #endif
 
