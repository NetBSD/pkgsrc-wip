$NetBSD: patch-Engine_linevent.c,v 1.2 2014/08/05 05:12:38 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- Engine/linevent.c.orig	2019-07-12 21:54:19.000000000 +0000
+++ Engine/linevent.c
@@ -31,7 +31,7 @@
 #include "linevent.h"
 
 #ifdef PIPES
-# if defined(SGI) || defined(LINUX) || defined(NeXT) || defined(__MACH__)
+# if defined(SGI) || defined(LINUX) || defined(NeXT) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  define _popen popen
 #  define _pclose pclose
 # elif defined(__BEOS__) ||  defined(__HAIKU__) || defined(__MACH__)
