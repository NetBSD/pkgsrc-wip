$NetBSD: patch-src_common_compat__getopt.c,v 1.1 2014/02/27 20:26:27 r-hansen Exp $

See comment in patch-src_common_compat__getopt.h.

--- src/common/compat_getopt.c.orig	2014-02-21 12:09:57.000000000 +0000
+++ src/common/compat_getopt.c
@@ -25,7 +25,7 @@
 
 #include "config.h"
 
-#if ! ( defined(HAVE_GETOPT_H) && defined(HAVE_GETOPT_LONG) && defined(HAVE_GETOPT_LONG_ONLY) )
+#if ! ( defined(HAVE_GETOPT_H) && defined(HAVE_GETOPT_LONG) )
 
 #include <sys/types.h>
 #include <stdlib.h>
