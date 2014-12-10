$NetBSD: patch-lib_ext2fs_tdb.c,v 1.1 2014/12/10 12:54:23 makoto Exp $

Move #include <sys/types.h> before the #define of _XOPEN_SOURCE so that
u_short etc. are being defined by it.

Fixes build on MirBSD. 

--- lib/ext2fs/tdb.c.orig	2014-06-26 04:19:40.000000000 +0900
+++ lib/ext2fs/tdb.c	2014-12-10 21:05:31.000000000 +0900
@@ -36,6 +36,7 @@ Last Changed Date: 2007-06-22 13:36:10 -
 #define HAVE_UTIME_H
 #define HAVE_UTIME
 #endif
+#include <sys/types.h>
 #define _XOPEN_SOURCE 600
 
 #include "config.h"
@@ -50,7 +51,6 @@ Last Changed Date: 2007-06-22 13:36:10 -
 #include <sys/select.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <time.h>
 #ifdef HAVE_UTIME_H
 #include <utime.h>
