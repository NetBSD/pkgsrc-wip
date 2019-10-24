$NetBSD$

Add NetBSD and DragonFlyBSD support.

--- InOut/libsnd.c.orig	2014-01-07 08:53:47.000000000 -0800
+++ InOut/libsnd.c	2014-02-12 23:47:56.000000000 -0800
@@ -34,6 +34,7 @@
 #ifdef PIPES
 # if defined(SGI) || defined(LINUX) || defined(__BEOS__) || defined(NeXT) ||  \
      defined(__MACH__)
+     defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  define _popen popen
 #  define _pclose pclose
 # endif
