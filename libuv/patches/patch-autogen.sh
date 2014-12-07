$NetBSD: patch-autogen.sh,v 1.1 2014/12/07 21:55:50 jonthn Exp $

Use libtoolize on Darwin instead of glibtoolize

--- autogen.sh.orig	2014-12-01 19:48:53.000000000 +0000
+++ autogen.sh
@@ -16,10 +16,6 @@
 
 cd `dirname "$0"`
 
-if [ "$LIBTOOLIZE" = "" ] && [ "`uname`" = "Darwin" ]; then
-  LIBTOOLIZE=glibtoolize
-fi
-
 ACLOCAL=${ACLOCAL:-aclocal}
 AUTOCONF=${AUTOCONF:-autoconf}
 AUTOMAKE=${AUTOMAKE:-automake}
