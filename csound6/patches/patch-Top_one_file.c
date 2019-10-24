$NetBSD$

Add NetBSD and DragonFlyBSD support.

--- Top/one_file.c.orig	2014-05-04 04:49:41.000000000 -0700
+++ Top/one_file.c	2014-08-04 22:21:26.000000000 -0700
@@ -29,7 +29,7 @@
 #include <stdlib.h>
 #include "corfile.h"
 
-#if defined(LINUX) || defined(__MACH__) || defined(WIN32)
+#if defined(LINUX) || defined(__MACH__) || defined(WIN32) || defined(__NetBSD__) || defined(__DragonFly__)
 #  include <sys/types.h>
 #  include <sys/stat.h>
 #endif
@@ -96,7 +96,7 @@
       }
 #endif
       if (ext != NULL && ext[0] != (char) 0) {
-#if !defined(LINUX) && !defined(__MACH__) && !defined(WIN32)
+#if !defined(LINUX) && !defined(__MACH__) && !defined(WIN32) && !defined(__NetBSD__) && !defined(__DragonFly__)
         char  *p;
         /* remove original extension (does not work on OS X */
         /* and may be a bad idea) */
