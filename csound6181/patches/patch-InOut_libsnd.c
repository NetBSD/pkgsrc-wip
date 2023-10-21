$NetBSD: patch-InOut_libsnd.c,v 1.2 2014/08/05 05:12:38 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- InOut/libsnd.c.orig	2023-10-21 12:16:36.670142255 +0000
+++ InOut/libsnd.c
@@ -33,7 +33,7 @@
 
 #ifdef PIPES
 # if defined(SGI) || defined(LINUX) || defined(__BEOS__) || defined(NeXT) ||  \
-     defined(__MACH__)
+     defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  define _popen popen
 #  define _pclose pclose
 # endif
